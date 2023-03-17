//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

// class Solution
// {   
//     public:
//     //Function to rotate matrix anticlockwise by 90 degrees.
//     void rotateby90(vector<vector<int> >& matrix, int n) 
//     { 
//         for (int diag = 0; diag < n ; diag++){
//             for (int i = diag+1; i < n; i++){
//                 int temp = matrix[diag][i];
//                 matrix[diag][i] = matrix[diag][i];
//                 matrix[diag][i] = temp;
//             }
//         }
//     } 
// };

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        int diagc = n-1;
        for (int diagr = 0; diagr < n ; diagr++){
            int constr = diagr;
            int constc = diagc;
            int tempr = diagr;
            int tempc = diagc;
            if (constc < 0) break;
            while (tempr <= n-1 && tempc >= 0){
                int k = matrix[constr][tempc];
                matrix[constr][tempc] = matrix[tempr][constc];
                matrix[tempr][constc] = k;
                tempr++;
                tempc--;
            }
            diagc--;
        }
        
        for (int i = 0; i < n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends