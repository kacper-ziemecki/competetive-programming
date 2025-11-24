  #include <bits/stdc++.h>
  using namespace std;
  #define endl "\n"
  #define ll long long
  #define ld long double


  void solve()
  {
    ll n;
    cin >> n;
    string text;
    cin >> text;
    ll first = n+1, second = n+1;
    for(ll i = 0; i+4 < n; i++){
      if(text.substr(i, 4) == "chef" && first == n+1) first = i;
      if(text.substr(i, 4) == "code" && second == n+1) second = i;
    }
    if(second < first){ 
      cout << "AC\n";
    }
    else{
      cout << "WA\n";
    }
  }

  int main()
  {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
  #endif
    
    ll t;
    cin >> t;
    while(t--)
    solve();
  }