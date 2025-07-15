class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(),intervals.end(),[](vector<int> i, vector<int> j){return i[0] < j[0];});
        
        for (int i = 1 ; i < intervals.size();i++){
                if (intervals[i][0] <= intervals[i-1][1]){
                    // overlap occur
                    if (intervals[i][1] >= intervals[i-1][1]){
                        // partially  overlapped
                        intervals[i-1][1] = intervals[i][1];
                    }
                    intervals.erase(intervals.begin()+i);
                    i--;
                }
        }
        return intervals;
    }
};