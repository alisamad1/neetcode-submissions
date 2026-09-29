class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int n = heights.size();
        int j = n - 1;
        int maxwater = 0;
        while(i < j){
            int height = min(heights[i], heights[j]);
            int width = j - i;
            int area = height * width;
            maxwater = max(area, maxwater);
            if(heights[i] < heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxwater;
    }
};
