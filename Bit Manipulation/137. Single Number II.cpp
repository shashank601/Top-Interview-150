class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[32];
        memset(arr, 0, sizeof(arr));

        for (auto num : nums) {
            for (int i = 0; i < 32; i++) {
                if ((num >> i) & 1) {
                    arr[31 - i]++;
                }
            }
        }

        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (arr[i] % 3) {
                ans |= (1 << (31 - i));
            }
        }

        return ans;

    }
};
