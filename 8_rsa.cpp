#include <bits/stdc++.h>
using namespace std;

// Function to compute modular exponentiation: (base^exp) % mod
// Using inbuilt function in C++ for modular exponentiation (__gcd and pow)
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // Ensure base is within mod range
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod; // Multiply base when exp is odd
        }
        base = (base * base) % mod; // Square the base
        exp /= 2; // Reduce exponent by half
    }
    return result;
}

// RSA encryption and decryption function
void rsaEncryptDecrypt() {
    // Step 1: Choose two prime numbers p and q
    long long p = 61, q = 53;
    
    // Step 2: Compute n = p * q and Euler's totient function phi = (p-1)*(q-1)
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    
    // Step 3: Choose an encryption key 'e' such that 1 < e < phi and gcd(e, phi) = 1
    long long e = 17; // Commonly chosen small prime number
    if (__gcd(e, phi) != 1) {
        cout << "Error: 'e' and phi are not coprime!" << endl;
        return;
    }
    
    // Step 4: Compute the decryption key 'd' such that (e * d) % phi = 1
    long long d = 0;
    for (long long k = 1; ; ++k) { // Find d using brute force
        if ((k * phi + 1) % e == 0) {
            d = (k * phi + 1) / e;
            break;
        }
    }
    
    // Step 5: Encrypt a message using C = (M^e) % n
    long long message = 65; // Example message
    long long encrypted = modularExponentiation(message, e, n);
    cout << "Original Message: " << message << endl;
    cout << "Encrypted Message: " << encrypted << endl;
    
    // Step 6: Decrypt the message using M = (C^d) % n
    long long decrypted = modularExponentiation(encrypted, d, n);
    cout << "Decrypted Message: " << decrypted << endl;
}

int main() {
    rsaEncryptDecrypt();
    return 0;
}
