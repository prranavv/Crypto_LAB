#include <iostream>
#include <cmath>

long long powerMod(long long base, long long exponent, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    long long q = 7;
    long long r = 3;
    long long a = 4;
    long long b = 5;

    long long A = powerMod(r, a, q);
    long long B = powerMod(r, b, q);

    std::cout << "Public key of Alice:" << A << std::endl;
    std::cout << "Public key of Bob:" << B << std::endl;

    long long secretKeyAlice = powerMod(B, a, q);
    long long secretKeyBob = powerMod(A, b, q);

    std::cout << "Secret key calculated by Alice:" << secretKeyAlice << std::endl;
    std::cout << "Secret key calculated by Bob:" << secretKeyBob << std::endl;

    return 0;
}