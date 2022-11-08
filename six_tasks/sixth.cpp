#include <fstream>
#include <iostream>

class Matrix{
    int width_, height_;
    int **rows_{};
public:
    Matrix()=default;
    ~Matrix()=default;
    Matrix(int n,int m){
        width_ = n;
        height_ = m;
        rows_ = new int*[height_]{};
        for (int i = 0; i < height_; ++i)
            rows_[i] = new int[width_]{};
    }
    Matrix(double scalar, int n){
        Matrix(n, n);
        for (int i = 0; i < n; ++i)
            rows_[i][i] = scalar;
    }
    Matrix(int **rows, int n, int m){
        width_ = n;
        height_ = m;
        for (int i = 0; i < width_; ++i) {
            for (int j = 0; j < height_; ++j) {
                rows_[i][j] = rows[i][j];
            }
        }
    }

    Matrix operator*(int scalar){
        auto res = Matrix();//todo
        for (int i = 0; i < height_; ++i)
            for (int j = 0; j < width_; ++j)
                rows_[i][j] *= scalar;
    }

    Matrix operator*(Matrix right){
        Matrix res = Matrix(this->width_, right.height_);

        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                for (int k = 0; k < right.height_; ++k) {
                    for (int l = 0; l < right.width_; ++l) {
                        res.rows_[i][j] += this->rows_[k][l] * right.rows_[l][k];
                    }
                }
            }
        }
        return res;
    }
    void printMatrix(){
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                std::cout << rows_[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main(){
    int a[3]={1, 2, 3};
    int b[3]={3, 2, 1};
    int *A[3]={a, a, b};
    int *B[3]={a, b,b};
    auto M = Matrix(A, 3, 3);
    auto N = Matrix(B, 3, 3);
    auto RES = M * N;
    RES.printMatrix();
    return 0;
}