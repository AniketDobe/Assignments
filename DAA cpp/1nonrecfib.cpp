#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1; // Exit with an error code
    }

    int first = 0, second = 1;

    cout << "Fibonacci Series:" << endl;

    if (n >= 1) {
        cout << first << " ";
    }
    if (n >= 2) {
        cout << second << " ";
    }

    for (int i = 2; i < n; i++) {
        int next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }

    return 0;
}
