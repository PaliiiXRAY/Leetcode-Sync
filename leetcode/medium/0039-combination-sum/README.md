# Combination Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of  **distinct**  integers `candidates` and a target integer `target`, return  *a list of all  **unique combinations**  of* `candidates` *where the chosen numbers sum to* `target` *.*  You may return the combinations in  **any order**.

The  **same**  number may be chosen from `candidates` an  **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

 

 **Example 1:** 

```
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

```

 **Example 2:** 

```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

```

 **Example 3:** 

```
Input: candidates = [2], target = 1
Output: []

```

 

 **Constraints:** 

- 1 <= candidates.length <= 30
- 2 <= candidates[i] <= 40
- All elements of candidates are distinct.
- 1 <= target <= 40

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.2 MB (beats 56.35%)  
**Submitted:** 2026-10-02T22:16:34.567Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/combination-sum/)