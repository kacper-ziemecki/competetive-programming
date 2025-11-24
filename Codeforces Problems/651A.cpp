#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double



void solve()
{
  ll a,b;
  cin >> a >> b;
  ll res = 0;
  if(a == 1 && b == 1){
    cout << 0 << endl;
    return;
  }
  while(a > 0 && b > 0){
    if(a >= b){
      a -= 2;
      b++;
    }
    else{
      b -= 2;
      a++;
    }
    res++;
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