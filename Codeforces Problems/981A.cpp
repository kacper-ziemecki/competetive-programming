#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  string text;
  cin >> text;

  bool flag1 = true, flag2 = true;
  for(ll i = 1; i < text.size(); i++){
    if(text[i] != text[i-1]){
      flag1 = false;
    }
    if(text[i] != text[text.size()-1-i]){
      flag2 = false;
    }
  }
  if(flag1){
    cout << 0 << endl;
    return;
  }
  if(!flag2){
    cout << text.size() << endl;
    return;
  }
  if(text.size() == 2 || text.size() == 1){
    cout << 0 << endl;
    return;
  }
  cout << text.size()-1 << endl;
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