#include <stdio.h>

// Function to find the modulo inverse of a with respect to m using Extended Euclidean Algorithm
int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to find x such that:
// x ≡ a1 (mod k1)
// x ≡ a2 (mod k2)
// x ≡ a3 (mod k3)
int findMinX(int num[], int rem[], int k)
{
    // Compute product of all numbers
    // int prod = 1;
    // for (int i = 0; i < k; i++)
    //     prod *= num[i];

    // // Initialize result
    // int result = 0;

    // // Apply above formula
    // for (int i = 0; i < k; i++)
    // {
    //     int pp = prod / num[i];
    //     result += rem[i] * modInverse(pp, num[i]) * pp;
    // }

    // return result % prod;
    int prod = 1;
    for (int i = 0; i < k; i++)
    {
        prod *= num[i];
    }
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}

int main()
{
    int num[] = {5, 11, 7};
    int rem[] = {3, 4, 5};
    int k = sizeof(num) / sizeof(num[0]);
    printf("%d\n", findMinX(num, rem, k));
    return 0;
}
