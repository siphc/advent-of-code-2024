// the input schema requires a tiny tweak to the input file.
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main(){
    std::ifstream input("05.txt");

    std::vector<std::vector<int>> order(100);
    int res = 0;

    std::string s;
    input >> s;
    while (s.length()==5){
        order.at(stoi(s.substr(0,2))).push_back(stoi(s.substr(3,2)));
        input >> s;
    }

    // this is terrible time complexity. too bad!
    while (input.peek()!=-1){
        input >> s;
        std::vector<int> currupdate;
        bool sanity = true;

        for (int i=0; i<(s.length()+1)/3; i++){
            if (!sanity) break;
            currupdate.push_back(stoi(s.substr(3*i,2)));
            for (int j=0; j<currupdate.size()-1; j++){
                std::vector<int>* currpage = &order.at(currupdate.back());
                if (std::find((*currpage).begin(), (*currpage).end(), currupdate.at(j)) != (*currpage).end()){
                    sanity = false; // story of my life
                    break;
                }
            }
        }

        // std::cout << s << ' ' << sanity << std::endl;
        if (sanity) res+=currupdate.at(currupdate.size()/2);
    }

    std::cout << res << std::endl;
}