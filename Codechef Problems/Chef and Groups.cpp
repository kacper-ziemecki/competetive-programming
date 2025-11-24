#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  int cnt = (text[0] == '1' ? 1 : 0);
  for(int i = 1; i < text.size(); i++){
    if(text[i] == '1' && text[i-1] == '0') cnt++;
  }
  cout << cnt << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}