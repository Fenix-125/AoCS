#include <iostream>
#include "include/cast_methods/AbstractCastDoubleFunction.h"
#include "include/cast_methods/StreamCast.h"
#include "include/PerformanceTester.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Invalid command line arguments!\n\t"
                     "Required 3 arguments  /*program mode*/ input file output file\n\t"
                     "e.g.: 1 file_in.txt file_out.txt" << std::endl;
        return 1;
    }

    AbstractCastDoubleFunction *test_func = nullptr;
    switch (strtoul(argv[1], nullptr, 0)) {
        case 1:
            test_func = new StreamCast();
            break;
        case 2:
            test_func = new StreamCast();
            break;
        case 3:
            test_func = new StreamCast();
            break;
        default:
            std::cout << "Invalid first command line argument (program mode)!" << std::endl;
            return 1;
    }

    PerformanceTester tester(argv[2], *test_func);
    tester.print_data();

//    std::cout << test.get_result() << std::endl; TODO: implement result output
    delete test_func; // TODO: test if AbstractCastDoubleFunction is safe deallocate
    return 0;
}
