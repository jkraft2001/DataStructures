// Kraft-HW1-Solution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;


// isPrime() copied from Lab 1.
// Also answers the third part of the homework.
bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
 
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0)
            return false;
    }

    return true;
}

// Checking consecutive values from the quadratic formula.
// Needed for the final part of the homework.
int consecutiveValues(int a, int b)
{
    int n = 0;

    while (isPrime((n * n) + (a * n) + (b + n)))
    {
        n++;
    }

    return n;
}

int main()
{
    // Answers for the first part of the homework.
    cout << "Primes from n^2 + n + 41:" << endl;

    for (int n = 0; n < 40; ++n) 
    {
        cout << n * n + n + 41 << " ";
    }

    cout << endl;

    // Answers for the second part of the homework.
    cout << "Primes from n^2 - 71n + 1601:" << endl;

    for (int n = 0; n < 40; ++n)
    {
        cout << (n * n) - (71 * n) + 1601 << " ";
    }

    cout << endl;

    // Answers for the final part of the homework.
    int maxPrimes = 0;
    int product = 0;

    for (int a = -999; a <= 999; ++a) 
    {
        for (int b = -1000; b <= 1000; ++b) 
        {
            int primes = consecutiveValues(a, b);

            if (primes > maxPrimes) 
            {
                maxPrimes = primes;
                product = a * b;
            }
        }
    }

    std::cout << "a: " << product / 1000 << ", b: " << product % 1000 << ", consecutive primes: " << maxPrimes << std::endl;

}
