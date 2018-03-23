class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        int count = 0;
        int tmp = 0;
        for(int i=0;i<=num;i++)
        {
            tmp = i;
            while(tmp)
            {
                count++;
                tmp = tmp & (tmp-1);
            }
            res[i] = count;
            count = 0;
        }
        return res;
    }
};


class Solution{
public:
    vector<int> countBits(int num){
	vector<int> res(num+1);
	for(int i=0;i<=num;i++)
	    res[i]=res[i-1]+(i&1);
	return res;
};
