#include <bits/stdc++.h>
using namespace std;

int extend(int a, int m, int x1, int x2)
{
    if (m == 0)
    {
        return x1;
    }

    int q = a / m;
    int r = a % m;
    int x = x1 - q * x2;

    return extend(m, r, x2, x);
}

int main()
{
    int a;
    cin >> a;

    int m;
    cin >> m;

    if (a > m)
        cout << extend(a, m, 1, 0);

    else
        cout << extend(a, m, 0, 1);
}
