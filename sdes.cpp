#include <iostream>
#include <string>
#include <vector>
using namespace std;

string initialPermute(string pt)
{
    vector<int> ip = {2, 6, 3, 1, 4, 8, 5, 7};
    string permuted = "";
    for (int i = 0; i < 8; ++i)
    {
        permuted += pt[ip[i] - 1];
    }
    return permuted;
}

string inversePermute(string ct)
{
    vector<int> ip_inv = {4, 1, 3, 5, 7, 2, 8, 6};
    string permuted = "";
    for (int i = 0; i < 8; ++i)
    {
        permuted += ct[ip_inv[i] - 1];
    }
    return permuted;
}

string xorOperation(string a, string b)
{
    string result = "";
    for (size_t i = 0; i < a.size(); ++i)
    {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

string decimalToBinary(int n)
{
    string binary = "00";
    if (n & 1)
        binary[1] = '1';
    if (n & 2)
        binary[0] = '1';
    return binary;
}

string sBox(string input)
{
    vector<vector<int>> s0 = {
        {1, 0, 3, 2},
        {3, 2, 1, 0},
        {0, 2, 1, 3},
        {3, 1, 3, 2}};
    vector<vector<int>> s1 = {
        {0, 1, 2, 3},
        {2, 0, 1, 3},
        {3, 0, 1, 0},
        {2, 1, 0, 3}};

    int row1 = 2 * (input[0] - '0') + (input[3] - '0');
    int col1 = 2 * (input[1] - '0') + (input[2] - '0');
    int row2 = 2 * (input[4] - '0') + (input[7] - '0');
    int col2 = 2 * (input[5] - '0') + (input[6] - '0');

    int val1 = s0[row1][col1];
    int val2 = s1[row2][col2];

    string output = decimalToBinary(val1) + decimalToBinary(val2);
    return output;
}

string expandPermute(string half)
{
    vector<int> ep = {4, 1, 2, 3, 2, 3, 4, 1};
    string expanded = "";
    for (int i = 0; i < 8; ++i)
    {
        expanded += half[ep[i] - 1];
    }
    return expanded;
}

string keyFunction(string half, string key)
{
    string expanded_half = expandPermute(half);
    string xored = xorOperation(expanded_half, key);
    string substituted = sBox(xored);
    vector<int> p4 = {2, 4, 3, 1};
    string p4_output = "";
    for (int i = 0; i < 4; ++i)
    {
        p4_output += substituted[p4[i] - 1];
    }
    return p4_output;
}

string swapFunction(string input)
{
    string left = input.substr(0, 4);
    string right = input.substr(4, 4);
    return right + left;
}

string encryptSDES(string pt, string key1, string key2)
{
    string ip = initialPermute(pt);

    string left = ip.substr(0, 4);
    string right = ip.substr(4, 4);

    string f_k1 = keyFunction(right, key1);
    string left_xor_f_k1 = xorOperation(left, f_k1);

    string combined = left_xor_f_k1 + right;
    string swapped = swapFunction(combined);

    string left_swapped = swapped.substr(0, 4);
    string right_swapped = swapped.substr(4, 4);

    string f_k2 = keyFunction(right_swapped, key2);
    string left_xor_f_k2 = xorOperation(left_swapped, f_k2);

    string preoutput = left_xor_f_k2 + right_swapped;
    string ct = inversePermute(preoutput);

    return ct;
}

int main()
{
    string PT;
    string key1;
    string key2;

    cin >> PT;
    cin >> key1;
    cin >> key2;

    cout << encryptSDES(PT, key1, key2) << endl;
}