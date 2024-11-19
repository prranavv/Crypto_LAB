#include <iostream>
using namespace std;

int modInverse(int a, int mod)
{
    int m0 = mod, t, q;
    int x0 = 0, x1 = 1;

    if (mod == 1)
        return 0;

    while (a > 1)
    {
        q = a / mod;
        t = mod;

        mod = a % mod, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

void pointAddition(int p, int a, int x1, int y1, int x2, int y2, int &x3, int &y3)
{
    int numerator = (y2 - y1) % p;
    if (numerator < 0)
        numerator += p;

    int denominator = (x2 - x1) % p;
    if (denominator < 0)
        denominator += p;

    int invDenominator = modInverse(denominator, p);

    int lambda = (numerator * invDenominator) % p;

    x3 = (lambda * lambda - x1 - x2) % p;
    if (x3 < 0)
        x3 += p;

    y3 = (lambda * (x1 - x3) - y1) % p;
    if (y3 < 0)
        y3 += p;
}

void pointDoubling(int p, int a, int x1, int y1, int &x3, int &y3)
{
    int numerator = (3 * x1 * x1 + a) % p;
    int denominator = (2 * y1) % p;

    int invDenominator = modInverse(denominator, p);

    int lambda = (numerator * invDenominator) % p;

    x3 = (lambda * lambda - 2 * x1) % p;
    if (x3 < 0)
        x3 += p;

    y3 = (lambda * (x1 - x3) - y1) % p;
    if (y3 < 0)
        y3 += p;
}

int main()
{
    int a = 2;
    int p = 17;

    int Gx = 5, Gy = 1;
    int Pmx = 3, Pmy = 1;
    int PBx = 7, PBy = 6;

    int C1x, C1y;
    pointDoubling(p, a, Gx, Gy, C1x, C1y);

    int C2x, C2y;
    pointDoubling(p, a, PBx, PBy, C2x, C2y);
    int CT2x, CT2y;
    pointAddition(p, a, Pmx, Pmy, C2x, C2y, CT2x, CT2y);

    cout << C1x << " " << C1y << endl;
    cout << CT2x << " " << CT2y << endl;

    return 0;
}
