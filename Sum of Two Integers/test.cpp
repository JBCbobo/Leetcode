class Solution {
public:
    int getSum(int a, int b) {
        while(b)  
        {  
            int carry = a & b;  //计算进位
            a = a ^ b;          //异或相加
            b = carry << 1;    //进位
        }  
        return a;  
    }
};