class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //Now im converting integer to strings
        vector<string> arr;

        for(auto it:nums)
        {
            arr.push_back(to_string(it));
        }

        //custom comparator based on sorting
        sort(arr.begin(),arr.end(),[](string& a,string&b)
        {
            return (b+a)<(a+b);
        });


        //special case of 0 handling
        if(arr[0]=="0") return "0";

        string ans="";

        for(string str:arr)
        {
            ans+=str;
        }
        return ans;
    }
};