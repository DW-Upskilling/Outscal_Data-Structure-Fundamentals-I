#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Outscal {
private:
  bool isPalindrome(string str, int s, int e) {
    // cout << s << " " << e << ": " << str.substr(s, e - (s - 1)) << endl;
    while (e > s) {
      if (str[s] != str[e])
        return false;
      e--;
      s++;
    }
    return true;
  }

public:
  string longestPalindromeSubstring(string str) {
    // Write your code here
    if (str.length() < 3)
      return str;

    int i = 0, j = 1, t1, t2;
    int output[2] = {0, 0};

    while (i < str.length()) {
      j = str.length() - 1;
      while (j > i) {
        if (str[i] == str[j] && isPalindrome(str, i, j)) {
          t1 = output[1] - output[0];
          t2 = j - i;
          if (t2 > t1) {
            output[0] = i;
            output[1] = j;
          }
          break;
        }
        j--;
      }
      i++;
    }
    return str.substr(output[0], output[1] - (output[0] - 1));
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
  string ans = s.longestPalindromeSubstring(a);
  cout << ans;
}