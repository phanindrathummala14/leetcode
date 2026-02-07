#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // handle closing brackets
            else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // stack should be empty if valid
        return st.empty();
    }
};
