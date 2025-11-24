#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  ll minutes;
  cin >> text >> minutes;
  ll time = 60*((text[0] - '0')*10 + (text[1] - '0')) + (text[3]-'0')*10 + (text[4] - '0');
  time += minutes;
  time %= 24 * 60;
  string first = to_string(time/60);
  string second = to_string(time - (time/60)*60);
  if(first.size() < 2) first = '0' + first;
  if(second.size() < 2) second = '0' + second;
  cout << first << ":" << second << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}