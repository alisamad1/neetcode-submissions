class Solution {
public:
    void twosums(vector<int>& nums, int start, vector<vector<int>>& result, int target){
        int i = start;
        int j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] < target){
                i++;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                result.push_back({-target, nums[i], nums[j]});
                while(i < j && nums[i] == nums[i + 1]){
                    i++;
                }
                while(i < j && nums[j] == nums[j - 1]){
                    j--;
                }
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            twosums(nums, i + 1, result, -nums[i]);
        }
        return result;
    }
};
