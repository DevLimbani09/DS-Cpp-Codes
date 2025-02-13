// Wave Print
// Send Feedback
// For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e,
// print the first column top to bottom, next column bottom to top and so on.

// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space.
//   They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

// Second line onwards, the next 'N' lines or rows represent the ith row values.

// Each of the ith row constitutes 'M' column values separated by a single space.

// Output format :
// For each test case, print the elements of the two-dimensional array/list in the sine wave order in a single line, separated by a single space.

// Output for every test case will be printed in a seperate line.

// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// 0 <= M <= 10^3
// Time Limit: 1sec

// Sample Input 1:
// 1
// 3 4
// 1  2  3  4
// 5  6  7  8
// 9 10 11 12

// Sample Output 1:
// 1 5 9 10 6 2 3 7 11 12 8 4

void wavePrint(int **input, int nRows, int mCols)
{
    int i = 0, j = 0, k = 0;
    int total = nRows * mCols;

    while (j < mCols)
    {
        if (j % 2 == 0)
        {
            i = 0;
            while (i < nRows)
            {
                cout << input[i][j] << " ";
                i++;
            }
        }
        else
        {
            i = nRows - 1;
            while (i >= 0)
            {
                cout << input[i][j] << " ";
                i--;
            }
        }
        j++;
    }
}

#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int row, col;
        cin >> row >> col;
        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }
        wavePrint(input, row, col);
        cout << endl;
    }
}
