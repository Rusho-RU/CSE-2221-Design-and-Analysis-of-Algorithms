#include <bits/stdc++.h>
using namespace std;

#define INF 1000
#define eps 0.000001

struct Point{
    double x, y;
    Point(double _x, double _y):x(_x), y(_y){}
    Point(){}
};

bool same(double a, double b){
    return abs(a-b)<eps;
}

int orientation(Point p1, Point p2, Point p3){
    double cross_product = (p1.x-p2.x) * (p2.y-p3.y) - (p1.y-p2.y) * (p2.x-p3.x);

    if(same(cross_product, 0))
        return 0;
    if(cross_product<0)
        return -1;
    return 1;
}

bool lineIntersected(Point p1, Point p2, Point p3, Point p4){
    orientation1 = orientation(p1, p2, p3);
    orientation2 = orientation(p1, p2, p4);

    if(orientation1 * orientation2 <= 0)
        return true;
}

bool pointInPolygon(vector<Point>& polygon, Point p){
    Point ray(INF, p.y);
    int n = polygon.size();

    for(int i=0; i<n; i++){
        int j = (i+1)%n;
        if(lineIntersected(polygon[i], polygon[j], p, ray)){

        }
    }
}

void scan(vector<Point>& v, int n){
    v.clear();

    for(int i=0; i<n; i++){
        double x,y;
        scanf("%lf %lf",&x,&y);
        v.push_back(Point(x,y));
    }

    reverse(v.begin(), v.end());

    return;
}

int main(){
    vector<Point>polygon1, polygon2;
    int n1, n2;
    scanf("%d",&n1);
    scan(polygon1, n1);

    scanf("%d",&n2);
    scan(polygon2, n2);


}
