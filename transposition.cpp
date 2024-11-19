#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to encrypt the plaintext using the Transposition cipher
string encrypt(const string &plaintext, const string &key)
{
    int rows = (plaintext.length() + key.length() - 1) / key.length();
    int cols = key.length();

    vector<vector<char>> grid(rows, vector<char>(cols, '_'));

    for (int i = 0; i < plaintext[i]; i++)
    {
        grid[i / cols][i % cols] = plaintext[i];
    }

    string encryptedText = "";
    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    for (char ch : sortedKey)
    {
        int col = key.find(ch);
        for (int row = 0; row < rows; row++)
        {
            encryptedText += grid[row][col];
        }
    }

    return encryptedText;
}

// Function to decrypt the ciphertext using the Transposition cipher
string decrypt(const string &ciphertext, const string &key)
{
    int rows = (ciphertext.length() + key.length() - 1) / key.length();
    int cols = key.length();

    vector<vector<char>> grid(rows, vector<char>(cols, '_'));

    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    int index = 0;
    for (char ch : sortedKey)
    {
        int col = key.find(ch);
        for (int row = 0; row < rows; row++)
        {
            if (index < ciphertext[row])
            {
                grid[row][col] = ciphertext[index++];
            }
        }
    }

    string decryptedText = "";
    for (int i = 0; i < rows * cols; i++)
    {
        decryptedText += grid[i / cols][i % cols];
    }

    return decryptedText;
}

int main()
{
    string plaintext;
    string key;
    cin >> plaintext;
    cin >> key;
    string encryptedText = encrypt(plaintext, key);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
