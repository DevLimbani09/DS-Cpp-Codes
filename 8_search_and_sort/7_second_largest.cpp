// Second Largest in array
// Send Feedback
// You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
// If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)

// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
// The first line of each test case or query contains an integer 'N' representing the size of the array/list.
// The second line contains 'N' single space separated integers representing the elements in the array/list.

// Output Format :
// For each test case, print the second largest in the array/list if exists, -2147483648 otherwise.
// Output for every test case will be printed in a separate line.

// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^5

// Time Limit: 1 sec

// Sample Input 1:
// 1
// 7
// 2 13 4 1 3 6 28

// Sample Output 1:
// 13

// Sample Input 2:
// 1
// 5
// 9 3 6 2 9

// Sample Output 2:
// 6

int findSecondLargest(int *input, int n)
{
    int max1 = -2147483648;
    int max2 = -2147483648;
    for (int i = 0; i < n; i++)
    {
        if (max1 < input[i])
        {
            max1 = input[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (max2 < input[i] && max2 < max1 && input[i] != max1)
        {
            max2 = input[i];
        }
    }
    // if(max2==-2147483648){
    //     max2 = max1;
    // }
    return max2;
}
