class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();

        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && ele2!=nums[i])
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i])
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
            {
                cnt1++;
               
            }         
            else if(nums[i]==ele2)
            {
               
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        //Now I goota veriify
        int cntEle1=0,cntEle2=0;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i]) cntEle1++;
            if(ele2==nums[i]) cntEle2++;
        }

        vector<int> ans;

        if(cntEle1> (n/3)) ans.push_back(ele1);
        if(cntEle2 > (n/3)) ans.push_back(ele2);

        return ans;
        

    }
};