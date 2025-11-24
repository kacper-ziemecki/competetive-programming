#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string text;
  getline(cin, text);
  getline(cin, text);
  getline(cin, text);
  vector<string> list1;
  string temp = "";
  for (auto el : text) {
    if (el == ' ' && temp != "") {
      list1.push_back(temp);
      temp = "";
    }
    else if (el == ' ' && temp == "") {
      continue;
    }
    else {
      temp += el;
    }
  }
  if (temp != "") list1.push_back(temp);

  vector<ll> list2;
  vector<string> list3;
  for (auto el : list1) {
    ll power = 1;
    ll number = 0;
    for (ll i = el.size() - 1; i >= 0; i--) {
      number += (el[i] - '0') * power;
      power *= 10;
    }
    list2.push_back(number);
  }
  string temp1;
  for (ll i = 0; i < list2.size(); i++) {
    cin >> temp1;
    list3.push_back(temp1);
  }

  vector<string> res((ll)list2.size(), "");
  for (ll i = 0; i < list2.size(); i++) {
    res[list2[i] - 1] = list3[i];
  }
  for (auto el : res) cout << el << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../input.txt", "r", stdin);
  freopen("../../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  ll i = 0;
  string temp;
  while (t--) {
    i++;
    if (i != 1) cout << endl;
    solve();
  }
}