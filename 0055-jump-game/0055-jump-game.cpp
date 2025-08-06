class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> table(nums.size(),false);
        table[0] = true;
        for (int i = 0; i < nums.size()-1;i++){
            int min;
            if (nums[i] <= nums.size()-i){
                min = nums[i];
            }
            else{
                min = nums.size()-i;
            }
            for (int j = 0; j < min; j++){
                table[i+j+1] = true;
            }

            if (table[i] == false){
                return false;
            }
        }
        if (table[nums.size()-1] == true){
            return true;
        }
        else{
            return false;
        }
    }
};