class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;

        for(auto it:nums)
        {
            mpp[it]++;
        }

        //CAn i put sort to map?
        //Nope
        //I will use a vector of paris
        //Else i can directly use priority queue
        vector<pair<int,int>> vec(mpp.begin(),mpp.end());

        sort(vec.begin(),vec.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });

        vector<int> ans;

        for(int i=0;i<k;i++)
        {
            int temp=vec[i].first;
            ans.push_back(temp);
        }

        return ans;
    }
};