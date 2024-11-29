#include <bits/stdc++.h>
using namespace std;

// Function to generate a random key
string generateKey(int length) {
    string key = "";
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < length; ++i) {
        key += char(rand() % 256); // Generate a random byte
    }
    return key;
}

// Function to encrypt or decrypt using the Verman Cipher
string vermanCipher(const string &text, const string &key) {
    string result = "";
    for (size_t i = 0; i < text.length(); ++i) {
        result += text[i] ^ key[i]; // XOR operation
    }
    return result;
}

int main() {
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Generate a random key of the same length as the plaintext
    string key = generateKey(plaintext.length());
    cout << "Generated key (in hex): ";
    for (char c : key) {
        cout << hex << setw(2) << setfill('0') << (int)(unsigned char)c << " ";
    }
    cout << endl;

    // Encrypt the plaintext
    string ciphertext = vermanCipher(plaintext, key);
    cout << "Ciphertext (in hex): ";
    for (char c : ciphertext) {
        cout << hex << setw(2) << setfill('0') << (int)(unsigned char)c << " ";
    }
    cout << endl;

    // Decrypt the ciphertext
    string decrypted = vermanCipher(ciphertext, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
