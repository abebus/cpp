#include <iostream>

int fact_recursive(int a){
    if (a < 2)
        return 1;
    return fact_recursive(a - 1) * a;
}

int fact_iterative(int a){
    int res = 1;
    for (int i = a; i > 0; i--) {
        res *= i;
    }
    return res;
}

int main(){
    int x;
    std::cin >> x;
    std::cout << fact_recursive(x) << '\n' << fact_iterative(x);
    return 0;
}
