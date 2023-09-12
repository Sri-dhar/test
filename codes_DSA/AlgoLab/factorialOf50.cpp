#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class factorial = 1;

    for (int i = 2; i <= 50; ++i) {
        factorial *= i;
    }

    std::cout << "Factorial of 50 is: " << factorial << std::endl;

    return 0;
}
