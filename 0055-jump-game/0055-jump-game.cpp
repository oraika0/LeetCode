class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size();i++){
            if (reach < i){
                return false;
            }
            reach = std::max(nums[i]+i,reach);
        }
        return true;
    }
};
// time comp:O(n)
//space comp:O(1)

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         vector<bool> table(nums.size(),false);
//         table[0] = true;
//         for (int i = 0; i < nums.size()-1;i++){
//             int min;
//             if (nums[i] <= nums.size()-i){
//                 min = nums[i];
//             }
//             else{
//                 min = nums.size()-i;
//             }
//             for (int j = 0; j < min; j++){
//                 table[i+j+1] = true;
//             }

//             if (table[i] == false){
//                 return false;
//             }
//         }
//         if (table[nums.size()-1] == true){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };
// time : O(n^2)
// space : O(n)