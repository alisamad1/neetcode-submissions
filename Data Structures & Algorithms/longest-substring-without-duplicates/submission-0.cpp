class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int i = 0;
        int ans = 0;
        for(int j = 0; j < s.size(); j++){
            while(seen.count(s[j])){
                seen.erase(s[i]);
                i++;
            }
            seen.insert(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
