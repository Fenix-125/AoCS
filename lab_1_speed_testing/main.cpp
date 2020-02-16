#include <iostream>
#include <cstdlib>
#include "include/PerformanceTester.h"
#include "include/cast_methods/AbstractCastDoubleFunction.h"
#include "include/cast_methods/StreamCast.h"
#include "include/cast_methods/ToStringCast.h"
#include "include/cast_methods/BoostLexicalCast.h"

static bool is_number(std::string s) {
    std::string::const_iterator it;
    for (it = s.begin(); it != s.end() && std::isdigit(*it); ++it);
    return !s.empty() && it == s.end();
}

int main(int argc, char **argv) {
    long long test_times = 1;
    if (argc != 4 && argc != 5) {
        std::cout << "Invalid command line arguments!\n\t"
                     "Required 3 arguments  /*program mode*/ input file output file\n\t"
                     "e.g.: 1 file_in.txt file_out.txt" << std::endl;
        return 1;
    } else if (!is_number(argv[1])) {
        std::cout << "Invalid command line arguments!\n\t"
                     "First argument(program mode) should be an integer." << std::endl;
        return 1;
    } else if (argc == 5) {
        if (!is_number(argv[4])) {
            std::cout << "Invalid command line arguments!\n\t"
                         "Forth argument(test repeat number) should be an integer." << std::endl;
            return 1;
        } else {
            test_times = strtoll(argv[4], nullptr, 10);
        }
    }

    AbstractCastDoubleFunction *test_func = nullptr;
    switch (strtoul(argv[1], nullptr, 0)) {
        case 1:
            test_func = new StreamCast();
            break;
        case 2:
            test_func = new ToStringCast();
            break;
        case 3:
            test_func = new BoostLexicalCast();
            break;
        default:
            std::cout << "Invalid first command line argument (program mode)!" << std::endl;
            return 1;
    }

    PerformanceTester tester(argv[2], test_func);
    tester.run_speed_test(test_times);
//    tester.print_data();
//    std::cout << test.get_result() << std::endl; TODO: implement result output

    delete test_func; // TODO: test if AbstractCastDoubleFunction is safe deallocate
    return 0;
}
