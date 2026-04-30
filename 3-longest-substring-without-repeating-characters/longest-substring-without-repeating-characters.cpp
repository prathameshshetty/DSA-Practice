class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int left = 0;
int right = 0;
int n = s.size();

unordered_map<char, int> mpp; // or set

int maxLen = 0;

while (right < n) {
    
    mpp[s[right]]++;

    
    while (mpp[s[right]] > 1) {
        mpp[s[left]]--;
        left++;
    }

    
    maxLen = max(maxLen, right - left + 1);

  
    right++;
}

return maxLen;
    }
};