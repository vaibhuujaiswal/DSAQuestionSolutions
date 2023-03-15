//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                arr.push_back(matrix[i][j]);
            }
        }
        for (int i = 0; i < n*m; i++){
            if (arr[i] == 0){
                int count = 0;
                if (i + 1 <= n*m - 1 && (i % m) + 1 < m) {
                    count += arr[i+1]; //right
                    matrix[i / m][(i % m) + 1] = 0;
                }
                if (i - 1 >= 0 && (i % m) - 1 >= 0) {
                    count += arr[i-1]; //left
                    matrix[i / m][(i % m) - 1] = 0;
                }
                if (i + m <=  n*m - 1 && (i / m) + 1 < n) {
                    count += arr[i+m]; //down
                    matrix[(i / m) + 1][i % m] = 0;
                }
                if (i - m >=  0 && (i / m) - 1 >= 0) {
                    count += arr[i-m]; //up
                    matrix[(i / m) - 1][i % m] = 0;
                }
                matrix[i / m][i % m] = count; //centre
                
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends