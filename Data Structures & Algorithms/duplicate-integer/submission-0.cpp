class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //set boolean to be false by default
        bool isDuplicate = false;
        //run through with a nested for loop and set the boolean high if duplicate value is found
        int target = 0;
        int temp = 0;


        for (int i = 0; i < nums.size(); i++) {
            target = nums[i];

            for (int j = 0; j < nums.size(); j++) {
                temp = nums[j];

                //check to see if indices match values
                if (temp == target && j != i) {
                    isDuplicate = true;
                }
            } 
        }

        return isDuplicate;
    }

};
