#include <iostream>
#include <fstream>

int main(){
    int a[1000];
    int b[1000];
    int bfreq[100000] = {};

    std::ifstream input("01.txt");

    for (int i=0; i<1000; i++){
        input >> a[i] >> b[i];
        bfreq[b[i]]++;
    }

    input.close();

    int res = 0;

    for (int i=0; i<1000; i++){
        res += a[i]*bfreq[a[i]];
    }

    std::cout << res;
}