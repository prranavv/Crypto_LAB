#include <iostream>
#include <cmath>

using namespace std;

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
    long long q = 11;
    long long r = 2;
    long long m = 89;
    long long a = 5;
    long long b = 6;

    long long publickeyA = powerMod(r, a, q);
    long long publicB = powerMod(r, b, q);

    cout << "Public key of A: " << publickeyA << endl;
    cout << "Public key of B: " << publicB << endl;

    long long secretA = powerMod(publickeyA, b, q);
    long long C1 = powerMod(r, b, q);

    long long C2 = (m * secretA) % q;
    cout << "Cipher text: " << C2 << endl;

    long long decryptedText = (C2 * powerMod(C1, q - 1 - a, q)) % q;

    cout << "Decrypted Message: " << decryptedText << endl;
    return 0;
}