#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct punkt{
  int x,y;
}; 

punkt odniesienie;

double cross(punkt a, punkt b, punkt c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

bool sprawdzanie(punkt a, punkt b){
    int cross_zaraznazwe = cross(odniesienie,a,b);
    if(cross_zaraznazwe == 0){
        return (odniesienie.x - a.x)*(odniesienie.x - a.x)+(odniesienie.y - a.y) * (odniesienie.y-a.y) < (odniesienie.x - b.x) * (odniesienie.x - b.x)+(odniesienie.y - b.y) * (odniesienie.y - b.y);
    }
    return cross_zaraznazwe < 0;
}


int main(){
    int n;
    cin >> n;
    vector<punkt> points(2*n);
    for (int i = 0; i < 2*n; ++i)
    {                 
        cin >> points[i].x >> points[i].y;
    }
    odniesienie.x = -1;
    odniesienie.y = -1;
  
    
    for(int i=0; i < points.size() ;i+= 2){
        cout << points[i].x << ' ' << points[i].y;
        cout << ' ';
        cout << points[i+1].x << ' ' << points[i+1].y;
        cout << endl;
    }
}