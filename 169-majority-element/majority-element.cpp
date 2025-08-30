class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        int ele=nums[0];
        for(int i=1;i<n;i++)
        {
            if(cnt<=0)
            {
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i]) cnt++;
            else cnt--;
        }
        //check
        int cnt1=0;

        for(int i=0;i<n;i++)
        {
            if(ele==nums[i]) cnt1++;
        }

        if(cnt1>=(n/2)) return ele;
        return -1;

    }
};