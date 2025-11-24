#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  char one, two, temp;
  cin >> one >> two;
  ll n;
  cin >> n;
  temp = one;
  for(ll i = 0; i < 1; i++){
    if(one == 'v'){
      one = '<';
    }
    else if(one == '<'){
      one = '^';
    }
    else if(one == '^'){
      one = '>';
    }
    else if(one == '>'){
      one = 'v';
    }
  }
  if(one == two){
    cout << "cw\n";
    return;
  } 
  one = temp;
  for(ll i = 0; i < 1; i++){
    if(one == 'v'){
      one = '>';
    }
    else if(one == '>'){
      one = '^';
    }
    else if(one == '^'){
      one = '<';
    }
    else if(one == '<'){
      one = 'v';
    }
  }
  if(one == two){
    cout << "ccw\n";
  }
  else{
    cout << "undefined\n";
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