#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(string text)
{
  cout << text << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif

  string text;
  while (getline(cin, text))
    solve(text);
}