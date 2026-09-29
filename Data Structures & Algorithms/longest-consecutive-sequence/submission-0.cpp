class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> numset(nums.begin(), nums.end());
        int maxLen = 0;
        for(int num : nums){
            if(numset.find(num - 1) == numset.end()){
                int currentnum = num;
                int count = 1;
                while(numset.find(currentnum + 1) != numset.end()){
                    currentnum++;
                    count++;
                }
                maxLen = max(maxLen , count);
            } 
        }
        return maxLen;
    }
};
