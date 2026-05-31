class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(); 
        int cols = matrix[0].size();
        vector<int> ans; 
        
        int t = 0;
        int b = rows - 1;

        int l = 0;
        int r = cols - 1;

        while (ans.size() < rows * cols)   {        <-- a better condn is l <= r && t <= b
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;


            for (i nt i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            r--;

            if (t <= b) {
                for (int i = r; i >= l; i--) {
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }

            if (l <= r) {
                for (int i = b; i >= t;  i--) {
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }

            

        }
        return ans;

         
    }
};

======

t repr upper row
to process it we go from l to r at fixed idx [t]
then move t inward (t++;)

b repr bottom row 
to process it we go from r to l at fixed idx [b]
then move b inwards (b--;)



spl case when 
t 
!=
b

t++;
b--;

they may becom ==

t
#      => t, b
b
do process new t, b


or 

they may cross each other dpeedning on dim.

#
t      =>  b
b      =>  t
#

dont process new t, b


if (t <= b) {

}
