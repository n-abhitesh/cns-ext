#include <bits/stdc++.h>
using namespace std;

string simpleColumnarEncrypt(string text, string key) {
    int n = key.length();
    int rows = ceil((double)text.length() / n);
    vector<vector<char>> grid(rows, vector<char>(n, ' '));

    // Fill the grid with characters from the message
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n && k < text.length(); j++) {
            grid[i][j] = text[k++];
        }
    }

    // Sort the key and get column order
    vector<pair<char, int>> keyWithIndex;
    for (int i = 0; i < n; i++) {
        keyWithIndex.push_back({key[i], i});
    }
    sort(keyWithIndex.begin(), keyWithIndex.end());

    // Create the encrypted text by reading columns in order
    string encrypted = "";
    for (int i = 0; i < n; i++) {
        int col = keyWithIndex[i].second;
        for (int j = 0; j < rows; j++) {
            if (grid[j][col] != ' ') encrypted += grid[j][col];
        }
    }

    return encrypted;
}

string simpleColumnarDecrypt(string text, string key) {
    int n = key.length();
    int rows = ceil((double)text.length() / n);
    vector<vector<char>> grid(rows, vector<char>(n, ' '));

    // Sort the key and get column order
    vector<pair<char, int>> keyWithIndex;
    for (int i = 0; i < n; i++) {
        keyWithIndex.push_back({key[i], i});
    }
    sort(keyWithIndex.begin(), keyWithIndex.end());

    // Fill the grid with encrypted characters in correct column order
    int k = 0;
    for (int i = 0; i < n; i++) {
        int col = keyWithIndex[i].second;
        for (int j = 0; j < rows && k < text.length(); j++) {
            grid[j][col] = text[k++];
        }
    }

    // Create the decrypted text by reading rows
    string decrypted = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != ' ') decrypted += grid[i][j];
        }
    }

    return decrypted;
}

int main() {
    string text, key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    getline(cin, key);

    string encrypted = simpleColumnarEncrypt(text, key);
    cout << "Encrypted Text: " << encrypted << endl;

    string decrypted = simpleColumnarDecrypt(encrypted, key);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
