#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define endl '\n'
#define pb push_back
void dbg_out(){cout << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){cout <<' ' <<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int rnd(int a, int b){
	return rand()%(b-a+1)+a;
}

void solve(){

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("./in.in", "r", stdin);

	int seed;
	cin >> seed;
	srand(seed);

	solve();
}