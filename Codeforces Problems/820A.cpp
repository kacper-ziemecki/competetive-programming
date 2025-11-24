#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll c,v0,v1,a,l;
  cin >> c >> v0 >> v1 >> a >> l;
  ll pages = 0;
  ll acc = 0;
  ll day = 0;
  while(pages < c){

    if(++day > 1){
      pages += min(v1, v0 + acc);
      pages -= l;
    }
    else{
      pages += min(v1, v0 + acc);
    }
    acc += a;
  }
  cout << day << endl;
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