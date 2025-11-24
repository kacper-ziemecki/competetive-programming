#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  sort(text.begin(), text.end());
  int cnt = 0;
  int i = 0;
  for(; i < text.size()-1; i++){
    if(text[i] == text[i+1]){
      i++;
    }
    cnt++;
  }
  if(i < text.size()) cnt++;
  cout << cnt << endl;
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