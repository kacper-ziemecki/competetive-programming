#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct Point{
  int x,y;
};

double cross(Point a, Point b, Point c){
  return (a.x-b.x)*(a.y-c.y)-(a.x-c.x)*(a.y-c.y);
}

void angle_sort(vector<Point> points){
  Point a = *min_element(points.begin(), points.end(), [](Point& b, Point& c) {
        return make_pair(b.y, b.x) < make_pair(c.y, c.x);
  });
  sort(points.begin(), points.end(), [&a](Point& b, Point& c){
    int cross_product = cross(a,b,c);
    if(cross_product == 0){
      return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) < (a.x-c.x)*(a.x-c.x)+(a.y-c.y)*(a.y-c.y);
    }
    return cross_product < 0;
  });
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);

  int n;
  cin >> n;
  vector<Point> points(2*n);
  for(int i = 0; i < 2*n; i++){
    cin >> points[i].x >> points[i].y;
  }

  for(int i = 0; i < points.size(); i++) cout << points[i].x << ' ' << points[i].y << endl;
  cout << endl;
}