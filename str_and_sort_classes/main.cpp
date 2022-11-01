#include <iostream>
#include <experimental/random>

class String{
    friend std::ostream& operator<<(std::ostream&, const String&);

    char *content_{nullptr};
    int size_{0};

    void resize(){
        this->size_ = 5;
        this->content_ = new char[size_];
    }
public:
    String() {};
    explicit String(int size){
        size_ = size;
        for (int i = 0; i < size; i ++){
            content_[i] = char(std::experimental::randint(32,125));
        }
    };
    String(const char *liter, int size){
        content_ = new char[size];
        size_ = size;
        for (int i = 0; i < size; i++){
            content_[i] = liter[i];
        }
    };
    ~String() {
        size_ = 0;
        delete[] content_;
    };
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    for (int i = 0; i < obj.size_; i++){
        os << obj.content_[i];
    }
    return os;
}

int main(){
    String teststr("char", 4);
    std::cout << teststr;
    return 0;
}