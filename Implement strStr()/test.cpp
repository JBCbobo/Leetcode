class Solution {
public:
    int strStr(string haystack, string needle) {
        int res;
        if(needle.empty()) return 0;
        for(int i=0,j=0;i<haystack.size();i++)
        {
            j = 0;
            while(haystack[i+j]==needle[j]&&needle[j]!=NULL)
            {
                j++;
            }
            if(j == needle.size())
            {
                return i;
            }
        }
       return -1;
    }
};