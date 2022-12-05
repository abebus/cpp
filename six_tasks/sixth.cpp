#include <fstream>
#include <iostream>
#include <cassert>

class Matrix{
    int width_{}, height_{};
    double **rows_{};
public:
    Matrix()=default;
    ~Matrix()=default;
    Matrix(int n,int m){
        width_ = n;
        height_ = m;
        rows_ = new double*[height_]{};
        for (int i = 0; i < height_; ++i)
            rows_[i] = new double [width_]{};
    }
    Matrix(double scalar, int n) : Matrix(n, n){
        for (int i = 0; i < n; ++i)
            rows_[i][i] = scalar;
    }
    Matrix(int **rows, int n, int m) : Matrix(n, m){
        for (int i = 0; i < height_; ++i)
            for (int j = 0; j < width_; ++j)
                rows_[i][j] = rows[i][j];
    }

    Matrix operator*(int scalar){
        auto res = Matrix(width_, height_);
        for (int i = 0; i < height_; ++i)
            for (int j = 0; j < width_; ++j)
                res.rows_[i][j] = rows_[i][j] * scalar;
        return res;
    }

    Matrix operator*(Matrix right){
        assert(height_ == right.width_);
        auto res = Matrix(this->height_, right.width_);
        for (int i = 0; i < height_; ++i)
            for (int j = 0; j < right.width_; ++j)
                for (int k = 0; k < right.width_; ++k)
                    res.rows_[i][j] += this->rows_[k][j] * right.rows_[i][k];
        return res;
    }

    Matrix operator+(Matrix right){
        assert(width_ == right.width_ and height_ == right.height_);
        auto res = Matrix(width_, height_);
        for (int i = 0; i < height_; ++i)
            for (int j = 0; j < width_; ++j)
                res.rows_[i][j] = rows_[i][j] + right.rows_[i][j];
        return res;
    }

    void printMatrix(){
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j)
                std::cout << rows_[i][j] << ' ';
            std::cout << '\n';
        }
    }

};

Matrix readFromFile(char* path){
    std::ifstream file;
    std::string line;
    file.open(path);
    auto outMat = Matrix();
    while (std::getline(file, line)){

    }
}

int main(){
    int a[2]={1, 0};
    int b[2]={0, 1};
    int c[2]={3, 4};
    int *A[3]={a,
               b,
               c};
    int *B[2]={c,
               b};
    auto M = Matrix(A, 2, 3);
    M.printMatrix();
    auto N = Matrix(B, 2, 2);
    N.printMatrix();
    auto RES = N * M;
    RES.printMatrix();
    return 0;
}