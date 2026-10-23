class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxlen = 0;
        int n = s.size();
        unordered_set<char> mapchar;
        for(int j = 0; j < n; j++){
            while(mapchar.find(s[j]) != mapchar.end()){
                mapchar.erase(s[i]);
                i++;
            }
            mapchar.insert(s[j]);
            maxlen = max(maxlen,j - i + 1);
        }
        return maxlen;
    }
};
