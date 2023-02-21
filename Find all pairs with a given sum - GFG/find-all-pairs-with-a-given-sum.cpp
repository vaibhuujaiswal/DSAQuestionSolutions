//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> final;
        sort(A, A + N);
        sort(B, B + M);
        for (int i = 0; i < N; i++){
           int value = X - A[i];
           int l = 0;
           int r = M-1;
           while (l <= r){
               int m = l + (r - l)/2;
               if (B[m] == value){
                   final.push_back(make_pair(A[i],B[m]));
                   break;}
               if (B[m] < value){
                   l = m + 1;
               }else{
                   r = m - 1;
               }
            }
            
        }
        return final;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends