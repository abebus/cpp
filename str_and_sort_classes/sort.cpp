#include <iostream>

class SortingStrategy{
public:
    virtual void sort(int *arr, int size) = 0;
    ~SortingStrategy() = default;
};

bool sorted(const int *arr, int size){
    for (int i = 0; i < size - 1; i++)
        if (arr[i] >= arr[i + 1])
            return false;
    return true;
}

class BogoSort : SortingStrategy{
public:
    void sort(int *arr, int size){
        while (!sorted(arr, size)){
            for (int i = 0; i < size; i++)
                std::swap(arr[i], arr[rand() % size]);
        }
    }
};

class Sort{
    BogoSort *ptr;
public:
    Sort()=default;
};

int main(){
    int testsize = 4;
    int *testarr = new int[testsize]{2,1,3,4};
    BogoSort a;
    a.sort(testarr, 4);
   for (int i = 0; i < testsize; i++)
        std::cout << testarr[i];
    return 0;
}