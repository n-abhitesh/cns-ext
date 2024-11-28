#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getKeyMatrix(string key) {
    vector<vector<int>> keyMatrix(2, vector<int>(2));
    int k = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            keyMatrix[i][j] = key[k++] - 'A'; // Convert letters to integers (0-25)
        }
    }
    return keyMatrix;
}

vector<int> encrypt(vector<vector<int>>& keyMatrix, string plaintext) {
    vector<int> ciphertext;
    for (int i = 0; i < plaintext.length(); i += 2) {
        int x = plaintext[i] - 'A';
        int y = plaintext[i + 1] - 'A';
        ciphertext.push_back((keyMatrix[0][0] * x + keyMatrix[0][1] * y) % 26);
        ciphertext.push_back((keyMatrix[1][0] * x + keyMatrix[1][1] * y) % 26);
    }
    return ciphertext;
}

string hillCipher(string key, string plaintext) {
    // Ensure the plaintext length is even
    if (plaintext.length() % 2 != 0) {
        plaintext += 'X'; // Padding if the length is odd
    }
    
    // Get the key matrix
    vector<vector<int>> keyMatrix = getKeyMatrix(key);
    
    // Encrypt the plaintext
    vector<int> ciphertext = encrypt(keyMatrix, plaintext);
    
    // Convert ciphertext to string
    string ciphertextStr = "";
    for (int i = 0; i < ciphertext.size(); i++) {
        ciphertextStr += (ciphertext[i] + 'A');
    }
    
    return ciphertextStr;
}

int main() {
    string key = "GYBNQKURP"; // 2x2 matrix key for Hill Cipher
    string plaintext = "HELLO";
    
    string ciphertext = hillCipher(key, plaintext);
    cout << "Encrypted Text: " << ciphertext << endl;
    
    return 0;
}

//static_cast<int>('B');
//static_cast<char>(66);

