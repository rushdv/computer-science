#include <iostream>
#define N 4
using namespace std;

// Print the board
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

// Check if safe (ROW-WISE version)
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check same column (above)
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve using ROW-WISE placement
bool solveNQUtil(int board[N][N], int row)
{
    // Base case: all rows processed
    if (row >= N)
        return true;

    // Try placing queen in each column
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;

            // Recur for next row
            if (solveNQUtil(board, row + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

// Main solver function
bool solveNQ()
{
    int board[N][N] = {0}; // initialize all to 0

    if (!solveNQUtil(board, 0))
    {
        cout << "Solution does not exist\n";
        return false;
    }

    printSolution(board);
    return true;
}

// Driver code
int main()
{
    solveNQ();
    return 0;
}
