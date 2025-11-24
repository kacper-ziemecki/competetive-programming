#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(52, 0), tmp(52,0);
  for(ll i = 0; i < 52; i++) list[i] = i+1;
  vector<vector<ll>> transform(n, vector<ll>(52, 0));
  for(auto &sub : transform){
    for(auto &el : sub){
      cin >> el;
    }
  }
  cin.ignore();
  string line;
  ll number;
  while(true){
    getline(cin, line);
    if(line.empty()){
      break;
    }
    number = stoi(line);
    tmp = list;
    for(ll i = 0; i < 52; i++){
      list[transform[number-1][i]-1] = tmp[i];
    }
    if(cin.eof()){
      break;
    }
  }
  for(auto el : list){
    if(el % 13 == 0){
      cout << "Ace";
    }
    else if(el % 13 == 12){
      cout << "King";
    }
    else if(el % 13 == 11){
      cout << "Queen";
    }
    else if(el % 13 == 10){
      cout << "Jack";
    }
    else{
      cout << (el % 13)+1;
    }

    if(el <= 13){
      cout << " of Clubs\n";
    }
    else if(el <= 13*2){
      cout << " of Diamonds\n";
    }
    else if(el <= 13*3){
      cout << " of Hearts\n";
    }
    else if(el <= 13*4){
      cout << " of Spades\n";
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif
  
  ll t;
  cin >> t;
  while(t--){
    solve();
    if(t != 0) cout << endl;
  }
}