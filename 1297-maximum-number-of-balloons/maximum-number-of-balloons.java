class Solution {
    public int maxNumberOfBalloons(String text) {
        int []freq=new int[26];

        for(char ch: text.toCharArray())
        {
            freq[ch-'a']++;
        }

        return Math.min(Math.min(freq[0],freq[1]),
        Math.min(
            Math.min(freq['l'-'a']/2,freq['o'-'a']/2),freq['n'-'a']) );
    }
}