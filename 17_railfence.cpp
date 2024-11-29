#include<bits/stdc++.h>
using namespace std;

// Function to encrypt text using Rail Fence Cipher
string encryptRailFence(string text, int key) {
    if (key == 1) return text; // No encryption for a single rail

    // Create a 2D vector for rail representation
    vector<string> rail(key, string(text.size(), '\0'));

    bool direction_down = false; // Direction of zigzag
    int row = 0; // Current row

    // Fill the rails
    for (int i = 0; i < text.size(); ++i) {
        rail[row][i] = text[i];
        if (row == 0 || row == key - 1) direction_down = !direction_down;
        row += (direction_down) ? 1 : -1;
    }

    // Construct the encrypted text
    string result;
    for (auto& r : rail) {
        for (char ch : r) {
            if (ch != '\0') result += ch;
        }
    }

    return result;
}

// Function to decrypt text using Rail Fence Cipher
string decryptRailFence(string cipher, int key) {
    if (key == 1) return cipher; // No decryption for a single rail

    // Create a 2D vector for rail representation
    vector<string> rail(key, string(cipher.size(), '\0'));

    // Mark the positions in rails
    bool direction_down = false;
    int row = 0;
    for (int i = 0; i < cipher.size(); ++i) {
        rail[row][i] = '*';
        if (row == 0 || row == key - 1) direction_down = !direction_down;
        row += (direction_down) ? 1 : -1;
    }

    // Fill the rails with cipher text
    int index = 0;
    for (int r = 0; r < key; ++r) {
        for (int c = 0; c < cipher.size(); ++c) {
            if (rail[r][c] == '*' && index < cipher.size()) {
                rail[r][c] = cipher[index++];
            }
        }
    }

    // Read the original message from the rails
    string result;
    row = 0;
    direction_down = false;
    for (int i = 0; i < cipher.size(); ++i) {
        result += rail[row][i];
        if (row == 0 || row == key - 1) direction_down = !direction_down;
        row += (direction_down) ? 1 : -1;
    }

    return result;
}

int main() {
    string text, encrypted, decrypted;
    int key;

    // Input
    cout << "Enter the plaintext: ";
    getline(cin, text);
    cout << "Enter the key: ";
    cin >> key;

    // Encrypt
    encrypted = encryptRailFence(text, key);
    cout << "Encrypted text: " << encrypted << endl;

    // Decrypt
    decrypted = decryptRailFence(encrypted, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
