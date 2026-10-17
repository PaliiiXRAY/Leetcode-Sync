#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store the number and its original index
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        // Custom comparator to sort by digit sum, then by value
        auto comp = [this](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        };

        sort(arr.begin(), arr.end(), comp);

        int swaps = 0;
        vector<bool> visited(n, false);

        // Cycle detection to find minimum swaps
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            
            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }

            if (cycle_size > 0) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};