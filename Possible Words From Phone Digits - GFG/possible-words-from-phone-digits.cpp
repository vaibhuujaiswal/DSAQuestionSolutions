//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        map<int,vector<int>> map;
        map[2] = {'a','b','c'};
        map[3] = {'d','e','f'};
        map[4] = {'g','h','i'};
        map[5] = {'j','k','l'};
        map[6] = {'m','n','o'};
        map[7] = {'p','q','r','s'};
        map[8] = {'t','u','v'};
        map[9] = {'w','x','y','z'};
        
        vector<string> output;
        string s = "";
        words(output,map,a,N,s,0);
        return output;
    }
    
    void words(vector<string> &output, map<int,vector<int>> &map,
    int a[], int N, string s, int arrIndex){
        if (s.size() == N || arrIndex == N){
            output.push_back(s);
            return;
        }
        if (map.find(a[arrIndex]) == map.end()) return;
        for (int i = 0 ; i < map[a[arrIndex]].size(); i++){
            string temp = s;
            temp += map[a[arrIndex]][i];
            words(output,map,a,N,temp,arrIndex+1);
        }
        return;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends