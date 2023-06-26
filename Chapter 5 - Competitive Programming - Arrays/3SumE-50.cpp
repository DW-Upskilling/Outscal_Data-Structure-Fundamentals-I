#include <bits/stdc++.h>
using namespace std;
class Outscal {
public:
  void maximum(int nums[], int size) {
    int left, right, sum;

    // sort the elements
    sort(nums, nums + size);

    int temp = 0;
    vector<vector<int>> output;
    for (int i = 0; i < size; i++) {
      if (i > 0 and nums[i] == nums[i - 1])
        continue;

      left = i + 1;
      right = size - 1;
      while (left < right) {
        sum = nums[i] + nums[left] + nums[right];
        if (sum == 0) {
          output.push_back({nums[i], nums[left], nums[right]});

          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;

          left++;
          right--;
        } else if (sum > 0) {
          right--;
        } else {
          left++;
        }
      }
    }

    for (auto list = output.rbegin(); list != output.rend(); ++list) {
      for (const auto element : *list) {
        cout << element << " ";
      }
      cout << endl;
    }
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
  s.maximum(arr, size);
}