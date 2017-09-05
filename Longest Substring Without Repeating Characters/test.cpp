/******************************
Descrip:Given a string, find the length of the longest 
substring without repeating characters
Time:2017/8/26
******************************/

int lengthOfLongestSubstring(char* s) {
    
    int j,i;
	int ans = 0;
	int n = strlen(s);
	int index[128] = { 0 };
    
	for(i = 0,j = 0; j < n; j++)
	{
		i = (index[*(s + j)] > i) ? index[*(s + j)] : i ; 
		ans = (ans > (j - i + 1)) ? ans : (j - i + 1);
		index[*(s + j)] = j + 1;
	}
	return ans;
    
}

/**************************************
C++ code in 9 lines. O(N)
***************************************/

int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
}

/***************************************
Java (Assuming ASCII 128)
The previous implements all have no assumption on the charset of the string s.
If we know that the charset is rather small, we can replace the Map with an integer array as direct access table.
Commonly used tables are:
int[26] for Letters 'a' - 'z' or 'A' - 'Z'
int[128] for ASCII
int[256] for Extended ASCII
offical solution
****************************************/

int lengthOfLongestSubstring(String s) {
	int n = s.length(), ans = 0;
	int[] index = new int[128]; // current index of character
	// try to extend the range [i, j]
	for (int j = 0, i = 0; j < n; j++) {
		i = Math.max(index[s.charAt(j)], i);
		ans = Math.max(ans, j - i + 1);
		index[s.charAt(j)] = j + 1;
	}
	return ans;
}


