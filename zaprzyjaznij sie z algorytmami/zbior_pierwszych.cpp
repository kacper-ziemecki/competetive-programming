#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve()
{
    ll a, b, c;
    cin >> a >> b;
    c = __gcd(a, b);
    while (a != 1) {
        if (__gcd(a, c) == 1) {
            cout << "NIE\n";
            return;
        }
        a /= __gcd(a, c);
    }
    cout << "TAK\n";
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

    ll t;
    cin >> t;
    while (t--) solve();
}