class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int i = 0;
        // all intervals before newInterval
        while (i < intervals.size() && newInterval[0] > intervals[i][1]){
            ret.push_back(intervals[i]);
            i++;
        }

        // already means that the next interval will overlap or newInterval are at the last
        ret.push_back(newInterval);
        while ( i < intervals.size() && ret.back()[1] >= intervals[i][0]){
            ret.back()[0] = min(ret.back()[0], intervals[i][0]);
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            i++;
        }

        //push the leftover intervals
        while(i < intervals.size()){
            ret.push_back(intervals[i]);
            i++;
        }

        return ret;
    }
};

 
// fsm 3 stage
// intervals before newinterval
// handle the overlap issues
// intervals after newinterval
// 
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// [[1,2],[3,5],[6,7],[8,10],[12,16]]
//          [4,8]
// [[1,2],[3,8]
//


// Output: [[1,2],[3,10],[12,16]]

