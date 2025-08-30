class Solution {
public:
    int solve(int a,int b,string ch)
    {
        if(ch=="+") return a+b;
        else if(ch=="-") return a-b;
        else if(ch=="*") return a*b;
        else return a/b;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;


        for(auto it: tokens)
        {
            if(it=="+" || it=="-" || it=="*" || it=="/")
            {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();

                int c=solve(a,b,it);

                st.push(c);
            }
            else{
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};