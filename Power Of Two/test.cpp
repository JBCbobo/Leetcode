class Solution {
    public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return !(n&(n-1));
        //amazing code
        //erase the last 1 bit
    }
};
