class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int mini= INT_MAX;
        for(int i=0;i<tasks.size();i++){
            mini = min(mini,(tasks[i][1]+tasks[i][0]));
        }
        return mini;
    }
};