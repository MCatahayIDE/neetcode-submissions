using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // temp containers, vars
        vector <pair <string, int> > idxed_strs;
        vector < vector<string> > grouped;                      // final vector of anagram groups
        int len = strs.size();

        // First, sort all vector strings alphabetically using sort
        for (int i = 0; i < len; ++i) {                         // ++i for memory increment ??

            idxed_strs.push_back(make_pair(strs[i] , i));       // add strings paired with its index in strs
            
            // sort each string alphabetically
            sort(idxed_strs[i].first.begin(), idxed_strs[i].first.end());
        }

        // sort the resulting sorted strings again
        sort(idxed_strs.begin() , idxed_strs.end());            // sort pushed pairs alphabetically

        // Now group sorted words into corresponding anagram vectors
        vector <string> temp_group;                             // declare temp grouping vector

        for (int j = 0; j < idxed_strs.size(); ++j) {
            // add strings to current anagram group given condition met, terminate if not

            // add to group if temp group is empty or current string matches previous string
            if (temp_group.empty() ||  idxed_strs[j - 1].first == idxed_strs[j].first) {
                temp_group.push_back(strs[idxed_strs[j].second]);  // pull word usings its index in strs
            }
            // word j part of a new anagram list, clear vector for new group, push finished group 
            else {
                grouped.push_back(temp_group);                  // push anagram group to return vector
                temp_group.clear();                             // clear temp for new group
                temp_group.push_back(strs[idxed_strs[j].second]);  // start next group, place first word  
            }
        }

        // check catch condition, ensure final group is pushed to return vector if not emptied
        if (!temp_group.empty()) {                              // detect non-empty temp
            grouped.push_back(temp_group);                      // push anagram group to return vector
        }

        /*

        //DEBUG: Test intended sorted output
        for (int k = 0; j < idxed_strs.size(); ++k) {
            test_v.push_back(idxed_strs[k].first);
        }

        */

        return grouped;
    }
};