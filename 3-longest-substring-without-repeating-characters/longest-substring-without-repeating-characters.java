class Solution {
    public int lengthOfLongestSubstring(String s) {
         // Stores character and its latest index
        HashMap<Character, Integer> map = new HashMap<>();

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            char ch = s.charAt(right);

            // If character already exists in current window
            if (map.containsKey(ch) && map.get(ch) >= left) {

                // Move left pointer just after previous occurrence
                left = map.get(ch) + 1;
            }

            // Update latest index of current character
            map.put(ch, right);

            // Calculate current window length
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }
}