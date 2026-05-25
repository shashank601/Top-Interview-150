class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;

        int i = 0;
        int j = height.size() - 1;

        while (i < j) 
        {   
            int l = height[i];
            int r = height[j];
            
            area = max(area, (j - i) * min(l, r));
            if  (l > r) {
                j--;
            } else {
                i++;
            }
        }

        return area;
    }
};









we move l or r inward in hope of finding new max area not new max height (singular)
[[8, 50, 2, 3, 3, 4, 5, 8]  
issue:
now guts says if we move r inward  we will skip better maximal soln

l                             r
[8, 7, 2, 3, 3, 4, 5, 8]  area = min of nums[l] and nums[r] X diff of index r and l 
[x  y   a   c   z   x]
nums[ l ] == nums[ r ] 
for this spl. case we cant decide greedily 
This feels dangerous because picking the wrong pointer might seem to skip a tall bar inside

Which move is the optimal decision?
due to symetricity i will skip case where moving r gives max height eg [8, 5, 4, 3, 3, 2, 50, 8]

objective: find max area
problem: greedy sounds not a good way(even thought it is but just not intuitive we have to prove its optimal )

case1) always move l when spl case (and hope we will get greater area) or 
case2) always move r when spl case (  same )
case3) just our gut feeling we can take optimal decision by doing some sort of scanning.

main ques once we get to the spl case
 how do we can get a better (larger) area 
answer both  l and r should end up on taller heights  then curr ht (which is == nums[l] == nums[r]  )
 (keyword: both)

if l moves and l end up on smaller ht 
it dont help in updating max  new calclulation will be smaller then max since width is shrinked 

if l end up on taller ht good (we half way there to get a new better optimal but we have to find a taller on r side too)we wont move l now 
note this taller ht this ht not contribute since r is smaller  r will be used in ans calc check formula

(since r was equal to prev l  and
 l < curr l  so
 r is lesser than  curr l) 

only r will move since l is now on taller 
and any calculataion will not be better till we find a new taller r



 which also compensate for shorten width bcz sometimes having two tall just doesnt work out the way we want  since width is always decreaing
on every move 

[8  1 2  3 3 2 4 5 3 2 (9 3 2 3 4 3 9)  4 1 1 1 1 1 2 2 3 4 4 5 3 2 8]
two tall ht couldnt able to compensate for widths max is unaffected

it dont help if r is smaller it will end up on calculations of area (we use min) and also once l and r were on same hts.  

so finally 
                  i       j    
l = 0 [8,......,x,......y,........8] r = 21

here we just want to know if better soln exist in range (l , r)   // not [l , r]
 now better ans is only possible if (x , y) > (8 , 8) and the shrinken width is  j - i  is compensated with that ht
 min(x,y)

 

