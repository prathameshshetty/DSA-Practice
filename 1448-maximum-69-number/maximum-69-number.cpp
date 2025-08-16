class Solution {
public:
    int maximum69Number (int num) {
        //so the thing is change the first 6 which appears whiletraversing
        //if no 6 then no need to chnage
        string str=to_string(num);


        int n=str.size();
        for(int i=0;i<n;i++)
        {
            if(str[i]=='6')
            {
                 str[i]='9';
                 break;
            }
        }


        return stoi(str);
    }
};