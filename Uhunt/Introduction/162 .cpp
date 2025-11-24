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
  vector<string> dealer,nonDealer;
  stack<string> list;
  string tmp;
  for(ll i = 0; i < 26*2; i++){
    cin >> tmp;
    if(i&1){
      dealer.push_back(tmp);
    }
    else{
      nonDealer.push_back(tmp);
    }
  }
  bool playerTurn = true, shouldEnd = false;
  while(!shouldEnd){
    if(dealer.empty() || nonDealer.empty()){
      shouldEnd = true;
      break;
    }
    if(playerTurn){
      list.push(nonDealer.back());
      nonDealer.pop_back();
    }
    else{
      list.push(dealer.back());
      dealer.pop_back();
    }
    playerTurn = !playerTurn;

    while(list.top()[1] == 'A' || list.top()[1] == 'K' || list.top()[1] == 'Q' || list.top()[1] == 'J'){
      if(dealer.empty() || nonDealer.empty()){
        shouldEnd = true;
        break;
      }
      if(list.top()[1] == 'J'){
        for(ll i = 0; i < 1; i++){
          if(dealer.empty() || nonDealer.empty()){
            shouldEnd = true;
            break;
          }
          if(playerTurn){
            list.push(nonDealer.back());
            nonDealer.pop_back();
          }
          else{
            list.push(dealer.back());
            dealer.pop_back();
          }
          if(list.top()[1] == 'A' || list.top()[1] == 'K' || list.top()[1] == 'Q' || list.top()[1] == 'J'){
            break;
          }
        }
        playerTurn = !playerTurn;
      }
      else if(list.top()[1] == 'Q'){
        for(ll i = 0; i < 2; i++){
          if(dealer.empty() || nonDealer.empty()){
            shouldEnd = true;
            break;
          }
          if(playerTurn){
            list.push(nonDealer.back());
            nonDealer.pop_back();
          }
          else{
            list.push(dealer.back());
            dealer.pop_back();
          }
          if(list.top()[1] == 'A' || list.top()[1] == 'K' || list.top()[1] == 'Q' || list.top()[1] == 'J'){
            break;
          }
        }
        playerTurn = !playerTurn;
      }
      else if(list.top()[1] == 'K'){
        for(ll i = 0; i < 3; i++){
          if(dealer.empty() || nonDealer.empty()){
            shouldEnd = true;
            break;
          }
          if(playerTurn){
            list.push(nonDealer.back());
            nonDealer.pop_back();
          }
          else{
            list.push(dealer.back());
            dealer.pop_back();
          }
          if(list.top()[1] == 'A' || list.top()[1] == 'K' || list.top()[1] == 'Q' || list.top()[1] == 'J'){
            break;
          }
        }
        playerTurn = !playerTurn;
      }
      else if(list.top()[1] == 'A'){
        for(ll i = 0; i < 4; i++){
          if(dealer.empty() || nonDealer.empty()){
            shouldEnd = true;
            break;
          }
          if(playerTurn){
            list.push(nonDealer.back());
            nonDealer.pop_back();
          }
          else{
            list.push(dealer.back());
            dealer.pop_back();
          }
          if(list.top()[1] == 'A' || list.top()[1] == 'K' || list.top()[1] == 'Q' || list.top()[1] == 'J'){
            break;
          }
        }
        playerTurn = !playerTurn;
      }
    }
  }
  if(shouldEnd){
    cout << "ended\n";
  }
  if(playerTurn){
    while(!list.empty()) dealer.insert(dealer.begin(), list.top()); list.pop();
  }
  else{
    while(!list.empty()) nonDealer.insert(nonDealer.begin(), list.top()); list.pop();
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
  
  solve();
}