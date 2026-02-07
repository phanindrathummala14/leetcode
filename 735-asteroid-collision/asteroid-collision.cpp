#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop(); // top explodes
                } 
                else if (abs(st.top()) == abs(a)) {
                    st.pop(); // both explode
                    destroyed = true;
                    break;
                } 
                else {
                    destroyed = true; // current explodes
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
