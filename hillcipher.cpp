#include <iostream>
#include <vector>
using namespace std;

int charToNum(char c)
{
    return c - 'A';
}

int numToChar(int n)
{
    return n + 'A';
}

vector<int> multiplyMatrix(vector<vector<int>> &matrix, vector<int> &vec)
{
    vector<int> result(vec.size(), 0);
    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i] += matrix[i][j] * vec[j];
        }
        result[i] = result[i] % 26;
    }

    return result;
}

string encrypt(string pt, vector<vector<int>> keyMatrix)
{
    int size = pt.size();
    vector<int> ptVector(size);

    for (int i = 0; i < size; i++)
    {
        ptVector[i] = charToNum(pt[i]);
    }

    vector<int> cipherVector = multiplyMatrix(keyMatrix, ptVector);

    string cipher = "";
    for (int i = 0; i < size; i++)
    {
        cipher += numToChar(cipherVector[i]);
    }
    return cipher;
}

string decrypt(string cipher, vector<vector<int>> inverseKeyMatrix)
{
    int size = cipher.size();
    vector<int> cipherVector(size);

    for (int i = 0; i < size; i++)
    {
        cipherVector[i] = charToNum(cipher[i]);
    }

    vector<int> ptVector = multiplyMatrix(inverseKeyMatrix, cipherVector);

    string pt = "";
    for (int i = 0; i < size; i++)
    {
        pt += numToChar(ptVector[i]);
    }
    return pt;
}

int main()
{
    string pt;
    cin >> pt;

    vector<vector<int>> keyMatrix(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> keyMatrix[i][j];
        }
    }

    vector<vector<int>> inverseKeyMatrix(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> inverseKeyMatrix[i][j];
        }
    }

    cout << "Encrypted text: " << encrypt(pt, keyMatrix) << endl;
    cout << "Decrypted text: " << decrypt(encrypt(pt, keyMatrix), inverseKeyMatrix) << endl;
}