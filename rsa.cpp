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

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

long long modInverse(long long e, long long phi)
{
    for (long long d = 1; d < phi; d++)
    {
        if ((d * e) % phi == 1)
        {
            return d;
        }
    }
    return -1;
}

int main()
{
    long long m = 4;
    long long p = 3;
    long long q = 5;
    long long e = 5;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long d = modInverse(e, phi);

    long long cipherText = powerMod(m, e, n);
    std::cout << "Cipher text is " << cipherText << std::endl;

    long long plainText = powerMod(cipherText, d, n);
    std::cout << "Plain Text is " << plainText << std::endl;
    return 0;
}