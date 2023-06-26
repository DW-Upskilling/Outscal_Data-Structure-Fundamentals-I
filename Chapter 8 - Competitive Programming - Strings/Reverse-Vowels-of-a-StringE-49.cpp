#include <iostream>
#include <string>
using namespace std;

class Outscal {
public:
  string reverse(string s) {
    const string vowels = "aeiou";
    char temp;
    int i = s.find_first_of(vowels), j = s.find_last_of(vowels);
    while (i != string::npos && j != string::npos && i < j) {
      // cout << i << " " << j << endl;
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;

      i = s.find_first_of(vowels, i + 1), j = s.find_last_of(vowels, j - 1);
    }

    return s;
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
  string ans = s.reverse(a);
  cout << ans;
}