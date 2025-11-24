#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  string first, second, one = "", two = "";
  cin >> first >> second;

  bool uno = false, dos = false;
  for(ll i = 0; i < first.size(); i++){
    if(first[i] == '0' && !uno){
      continue;
    }
    uno = true;
    one += first[i];
  }
  for(ll i = 0; i < second.size(); i++){
    if(second[i] == '0' && !dos){
      continue;
    }
    dos = true;
    two += second[i];
  }
  if(one.size() < two.size()){
    cout << "<\n";
    return;
  }
  else if(one.size() > two.size()){
    cout << ">\n";
    return;
  }
  else{
    for(ll i = 0; i < one.size(); i++){
      if(one[i] > two[i]){
        cout << ">\n";
        return;
      }
      else if(one[i] < two[i]){
        cout << "<\n";
        return;
      }
    }
    cout << "=\n";
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