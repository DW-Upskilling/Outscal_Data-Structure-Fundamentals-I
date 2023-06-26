#include <bits/stdc++.h>
using namespace std;

class Outscal {
public:
  string substring(string s, string t) {
    // Write your code here
    vector<int> counts(256, 0);
    vector<int> indices;

    for (int i = 0; i < t.length(); i++)
      counts[t[i]] += 1;

    int i = 0, j;
    int output[2] = {0, s.length() - 1};
    bool flg = false;

    while (i < s.length()) {
      while (i < s.length() && counts[s[i]] < 1)
        i++;
      if (i >= s.length())
        break;
      // cout << "i: " << i << endl;
      counts[s[i]] -= 1;
      j = i + 1;

      while (j < s.length()) {
        while (j < s.length() && counts[s[j]] < 1)
          j++;
        if (j > s.length())
          break;
        // cout << "j: " << j << endl;

        counts[s[j]] -= 1;
        indices.push_back(j);
        flg = true;
        for (int k = 0; k < 256; k++) {
          if (counts[k] != 0) {
            flg = false;
            break;
          }
        }

        if (flg) {
          // cout << i << " " << j << " " << (j - (i - 1)) << " " << s.substr(i,
          // j - (i - 1)) << endl;
          if ((output[1] - (output[0] - 1)) > (j - (i - 1))) {
            output[0] = i;
            output[1] = j;
          }
          break;
        }
        j++;
      }

      for (int k = indices.size() - 1; k >= 0; k--) {
        counts[s[indices[k]]] += 1;
        indices.pop_back();
      }

      counts[s[i]] += 1;
      i++;
    }

    return s.substr(output[0], (output[1] - (output[0] - 1)));
  }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  string a, b;
  cin >> a >> b;
  class Outscal s;
  string ans = s.substring(a, b);
  cout << ans;
}