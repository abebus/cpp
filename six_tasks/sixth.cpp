#include <fstream>

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

    Matrix operator*(int scalar){
        for (int i = 0; i < height_; ++i)
            for (int j = 0; j < width_; ++j)
                rows_[i][j] *= scalar;
    }

    Matrix operator*(Matrix right){
        Matrix res = Matrix(this->width_, right.height_);
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                res.rows_[i][j] = 1;//todo
            }
        }
    }
};