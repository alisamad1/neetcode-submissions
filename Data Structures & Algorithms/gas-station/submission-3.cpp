class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startindex = 0;
        int fuel = 0;
        int totalgas = 0;
        int totalcost = 0;
        for(int i = 0; i < gas.size(); i++){
            totalgas += gas[i];
            totalcost += cost[i];
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                startindex = i + 1;
                fuel = 0;
            }
        }
        if(totalgas >= totalcost){
            return startindex;
        }
        else{
            return -1;
        }
    }
};
