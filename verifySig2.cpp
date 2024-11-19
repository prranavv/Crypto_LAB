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
    int q, alpha, XA, k, H;
    cin >> q >> alpha >> XA >> k >> H;

    // int YA = mod_exp(alpha, XA, q);

    // int s1 = mod_exp(alpha, k, q);
    // int k_inv = mod_inverse(k, q - 1);
    // int s2 = (k_inv * (H - XA * s1)) % (q - 1);
    // if (s2 < 0)
    //     s2 += (q - 1);

    // cout << "s1=" << s1 << endl;
    // cout << "s2=" << s2 << endl;

    // int v1 = mod_exp(alpha, H, q);
    // int v2 = (mod_exp(YA, s1, q) * mod_exp(s1, s2, q)) % q;

    // cout << "v1=" << v1 << endl;
    // cout << "v2=" << v2 << endl;

    int Ya = mod_exp(alpha, XA, q);
    int s1 = mod_exp(alpha, k, q);
    int k_inv = mod_inverse(k, q - 1);
    int s2 = (k_inv * (H - XA * s1)) % (q - 1);
    if (s2 < 0)
    {
        s2 += (q - 1);
    }

    int v1 = mod_exp(alpha, H, q);
    int v2 = (mod_exp(Ya, s1, q) * mod_exp(s1, s2, q)) % q;
    cout << "v1=" << v1 << endl;
    cout << "v2=" << v2 << endl;
    return 0;
}