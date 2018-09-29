#include <bits/stdc++.h>
using namespace std;

#define eps 0.00001

struct Point{
    double x, y;
    Point(double _x, double _y):x(_x), y(_y){}
    Point(){}
};

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

bool cmp(const Point& a, const Point& b){
    if(abs(a.x-b.x) < eps)
        return a.y<b.y;
    return a.x<b.x;
}

bool Same(double a, double b){
    if(abs(a-b) < eps) return true;
    return false;
}

double cross(const Point& a, const Point& b, const Point& c){
    return (b.x - a.x)*(c.y - b.y) - (c.x - b.x)*(b.y - a.y);
}

bool lineIntersected(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
    double pos_of_a = cross(p1, p2, p3);
    double pos_of_b = cross(p1, p2, p4);

    if(pos_of_a * pos_of_b < 0)
        return false;

    return true;
}

Point coordinate_of_intersection(const Point& p1, const Point& p2, const Point& p3, const Point& p4){
    double a1 = p2.y - p1.y;
    double b1 = p1.x - p2.x;
    double c1 = a1*p1.x + b1*p1.y;

    double a2 = p4.y - p3.y;
    double b2 = p3.x - p4.x;
    double c2 = a2*p3.x + b2*p3.y;

    double determinant = a1*b2 - a2*b1;

    if(determinant==0)
        return Point();

    double x = (c1*b2 - c2*b1)/determinant;
    double y = (c2*a1 - c1*a2)/determinant;

    return Point(x, y);
}

bool InPolygon(const vector<Point>& polygon, Point p){
    int n = polygon.size();

    for(int i=0; i<n; i++){
        int j = (i+1)%n;
    }
}

void WeilerAtherton(vector<Point>& clipper, vector<Point>& clipped){
    int n1 = clipper.size(), n2 = clipped.size();
    vector<Point>clippedPolygon;

    for(int i=0; i<n1; i++){
        int j = (i+1)%n1;
        for(int k=0; k<n2; k++){
            int l = (k+1)%n2;
            if(lineIntersected(clipper[i], clipper[j], clipped[k], clipped[l])){
                clippedPolygon.push_back(coordinate_of_intersection(clipper[i-1], clipper[i], clipped[j-1], clipped[j]));
            }
        }
    }
}

int main(){
    int n;
    vector<Point>clipper, clipped;

    freopen("myfile.txt", "w", stdout);

    while(scanf("%d",&n) && n>2){
        scan(clipper, n);

        scanf("%d",&n);
        scan(clipped, n);

        WeilerAtherton(clipper, clipped);

        if(clipped.empty())
            puts("0");

        else{
            sort(clipped.begin(), clipped.end(), cmp);

            printf("%d\n",clipped.size());
            for(int i=0; i<clipped.size(); i++){
                printf("%0.2lf %0.2lf\n",clipped[i].x, clipped[i].y);
            }
        }
    }

    return 0;
}

