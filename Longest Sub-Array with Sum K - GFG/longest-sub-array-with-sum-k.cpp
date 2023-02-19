//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int sum = 0;
        int global = 0;
        unordered_map<int,int> map;
        for (int i = 0; i < N; i++){
            sum += A[i];
            
            if (sum == K){
                global = i + 1;
            }
            if (map.find(sum) == map.end()){
                map[sum] = i;
            }
            if (map.find(sum - K) != map.end()){
                global = max(global, i - map[sum - K]); 
            }
        }
        return global;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends