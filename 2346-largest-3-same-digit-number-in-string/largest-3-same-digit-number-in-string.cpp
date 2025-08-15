class Solution {
public:
    string largestGoodInteger(string num) {
        //I'll put a unordered map
        //along with a sliding widnow
        unordered_map<char,int> mpp;
    int n=num.size();
for(int i=0;i<3;i++) mpp[num[i]]++;
string ans="";
int res=-1;
if(mpp.size()==1) 
{
    res=num[0]-'0';
}
        for(int i=3;i<n;i++)
        {
            //remove then add
            mpp[num[i-3]]--;
            if(mpp[num[i-3]]<=0) mpp.erase(num[i-3]);

            //now add
            mpp[num[i]]++;

            //now check for ans
            if(mpp.size()==1)
            res=max(res,num[i]-'0');
        }


        if(res==-1) return ans;

        ans+=to_string(res)+to_string(res)+to_string(res);

        return ans;
    }
};