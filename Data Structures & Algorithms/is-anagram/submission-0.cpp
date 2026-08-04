class Solution {
public:
    bool isAnagram(string s, string t) {
        // copy input to sorting strings
        //string s_sorted = s;
        //string t_sorted = t;

        // sort both strings alphabetically
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // return boolean based on whether sorted string are similar
        if (s == t) {
            return true;
        } else {
            return false;
        }
    }
};