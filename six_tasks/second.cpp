#include <iostream>

int main(){
    int size, step;
    std::cin >> size >> step;
    auto *nums = new double [size];
    double sum = 0;
    for (int i = 0; i < size; i += step) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    std::cout << sum / size;

    return 0;
}