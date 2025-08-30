class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }

        vector<pair<int,int>> vec(mpp.begin(),mpp.end());

        sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b)
        {
            return a.second>b.second;
        });

        vector<int> ans;

        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }

        return ans;
    }

};