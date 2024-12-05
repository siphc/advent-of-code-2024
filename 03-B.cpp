// this is still bad code. when do i ever learn?
#include <iostream>
#include <fstream>
#include <regex>

int main(){
    std::ifstream input("03.txt");

    std::regex match("do\\(\\)|don't\\(\\)|mul\\((\\d{1,3}),(\\d{1,3})\\)");

    long long res = 0;
    bool status = 1;
    std::string line;

    while (input.peek() != -1){
        input >> line;

        std::for_each(std::sregex_iterator(line.begin(), line.end(), match), std::sregex_iterator(), [&res, &status](const auto i){
            if (i[1]=="") status = (i[0]=="do()"?1:0);
            else res += (status?stoi(i[1])*stoi(i[2]):0);
        });
    }

    std::cout << res << std::endl;
}