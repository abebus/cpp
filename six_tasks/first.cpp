#include <iostream>

int main(){
    char name[30], surname[30];
    int age, expected_points;
    std::cin >> name >> surname >> age >> expected_points;
    std::cout << "Шансы получить " << expected_points << " баллов у " <<
    name << " " << surname <<" равны " << abs(age - 100) << "%";
    return 0;
}