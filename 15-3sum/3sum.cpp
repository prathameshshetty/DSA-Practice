class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Here using two pointers inside a for loop
        //checking for duplicates at 2 places to avoid duplicate triplets
        

        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        int n=nums.size();
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

                    ans.push_back(temp);
                    low++;
                    high--;

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