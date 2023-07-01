class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex = rowIndex + 1;
        long long ans = 1;
        vector<int> rowList;
        rowList.push_back(ans);
        //consider 0 based indexing
        for (int i = 1; i < rowIndex; i++){
            ans = ans * (rowIndex - i);
            ans = ans / (i);
            rowList.push_back(ans);
        }
        return rowList;
    }
};