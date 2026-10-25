#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(int openCount, int closeCount, int n, string currentString, vector<string>& result) {
        // Step 1: Base Case
        // If the length of currentString is 2 * n, we've formed a valid combination.
        if (currentString.size() == 2*n){
             result.push_back(currentString); 
             return;
             }
        // Add it to the result vector and return.
        // Step 2: Try adding an Open Parenthesis '('
        // Only if we haven't used all 'n' open parentheses yet.
        if (openCount < n) {
            // Recursive call adding "(" to currentString and incrementing openCount
           backtrack(openCount + 1, closeCount, n, currentString + "(", result);
        }

        // Step 3: Try adding a Close Parenthesis ')'
        // Only if there are more open parentheses used than close ones.
        if (openCount > closeCount) {
            // Recursive call adding ")" to currentString and incrementing closeCount
          backtrack(openCount, closeCount + 1, n, currentString + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Start the recursion with 0 open, 0 close, and an empty string.
        backtrack(0, 0, n, "", result);
        return result;
    }
};