// Code : Min Cost Path
// Send Feedback
// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
// From a cell (i, j), you can move in three directions:
// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.
//  Input format :
// The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. 
// They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

// The second line onwards, the next 'M' lines or rows represent the ith row values.

// Each of the ith row constitutes 'N' column values separated by a single space.
// Output format :
// Print the minimum cost to reach the destination.
// Constraints :
// 1 <= M <= 10 ^ 2
// 1 <= N <=  10 ^ 2

// Time Limit: 1 sec
// Sample Input 1 :
// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1
// Sample Output 1 :
// 13
// Sample Input 2 :
// 3 4
// 10 6 9 0
// -23 8 9 90
// -200 0 89 200
// Sample Output 2 :
// 76
// Sample Input 3 :
// 5 6
// 9 6 0 12 90 1
// 2 7 8 5 78 6
// 1 6 0 5 10 -4 
// 9 6 2 -10 7 4
// 10 -2 0 5 5 7
// Sample Output 3 :
// 18


#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n, int rows, int cols, vector<vector<int>>& dp ){
    if(rows==m-1 && cols==n-1){
        return input[rows][cols];
    }
    
    if(rows==m-1 ){
        //sum all cols
        int a = 0;
        for(int i=cols;i<n;i++){
            a+=input[rows][i];
        }
        return a;
    }
    if(cols==n-1){
        //sum all rows
        int a = 0;
        for(int i=rows;i<m;i++){
            a+=input[i][cols];
        }
        return a;
    }
    
    
    if(dp[rows][cols]!=-1) return dp[rows][cols];
    
    int path1 = INT_MAX, path2 = INT_MAX, path3 = INT_MAX;
    
    path1 = input[rows][cols] + minCostPath(input, m, n, rows+1, cols, dp);
    path2 = input[rows][cols] + minCostPath(input, m, n, rows, cols+1, dp);
    path3 = input[rows][cols] + minCostPath(input, m, n, rows+1, cols+1, dp);
    
    
    int k = min(path1, min(path2, path3));
    
    dp[rows][cols] = k;
    
    return k;
    
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here
    int i=0, j=0;
    // vector<int> dp();
    vector<vector<int>> dp(m, vector<int>(n+1, -1));
    int k = minCostPath(input, m, n, i, j, dp);
    return k;
}
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
