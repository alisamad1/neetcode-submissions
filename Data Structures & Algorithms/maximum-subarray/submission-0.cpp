class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int sum_including_max = nums[0];
        int sum_max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int n = nums[i];
            sum_including_max = max(sum_including_max + n, n);
            sum_max = max(sum_including_max, sum_max);
        }
        return sum_max;
    }
};
