#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

void solve()
{
  string one, two, three;
  cin >> one >> two >> three;
  if(one == "rock" && two == "scissors" && three == "scissors"){
    cout << "F\n";
  }
  else if(one == "scissors" && two == "rock" && three == "scissors"){
    cout << "M\n";
  }
  else if(one == "scissors" && two == "scissors" && three == "rock"){
    cout << "S\n";
  }
  else if(one == "paper" && two == "rock" && three == "rock"){
    cout << "F\n";
  }
  else if(one == "rock" && two == "paper" && three == "rock"){
    cout << "M\n";
  }
  else if(one == "rock" && two == "rock" && three == "paper"){
    cout << "S\n";
  }
  else if(one == "scissors" && two == "paper" && three == "paper"){
    cout << "F\n";
  }
  else if(one == "paper" && two == "scissors" && three == "paper"){
    cout << "M\n";
  }
  else if(one == "paper" && two == "paper" && three == "scissors"){
    cout << "S\n";
  }
  else{
    cout << "?\n";
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