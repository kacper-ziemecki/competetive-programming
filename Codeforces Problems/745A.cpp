#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  string text;
  cin >> text;
  ll res = 0;
  vector<string> list;
  for(ll i = 0; i < text.size(); i++){
    string temp;
    temp += text.back();
    for(ll j = 0; j < text.size()-1;j++){
      temp += text[j];
    }
    text = temp;
    bool flag = false;
    for(auto el : list){
      if(el == text){
        flag = true;
      }
    }
    if(!flag){
      list.push_back(text);
      res++;
    }
  }
  cout << res << endl;
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