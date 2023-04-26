//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> stack;
        vector <long long> left(n,0);
        vector <long long> right(n,0);
        for (int i = 0; i < n; i++){
            while (!stack.empty() && arr[stack.top()] >= arr[i]){
                stack.pop();
            }
            if (!stack.empty()){
                left[i] = stack.top() + 1;
            }else{
                left[i] = 0;
            }
            stack.push(i);
        }
        while (!stack.empty()){stack.pop();} //clear stack for next
        for (int i = n-1; i >= 0; i--){
            while (!stack.empty() && arr[stack.top()] >= arr[i]){
                stack.pop();
            }
            if (!stack.empty()){
                right[i] = stack.top()-1; //boundary
            }else{
                right[i] = n-1;
            }
            stack.push(i);
        }
        // for (auto i : left){
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto i : right){
        //     cout << i<< " ";
        // }
        // cout << endl;
        
        long long maximum = INT_MIN;
        for (int i = 0; i < n; i++){
            long long l = left[i];
            long long r = right[i];
            maximum = max(maximum,(r - l + 1)*arr[i]);
        }
        return maximum;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends