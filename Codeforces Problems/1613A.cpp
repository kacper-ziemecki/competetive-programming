#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void solve()
{
  string one, two;
  ll first, second;
  cin >> one >> first >> two >> second;
  if(one.size() + first > two.size() + second){
    cout << ">\n";
  }
  else if(one.size() + first < two.size() + second){
    cout << "<\n";
  }
  else{
    for(ll i = 0; i < min(one.size(), two.size()); i++){
      if((one[i] - '0') > (two[i] - '0')){
        cout << ">\n";
        return;
      }
      if((one[i] - '0') < (two[i] - '0')){
        cout << "<\n";
        return;
      }
    }
    if(one.size() > two.size()){
      for(ll i = two.size(); i < one.size(); i++){
        if(one[i] != '0'){
          cout << ">\n";
          return;
        }
      }
      cout << "=\n";
    }
    else if(one.size() < two.size()){
      for(ll i = one.size(); i < two.size(); i++){
        if(two[i] != '0'){
          cout << "<\n";
          return;
        }
      }
      cout << "=\n";
    }
    else{
      cout << "=\n";
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
  freopen("../../output.txt", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
}