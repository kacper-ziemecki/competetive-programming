#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  string text;
  cin >> text;
  if(text.size() < 3){
    cout << "Bad\n";
    return;
  }
  for(int i = 0; i < text.size() - 2; i++){
    if(text[i] == '0' && text[i+1] == '1' && text[i+2] == '0'){
      cout << "Good\n";
      return;
    }
    else if(text[i] == '1' && text[i+1] == '0' && text[i+2] == '1'){
      cout << "Good\n";
      return;
    }
  }
  cout << "Bad\n";
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