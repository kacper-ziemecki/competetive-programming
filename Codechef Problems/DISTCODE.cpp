#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  set<string> lista;
  for(ll i = 1; i < text.size(); i++){
    string temp;
    temp += text[i-1];
    temp += text[i];
    lista.emplace(temp);
  }
  cout << lista.size() << endl;
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
  
  ll t;
  cin >> t;
  while(t--) solve();
}