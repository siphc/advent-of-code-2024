// God has given us a standard library, I am going to use it.
#include <vector>
#include <fstream>
#include <iostream>

bool validity(const std::vector<int>& ar){
    int direction = (ar[1]>ar[0] ? 1 : -1);

    for (int i=1; i<ar.size(); i++){
        if (abs(ar[i]-ar[i-1])>3 || (ar[i]-ar[i-1])*direction<=0){
            return false;
        }
    }

    return true;
}


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

        if (validity(data[i])){
            res++;
            continue;
        }
        else {
            for (int j=0; j<data[i].size(); j++){
                std::vector<int> dampened = data[i];
                dampened.erase(dampened.begin()+j);
                if (validity(dampened)){
                    res++;
                    break;
                }
            }
        }
    }

    input.close();

    std::cout << res << std::endl;
}