class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1; 
        int p2 = n - 1;

        int p3 = m + n - 1;

        while (p1 >= 0 || p2 >= 0) {
            int cand1 = p1 < 0 ? INT_MIN : nums1[p1];
            int cand2 = p2 < 0 ? INT_MIN : nums2[p2];


            if (cand1 > cand2) {
                nums1[p3] = cand1;
                --p1;
            } else {
                nums1[p3] = cand2;
                --p2;
            }
            --p3;
        }

    }
};

======

be defensive when two pointers are moving codintionally
