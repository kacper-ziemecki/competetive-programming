#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


bool test(ll time){
  ll hours = time/60;
  ll minutes = time - (hours*60);
  if(hours%10 == 7) return true;
  if(minutes%10 == 7) return true;
  return false;
}

void solve()
{
  ll n;
  cin >> n;
  ll h,m;
  cin >> h >> m;
  ll time = h*60 + m;
  ll res = 0;
  while(!test(time)){
    time -= n;
    if(time < 0){
      time += 24*60;
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