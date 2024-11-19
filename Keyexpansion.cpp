#include <stdio.h>

// Function to perform permutation
void permute(int input[], int output[], int perm[], int n)
{
    for (int i = 0; i < n; i++)
    {
        output[i] = input[perm[i] - 1];
    }
}

// Function to perform circular left shift
void circularLeftShift(int input[], int n, int shifts)
{
    int temp[10];
    for (int i = 0; i < n; i++)
    {
        temp[i] = input[i];
    }
    for (int i = 0; i < n; i++)
    {
        input[i] = temp[(i + shifts) % n];
    }
}

// Function to generate the two keys
void generateKeys(int key[], int key1[], int key2[])
{
    int p10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6}; // P10 permutation
    int p8[8] = {6, 3, 7, 4, 8, 5, 10, 9};         // P8 permutation

    int permutedKey[10];
    permute(key, permutedKey, p10, 10);

    int left[5], right[5];
    for (int i = 0; i < 5; i++)
    {
        left[i] = permutedKey[i];
        right[i] = permutedKey[i + 5];
    }

    // LS-1
    circularLeftShift(left, 5, 1);
    circularLeftShift(right, 5, 1);

    int combinedKey[10];
    for (int i = 0; i < 5; i++)
    {
        combinedKey[i] = left[i];
        combinedKey[i + 5] = right[i];
    }

    permute(combinedKey, key1, p8, 8); // Generate Key1

    // LS-2
    circularLeftShift(left, 5, 2);
    circularLeftShift(right, 5, 2);

    for (int i = 0; i < 5; i++)
    {
        combinedKey[i] = left[i];
        combinedKey[i + 5] = right[i];
    }

    permute(combinedKey, key2, p8, 8); // Generate Key2
}

int main()
{
    int key[10] = {1, 1, 0, 0, 0, 1, 1, 1, 1, 0}; // Given key

    int key1[8], key2[8];
    generateKeys(key, key1, key2);
    for (int i = 0; i < 8; i++)
    {
        printf("%d", key1[i]);
    }
    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        printf("%d", key2[i]);
    }
    printf("\n");

    return 0;
}