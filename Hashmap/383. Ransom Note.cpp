class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        int v[26];
        memset(v, 0, sizeof(v));

        for (auto& ch : magazine) {
            v[ch - 'a']++;
        }

        for (auto& ch : ransomNote) {
            if (v[ch - 'a'] > 0) {
                --v[ch - 'a'];
            } else return false;
        }
        return true;
    }
};
