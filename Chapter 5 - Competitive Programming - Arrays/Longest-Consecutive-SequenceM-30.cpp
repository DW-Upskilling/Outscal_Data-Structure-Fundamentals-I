#include <bits/stdc++.h>
#include <string>
using namespace std;
void longestConsecutive(int arr[], int size) {
  vector<int> v;

  for (int i = 0; i < size; i++)
    v.push_back(arr[i]);
  sort(v.begin(), v.end());

  // for (int i = 0; i < size; i++)
  //   cout << v[i] << " ";
  // cout << endl;

  int i = 0, j = 0, output = 0;
  // Write your code here
  while (i < size) {
    j = i + 1;
    // cout << v[j-1] << "\t" << v[j] << endl;
    while (j < size && v[j - 1] == v[j] - 1)
      j++;
    output = (j - i) > output ? (j - i) : output;
    i = j;
  }
  cout << output << endl;
}

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
  longestConsecutive(arr, size);
}