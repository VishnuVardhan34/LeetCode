// Last updated: 8/4/2026, 12:24:58 PM
#include<stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& c : tokens) {
            if (c == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b+a);
            } else if (c == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b-a);
            } else if (c == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b*a);
            } else if (c == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b/a);
            } else {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};