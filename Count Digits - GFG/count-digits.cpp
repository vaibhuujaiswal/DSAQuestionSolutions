//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int count = 0;
        int K = N;
        while (K > 0){
            int num = K % 10;
            if (num == 0){
                K = K - num;
                K = K/10;
                continue;
            }
            if (N % num == 0){
                count++;
            }
            K = K - num;
            K = K/10;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends