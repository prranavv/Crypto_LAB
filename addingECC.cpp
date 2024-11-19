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

void pointAddition(int p, int a, int x1, int y1, int x2, int y2)
{
    int numerator = (y2 - y1) % p;
    if (numerator < 0)
        numerator += p;

    int denominator = (x2 - x1) % p;
    if (denominator < 0)
        denominator += p;

    int invDenominator = modInverse(denominator, p);

    int lambda = (numerator * invDenominator) % p;

    int x3 = (lambda * lambda - x1 - x2) % p;
    if (x3 < 0)
        x3 += p;

    int y3 = (lambda * (x1 - x3) - y1) % p;
    if (y3 < 0)
        y3 += p;

    cout << x3 << " " << y3 << "\n";
}

int main()
{
    int p;
    int a;
    int b;
    int x1, y1;
    int x2, y2;
    cin >> p;
    cin >> a;
    cin >> b;
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;
    // Perform point addition
    pointAddition(p, a, x1, y1, x2, y2);

    return 0;
}
