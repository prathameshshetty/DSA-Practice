class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0;

        int n=nums.size();

        int k=0;

        while(k<n && nums[k]==nums[k+1]) k++;

        if(k>=n ) return 0;

        for(int i=k+1;i<n-1;i++)
        {
            if( nums[i-1]==nums[i]) continue;
            int left=0,right=0;
            right=nums[i+1];
            left=nums[i-1];
            if(nums[i]==nums[i+1])
            {
                int j=i;
                while(j+1<n && nums[j]==nums[j+1]) j++;

                if(j>=n-1) return cnt;
                right=nums[j+1];

                //if re
            }
        
            if((nums[i]>right&& nums[i]>left) || (nums[i]<right && nums[i]<left))
            {
                cnt++;
                cout<<left<<" "<<right<<" ";
                cout<<"\n";
            }
        }

        return cnt;
    }
};