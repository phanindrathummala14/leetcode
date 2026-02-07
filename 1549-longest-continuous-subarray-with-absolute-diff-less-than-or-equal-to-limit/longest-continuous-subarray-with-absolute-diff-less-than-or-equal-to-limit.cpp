#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxD, minD;
        int l = 0, ans = 0;

        for (int r = 0; r < nums.size(); r++) {
            // maintain max deque
            while (!maxD.empty() && nums[r] > maxD.back()) {
                maxD.pop_back();
            }
            maxD.push_back(nums[r]);

            // maintain min deque
            while (!minD.empty() && nums[r] < minD.back()) {
                minD.pop_back();
            }
            minD.push_back(nums[r]);

            // shrink window if invalid
            while (maxD.front() - minD.front() > limit) {
                if (nums[l] == maxD.front()) maxD.pop_front();
                if (nums[l] == minD.front()) minD.pop_front();
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
