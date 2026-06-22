class Solution {
    public int maxNumberOfBalloons(String text) {
        int [] freq=new int[26];

        //Step 1: Frwquency count
        for(char ch: text.toCharArray())
        {
            freq[ch-'a']++;
        }

        //Step 2: get minimum of all 5


    return Math.min(   Math.min(freq[0],freq[1]),
                        Math.min(freq['l'-'a']/2 , Math.min( freq['o'-'a']/2, freq['n'-'a']) ) );


    }
}