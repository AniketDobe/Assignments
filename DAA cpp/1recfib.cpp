#include <iostream>
using namespace std;
// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1; // Exit with an error code
    }

    cout << "Fibonacci Series:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }

    return 0;
}
