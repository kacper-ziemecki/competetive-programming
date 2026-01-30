#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
void dbg_out(){ cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H,Tail... T){ cout << ' ' << H; dbg_out(T...);}
#define dbg(...) cout << '(' << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
