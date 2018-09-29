#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x, y;
    Point(double _x, double _y):x(_x), y(_y){}
    Point(){}
};

double cross(const Point& a, const Point& b, const Point& c){
    return (b.x - a.x)*(c.y - b.y) - (c.x - b.x)*(b.y - a.y);
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

///This function clips all edges with respect to clipper polygon's one edge
void clip(const Point& p1, const Point& p2, vector<Point>& polygon){
    int n = polygon.size();
    Point p3, p4;
    vector<Point>clipped;

    for(int a=0; a<n; a++){
        int b = (a+1)%n;
        p3 = polygon[a];
        p4 = polygon[b];

        double orientation_of_a = cross(p1, p2, p3);
        double orientation_of_b = cross(p1, p2, p4);

        ///Case 1: Both points are inside
        if(orientation_of_a<=0 && orientation_of_b<=0){
            ///Point b is added
            clipped.push_back(p4);
        }

        ///Case 2: Point a is outside, b is inside
        else if(orientation_of_a>0 && orientation_of_b<=0){
            ///Point of intersection and point b is added
            Point crossed = coordinate_of_intersection(p1, p2, p3, p4);
            clipped.push_back(crossed);
            clipped.push_back(p4);
        }

        ///Case 3: Point a is inside, b is outside
        else if(orientation_of_a<=0 && orientation_of_b>0){
            Point crossed = coordinate_of_intersection(p1, p2, p3, p4);
            clipped.push_back(crossed);
        }

        ///Case 4: Both points are outside
        else{
            ///Do nothing
        }
    }

    polygon = clipped;

    return;
}

///When returning, clipped holds the coordinates of clipped polygon
///This function returns clipped clipped w.r.t. clipper
void SutherlandHodgman(const vector<Point>& clipper, vector<Point>& clipped){
    int n = clipper.size();

    for(int a=0; a<n; a++){
        int b = (a+1)%n;
        clip(clipper[a], clipper[b], clipped);
    }

    return;
}
