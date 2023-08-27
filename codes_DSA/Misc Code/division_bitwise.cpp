#include <iostream>
#include<limits.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1LL : 1LL;

        long long a = abs(static_cast<long long>(dividend));
        long long b = abs(static_cast<long long>(divisor));
        long long c = 0;

        while (a >= b) {
            long long temp = b;
            long long count = 1;

            while ((temp << 1) <= a) {
                temp = temp << 1;
                count = count << 1;
            }

            a = a - temp;
            c = c + count;
        }

        return static_cast<int>(sign * c);
    }
};

int divideUsingBitwise(int dividend, int divisor) {
    // Check for division by zero
    if (divisor == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0;
    }

    // Handle the special case of division with the minimum value
    if (dividend == INT32_MIN && divisor == -1) {
        return INT32_MAX; // Integer overflow
    }

    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; // Determine the sign of the quotient

    // Take the absolute values of dividend and divisor
    long long absDividend = llabs(dividend);
    long long absDivisor = llabs(divisor);

    while (absDividend >= absDivisor) {
        long long temp = absDivisor;
        long long count = 1;

        // Left shift divisor until it becomes greater than dividend
        while ((temp << 1) <= absDividend) {
            temp <<= 1; // Left shift divisor by 1
            count <<= 1; // Left shift count by 1
        }

        // Subtract the shifted divisor from dividend
        absDividend -= temp;
        quotient += (int)̥count;
    }

    return sign * quotient;
}

int main() {
    int dividend, divisor;
    std::cout << "Enter dividend: ";
    std::cin >> dividend;
    std::cout << "Enter divisor: ";
    std::cin >> divisor;

    int result = divide(dividend, divisor);
    std::cout << "Quotient: " << result << std::endl;

    return 0;
}
