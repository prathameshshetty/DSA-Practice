class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }

        
        int ans=1;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
           if(i+1<n && maxi==nums[i] && nums[i]==nums[i+1])
           {
             cnt++;
             ans=max(ans,cnt);
           }
           else
           {
            cnt=1;
            ans=max(ans,cnt);
           }
        }

        return ans;
    }
};