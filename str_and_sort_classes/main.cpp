#include <iostream>

class String{
    friend std::ostream& operator<<(std::ostream&, const String&);

    char *content_{nullptr};
    int size_{0};

    void resize(){
        this->size_ = 5;
        this->content_ = new char[size_];
    }
public:
    String() = default;
    explicit String(int size){
        size_ = size;
        content_ = new char[size];
        for (int i = 0; i < size; i ++){
            content_[i] = char(33 + int(93*double(rand())/32768));
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
    String teststr( 8);
    String test2(10);
    std::cout << teststr << test2;
    return 0;
}