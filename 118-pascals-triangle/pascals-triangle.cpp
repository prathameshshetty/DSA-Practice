class Solution {
public:

    vector<int> generateRow(int n)
    {
        vector<int> ans;
        ans.push_back(1);

        long long res=1;
        for(int i=1;i<n;i++)
        {
            res=res*(n-i);
            res=res/(i);
            ans.push_back(res);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;


        //now I want to call genrate Rows for each row

        for(int row=1;row<=numRows;row++)
        {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};