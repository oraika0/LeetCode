class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0) return ret;
        string element = "";
        for (int i = 0; i < nums.size(); i++){
            if (i+1 >= nums.size() || nums[i+1]-1 != nums[i]){
                element += to_string(nums[i]);
                ret.push_back(element);
                element = "";
            }
            else if (element == "" && nums[i+1]-1 == nums[i]){
                element = to_string(nums[i]) + "->";
            }
        }
        return ret;
    }
};

// one pass algo

// two cases:
// single interval
// multiple intervals with ->

// maybe peeking the next one to check
// with a buffer elemeet 
// for all nums
//      if element == null 
//           if (peek and only 1)
//                element = to_string(current)
//                element.push 
//                element = null 
//           else
//               element = to_string(current) + "->"
//      else
//           if (peek only 1)
//               element += to_string()
//               element.push
//               elemment = null
//           else
//               continue
//            
//reduce ver.
// if peek and only 1 : 
        // element += to_string()
//         element.push
//         elemment = null
// 
// if element = null && peek more then 1
        // then 
        //      element = to_string(current) + "->"