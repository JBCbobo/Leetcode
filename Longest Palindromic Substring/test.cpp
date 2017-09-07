/*
 * Descripe : Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 * Date : 2017/9/6
 */
int expandAroundCenter(char * s,int strsize,int left,int right)
{
    int l=left,r=right;
    while(l>=0 && r<strsize && s[l] == s[r])
    {
        l--;
        r++;
    }
    return r-l-1;
}

char * longestPalindrome(char* s)
{
    int start = 0,end = 0;
    int i = 0;
    int size = 0;
    int len1;
    int len2;
    int len;
    for(size = 0 ; s[size]; size++);
    for(i = 0; i < size; i++)
    {
        len1 = expandAroundCenter(s,size,i,i);//when the string length is odd
        len2 = expandAroundCenter(s,size,i,i+1);//when the string length is even
        len = (len1 > len2) ? len1 : len2;
        if(len > end - start)
        {
            end = i + len / 2;
            start = i - (len - 1)/2;
        }
    }
    s[end+1] = '\0';//turncate the string
    return s+start ;
}
