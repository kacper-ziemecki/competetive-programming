#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  string number;
  cin >> number;
  ll i = 0;
  for(;i < number.size();){
    if(i+2 < number.size() && number[i] == '1' && number[i+1] == '4' && number[i+2] == '4'){
      i += 3;
    }
    else if(i+1 < number.size() && number[i] == '1' && number[i+1] == '4'){
      i += 2;
    }
    else if(i < number.size() && number[i] == '1'){
      i++;
    }
    else{
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  solve();
  
}