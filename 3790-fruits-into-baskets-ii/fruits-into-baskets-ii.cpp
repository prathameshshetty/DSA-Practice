class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int cnt=0;
        vector<int> temp(baskets.begin(),baskets.end());
        int n=fruits.size();
        for(int i=0;i<n;i++)
        {
            bool isFound=false;
            for(int j=0;j<temp.size();j++)
            {
                if(fruits[i]<=temp[j])
                {
                    isFound=true;
                    temp.erase(temp.begin()+j);
                    break;
                }
                
            }

            if(isFound==false) cnt++;
        }

        return cnt;
    }
};