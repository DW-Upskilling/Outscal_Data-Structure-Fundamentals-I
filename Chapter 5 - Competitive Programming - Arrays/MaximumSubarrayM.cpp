#include <iostream>
#include <vector>

using namespace std;
class Outscal {
private:
  int prefixSumApproach(int nums[], int size) {
    /* Not working Following Test Case:
    Input: 2 -2 -1
    Expected Output: -1
    */
    int output = nums[0], index = 0;
    vector<int> cum_sum;

    cum_sum.push_back(nums[0]);
    for (int i = 1; i < size; i++) {
      cum_sum.push_back(cum_sum[i - 1] + nums[i]);
      if (output < cum_sum[i]) {
        output = cum_sum[i];
        index = i;
      }
    }

    int s = 0;
    for (int i = index; i >= 0; i--) {
      s += nums[i];
      if (s > output)
        output = s;
    }
    return output;
  }
  int kadanesAlgorithm(int nums[], int size) {
    // Approach suggested by the reviewer 1
    int output = nums[0], current = 0;

    for (int i = 0; i < size; i++) {
      current += nums[i];
      output = output > current ? output : current;
      if (current < 0) {
        current = 0;
      }
    }
    return output;
  }

public:
  int maximumSubarray(int nums[], int size) {
    if (size == 0)
      return 0;
    // WRITE YOUR CODE HERE
    // return prefixSumApproach(nums, size);
    return kadanesAlgorithm(nums, size);
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  class Outscal s;
  cout << s.maximumSubarray(arr, size);
}