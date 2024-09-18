#include <iostream>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
    do {                                               \
        std::cout<<std::endl;                          \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)


int main() {
    int x = 5;
    int y = 0;

    // Example of a failing assertion
    assert(y != 0 && "y should not be zero before division");
    
    // If the assertion passes, the division will occur
    int z = x / y;

    std::cout << "Result: " << z << std::endl;
    
    return 0;
}
