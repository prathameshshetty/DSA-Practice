class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;

        for(auto it:s)
        {
            mpp[it]++;
        }
        vector<pair<char,int>> vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[&](auto it1,auto it2)
        {
            return it1.second>it2.second;
        });


        string ans="";

        for(auto it:vec)
        {
            int cnt=it.second;

            for(int i=0;i<cnt;i++)
            {
                ans+=it.first;
            }
        }

        return ans;

    
    }
};