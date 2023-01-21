//  Running Median
// Send Feedback
// You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
// Print only the integer part of the median.
// Input Format :

// The first line of input contains an integer 'N', denoting the number of integers in the stream.

// The second line of input contains 'N' integers separated by a single space.

// Output Format :

// Print the running median for every integer added to the running list in one line (space-separated).

// Input Constraints

// 0 <= N <= 10 ^ 5
// 1 <= ARR[i] <= 10 ^ 5

// Time Limit: 1 sec

// Sample Input 1 :

// 6
// 6 2 1 3 7 5

// Sample Output 1 :

// 6 4 2 2 3 4

// Explanation of Sample Output 1 :

// S = {6}, median = 6
// S = {6, 2} -> {2, 6}, median = 4
// S = {6, 2, 1} -> {1, 2, 6}, median = 2
// S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
// S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
// S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

// Sample Input 2 :

// 5
// 5 4 3 2 1

// Sample Output 2 :

// 5 4 4 3 3

        /// type is unsigned long  so we have to convert to integer
		/// line 31


#include<queue>
#include<vector>
void findMedian(int *arr, int n)
{
    // Write your code here
    // make min heap
    if(n==0){
        return;
    }
    vector<int> v;
    priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<int> p;
    p.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        //decide where next element goes compare
        if(arr[i]<p.top()){
            p.push(arr[i]);
        }
        else{
            pq.push(arr[i]);
        }
        
        
        // compare number of elements
        /// type is unsigned long  so we have to convert to integer
        if(int(p.size()-pq.size())>1){
            pq.push(p.top());
            p.pop();
        }
        if(int(pq.size()-p.size())>1){
            p.push(pq.top());
            pq.pop();
        }
        
        //cout<<(pq.top()+p.top())/2<<" ";
        if(pq.size()==p.size()){
            cout<<(pq.top()+p.top())/2<<" ";
        }
        else if(p.size()>pq.size()){
            cout<<p.top()<<" ";
        }
        else{
            cout<<pq.top()<<" ";
        }
    }
    return;
    
}
