#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices;
        stack<int> st; // store indices

        for (int i = 0; i < n; i++) {
            // apply discount to previous items
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
