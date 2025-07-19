class Solution {
public:
bool strCompare(string s1,string s2)
{
    if(s1.size()!=s2.size()) return false;
    int n=s1.size();
    for(int i=0;i<n;i++) if(s1[i]!=s2[i]) return false;
    return true;
}


    bool isSubFolder(string str1,string str2)
    {
        //I gotta split them
        int n1=str1.size();
        int n2=str2.size();
        if(n1>n2) return false;

        int i=0,j=0;
        //Now compare each string]
        while(i<n1 && j<n2)
        {
            if(str1[i]=='/' && str2[j]=='/')
            {
                i++;j++;
            }
            else{
                string substr1="";
                while(i<n1 && str1[i]!='/')
                {
                    substr1+=str1[i++];
                }
                string substr2="";
                while(j<n2 && str2[j]!='/')
                {
                    substr2+=str2[j++];
                }

                if(!strCompare(substr1,substr2)) return false; 
            }
        }
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        //its more like I have to do a apttern matching of steing
        //if the whole folder path is found and extra then its a subfolder

        //one thing i can do is sorting
        sort(folder.begin(),folder.end());
        int n=folder.size();
        vector<string> ans;
        for(int i=0;i<n;i++) cout<<folder[i]<<" ";


        int l=0,r=1;

        while(r<n)
        {
            if(isSubFolder(folder[l],folder[r]))
            {
                r++;
            }
            else{
                ans.push_back(folder[l]);
                l=r;
                r++;
            }
        }
        ans.push_back(folder[l]);
        return ans;
    }
};