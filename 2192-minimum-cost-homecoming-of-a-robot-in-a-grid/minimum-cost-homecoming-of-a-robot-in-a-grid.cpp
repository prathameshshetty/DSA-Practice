class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m=rowCosts.size();
        int n=colCosts.size();

        int sum=0;
        //calculate row
        if(startPos[0]<homePos[0])
        {
            for(int i=startPos[0]+1;i<=homePos[0];i++)
            {
                sum+=rowCosts[i];
            }

        }
        else if(startPos[0]>homePos[0])
        {
            for(int i=startPos[0]-1;i>=homePos[0];i--)
            {
                sum+=rowCosts[i];
            }
        }


        //now do the same for colums
        if(startPos[1]<homePos[1])
        {
            for(int i=startPos[1]+1;i<=homePos[1];i++) sum+=colCosts[i];
        }
        else if(startPos[1]>homePos[1]) 
        {
            for(int i=startPos[1]-1;i>=homePos[1];i--) sum+=colCosts[i];
        }


        return sum;
    }
};