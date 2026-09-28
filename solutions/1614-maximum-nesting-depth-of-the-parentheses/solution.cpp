class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int m=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                m=max(m,(int)st.size());
            }
            if(s[i]==')') st.pop();
        }
        return m;
    }
};
