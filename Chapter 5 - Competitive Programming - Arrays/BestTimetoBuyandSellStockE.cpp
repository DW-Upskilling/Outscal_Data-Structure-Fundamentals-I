#include <bits/stdc++.h>
using namespace std;
class Outscal {
public:
  int maximum(int nums[], int size) {
    int max_profit = 0, current, mine = nums[0];
    for (int i = 1; i < size; i++) {
      if (nums[i] < mine) {
        mine = nums[i];
      } else {
        current = nums[i] - mine;
        max_profit = max_profit < current ? current : max_profit;
      }
    }

    return max_profit;
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
  cout << s.maximum(arr, size);
}