class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap;
       for (int i = 0; i<stones.size(); i++){
        maxHeap.push(stones[i]);
       }
       while(maxHeap.size() > 1){
        int heavy1 = maxHeap.top();
        maxHeap.pop();
         int heavy2 = maxHeap.top();
        maxHeap.pop();
        if (heavy1 != heavy2){
            int weight = heavy1-heavy2;
          maxHeap.push(weight);
        }
       }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};