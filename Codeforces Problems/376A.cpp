#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  ll first = 0, second = 0;
  bool flag = true;
  for(auto el : text){
    if(el == '^'){
      flag = false;
      continue;
    }

    if(flag && (el != '=')){
      first += el-'0';
    }
    else if(!flag && (el != '=')){
      second += el-'0';
    }
  }
  cout << first << " " << second << endl;
  if(first > second){
    cout << "left\n";
  }
  else if(first < second){
    cout << "right\n";
  }
  else{
    cout << "balance\n";
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