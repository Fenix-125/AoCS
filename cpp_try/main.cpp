#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cstring>

class Test {
public:
    Test() {
        std::cout << "test create" << std::endl;
    }

    ~Test() {
        std::cout << "deleted test" << std::endl;
    }
};


class MyString {
public:
    char *data_m = nullptr;
    size_t size_m = 0, capacity_m = 0;

    MyString(const char *str) {
        size_m = strlen(str);
        size_m = size_m + 1;
        data_m = new char[capacity_m];
        strcpy(data_m, str);
    }

    MyString() : capacity_m(16) {
        data_m = new char[capacity_m];
    }

    ~MyString() {
        delete[] data_m;
    }

    size_t size() const {
        return size_m;
    }

    char &operator[](size_t i) {
        return data_m[i];
    }

    const char &operator[](size_t i) const {
        return data_m[i];
    }

    MyString(const MyString &arg) : capacity_m(arg.capacity_m), size_m(arg.size_m) {
        data_m = new char[capacity_m];
        for (size_t i = 0; i < size_m; ++i) {
            data_m[i] = arg.data_m[i];
        }
    }

    void swap(MyString &other) {
        std::swap(size_m, other.size_m);
        std::swap(capacity_m, other.capacity_m);
        std::swap(data_m, other.data_m);
    }

    MyString &operator=(const MyString &arg) {
        if (&arg == this) { return *this; }
        MyString temp{arg};
        temp.swap(*this);
        return *this;
    }
};

void file_read() {
    std::ifstream file("f_inp.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
    }

    int x;
    std::vector<int> v;
    while (file >> x) {
        v.push_back(x);
    }

    for (auto &y: v) {
        std::cout << y << std::endl;
    }
    file.close();
}

void array_test() {
    int *pi = new int;
    *pi = 3;
    delete pi;

    int *p = new int[100];
    delete[] p;

    size_t N;
    std::cin >> N;
    int *pp = new int[N];
    delete[] pp;
}

void map_work() {
    std::map<std::string, int> my_map;
    my_map["key"] = 1;
//    std::cout << my_map["key"] << std::endl;
    for (auto &x : my_map) {
        std::cout << x.first << " - " << x.second << std::endl;
    }
}

int main() {
//    std::cout << "Hello, World!" << std::endl;
//    file_read();
    map_work();

    return 0;
}
