#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a,b;
  cin >> a >> b;
  vector<bool> list(a, false);
  string text;
  ll c;
  ll count = 0;
  for(ll i = 0; i < b; i++){
    cin >> text;
    if(text == "CLOSEALL"){
      for(ll j = 0; j < a; j++){
        list[j] = false;
      }
      count = 0;
    }
    else{
      cin >> c;
      if(list[c-1]) count--;
      else count++;
      list[c-1] = !list[c-1];
    }
    cout << count << endl;
  }
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
  
  solve();
}