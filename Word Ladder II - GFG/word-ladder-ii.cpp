//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> output;
        queue<vector<string>> q;
        set<string> s;
        for (int i = 0; i < wordList.size(); i++){
            s.insert(wordList[i]);
        }
        vector<string> temp1;
        temp1.push_back(beginWord);
        q.push(temp1); // recheck
        while (!q.empty()){
            int n = q.size();
            if (output.size() != 0) return output;
            for (int l = 0; l < n; l++){
                vector<string> qarr = q.front(); q.pop();
                string word = qarr.back();
                
                if (word == endWord){
                    output.push_back(qarr);
                    continue;
                }
                s.erase(word);
                for (int i = 0; i < word.size(); i++){
                    char original = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++){
                        word[i] = ch;
                        vector<string> temp = qarr;
                        if (s.find(word) != s.end()){
                            temp.push_back(word);
                            q.push(temp);
                        }
                    }
                    word[i] = original;
                }
            }
        }
        return output;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends