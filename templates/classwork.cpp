#include <iostream>
#include <string>

int get_max(int a, int b)
{
    return (a > b ? a : b);
}

std::string get_max(std::string a, std::string b)
{
    return (a > b ? a : b);
}

// Template Func
template <typename T>
T get_max(T a, T b)
{
    return (a > b ? a : b);
}

// Part spec
template <typename T>
class Printer
{
public:
    void show(T value);
};

template <typename T>
void Printer<T>::show(T value)
{
    std::cout << "Value = " << value << '\n';
}

template <>
void Printer<char>::show(char value)
{
    std::cout << "Char Value = " << value << '\n';
}

template <>
void Printer<std::string>::show(std::basic_string<char> value) {
    for (int i = value.size(); i >= 0 ; i--) {
        std::cout<< value[i];
    }
    std::cout<<std::endl;
}

template <typename T>
void mySwap(T& a, T& b){
    T c = b;
    b = a;
    a = c;
}

int main()
{
    // 1. Template Func

    // int a = 5, b = 6;
    // std::cout << get_max(a, b) << '\n';

    // std::string s1 = "abc", s2 = "def";
    // std::cout << get_max(s1, s2) << '\n';

    // int a = 5, b = 6;
    // std::cout << get_max<int>(a, b) << '\n';

    // long c = 5, d = 6;
    // std::cout << get_max<long>(c, d) << '\n';

    // std::string s1 = "abc", s2 = "abca";
    // std::cout << get_max<std::string>(s1, s2) << '\n';

    // int a = 5, b = 6;
    // int *p1 = &a, *p2 = &b;
    // std::cout << get_max<int*>(p1, p2) << '\n';

    // 2. Part spec

    // Printer<int> printer;
    // printer.show(65);

    // Printer<char> printer;
    // printer.show('A');

    Printer<std::string> printer;
    printer.show("my_value");

    // Classwork
    // 1. Swap func (int, char, std::string)
    // 2. Impl spec for reversing std::string
    int a = 1;
    int b = 2;
    mySwap(a ,b);

    return 0;
}