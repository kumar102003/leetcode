class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count = 0;
        for( auto &ch : s){
            if(ch=='('){
                st.push(ch);
            }
            else if(ch ==')'){
                count++;
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    count--;
                }
            }
        }
        // if(!st.empty()){
        //     return st.size();
        // }
        return st.size()+count;
    }
};