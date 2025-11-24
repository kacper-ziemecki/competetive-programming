#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  string text;
  cin >> text;
  int x=0,y=0;
  for(int i = 0; i < n; i++){
    if(i == 0){
      if(text[i] == 'U'){
        y++;
      }
      else if(text[i] == 'D'){
        y--;
      }
      else if(text[i] == 'R'){
        x++;
      }
      else{
        x--;
      }
    }
    else if(text[i] != text[i-1] && !(text[i] == 'U' && text[i-1] == 'D') && !(text[i] == 'D' && text[i-1] == 'U') && !(text[i] == 'R' && text[i-1] == 'L') && !(text[i] == 'L' && text[i-1] == 'R')){
      if(text[i] == 'U'){
        y++;
      }
      else if(text[i] == 'D'){
        y--;
      }
      else if(text[i] == 'R'){
        x++;
      }
      else{
        x--;
      }
    }  
  }
  cout << x << ' ' << y << endl;
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