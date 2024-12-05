#include <iostream>
#include <fstream>

int main(){
    int a[1000];
    int b[1000];

    std::ifstream input("01.txt");

    for (int i=0; i<1000; i++){
        input >> a[i] >> b[i];
    }

    input.close();

    qsort(a, 1000, 4, [](const void* x, const void* y){
        return *static_cast<const int*>(x) - *static_cast<const int*>(y);
    });
    qsort(b, 1000, 4, [](const void* x, const void* y){
        return *static_cast<const int*>(x) - *static_cast<const int*>(y);
    });

    int res = 0;

    for (int i=0; i<1000; i++){
        res += abs(a[i]-b[i]);
    }

    std::cout << res << std::endl;
}