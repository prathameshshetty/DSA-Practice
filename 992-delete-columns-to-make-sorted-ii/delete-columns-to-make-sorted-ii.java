class Solution {
    public int minDeletionSize(String[] strs) {
        int r = strs.length;
        int c = strs[0].length();
        int deletions = 0;

        boolean[] fixed = new boolean[r - 1];

        for (int col = 0; col < c; col++) {

            // Step 1: Check if this column breaks order
            boolean bad = false;
            for (int i = 0; i < r - 1; i++) {
                if (!fixed[i] && strs[i].charAt(col) > strs[i + 1].charAt(col)) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                deletions++;
                continue;
            }

            // Step 2: Fix order where possible
            for (int i = 0; i < r - 1; i++) {
                if (!fixed[i] && strs[i].charAt(col) < strs[i + 1].charAt(col)) {
                    fixed[i] = true;
                }
            }
        }

        return deletions;
    }
}
