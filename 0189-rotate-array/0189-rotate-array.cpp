class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size()){
            k %= nums.size();
        }
        vector<int> temp(nums.begin(),nums.begin()+nums.size()-k);
        for(int i=0; i<k;i++){
            cout << i << " " << nums.size()-k+i << endl;
            nums[i] = nums[nums.size()-k+i];
        }
        for(int j=0;j<temp.size();j++){
            nums[j+k]=temp[j];
        }
    }
};

/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]



*/