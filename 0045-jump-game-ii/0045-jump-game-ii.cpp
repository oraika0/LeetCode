#include <climits>
class Solution {
public:
    int jump(vector<int>& nums) {
        int near = 0;
        int far = 0;
        int prevFar = 0;
        int jump = 0;
        while (far < nums.size()-1){
            prevFar = far;
            cout << near << " " << far << endl;
            for (int i = near;i <= prevFar; i++){
                cout << "i:" << i << " ";
                far = std::max(far,std::min(i+nums[i],(int)nums.size()-1));
                cout << far << endl;
            }
            near = prevFar + 1;
            jump++;
            cout << near << " " << far << endl;
        }
        return jump;
    } 
};
/*
a greedy way to solve the problem is finding the nearest and farest range of each hop (with removing those ranges that is 100% worse than others)
time : O(n)
space : O(1), it seems like there are nested for loops, but the range will never overlap, so the time complexity is O(n).
(it doesn't work in dag that can only jump k step)
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j)


ex:
Input: nums = [2,3,1,1,4]
Output: 2

2 3 1 1 4
n
f 
explain : we are initialized at first pos with 0 hops, the possible range is {3,1} with 1 hop
2 3 1 1 4
  n
    f
hop:1

explain : at the range {3,1}, "all possible range for 2 hops is {3,1,1,4}",but since hopping into current range is always a worse case than hop out the range (using more total hops), we can remove 3 from the "next possible range" that will become {1,1,4}
2 3 1 1 4
      n
        f 
hop:2

then the far pointer reaches the end of the array, return $hop.
*/




// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         vector<int> DP(nums.size(),INT_MAX);
//         DP[0] = 0;
//         for (int i = 1; i < nums.size(); i++){
//             for (int j = 0; j < i; j++){
//                 if (i <= j + nums[j]){
//                     DP[i] = min(DP[i], DP[j] + 1);
//                 }
//             }
//         }
//         return DP[nums.size()-1];
//     }
// };
// DP way
// DP[i] = min (DP[j] + 1) , i > j
// DP[0] = 0
// time : O(n^2)
// space : O(n)