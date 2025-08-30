class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int low=i+1;
            int high=n-1;

            while(low<high)
            {
                int sum=nums[i]+nums[low]+nums[high];

                if(sum==0)
                {
                    vector<int> temp={nums[i],nums[low],nums[high]};
                    low++;
                    high--;

                    ans.push_back(temp);
                    //now to avoid duplicates
                    while(low<high && nums[low]==nums[low-1]) low++;
                    while(low<high && nums[high]==nums[high+1]) high--;
                }
                else if(sum>0) high--;
                else low++;
            }
        }

        return ans;
    }
};