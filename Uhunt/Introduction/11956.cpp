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
  string text;
  getline(cin, text);
  vector<int> list(100, 0);
  int pointer = 0;
  for(auto el : text){
    // if(el == '.'){
    //   cout << hex << uppercase << showbase << list[pointer] << " ";
    // }
    if(el == '+'){
      list[pointer]++;
      if(list[pointer] > 255) list[pointer] = 0;
    }
    if(el == '-'){
      list[pointer]--;
      if(list[pointer] < 0) list[pointer] = 255;
    }
    if(el == '>'){
      pointer++;
      if(pointer > 99) pointer = 0;
    }
    if(el == '<'){
      pointer--;
      if(pointer < 0) pointer = 99;
    }
  }
  for(auto el : list){
    stringstream temporary;
    temporary << hex << uppercase << el;
    string temporary1;
    temporary >> temporary1;
    if(temporary1.size() == 1){
      cout << " 0" + temporary1;
    }
    else{
      cout << " " << temporary1;
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
  
  ll t,temp=0;
  cin >> t;
  cin.ignore();
  while(t--){
    temp++;
    cout << "Case " << temp << ":";
    solve();
    cout << endl;
  }
}