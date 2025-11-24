#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string one, two;
  cin >> one >> two;
  for(ll i = 0; i < min(two.size(), one.size()); i++){
    if(one[one.size()-1-i] != two[two.size()-1-i]){
      cout << one.size() - i + two.size() - i << endl;
      return;
    }
  }
  cout << abs((int)one.size() - (int)two.size()) << endl;
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