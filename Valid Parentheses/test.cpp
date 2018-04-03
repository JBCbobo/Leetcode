class Solution {
public:
    bool isValid(string s) {
        stack<char> Parentheses;
        if(s.empty()||s.size()%2!=0) return false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                Parentheses.push(s[i]);
            }
            if(!Parentheses.empty()&&(s[i]==')'||s[i]=='}'||s[i]==']'))
            {
                int tmp = Parentheses.top();
                if(s[i]-tmp== 1||s[i]-tmp==2)
                {
                    Parentheses.pop();
                }
                else 
                {
                    return false;
                }
            }
        }
        return Parentheses.empty()?true:false;
        
    }
};