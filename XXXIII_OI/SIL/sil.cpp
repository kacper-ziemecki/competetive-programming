#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void dbg_out(){cout<<endl;}
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){cout<<' '<<H;dbg_out(T...);}
#define dbg(...) cout<<'('<<#__VA_ARGS__<<"):", dbg_out(__VA_ARGS__)

int n,x,y,g;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int c, int &x0, int &y0, int &g) {
    g = gcd(3, 8, x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    return true;
}

void solve(){
	cin >> n;
	if(!find_any_solution(n, x, y, g)){
        cout << "NIE\n";
        return;
    }

    if(x < 0){
        int k = (abs(x)+(8/g)-1)/(8/g);
        dbg(x,k);
        x += k*(8/g);
        y -= k*(3/g);
    } else if(y < 0){
        int k = (abs(y)+(3/g)-1)/(3/g);
        dbg(y,k);
        x -= k*(8/g);
        y += k*(3/g);
    }
    dbg(x,y);
    cout << (x<0 || y<0 ? "NIE\n" : "TAK\n");
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}