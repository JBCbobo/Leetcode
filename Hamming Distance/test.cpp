class Solution {
public:
    int hammingDistance(int x, int y) { 
        int tmp = x^y;
        int res = 0;
        while(tmp)
        {
            res++;
            tmp = tmp&(tmp-1);
        }
        return res;
    }
};
