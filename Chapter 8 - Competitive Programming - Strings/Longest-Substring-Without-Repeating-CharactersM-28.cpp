#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  int substring(string s) {
    // Write your code here
    vector<int> counts(256, 0);

    for (int i = 0; i < s.length(); i++) {
      counts[(int)s[i]] += 1;
    }

    int i = 0, j = s.length() - 1, output = 1;
    bool flg = false;
    while (i < s.length()) {
      j = s.length() - 1;

      while (j >= i) {
        for (int k = 0; k < 256; k++) {
          if (counts[k] > 1) {
            flg = false;
            break;
          } else
            flg = true;
        }
        if (flg)
          break;
        counts[(int)s[j]] -= 1;
        j--;
      }

      if (flg) {
        // cout << i << " " << j << ": " << s.substr(i, j - (i - 1)) << endl;
        output = output > (j - (i - 1)) ? output : (j - (i - 1));
      }

      j++;
      while (j < s.length()) {
        counts[(int)s[j]] += 1;
        j++;
      }

      counts[(int)s[i]] -= 1;
      i++;
    }

    return output;
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
  int ans = s.substring(a);
  cout << ans;
}