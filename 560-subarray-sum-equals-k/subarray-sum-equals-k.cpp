class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int n=nums.size();

       unordered_map<int,int> mpp;
       mpp[0]=1;
        int prefixSum=0;
        int cnt=0;
       for(int i=0;i<n;i++)
       {
            prefixSum+=nums[i];
            int remSum=prefixSum-k;
        if(mpp.find(remSum)!=mpp.end())
        {
            cnt+=(mpp[remSum]);
        }
            mpp[prefixSum]++;
       } 

       return cnt;
    }
};