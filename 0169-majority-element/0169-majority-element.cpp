class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int major = nums[0];
        for (int n : nums){
            if (freq == 0){
                major = n;
            }
            if (n == major){
                freq++;
            }
            else{
                freq--;
            }
        }
        return major;
    }
};

// important: majority appears more than roof floor(n/2), it is useful for us to find a better algo then simply finding the most frequently element.

// Moore's Voting Algorithm
// since majority appears more then floor(n/2), the majority element are always at least one more than summing up all the other elements
// even if we remove two unequal elements pair by pair from the array, the remaining majority number remains the same, and the remaining element is majority.
// The implementation way is maintain the current majority element.Since we meet a unequal element form the current majority number, minus 1 from the current majority's frequency.  

// (it is ok if there are more then two kinds of elements cause the worst case are those array that has only two kinds of element and majority has exactly 1 more than the other. Since case that has more than two kinds of elements are not the worst case, it still works if we pair up two non-mojority element together.)