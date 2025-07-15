class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(),intervals.end(),[](vector<int> i, vector<int> j){return i[0] < j[0];});
        
        for (int i = 0 ; i < intervals.size();i++){
            for (int j = 0; j < i;j++){
                if (intervals[i][0] <= intervals[j][1]){
                    // overlap occur
                    if (intervals[i][1] >= intervals[j][1]){
                        // partially  overlapped
                        intervals[j][1] = intervals[i][1];
                    }
                    intervals.erase(intervals.begin()+i);
                    i--;
                }
            }
        }
        return intervals;
    }
};