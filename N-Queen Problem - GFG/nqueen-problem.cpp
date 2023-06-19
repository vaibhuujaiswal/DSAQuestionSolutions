//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> output;
        if (n == 1){
            output.push_back({1});
            return output;
        }
        vector<int> upperDiagonal(2*n - 1,0);
        vector<int> lowerDiagonal(2*n - 1,0);
        vector<int> rowleft(n,0);
        recur(0,upperDiagonal,lowerDiagonal,rowleft,output,n);
        sort(output.begin(),output.end());
        return output;
    }
    
    void recur(int col, vector<int> upperDiagonal, vector<int> lowerDiagonal,  vector<int> rowleft, 
        vector<vector<int>> &output, int n){
            if (col == n){
                output.push_back(rowleft);
                return;
            }
            for (int row = 0; row < n; row++){
                if ((upperDiagonal[n - 1 + col - row] == 0) and (lowerDiagonal[row + col] == 0)
                and (rowleft[row] == 0)){
                    upperDiagonal[n - 1 + col - row] = 1;
                    lowerDiagonal[row + col] = 1;
                    rowleft[row] = col+1;
                    
                    recur(col+1,upperDiagonal,lowerDiagonal,rowleft,output,n);
                    //backtracking step :-
                    upperDiagonal[n - 1 + col - row] = 0;
                    lowerDiagonal[row + col] = 0;
                    rowleft[row] = 0;
                }
            }
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends