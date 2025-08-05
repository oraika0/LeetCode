class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2){
            return nums.size();
        }
        int op = 2;
        for (int i = 2; i < nums.size(); i++){
            if (nums[i] != nums[op-2]){
                nums[op] = nums[i];
                op++;
            }
        }
        return op;
    }
};