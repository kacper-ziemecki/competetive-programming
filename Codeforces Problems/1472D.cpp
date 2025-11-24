#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  vector<ll> one = {}, two = {};
  ll temp;
  for(ll i = 0; i < n; i++){
    cin >> temp;
    if(temp&1){
      two.push_back(temp);
    }
    else{
      one.push_back(temp);
    }
  }
  if(one.empty()){
    if(two.size() == 1){
      cout << "Tie\n";
      return;
    }
    cout << "Bob\n";
    return;
  }
  else if(two.empty()){
    cout << "Alice\n";
    return;
  }
  ll first = 0, second = 0;
  ll index0 = 0, index1 = 0;
  for(ll i = 0; i < n; i++){
    if(i&1){
      if(index1 < two.size() && two[index1] >= one[index0]){
        second += two[index1];
        index1++;
      }
      else{
        index0++;
      }
    }
    else{
      if(index0 < one.size() && one[index0] >= two[index1]){
        first += one[index0];
        index0++;
      }
      else{
        index1++;
      }
    }
  }

  if(first > second){
    cout << "Alice\n";
  }
  else if(first < second){
    cout << "Bob\n";
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

  ll t;
  cin >> t;
  while(t--) solve();
}