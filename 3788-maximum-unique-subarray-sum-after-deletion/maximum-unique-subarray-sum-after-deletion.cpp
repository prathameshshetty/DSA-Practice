class Solution {
public:
    int maxSum(vector<int>& nums) {
        //sum of all unique postive integers
        int n=nums.size();
       
        unordered_map<int,int> mpp;

        for(auto& it:nums)
        {
            if(it>0)
            {
                mpp[it]++;
            }
        }
        int sum=0;
        for(auto &it:mpp)
        {
            sum+=it.first;
        }
        if(mpp.size()==0)
        {
            //return the largest element
            int num=INT_MIN;

            for(auto &it:nums)
            {
                num=max(num,it);
            }

            return num;
        }
        return sum;


        
    }
};