/*
#include<bits/stdc++.h>
using namespace std;

// Function to implement Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b); // Swap a and b
    }
    return a;
}

int main() {
    int a = 56, b = 98;
    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
// It returns the gcd and also updates x and y for the equation ax + by = gcd(a, b)
int extendedGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int gcd = extendedGcd(b, a % b, x1, y1);
    
    // Update x and y based on recursive result
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}

int main() {
    int a = 56, b = 98;
    int x, y;
    int gcd = extendedGcd(a, b, x, y);
    cout << "GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << "Coefficients x and y are: " << x << " " << y << endl;
    return 0;
}

*/
