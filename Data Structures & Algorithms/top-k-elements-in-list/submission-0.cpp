class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(k <= 0 || nums.empty()){
            return res;
        }
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> freq;
        int n = nums.size();
        int count = 1;
        for(int i = 1; i <= n; i++){
            if(i < n && nums[i] == nums[i - 1]){
                count++;
            }
            else{
                freq.push_back({nums[i-1],count});
                count = 1;
            }
        }
        sort(freq.begin(),freq.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second > b.second;
        });
        k = min(k,(int)freq.size());
        for(int i = 0; i < k; i++){
            res.push_back(freq[i].first);
        }
        return res;
    }
};
