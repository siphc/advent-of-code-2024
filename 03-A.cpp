// this is bad code.
#include <iostream>
#include <fstream>
#include <regex>

int main(){
    std::ifstream input("03.txt");

    std::regex match("mul\\((\\d{1,3}),(\\d{1,3})\\)");

    long long res = 0;
    std::string line;

    while (input.peek() != -1){
        input >> line;

        std::for_each(std::sregex_iterator(line.begin(), line.end(), match), std::sregex_iterator(), [&res](const auto i){
            res += stoi(i[1])*stoi(i[2]);
        });
    }

    std::cout << res << std::endl;
}