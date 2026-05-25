class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int cnt = 0;
        vector<int> freq(26);

        for (auto& ch : s) {
            freq[ch - 'a']++;
        }

        for (auto& ch : t) {
            freq[ch - 'a']--;
        }

        for (auto& val : freq) {
            if (val) return false;
        }
        return true;
    }
};

======

caan combine last two loops  

sinxe size is same if any freq become negative we can rteurn false;
