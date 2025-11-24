#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  ll i = 0;
  string res;
  for(; i < n; i++){
    if(i+2 < n && text[i] == 'o' && text[i+1] == 'g' && text[i+2] == 'o'){
      i += 3;
      while(i+1 < n && text[i] == 'g' && text[i+1] == 'o'){
        i+=2;
      }
      res += "***";
      i--;
    }
    else {
      res += text[i];
    }
  }
  cout << res << endl;
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