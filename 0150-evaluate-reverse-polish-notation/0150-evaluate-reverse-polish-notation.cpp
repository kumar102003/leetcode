class Solution {

public:
 

// string solve(string s1, string s2, string op) {
//     int a = stoi(s1);
//     int b = stoi(s2);
//     int res;

//     if (op == "+") {
//         res = a + b;
//     } 
//     else if (op == "-") {
//         res = a - b;
//     } 
//     else if (op == "*") {
//         res = a * b;
//     } 
//     else if (op == "/") {
//         res = a / b;
//     } 
//     else {
//         return "";
//     }

//     return to_string(res);
// }

    int evalRPN(vector<string>& tokens) {
        unordered_map<string,function<int(int,int)>>mp={
            {"+" , [](int a, int b){return a+b;}},
            {"-" , [](int a, int b){return a-b;}},
            {"*" , [](int a, int b){return (long)a*(long)b;}},
            {"/" , [](int a, int b){return a/b;}}
            
        };
     stack<int>st;
     for( int i = 0  ;i < tokens.size(); i++){
        string str = tokens[i];
       
        if ( str == "+" || str == "-" || str =="*" || str == "/"){
           int temp1 = st.top();
           st.pop();
           int temp2 = st.top();
           st.pop();
           int temp = mp[str](temp2,temp1);
           st.push(temp);
        }
        else{
            st.push(stoi(str));
        }
     }
     
     
     return st.top();
    }
};