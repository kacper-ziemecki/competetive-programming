#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n;

void solve(){
	cin >> n;
	for(int i = 0; i <= (1e9)/8; i++){
        if((n-i*8) < 0) break;
        if((n-i*8) % 3 == 0){
            // dbg(i, (n-i*8)/3);
            cout << "TAK\n";
            return;
        }
    }
    cout << "NIE\n";
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}