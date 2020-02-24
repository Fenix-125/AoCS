#include <iostream>
#include <algorithm>

template<typename T>
class MyVector {
    T *data = nullptr;
    size_t size_m, capacity_m;

public:
    MyVector(size_t in_size = 0) : size_m(in_size), capacity_m(std::max<size_t>(in_size, 16)) {
        data = new T[capacity_m];
        for (size_t i = 0; i < size_m; ++i) {
            data[i] = T{};
        }
    }

    MyVector(const MyVector &) = delete;

    MyVector &operator=(const MyVector &) = delete;

    ~MyVector() {
        delete[] data;
    }
};


template<typename T, size_t N>
class MyArray {
    T data[N];
public:
    constexpr size_t size() const { return N; }
};


template<>
class MyVector<bool> {
};


template<size_t N>
class MyArray<bool, N> {
};


template<size_t N>
struct fact {
    static constexpr size_t val = fact<N - 1>::val * N;
};

template<>
struct fact<0> {
    static constexpr size_t val = 0;
};

int main() {

    MyVector<int> t1{5};
    MyVector<std::string> t2{7};

    return 0;
}
