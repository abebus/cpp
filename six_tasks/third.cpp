#include <iostream>

void swap_ptr(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_lnk(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void print(int a, int b){
    std::cout << a << ' ' << &a << ' '
              << b << ' ' << &b << '\n';
}

int main(){
    int a, b;
    std::cin >> a >> b;
    print(a, b);
    swap_ptr(&a, &b);
    print(a, b);
    swap_lnk(a, b);
    print(a, b);


    return 0;
}