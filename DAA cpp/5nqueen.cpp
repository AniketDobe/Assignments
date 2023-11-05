#include <iostream>
using namespace std;

bool isSafe(int *board, int row, int col, int n) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

void printBoard(int *board, int n) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[col] == row) cout << "Q";
            else cout << "_";
        }
        cout << endl;
    }
}

bool findSolution(int *board, int col, int n) {
    if (col == n) {
        printBoard(board, n);
        return true; // Found a solution
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[col] = row;
            if (findSolution(board, col + 1, n)) {
                return true; // Return after finding the first solution
            }
        }
    }
    return false; // No solution found
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    int *board = new int[n];

    if (findSolution(board, 0, n)) {
        cout << "Solution found!" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    delete[] board; // Don't forget to deallocate memory.
    return 0;
}
