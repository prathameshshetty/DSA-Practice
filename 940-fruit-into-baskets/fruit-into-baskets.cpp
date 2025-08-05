class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //sliding window with maxi 2elements in thw idnow and ans is themaxi window size
        int n=fruits.size();
        if(n==1) return 1;
        int l=0,r=0;
        int ans=0;
        unordered_map<int,int> mpp;
        while(r<n)
        {
            mpp[fruits[r]]++;

            //Now afetr putting the window size should be 2

            while(mpp.size()>2)
            {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]<=0) mpp.erase(fruits[l]);
                l++;
            }

            if(mpp.size()==2 || mpp.size()==1)
            {
                ans=max(ans,r-l+1);
            }
          
            r++;
        }
        return ans;
    }
};