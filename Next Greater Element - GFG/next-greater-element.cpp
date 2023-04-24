//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> final(n,-1);
        stack<long long> stack;
        for (int i = n - 1; i >= 0; i--){
            long long ele = arr[i];
            while (!stack.empty() && ele >= stack.top()){
                stack.pop();
            }
            if (stack.empty()){
                stack.push(ele);
                continue;
            }else{
                final[i] = stack.top();
                stack.push(ele);
            }
        }
        return final;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends