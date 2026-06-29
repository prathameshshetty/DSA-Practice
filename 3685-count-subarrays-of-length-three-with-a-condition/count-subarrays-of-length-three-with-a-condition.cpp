class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            double sum1=nums[i]+nums[i+2];
            double sum2=(nums[i+1]*1.0)/2.0;
            if(sum1==sum2) cnt++;
        }

        return cnt;

    }
};