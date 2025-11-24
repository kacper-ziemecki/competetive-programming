#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll a,b;
  cin >> a >> b;
  if(a*3 <= b){
    cout << 0 << endl;
    return;
  }
  while(a*2 < b){
    a--;
    b -= 3;
  }
  cout << a << endl;
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