#include <iostream>
using namespace std;

int modInverse(int a, int mod)
{
    // int m0 = mod, t, q;
    // int x0 = 0, x1 = 1;

    // if (mod == 1)
    //     return 0;

    // while (a > 1)
    // {
    //     q = a / mod;
    //     t = mod;

    //     mod = a % mod, a = t;
    //     t = x0;

    //     x0 = x1 - q * x0;
    //     x1 = t;
    // }

    // if (x1 < 0)
    //     x1 += m0;

    // return x1;
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
    {
        x1 += m0;
    }
    return x1;
}
int modD(int a, int mod)
{
    int m0 = mod, q, t;
    int x0 = 0, x1 = 1;

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
    {
        x1 += mod;
    }
    return x1;
}
void pointDoubling(int p, int a, int x, int y, int mod)
{
    // int numerator = (3 * x * x + a) % mod;
    // int denominator = (2 * y) % mod;

    // int invDenominator = modInverse(denominator, mod);

    // int lambda = (numerator * invDenominator) % mod;

    // int x3 = (lambda * lambda - 2 * x) % mod;
    // if (x3 < 0)
    //     x3 += mod;

    // int y3 = (lambda * (x - x3) - y) % mod;
    // if (y3 < 0)
    //     y3 += mod;

    // cout << x3 << " " << y3;
    int num = (3 * x * x + a) % mod;
    int den = (2 * y) % mod;
    int invDen = modD(den, mod);

    int lambda = (num * invDen) % mod;

    int x3 = (lambda * lambda - 2 * x) % mod;
    if (x3 < 0)
    {
        x3 += mod;
    }

    int y3 = (lambda * (x - x3) - y) % mod;
    if (y3 < 0)
    {
        y3 += mod;
    }
    cout << x3 << " " << y3;
}

int main()
{
    int p;
    int a;
    int b;
    int x;
    int y;
    cin >> p;
    cin >> a;
    cin >> b;
    cin >> x;
    cin >> y;
    // Perform point doubling
    pointDoubling(p, a, x, y, p);

    return 0;
}
