class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedChars(26, false);
        
        // Mark allowed characters
        for (char c : allowed) {
            allowedChars[c - 'a'] = true;
        }
        
        int count = 0;
        
        // Check each word
        for (const string& word : words) {
            bool isConsistent = true;
            for (char c : word) {
                if (!allowedChars[c - 'a']) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) count++;
        }
        
        return count;
    }
};
