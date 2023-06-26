#include <iostream>
#include <vector>
using namespace std;

class Outscal {
private:
  int solution1(string a, string b) {
    /*
    Failed for the following test case:
    Input: sea ate
    Expected: 4
    Actual: 2
    */
    vector<int> counts(256, 0);

    int i = 0, j = 0;

    while (i < a.length() && j < b.length()) {
      counts[a[i++]] += 1;
      counts[b[j++]] -= 1;
    }

    while (i < a.length()) {
      counts[a[i++]] += 1;
    }
    while (j < b.length()) {
      counts[b[j++]] -= 1;
    }

    int output = 0;
    for (i = 0; i < 256; i++) {
      if (counts[i] > 0) {
        output += counts[i];
      } else if (counts[i] < 0)
        output += (-1 * counts[i]);
    }
    return output;
  }

public:
  int reverse(string a, string b) {
    // Write your code here

    int i = 0, j, k, p, curr, output = INT16_MAX;

    while (i < a.length()) {
      j = i;
      k = 0;
      curr = i;
      while (j < a.length()) {
        // cout << j << " " << k << " " << curr << endl;
        p = k;
        while (p < b.length() && b[p] != a[j])
          p++;
        if (p < b.length()) {
          curr += p - k;
          k = p + 1;
        } else {
          curr += 1;
        }
        j++;
      }
      curr += b.length() - k;
      // cout << "curr: " << curr << endl;
      output = min(curr, output);
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
  string a, b;
  cin >> a >> b;
  class Outscal s;
  int ans = s.reverse(a, b);
  cout << ans;
}