#include <iostream>
#include <vector>
using namespace std;
class Outscal {
public:
  int trap(int nums[], int size) {
    // WRITE YOUR CODE HERE
    if (size < 1)
      return 0;

    
    vector<int> lmax(size, nums[0]), rmax(size, nums[size - 1]);
    for (int i = 1; i < size; i++) {
      lmax[i] = max(nums[i], lmax[i - 1]);
      rmax[size - i - 1] = max(nums[size - i - 1], rmax[size - i]);
    }

    int output = 0;
    for (int i = 1; i < size - 1; i++) {
      output += min(lmax[i], rmax[i]) - nums[i];
    }

    return output;
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
  cout << s.trap(arr, size);
}