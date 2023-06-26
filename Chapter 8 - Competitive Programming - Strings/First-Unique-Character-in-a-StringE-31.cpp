#include <iostream>
#include <vector>
using namespace std;

class Outscal {
public:
  int unique(string s) {
    // Write your code here
    vector<int> counts(256, 0);

    for (int i = 0; i < s.length(); i++)
      counts[(int)s[i]] += 1;

    for (int i = 0; i < s.length(); i++)
      if (counts[(int)s[i]] == 1)
        return i;

    return -1;
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  string a;
  cin >> a;
  class Outscal s;
  int ans = s.unique(a);
  cout << ans;
}