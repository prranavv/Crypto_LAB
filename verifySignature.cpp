#include <iostream>
#include <cmath>

using namespace std;

int mod_exp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int mod_inverse(int a, int mod)
{
    int m0 = mod, t, q;
    int x0 = 0, x1 = 1;
    if (mod == 1)
        return 0;
    while (a > 1)
    {
        q = a / mod;
        t = mod;
        mod = a % mod;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

int main()
{
    int p, q, H_M, h, X, k;
    cin >> p >> q >> H_M >> h >> X >> k;

    // int g = mod_exp(h, (p - 1) / q, p);
    // int r = mod_exp(g, k, p) % q;
    // int k_inv = mod_inverse(k, q);
    // int s = (k_inv * (H_M + X * r)) % q;

    // cout << "r=" << r << endl;
    // cout << "s=" << s << endl;

    // int w = mod_inverse(s, q);
    // int u1 = (H_M * w) % q;
    // int u2 = (r * w) % q;
    // int y = mod_exp(g, X, p);
    // int v = (mod_exp(g, u1, p) * mod_exp(y, u2, p) % p) % q;

    // cout << "w=" << w << endl;
    // cout << "u1=" << u1 << endl;
    // cout << "u2=" << u2 << endl;
    // cout << "v=" << v << endl;
    int g = mod_exp(h, (p - 1) / q, p);
    int r = mod_exp(g, k, p) % q;
    int k_inv = mod_inverse(k, q);
    int s = (k_inv * (H_M + X * r)) % q;

    cout << "r=" << r << endl;
    cout << "s=" << s << endl;

    int w = mod_inverse(s, q);
    int u1 = (H_M * w) % q;
    int u2 = (r * w) % q;
    int y = mod_exp(g, X, p);
    int v = (mod_exp(g, u1, p) * mod_exp(y, u2, p) % p) % q;
    cout << "w=" << w << endl;
    cout << "u1=" << u1 << endl;
    cout << "u2=" << u2 << endl;
    cout << "v=" << v << endl;
    return 0;
}