class Solution {
public:
    int helper(vector<int>& prices, int day, int canBuy, int k, vector<vector<int>>& dp){
        if(day == prices.size() || k == 0){
            return 0;
        }
        if(dp[day][canBuy] != -1){
            return dp[day][canBuy];
        }
        int skip = helper(prices, day + 1, canBuy, k , dp);
        if(canBuy){
            int buy = -prices[day] + helper(prices, day + 1, 0, k, dp);
            dp[day][canBuy] = max(skip, buy);
        }
        else{
            int sell = prices[day] + helper(prices, day + 1, 1, k - 1, dp);
            dp[day][canBuy] = max(skip, sell);
        }
        return dp[day][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return helper(prices, 0, 1,1 , dp);
    }
};
