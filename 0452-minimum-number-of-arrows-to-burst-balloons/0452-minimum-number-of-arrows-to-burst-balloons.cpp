class Solution {
public:
    // interval covering problems are classic greedy friendly problems
    // for contunuous ballons, they will be shot by the same arrow
    // a greedy way : following the sorted intervals, choose the last point that can cover
    //  the most "continuous" intervals

    // one pass
    // for each sorted ballons, shoot at the tail 
    // 
    // ex 
    // 1  ------------
    // 2    -------------
    // 3      --
    // 4           --
    //         |(shot here)(then keep finding the next position to shoot (starts from interval 4))
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0){
            return 0;
        } 
        
        int ret = 1;
        sort(points.begin(),points.end());
        for(auto point : points){
            cout << point[0] << "," << point[1] << endl;
        }
        cout << endl;
        int lastPos = points[0][1];
        for (auto point : points){
            if (lastPos >= point[0]){
                // can be covered by the same arrow
                lastPos = min(lastPos,point[1]);
            }
            else {
                // can't
                lastPos = point[1];
                ret++;
            } 
        }
        return ret;
    }
};
