class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x)
        {
            res = res*10 + x%10;   //-123%10 = -3 and -123/10 = -12
            if((res>INT_MAX||res<INT_MIN)) return 0;
            x/=10;
            
        }
        return res;
    }
};

class Solution1 {
public:
    int reverse(int x) {
        int result = 0;
        while (x)
        {
            int pr = result * 10 + x % 10;
            if (result != pr / 10) return 0;
            result = pr;
            x /= 10;
        }
        return result;
    }
};

class Solution3 {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};