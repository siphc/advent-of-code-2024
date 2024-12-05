#include <fstream>
#include <iostream>
#include <vector>

bool search(std::vector<std::string>& matrix, const int& ROWS, const int& COLS, int r, int c){
    if ((r*c)==0 || r==ROWS-1 || c==COLS-1) return false;

    char diag[4] = {matrix[r-1][c-1], matrix[r-1][c+1], matrix[r+1][c-1], matrix[r+1][c+1]};

    if (diag[0]+diag[1]+diag[2]+diag[3]!=320) return false;

    if (diag[0]==diag[3]) return false;

    return true;
}

int main(){
    std::ifstream input("04.txt");

    std::vector<std::string> matrix;

    while (input.peek()!=-1){
        std::string s;
        input >> s;
        matrix.push_back(s);
    }

    input.close();

    const int ROWS = matrix.size();
    const int COLS = matrix[0].length();
    int res = 0;

    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLS; j++){
            if (matrix[i].at(j)=='A'){
                res+=search(matrix, ROWS, COLS, i, j);
            }
        }
    }

    std::cout << res << std::endl;
}