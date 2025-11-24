#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

map<char, int> mapa{{'2', 1}, {'3', 2}, {'4', 3}, {'5', 4}, {'6', 5}, {'7', 6}, {'8', 7}, {'9', 8}, {'T', 9}, {'J', 10}, {'Q', 11}, {'K', 12}, {'A', 13}};
bool convert(string test){
  return mapa[test[0]];

}

void solve(string test)
{
  vector<ll> one(5,0), two(5,0);
  one[0] = convert(test);
  for(ll i = 1;i < 5; i++){
    cin >> test;
    one[i] = convert(test);
  }
  for(ll i = 0; i < 5; i++){
    cin >> test;
    two[i] = convert(test);
  }
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());

  //straight flush
  bool tmp1 = true, tmp2 = true;
  for(ll i = 1; i < 5; i++){
    if(one[i]-1 != one[i-1]){
      tmp1 = false;
      break;
    }
  }
  for(ll i = 1; i < 5; i++){
    if(two[i]-1 != one[i-1]){
      tmp2 = false;
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif

  string test;
  cin >> test;
  while(!cin.eof()){
    solve(test);
    cin >> test;
  }
  
}