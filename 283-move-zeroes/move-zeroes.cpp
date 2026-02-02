class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }

        // Fill remaining positions with zeros
        while (k < nums.size()) {
            nums[k++] = 0;
        }
    }
};
