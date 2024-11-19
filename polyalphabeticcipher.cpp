#include <iostream>
using namespace std;

string encipher(string plaintext, string key)
{
    string result = "";
    for (int i = 0; plaintext[i]; i++)
    {
        if (plaintext[i] == ' ')
        {
            result += ' ';
        }
        else if (islower(plaintext[i]))
        {
            result += (plaintext[i] - 'a' + key[i % key.length()] - 'a') % 26 + 'a';
        }
        else if (isupper(plaintext[i]))
        {
            result += (plaintext[i] - 'A' + key[i % key.length()] - 'A') % 26 + 'A';
        }
    }
    return result;
}

string decipher(string plaintext, string key)
{
    string result = "";

    for (int i = 0; plaintext[i]; i++)
    {
        if (plaintext[i] == ' ')
        {
            result += ' ';
        }
        else if (islower(plaintext[i]))
        {
            result += (plaintext[i] - 'a' - (key[i % key.length()] - 'a') + 26) % 26 + 'a';
        }
        else if (isupper(plaintext[i]))
        {
            result += (plaintext[i] - 'A' - (key[i % key.length()] - 'A') + 26) % 26 + 'A';
        }
    }
    return result;
}

// string encrypt(string pt, string key)
// {
//     string result = "";
//     for (int i = 0; i < pt[i]; i++)
//     {
//         if (pt[i] == ' ')
//         {
//             result += " ";
//         }
//         else if (islower(pt[i]))
//         {
//             result += (pt[i] - 'a' + key[i % key.length()]-'a')%26+'a';
//         }
//     }
// }

int main()
{
    string plaintext;
    getline(cin, plaintext);

    string key;
    cin >> key;

    string pattern;
    for (int i = 0; plaintext[i]; i++)
    {
        pattern += key[i % key.length()];
    }
    cout << "New key generated: " << pattern << endl;
    cout << "Encrypted text: " << encipher(plaintext, pattern) << endl;
    cout << "Decrypted text: " << decipher(encipher(plaintext, pattern), pattern) << endl;
    return 0;
}