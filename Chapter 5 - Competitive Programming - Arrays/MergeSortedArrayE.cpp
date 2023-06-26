#include <bits/stdc++.h>
using namespace std;
class Outscal {
public:
  void merge(int nums1[], int nums2[], int size1, int size2) {
    vector<int> v;
    int i = 0, j = 0;
    
    while (i < size1 && j < size2) {
      if (nums1[i] < nums2[j]) {
        v.push_back(nums1[i++]);
      } else {
        v.push_back(nums2[j++]);
      }
    }
    
    while (i < size1) {
      v.push_back(nums1[i++]);
    }
    while (j < size2) {
      v.push_back(nums2[j++]);
    }

    for (auto ptr = v.begin(); ptr != v.end(); ptr++) {
      cout << *ptr << " ";
    }
    cout << endl;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int size1;
  cin >> size1;
  int nums1[size1];
  for (int i = 0; i < size1; i++) {
    cin >> nums1[i];
  }
  int size2;
  cin >> size2;
  int nums2[size2];
  for (int i = 0; i < size2; i++) {
    cin >> nums2[i];
  }
  class Outscal s;
  s.merge(nums1, nums2, size1, size2);
}