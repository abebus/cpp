#include <iostream>

class Obj
{
public:
    Obj() { std::cout << "Obj ctor called\n"; };

    ~Obj() { std::cout << "Obj dtor called\n"; };

public:
    void test_func()
    {
        std::cout << "test_func called!\n";
    }
};

class ReferenceCount
{
private:
    int count = 0; // Reference count

public:
    void operator++()
    {
        // Implement method
        ++count;
    }

public:
    void operator++(int)
    {
        // Implement method
        count++;
    }

public:
    void operator--()
    {
        // Implement method
        --count;
    }

public:
    void operator--(int)
    {
        // Implement method
        count--;
    }

public:
    int use_count() const
    {
        // Implement method
        return count;
    }
};

template<typename T> class SimpleSharedSmartPointer
{
private:
    T *data;   // pointer
    ReferenceCount *reference; // Reference count

public:
    SimpleSharedSmartPointer()
    {
        // Implement method
        reference = new ReferenceCount;
        data = nullptr;
    }

    SimpleSharedSmartPointer(T* pValue) : data(pValue)
    {
        // Implement method
        reference = new ReferenceCount;
        (*reference)++;
    }

    // Copy operator
    SimpleSharedSmartPointer(const SimpleSharedSmartPointer<T>& sp) : data(sp.data), reference(sp.reference)
    {
        // Implement method
        (*reference)++;
    }

    ~SimpleSharedSmartPointer()
    {
        // Implement method
        (*reference)--;
        if (use_count()  == 0){
            delete data;
            delete reference;
        }
    }

    // Assignment operator
    SimpleSharedSmartPointer<T>& operator = (const SimpleSharedSmartPointer<T>& sp)
    {
        if (this != &sp)
        {
            // Implement method
            data = sp.data;
            reference = sp.reference;
            (*reference)++;
        }
        return *this;
    }

    T& operator* ()
    {
        return *data;
    }

    T* operator-> ()
    {
        return data;
    }

public:
    int use_count()
    {
        // Implement method
        return (*reference).use_count();
    }
};

int main()
{
    SimpleSharedSmartPointer<Obj> ptr(new Obj());
    ptr->test_func();
    std::cout << "Count used = " << ptr.use_count() << '\n';
    {
        SimpleSharedSmartPointer<Obj> ptr2 = ptr;
        std::cout << "Count used = " << ptr.use_count() << '\n';
    }
    std::cout << "Count used = " << ptr.use_count() << '\n';
    return 0;
}