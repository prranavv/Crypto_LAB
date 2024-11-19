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
    int p, q, e, w;
    cin >> p >> q >> e >> w;

    // int n = p * q;
    // int phi_n = (p - 1) * (q - 1);

    // int d = mod_inverse(e, phi_n);
    // int s = mod_exp(w, d, n);

    // cout << "s=" << s << endl;

    // int w_calculated = mod_exp(s, e, n);

    // cout << "w calculated from s =" << w_calculated << endl;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int d = mod_inverse(e, phi);
    int s = mod_exp(w, d, n);

    int w_cal = mod_exp(s, e, n);

    cout << "w calculated from s =" << w_cal << endl;

    return 0;
}