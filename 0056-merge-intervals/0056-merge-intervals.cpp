// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         // stop using vector.erase() in a loop, it cause huge overhead
//         if (intervals.size() == 1) return intervals;

//         sort(intervals.begin(),intervals.end(),[](vector<int> i, vector<int> j){return i[0] < j[0];});
//         vector<vector<int>> ret;
//         ret.push_back(intervals[0]);
//         for (int i = 1 ; i < intervals.size();i++){
//             if (intervals[i][0] <= ret[ret.size()-1][1]){
//                 // overlap occur
//                 if (intervals[i][1] >= ret[ret.size()-1][1]){
//                     // partially  overlapped
//                     ret[ret.size()-1][1] = intervals[i][1];
//                 }
//             }
//             else{
//                 ret.push_back(intervals[i]);
//             }
//         }
//         return ret;
//     }
// };
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            } else {
                merged.push_back(prev);
                prev = interval;
            }
        }

        merged.push_back(prev);
        return merged;        
    }
};