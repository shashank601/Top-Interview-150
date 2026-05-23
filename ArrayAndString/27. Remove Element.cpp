class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int wrt = n - 1;
        int read = n - 1;
        int cnt = 0;

        while (read >= 0) {
            if (nums[read] == val) {
                swap(nums[read], nums[wrt]);
                wrt--;
                cnt++;
            }
            read--;
        }

        return n - cnt;
    }
};

=========


gpt:
int k = 0;

for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != val) {
        nums[k++] = nums[i];
    }
}

we can overwrite val
