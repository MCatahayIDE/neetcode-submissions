class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //array index values
        int temp = 0;
        int temp1 = 0;

        //break conditional
        bool endFlag = false;


        //return data storage
        vector<int> twoSum = { 0, 0 };

        //array traversal
        for (int i = 0; i < nums.size(); i++) {
            temp = nums[i];

            for (int j = 1; j < nums.size(); j++) {
                temp1 = nums[j];

                //check to see if indices match values
                //indices cannot match, use conditional to filter
                if (temp + temp1 == target && i != j) {
                    twoSum[0] = i;
                    twoSum[1] = j;
                    
                    //initiate break condition for both loops if pair is found
                    endFlag = true;         
                    break;                  //exits internal for loop
                    
                    
                }
            } 

            //checks for break condition for external loop
            if(endFlag)
            break;
        }

        return twoSum;
    }
};
