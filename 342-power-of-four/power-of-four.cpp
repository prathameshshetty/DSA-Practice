class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n==1) return true;

        return ((floor(log2(n)/log2(4)))==(ceil(log2(n)/log2(4))));
    }
};