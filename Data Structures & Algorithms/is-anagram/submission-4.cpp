class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> map;
        for(char ch : s){
            map[ch] += 1;
        }
        for(char ch : t){
            map[ch] -= 1;
        }
        for(auto& pair : map){
            if(pair.second != 0){
                return false;
            }
        }
        return true;
    }
};
