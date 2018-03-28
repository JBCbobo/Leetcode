class Solution {
public:
    string countAndSay(int n) {
        string say="1";
        int count=1;
        for(int i=2;i<=n;i++)
        {
            string tmp = "";
            for(int j=0;j<say.size();j++)
            {
                if(say[j] == say[j+1])
                {
                    count++;
                }
                else
                {
                    tmp =  tmp + (char)(count+'0') + say[j];
                    count = 1;
                }
            }
            say = tmp;
        }
        return say;
    }
};