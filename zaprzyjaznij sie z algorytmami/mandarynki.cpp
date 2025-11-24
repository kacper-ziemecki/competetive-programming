#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    if(n == 1){
        cout << 2 << endl;
        return;
    }
    if(n == 2){
        cout << 4 << endl;
        return;
    }
    cout << 1 + n*n - n << endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("../../input.txt", "r", stdin);
    //     freopen("../../output.txt", "w", stdout);
    // #endif
    
    solve();
}