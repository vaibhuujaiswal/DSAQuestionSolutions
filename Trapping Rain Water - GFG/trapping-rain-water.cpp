//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        int maxright[n];
        int maxleft[n];
        long long output = 0;
        int m = INT_MIN;
        int r = INT_MIN;
        for (int i = 0; i < n; i++){
            maxleft[i] = max(m,height[i]);
            m = maxleft[i];
        }
        
        for (int j = n-1; j >= 0; j--){
            maxright[j] = max(r,height[j]);
            r = maxright[j];
        }
            
            
        for (int i = 1; i < n - 1; i++){
            int value = min(maxleft[i-1],maxright[i+1]) - height[i];
            if (value > 0){
                output += value;
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends