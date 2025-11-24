#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double


void solve()
{
  string text;
  cin >> text;
  ll first = 0, second = 0;
  ll res1 = 10, res2 = 10;

  for(ll i = 0; i < 10; i++){
    if(i&1){
      if(text[i] == '1'){
        second++;
      }
      if(first + (10 - i - 1)/2 < second){
        res2 = i+1;
        break;
      }
      if(second + (10 - i - 1)/2 < first){
        res2 = i+1;
        break;
      }
    }
    else{
      if(text[i] == '1'){
        first++;
      }
      else if(text[i] == '?'){
        first++;
      }
      if(first + (10 - i + 1)/2 < second){
        res2 = i+1;
        break;
      }
      if(second + (10 - i + 1)/2 < first){
        res2 = i+1;
        break;
      }
    }
  }

  first = 0, second = 0;
  for(ll i = 0; i < 10; i++){
    if(i&1){
      if(text[i] == '1'){
        second++;
      }
      else if(text[i] == '?'){
        second++;
      }

      if(first + (10 - i - 1)/2 < second){
        res2 = i+1;
        break;
      } 
      if(second + (10 - i + 1)/2 < first){
        res2 = i+1;
        break;
      }

    }
    else{
      if(text[i] == '1'){
        first++;
      }
      if(first + (10 - i + 1)/2 < second){
        res2 = i+1;
        break;
      }
      if(second + (10 - i - 1)/2 < first){
        res2 = i+1;
       break;
      }
    }
  }
  cout << min(res1, res2) << endl;
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