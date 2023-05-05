//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        deque<int> deq;
        vector<int> output;
        for (int i = 0; i < n; i++){
            if (!deq.empty() && deq.front() == i - k){
                deq.pop_front();
            }
            while (!deq.empty() && nums[deq.back()] <= nums[i]){
                    deq.pop_back();
            }
            deq.push_back(i);
            if (i >= k-1){
                output.push_back(nums[deq.front()]);
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends