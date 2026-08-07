using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num_single;
        unordered_map<int , int> nums_map;          // map using int as key, storing freq as value

        // traverse once through nums to record frequency, O(n)
        for (int i = 0; i < nums.size(); i++) {
            nums_map[nums[i]]++;                    // use int at nums[i] as key, increment associated value/freq
        }

        // traverse and populate pair vector using map
        vector<pair<int,int>> nums_vector;

        for (auto j = nums_map.begin(); j != nums_map.end(); j++){
            nums_vector.push_back(make_pair(j->first , j->second));     // key:first, freq:second
        }

        // traverse one last time through vector until int with correct frequency is found
        for (int k = 0; k < nums_vector.size(); k++){
            if (nums_vector[k].second == 1) {  
                num_single = nums_vector[k].first;        // return key associating int with freq 1
                break; 

            }
        }

        return num_single;
    }
};