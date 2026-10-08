class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int res = nums[0];
        int max_prod = nums[0];
        int min_prod = nums[0];
        for(int i = 1; i < n; i++){
            int temp = max_prod;
            max_prod = max({nums[i], max_prod * nums[i], min_prod * nums[i]});
            min_prod = min({nums[i], temp * nums[i], min_prod * nums[i]});
            res = max(res, max_prod);
        }
        return res;
    }
};
