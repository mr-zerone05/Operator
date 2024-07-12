#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ADD(string a, string b){
      int len = max((int)a.size(), (int)b.size());
      while (a.size() < len) a = "0" + a;
      while (b.size() < len) b = "0" + b;
      string res = "";
      int carry = 0;
      for(int i = len - 1; i >= 0; i--){
            int temp = (a[i] - '0') + (b[i] - '0') + carry;
            int dv = temp % 10;
            carry = temp / 10;
            res.push_back(dv + '0');
      }
      if (carry != 0) res.push_back(carry + '0');
      reverse(res.begin(), res.end());
      return res;
}
string MULINT(string a, int b){
      int len = a.size();
      string res = "";
      int carry = 0;
      for(int i = len - 1; i >= 0; i--){
            int temp = (a[i] - '0') * b + carry;
            int dv = temp % 10;
            carry = temp / 10;
            res.push_back(dv + '0');
      }
      if (carry != 0) res.push_back(carry + '0');
      reverse(res.begin(), res.end());
      return res;
}
string MULSTR(string a, string b){
      int len = b.size();
      string res = "0";
      string bonus = "";
      for(int i = len - 1; i >= 0; i--){
            string temp = MULINT(a, b[i] - '0') + bonus;
            res = ADD(res, temp);
            bonus += "0";
      }      
      while (res[0] == '0' && res.size() > 1) res.erase(res.begin());
      return res;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string res = MULSTR(num1, num2);
    cout << res << endl;
    return 0;
}