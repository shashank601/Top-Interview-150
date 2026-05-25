class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (auto num : nums) {
            pq.push(num);
        }

        
        while (!pq.empty() && k-- > 1) {
            pq.pop();
        }

        return pq.top();
    }
};

====

if use min heap (much better sc)

it keeps top k largest elemnt seen so far   <-- we can enforce


curr element

choose top is better or this curr

if top is worse remove it and push curr
otherwise discard curr



====

Usually:

heap solution = acceptable
quickselect = optimal   <-- quicksort hi hai (avg case O n)
