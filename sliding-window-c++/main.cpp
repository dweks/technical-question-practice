#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

/*
You are given an array of integers nums, there is a sliding window
of size k which is moving from the very left of the array to the 
very right. You can only see the k numbers in the window. Each time
the sliding window moves right by one position.

Return the max sliding window.
*/

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> & nums, int k) {
      vector<int> max_window;
      int size = nums.size();
      if (size < k)
        throw "Window greater than array size";
      if (size > pow(10, 5))
        throw "Vector too long: greater than 10^5";
      if (size < 1)
        throw "Vector too short: less than 1";

      if (size == k) {
        int largest{INT_MIN};
        for(const auto & num : nums) {
          largest = num > largest ? num : largest;
        }
        max_window.push_back(largest);
      } else {
        for (int i{0}; i <= size - k; ++i) {
          int largest{INT_MIN};
          for (int j{i}; j < i + k; ++j) {
            largest = nums[j] > largest ? nums[j] : largest;
          }
          max_window.push_back(largest);
          largest = INT_MIN;
        }
      }
      return max_window;
    }
};

int main() {
  Solution test;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  try {
    vector<int> max = test.maxSlidingWindow(nums, k);
    cout << max.size() << endl;
    for (const auto & num : max)
      cout << num << " ";
  }
  catch (char * e) {
    cout << e;
  }

  return 0;
}