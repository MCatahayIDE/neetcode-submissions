class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = -1;
        int n = nums.size();

        int floor = 0;
        int ceiling = n - 1;
        int mid;

        while (floor <= ceiling) {
            mid = floor + (ceiling - floor) / 2;      // take mid as halfway of delta between floor and ceiling
                if (nums[mid] == target){   
                    return mid;
                } else if (nums[mid] < target) {      // set floor to limit search to half with larger ints
                    floor = mid + 1;
                } else {                              // o.w. search on half with smaller values than mid
                    ceiling = mid - 1;
                }

        }

        return idx;
    }
};