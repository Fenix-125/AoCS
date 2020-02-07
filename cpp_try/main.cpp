#include <iostream>


class Test {
public:
    Test() {
        std::cout << "test create" << std::endl;
    }

    ~Test() {
        std::cout << "deleted test" << std::endl;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;

    int *pi = new int;
    *pi = 3;
    delete pi;

    int *p = new int[100];
    delete[] p;

    size_t N;
    std::cin >> N;
    int *pp = new int[N];
    delete[] pp;


    return 0;
}
