#include <iostream>
#include <cassert>

class String{
    friend std::ostream& operator<<(std::ostream&, const String&);
    //friend String operator[](String&, String&);

    char *content_{nullptr};
    int size_{0};

    void resize(){
        this->size_ = 5;
        this->content_ = new char[size_];
    }
public:
    String() = default;
    String(char ch, int size){
        size_ = size;
        content_ = new char[size];
        for (int i = 0; i < size; i++)
            content_[i] = ch;
    }
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
        delete[] content_;
        size_ = 0;
    };

    char& operator[](int);
    String& operator+(String);
    String& operator+=(String);
    String& operator=(String);

    bool operator==(String);
    bool operator>(String);
    bool operator<(String);
    bool operator<=(String);
    bool operator>=(String);
    bool operator!=(String);

    int len() const{return size_;}


    String upper(){
        String res = String(this->content_,this->size_);
        for (int i = 0; i < size_; i++){
            if (this->content_[i] >= 'a' and this->content_[i] <= 'z')
                res[i] = this->content_[i] - ('a' - 'A');
        }
        return res;
    }
    String lower(){
        String res = String(this->content_,this->size_);
        for (int i = 0; i < size_; i++){
            if (this->content_[i] >= 'A' and this->content_[i] <= 'Z')
                res[i] = this->content_[i] + ('a' - 'A');
        }
        return res;
    }
};

std::ostream& operator<<(std::ostream& os, const String& obj)
{
    for (int i = 0; i < obj.size_; i++){
        os << obj.content_[i];
    }
    return os;
}

char& String::operator[](int index) {
    assert(index < size_);
    return content_[index];
}

String& String::operator+(String right) {
    String res = String(this->len() + right.len());
    for (int i = 0; i < this->size_; i++){
        res[i] = this->content_[i];
        printf("%c", res[i]);
    }
    for (int i = 0; i < right.size_; i++) {
        res[i] = right.content_[i];
        printf("%c", res[i]);
    }
    return res;
}

int main(){
    String teststr("cock", 4);
    String test2("check", 5);
    String a = teststr + test2;
    //std::cout << teststr + test2.lower();
    return 0;
}