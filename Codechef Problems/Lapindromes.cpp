#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  unordered_map<char, int> one,two;
  for(int i = 0; i < text.size()/2; i++){
    one[text[i]]++;
  }
  for(int i = (text.size()+2-1)/2; i < text.size(); i++){
    two[text[i]]++;
  }

  for(auto el : one){
    if(el.second != two[el.first]){
      cout << "NO\n";
      return;
    }
  }
  for(auto el : two){
    if(el.second != one[el.first]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}