#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  int cnt = 1;
  for(int i = 1; i < text.size(); i++){
    if(text[i] != text[i-1]) cnt++;
  }
  cout << cnt / 2 << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  ll t;
  cin >> t;
  while(t--) solve();
}