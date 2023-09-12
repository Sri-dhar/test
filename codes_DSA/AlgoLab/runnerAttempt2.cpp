#include <iostream>
#include <cmath>

int main() {
    std::cout << "Enter the value of n: ";
    int n;
    std::cin >> n;

    long long int outcomes = std::pow(2, n) - 1;
    std::cout << "The number of outcomes possible when ties are allowed: " << outcomes << std::endl;

    return 0;
}