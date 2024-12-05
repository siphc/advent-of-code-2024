#include <fstream>
#include <iostream>
#include <vector>

int search(std::vector<std::string>& matrix, const int& ROWS, const int& COLS, int r, int c){
    int res = 0;

    if (r>=3){
        if (c>=3){
            res+=(matrix[r-1][c-1]=='M'&&matrix[r-2][c-2]=='A'&&matrix[r-3][c-3]=='S' ? 1 : 0);
        }
        if (COLS-c>3){
            res+=(matrix[r-1][c+1]=='M'&&matrix[r-2][c+2]=='A'&&matrix[r-3][c+3]=='S' ? 1 : 0);
        }
        res+=(matrix[r-1][c]=='M'&&matrix[r-2][c]=='A'&&matrix[r-3][c]=='S' ? 1 : 0);
    }
    if (ROWS-r>3){
        if (c>=3){
            res+=(matrix[r+1][c-1]=='M'&&matrix[r+2][c-2]=='A'&&matrix[r+3][c-3]=='S' ? 1 : 0);
        }
        if (COLS-c>3){
            res+=(matrix[r+1][c+1]=='M'&&matrix[r+2][c+2]=='A'&&matrix[r+3][c+3]=='S' ? 1 : 0);
        }
        res+=(matrix[r+1][c]=='M'&&matrix[r+2][c]=='A'&&matrix[r+3][c]=='S' ? 1 : 0);
    }
    if (c>=3){
        res+=(matrix[r][c-1]=='M'&&matrix[r][c-2]=='A'&&matrix[r][c-3]=='S' ? 1 : 0);
    }
    if (COLS-c>3){
        res+=(matrix[r][c+1]=='M'&&matrix[r][c+2]=='A'&&matrix[r][c+3]=='S' ? 1 : 0);
    }

    return res;
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
            if (matrix[i].at(j)=='X'){
                res+=search(matrix, ROWS, COLS, i, j);
            }
        }
    }

    std::cout << res << std::endl;
}