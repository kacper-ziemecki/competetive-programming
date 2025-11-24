#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(long double a,long double b,long double c,long double d)
{
  vector<pair<long double, long double>> list(d, {0, 0});
  for(auto &el : list) cin >> el.first >> el.second;

  ll res = 0;
  long double car = b+c, bank = c;
  car -= car*list[0].second;
  ll index = 0, realIndex = 0;
  // dbg(res, car, bank);
  while(bank >= car){
    res++;
    bank -= c/a;
    index++;
    while(list[realIndex].first < index && realIndex < list.size()){
      realIndex++;
    }
    if(list[realIndex].first > index || realIndex >= list.size()){
      car -= car*list[realIndex-1].second;
      // cout << list[realIndex-1].second << endl;
    }
    else{
      car -= car*list[realIndex].second;
      // cout << list[realIndex].second << endl;
    }
    // dbg(res, car, bank);
  }
  if(res == 1){
    cout << "1 month\n";
  }
  else{
    cout << res << " months" << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif
  
  double a=1,b,c,d;
  while(true){
    cin >> a >> b >> c >> d;
    if(a < 0) break;
    solve(a,b,c,d);
  }
}