class Solution {
public:


    long long cntSub(int n)
    {
        long long ans=(1LL*n*(n+1))/2*1LL;

        return ans;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;

        int n=nums.size();
        //I need to count the window size of contiguous subarrays
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                cnt++;
            }
            else{
                if(cnt!=0)
                {
                    ans+=cntSub(cnt);
                }
                cnt=0;
            }
        }
        if(cnt!=0)
                {
                    ans+=cntSub(cnt);
                }


                return ans;
    }
};