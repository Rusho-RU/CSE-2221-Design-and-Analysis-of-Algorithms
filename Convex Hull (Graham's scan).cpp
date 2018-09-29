#include <bits/stdc++.h>
using namespace std;

#define eps 0.000001

struct Point{
    double x, y;
    Point(double _x, double _y){
        this->x = _x;
        this->y = _y;
    }

    Point(){}
};

Point bottomLeft;

bool isSame(double a, double b){
    return abs(a-b) < eps;
}

int findGrahamPoint(vector<Point>& polygon){
    int gp = 0;
    for(int i=1; i<polygon.size(); i++)
        if(polygon[i].y < polygon[gp].y || (isSame(polygon[i].y, polygon[gp].y) && polygon[i].x < polygon[gp].x))
            gp = i;
    return gp;
}

double cross(const Point& a, const Point& b, const Point& c){
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

double dist(const Point& a, const Point& b){
    double x = a.x-b.x, y = a.y-b.y;
    return x*x + y*y;
}

bool cmp(const Point& a, const Point& b){
    double val = cross(bottomLeft,a,b);

    if(isSame(val, 0))
        return dist(bottomLeft, a) < dist(bottomLeft, b);

    return val>1;
}

void reorder(vector<Point>& polygon){
    vector<Point>::iterator it = polygon.begin();
    sort(++it, polygon.end(), cmp);
    return;
}

Point nextToTop(stack<Point>& hullPoint){
    Point hold = hullPoint.top();
    hullPoint.pop();
    Point ret = hullPoint.top();
    hullPoint.push(hold);
    return ret;
}

void convexHull(vector<Point>& polygon, stack<Point>& hullPoint){
    int gp = findGrahamPoint(polygon);
    swap(polygon[0], polygon[gp]);
    bottomLeft = polygon[0];
    reorder(polygon);

    hullPoint.push(polygon[0]);
    hullPoint.push(polygon[1]);
    hullPoint.push(polygon[2]);

    for(int i=3; i<polygon.size(); i++){
        while(cross(nextToTop(hullPoint), hullPoint.top(), polygon[i]) < 0)
            hullPoint.pop();

        hullPoint.push(polygon[i]);
    }

    return;
}

int main(){
    int numOfPoints;
    scanf("%d",&numOfPoints);

    vector<Point>polygon;
    stack<Point>hullPoint;

    for(int i=0; i<numOfPoints; i++){
        double x,y;
        scanf("%lf %lf",&x,&y);
        polygon.push_back(Point(x,y));
    }

    convexHull(polygon, hullPoint);

    while(!hullPoint.empty()){
        printf("%lf %lf\n",hullPoint.top().x, hullPoint.top().y);
        hullPoint.pop();
    }

    return 0;
}
