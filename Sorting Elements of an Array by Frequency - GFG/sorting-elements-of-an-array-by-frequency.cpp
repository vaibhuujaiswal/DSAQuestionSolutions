#include <iostream>
using namespace std;
#include <bits/stdc++.h>


bool mycomp(pair<int,int> a, pair<int,int> b)
{
    if (a.first != b.first) //first represents its frequency
        return (a.first > b.first);
    else //second represents the element itself
        return a.second < b.second;
}

void sortbyfrequencyfunction(vector<int> arr, int n){
        unordered_map<int, int> umap;
        for (int i: arr) umap[i]++;
        vector<pair<int, int>> counter;
        for (auto i : umap){
            counter.push_back(make_pair(i.second,i.first));
        }
        sort(counter.begin(),counter.end(),mycomp);
        for (auto i: counter){
            for (int j = 0; j < i.first; j++){
                cout << i.second << " ";   
            }
        }
        cout << endl;
    }

int main() {
	int t;
	cin >> t;
	while (t > 0){
	    int n;
	    cin >> n;
	    vector<int> arr;
	    while (n > 0){
	        int temp;
	        cin >> temp;
	        arr.push_back(temp);
	        n--;
	    }
	    sortbyfrequencyfunction(arr,n);
	    t--;
	}
	return 0;
}
