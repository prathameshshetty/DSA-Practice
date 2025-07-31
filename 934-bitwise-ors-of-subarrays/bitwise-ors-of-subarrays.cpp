class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        vector<int> s; // Step 1: Store intermediate OR results
        int l = 0;

        // Step 2: Go through the array
        for (int a : arr) 
        { 
            int r = s.size(); 
            s.push_back(a);   

            // Step 3: Extend previous ORs with current value
            for (int i = l; i < r; ++i) 
            {
                int v = s[i] | a;
                
                // Avoid duplicate last entry
                if (v != s.back()) 
                { 
                    s.push_back(v);
                }
            }

            // Step 4: Set l to where this round started
            l = r;
        }

        // Step 5: Use unordered_set to find unique ORs
        unordered_set<int> unique(s.begin(), s.end());
        return unique.size();
    }
};