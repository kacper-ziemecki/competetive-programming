#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  ld a,b,c,d;
  cin >> a >> b >> c >> d;
  if(max(3 * a / 10, a - a / 250 * c) > max(3 * b / 10, b - b / 250 * d)){
    cout << "Misha\n";
  }
  else if(max(3 * a / 10, a - a / 250 * c) < max(3 * b / 10, b - b / 250 * d)){
    cout << "Vasya\n";
  }
  else{
    cout << "Tie\n";
  }
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