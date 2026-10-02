#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current_path, vector<vector<int>>& result) {
        // Step 1: Base Cases
        if (target == 0) {
            result.push_back(current_path);
            return;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }

        // Step 2: Make the choice to TAKE the current candidate
        // Add the number to our path
        current_path.push_back(candidates[index]);
        
        // YOUR LOGIC HERE: Make the recursive call to KEEP exploring with this number.
        // What happens to the target? What happens to the index?
        // backtrack(...);
        backtrack(index,target-candidates[index],candidates,current_path,result);

        // Step 3: UNDO the choice (The backtrack!)
        current_path.pop_back(); 

        // Step 4: Make the choice to SKIP the current candidate
        // YOUR LOGIC HERE: Make the recursive call to explore the NEXT number.
        // What happens to the target? What happens to the index?.
        //  backtrack(...);
        backtrack(index + 1 , target, candidates,current_path,result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_path;
        
        backtrack(0, target, candidates, current_path, result);
        
        return result;
    }
};