// God has given us a standard library, I am going to use it.
#include <vector>
#include <fstream>
#include <iostream>

int main(){
    std::vector<std::vector<int>> data(1000);

    std::ifstream input("02.txt");

    int res = 0;

    for (int i=0; i<1000; i++){
        while (input.peek() != '\n' && input.peek() != -1){ // -1 is eof
            data[i].push_back(0);
            input >> data[i].back();
        }
        input.ignore(1, '\n');

        int direction = (data[i][1]>data[i][0] ? 1 : -1);

        for (int j=1; j<data[i].size(); j++){
            if (abs(data[i][j]-data[i][j-1])>3 || (data[i][j]-data[i][j-1])*direction<=0){
                res--;
                break;
            }
        }

        res++;
    }

    input.close();

    std::cout << res << std::endl;
}