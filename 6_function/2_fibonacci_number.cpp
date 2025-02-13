// Fibonacci Number
// Send Feedback
// Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
// Fibonacci Series is defined by the recurrence
//     F(n) = F(n-1) + F(n-2)
// where F(0) = 0 and F(1) = 1

// Input Format :
// Integer N

// Output Format :
// true or false

// Constraints :
// 0 <= n <= 10^4

// Sample Input 1 :
// 5

// Sample Output 1 :
// true

bool checkMember(int n)
{

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    // if(n==0)return false;
    int f0 = 0;
    int f1 = 1;
    int fn;
    while (f0 < n)
    {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    if (f0 == n)
    {
        return true;
    }
    return false;
}
