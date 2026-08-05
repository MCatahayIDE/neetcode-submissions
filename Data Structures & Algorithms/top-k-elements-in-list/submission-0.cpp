using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // declare hashmap, return vector
        unordered_map<int , int> freq_map;                  // key = int @ index,  value = frequency
        vector<int> k_elems;    

        /// traverse vector and map each value to a key with corresponding freq.

        for (int i = 0; i < nums.size(); i++) {
            // !!! use operator to access value by key, creates key and increments automatically
            freq_map[nums[i]]++;                            // increment frequency of value/key @ i
        }

        /// move map to pair vector, sort keys by ascending frequency 
        vector<pair<int,int>> freq_vec;                     // pair vector storing key/value, and its frequency

        // subsequent map traversal and push to pair vector
        for (auto j = freq_map.begin(); j != freq_map.end(); j++) {
            freq_vec.push_back(make_pair(j->second, j->first));
        } 
        
        // sort pair vector by ascending frequency value, O(nlog(n)) expected
        sort(freq_vec.begin() , freq_vec.end());

        // extract k values associated with highest frequencies 
        for (int freq_i = 0; freq_i < k; freq_i++) {
            k_elems.push_back(freq_vec[freq_vec.size() - (1+freq_i)].second);
        }


        return k_elems;

    }
};