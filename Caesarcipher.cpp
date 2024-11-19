#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int k)
{
    string res = "";
    for (int i = 0; i < text[i]; i++)
    {
        if (text[i] == ' ')
        {
            res += " ";
        }
        else if (text[i] >= '0' && text[i] <= '9')
        {
            res += (text[i] - '0' + k) % 10 + '0';
        }
        else if (islower(text[i]))
        {
            res += (text[i] - 'a' + k) % 26 + 'a';
        }
        else if (isupper(text[i]))
        {
            res += (text[i] - 'A' + k) % 26 + 'A';
        }
    }
    return res;
}

string decrypt(string text, int k)
{
    string res = "";
    for (int i = 0; i < text[i]; i++)
    {
        if (text[i] == ' ')
        {
            res += " ";
        }
        else if (text[i] >= '0' && text[i] <= '9')
        {
            res += (text[i] - '0' - k) % 10 + '0';
        }
        else if (islower(text[i]))
        {
            res += (text[i] - 'a' - k) % 26 + 'a';
        }
        else if (isupper(text[i]))
        {
            res += (text[i] - 'A' - k) % 26 + 'A';
        }
    }
    return res;
}

int main()
{
    string text;
    int shift;
    getline(cin, text);
    cin >> shift;
    cout << "Encrypted text: " << encrypt(text, shift) << endl;
    cout << "Decrypted text: " << decrypt(encrypt(text, shift), shift) << endl;
}