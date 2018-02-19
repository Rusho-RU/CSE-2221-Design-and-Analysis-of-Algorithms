#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

vector<point>p;
stack<point>hullPoint;

int findGrahamPoint(){
    int gp = 0;

    for(int i=1; i<p.size(); i++)
        if(p[i].y < p[gp].y || (p[i].y == p[gp].y && p[i].x < p[gp].x))
            gp = i;

    return gp;
}

int ccw(const point& a, const point& b, const point& c){
    int val = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);

    if(val<0)
        return -1;
    if(val>0)
        return 1;
    return 0;
}

int dist(const point& a, const point& b){
    int x = a.x-b.x, y = a.y-b.y;

    return x*x + y*y;
}

bool cmp(const point& a, const point& b){
    int val = ccw(p[0],a,b);

    if(val==0)
        return dist(p[0], a) < dist(p[0], b);

    return val==1;
}

void reorder(){
    vector<point>::iterator it = p.begin();
    sort(++it, p.end(), cmp);
    return;
}

point nextToTop(){
    point hold = hullPoint.top();
    hullPoint.pop();
    point ret = hullPoint.top();
    hullPoint.push(hold);
    return ret;
}

void convexHull(){
    reorder();

    hullPoint.push(p[0]);
    hullPoint.push(p[1]);
    hullPoint.push(p[2]);

    for(int i=3; i<p.size(); i++){
        while(ccw(nextToTop(), hullPoint.top(), p[i])==-1)
            hullPoint.pop();

        hullPoint.push(p[i]);
    }

    return;
}

int main(){
    int numOfPoints;
    scanf("%d",&numOfPoints);

    for(int i=0; i<numOfPoints; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        p.push_back(point(x,y));
    }

    int grahamPoint = findGrahamPoint();
    swap(p[0], p[grahamPoint]);

    convexHull();

    while(!hullPoint.empty()){
        printf("%d %d\n",hullPoint.top().x, hullPoint.top().y);
        hullPoint.pop();
    }

    return 0;
}
