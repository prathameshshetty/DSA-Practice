class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int leftCnt=0,rightCnt=0;
        int n=words.size();

        bool flag=false;

        if(words[startIndex]==target) return 0;
        //LeftSide

        int l=startIndex;
        while(true)
        {
            l=(n+(l-1))%n;
            leftCnt++;
            if(words[l]==target)
            {
                flag=true;
                break;
            }
            if(startIndex==l) break;
            
        }
        if(flag ==false) return -1;
        //Right Side
        int r=startIndex;
        while(true)
        {
            r=(r+1)%n;
            rightCnt++;
            if(words[r]==target)
            {
                break;
            }
            if(startIndex==r) break;
        }


        if(flag==false) return -1;

        return min(leftCnt,rightCnt);
    }
};