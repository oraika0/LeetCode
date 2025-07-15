class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // stop using vector.erase() in a loop, it cause huge overhead
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(),intervals.end(),[](vector<int>& i, vector<int>& j){return i[0] < j[0];});
        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for (int i = 1 ; i < intervals.size();i++){
            if (intervals[i][0] <= ret[ret.size()-1][1]){
                // overlap occur
                if (intervals[i][1] >= ret[ret.size()-1][1]){
                    // partially  overlapped
                    ret[ret.size()-1][1] = intervals[i][1];
                }
            }
            else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};