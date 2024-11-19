#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to generate the key order
std::vector<int> getKeyOrder(const std::string &key)
{
    std::vector<std::pair<char, int>> keyOrder;
    for (int i = 0; i < key.size(); ++i)
    {
        keyOrder.emplace_back(key[i], i);
    }
    std::sort(keyOrder.begin(), keyOrder.end());
    std::vector<int> order;
    for (const auto &pair : keyOrder)
    {
        order.push_back(pair.second);
    }
    return order;
}

// Function to encrypt using the transposition cipher
std::string encrypt(const std::string &plaintext, const std::string &key)
{
    std::vector<int> order = getKeyOrder(key);
    int columns = key.size();
    int rows = (plaintext.size() + columns - 1) / columns; // Ceiling division

    // Create a grid and fill it with characters from plaintext
    std::vector<std::vector<char>> grid(rows, std::vector<char>(columns, '_'));
    for (int i = 0; i < plaintext.size(); ++i)
    {
        grid[i / columns][i % columns] = plaintext[i];
    }

    // Read the grid column-wise according to the key order
    std::string ciphertext;
    for (int col : order)
    {
        for (int row = 0; row < rows; ++row)
        {
            ciphertext += grid[row][col];
        }
    }
    return ciphertext;
}

// Function to decrypt using the transposition cipher
std::string decrypt(const std::string &ciphertext, const std::string &key)
{
    std::vector<int> order = getKeyOrder(key);
    int columns = key.size();
    int rows = (ciphertext.size() + columns - 1) / columns; // Ceiling division

    // Create a grid and fill it column-wise according to the key order
    std::vector<std::vector<char>> grid(rows, std::vector<char>(columns, '_'));
    int index = 0;
    for (int col : order)
    {
        for (int row = 0; row < rows && index < ciphertext.size(); ++row)
        {
            grid[row][col] = ciphertext[index++];
        }
    }

    // Read the grid row-wise to reconstruct the plaintext
    std::string plaintext;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < columns; ++col)
        {
            if (grid[row][col] != '_')
            {
                plaintext += grid[row][col];
            }
        }
    }
    return plaintext;
}

int main()
{
    std::string plaintext = "Apple is fresh";
    std::string key = "heal";

    std::string encryptedText = encrypt(plaintext, key);
    std::string decryptedText = decrypt(encryptedText, key);

    std::cout << "Encrypted text: " << encryptedText << std::endl;
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}
