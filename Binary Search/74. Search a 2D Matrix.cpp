class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix.size() - 1;

        int rowSize = matrix[0].size();

        while (i <= j) {
            int mid = i + (j - i)/2;

            if (target >= matrix[mid][0] && matrix[mid][rowSize - 1] >= target) {
                int rowNum = mid;

                int i = 0;
                int j = rowSize - 1;

                while (i <= j) {
                    int mid = i + (j - i)/2;

                    if (matrix[rowNum][mid] == target) {
                        return true;
                    }

                    if (matrix[rowNum][mid] > target) {
                        j = mid - 1;
                    } else { 
                        i = mid + 1;
                    }
                }

                return false;
            }

            if (target < matrix[mid][0]) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        return false;
        
    }
};
