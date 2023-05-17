//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr + n);
    	sort(dep,dep + n);
    	int a = 1;
    	int d = 0;
    	int maxPlatforms = 1;
    	int currPlatforms = 1;
    	while (a < n && d < n){
    	    if (arr[a] <= dep[d]){
    	        currPlatforms++;
    	        a++;
    	    }else if (arr[a] > dep[d]){
    	        d++;
    	        currPlatforms--;
    	    }
    	    maxPlatforms = max(maxPlatforms,currPlatforms);
    	}
    	

    	
    	return maxPlatforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends