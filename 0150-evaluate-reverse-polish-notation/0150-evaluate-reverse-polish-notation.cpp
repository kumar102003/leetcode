class Solution {

public:
 

string solve(string s1, string s2, string op) {
    int a = stoi(s1);
    int b = stoi(s2);
    int res;

    if (op == "+") {
        res = a + b;
    } 
    else if (op == "-") {
        res = a - b;
    } 
    else if (op == "*") {
        res = a * b;
    } 
    else if (op == "/") {
        res = a / b;
    } 
    else {
        return "";
    }

    return to_string(res);
}

    int evalRPN(vector<string>& tokens) {
     stack<string>st;
     for( int i = 0  ;i < tokens.size(); i++){
        string str = tokens[i];
       string ans = "";
        if ( str == "+" || str == "-" || str =="*" || str == "/"){
           string temp1 = st.top();
           st.pop();
           string temp2 = st.top();
           st.pop();
           string temp = solve(temp2,temp1,str);
           st.push(temp);
        }
        else{
            st.push(str);
        }
     }
     string ans = st.top();
     
     return stoi(ans);
    }
};