#include <bits/stdc++.h>
using namespace std;

// Function to generate the Playfair cipher key matrix
vector<vector<char>> generateKeyMatrix(string key) {
    vector<vector<char>> keyMatrix(5, vector<char>(5));
    unordered_set<char> used;
    int index = 0;

    // Process the key
    for (char c : key) {
        if (c == 'j') c = 'i'; // Treat 'j' as 'i'
        if (!used.count(c)) {
            keyMatrix[index / 5][index % 5] = c;
            used.insert(c);
            index++;
        }
    }

    // Fill remaining alphabet letters
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'j') continue; // Skip 'j'
        if (!used.count(c)) {
            keyMatrix[index / 5][index % 5] = c;
            used.insert(c);
            index++;
        }
    }

    return keyMatrix;
}

// Function to preprocess the plaintext
string preprocessText(string text) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) result += tolower(c);
    }
    return result;
}

// Function to find the position of a character in the key matrix
pair<int, int> findPosition(const vector<vector<char>>& keyMatrix, char c) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == c) return {i, j};
        }
    }
    return {-1, -1}; // Shouldn't occur
}

// Function to encrypt the plaintext using the Playfair cipher
string playfairCipher(string plaintext, string key) {
    vector<vector<char>> keyMatrix = generateKeyMatrix(preprocessText(key));
    string processedText = preprocessText(plaintext);

    // Add filler 'x' if duplicate letters or odd length
    for (size_t i = 0; i < processedText.length(); i += 2) {
        if (i + 1 == processedText.length() || processedText[i] == processedText[i + 1]) {
            processedText.insert(i + 1, 1, 'x');
        }
    }

    string ciphertext = "";
    for (size_t i = 0; i < processedText.length(); i += 2) {
        char a = processedText[i], b = processedText[i + 1];
        auto [r1, c1] = findPosition(keyMatrix, a);
        auto [r2, c2] = findPosition(keyMatrix, b);

        if (r1 == r2) {
            // Same row
            ciphertext += keyMatrix[r1][(c1 + 1) % 5];
            ciphertext += keyMatrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            // Same column
            ciphertext += keyMatrix[(r1 + 1) % 5][c1];
            ciphertext += keyMatrix[(r2 + 1) % 5][c2];
        } else {
            // Rectangle rule
            ciphertext += keyMatrix[r1][c2];
            ciphertext += keyMatrix[r2][c1];
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    cout << "Enter the key: ";
    getline(cin, key);

    string encryptedText = playfairCipher(plaintext, key);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
