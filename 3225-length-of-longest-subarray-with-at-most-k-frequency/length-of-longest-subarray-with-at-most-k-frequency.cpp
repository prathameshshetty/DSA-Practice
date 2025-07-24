class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        unordered_map<int,int> mpp;
        int maxSize=0;
        while(r<n)
        {
            if(mpp[nums[r]]<k)
            {
                mpp[nums[r]]++;
                r++;
            }
            else{
                //it is alread k
                //it is more than k


                while(l<=r && l<n && mpp[nums[r]]>=k )
                {
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                    
                    l++;
                }
                
            }
             
                maxSize=max(maxSize,r-l);
        
        }

        
                maxSize=max(maxSize,r-l);
        return maxSize;
    }
};