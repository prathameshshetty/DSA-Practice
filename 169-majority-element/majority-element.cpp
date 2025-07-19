class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int ele=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(cnt<=0)
            {
                cnt=1;
                ele=nums[i];
            }else if(nums[i]==ele) cnt++;
            else cnt--;
        }

        //check once
        int cntEle=0;
        for(int i=0;i<n;i++)
        {
            if(ele==nums[i]) cntEle++;
        }


        if(cntEle> n/2) return ele;
        return -1;
    }
};