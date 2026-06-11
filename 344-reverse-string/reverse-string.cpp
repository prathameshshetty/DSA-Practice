class Solution {
public:
    void reverseString(vector<char>& s) {
    int n = s.size();
    vector<char> str(n,0);
    for(int i=n-1;i>=0;i--){
        str[i] = s[n-i-1];
    }
    s = str;
    }
};