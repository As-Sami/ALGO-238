#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y;

    Point(){
        x = y = 0;
    }
    Point(int _x, int _y){
        x = _x, y = _y;
    }

    Point operator - (Point p){
        return Point(x-p.x , y-p.y);
    }

    bool operator < (Point p){
        if( x==p.x ) return y<p.y;

        return x<p.x;
    }
};

bool is_anticlockwise(Point a, Point b, Point c){

    Point AB( b-a );
    Point BC( c-b );

    int cross_product = AB.x*BC.y - AB.y*BC.x;

    return cross_product > 0;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> v(n);
    for(int i=0 ; i<n ; i++ ){
        int x,y;
        cin >> x >> y;
        v[i] = Point(x,y);
    }

    sort(v.begin(), v.end());

    vector<Point> ans;
    for( int i=0 ; i<n ; i++ ){
        if( ans.size() < 2 ){
            ans.push_back(v[i]);
        }else{

            Point p1 = ans[ans.size()-2];
            Point p2 = ans[ans.size()-1];
            Point p3 = v[i];

            if( is_anticlockwise(p1, p2, p3) ){
                ans.push_back(p3);
            }else{
                ans.pop_back();
                i--;
            }
        }
    }

    reverse(v.begin(), v.end());

    vector<Point> ans1;
    for( int i=0 ; i<n ; i++ ){
        if( ans1.size() < 2 ){
            ans1.push_back(v[i]);
        }else{

            Point p1 = ans1[ans1.size()-2];
            Point p2 = ans1[ans1.size()-1];
            Point p3 = v[i];

            if( is_anticlockwise(p1, p2, p3) ){
                ans1.push_back(p3);
            }else{
                ans1.pop_back();
                i--;
            }
        }
    }

    ans.pop_back();
    ans1.pop_back();

    vector<Point> convex_hull;

    for(int i=0 ; i<ans.size() ; i++ ) 
        convex_hull.push_back(ans[i]);
    for(int i=0 ; i<ans1.size() ; i++ ) 
        convex_hull.push_back(ans1[i]);

    cout << convex_hull.size() << endl;
    for(int i=0 ; i<convex_hull.size() ; i++ )
        cout << convex_hull[i].x << ' ' << convex_hull[i].y << endl;

    return 0;
}

/*
8 
7 7 
7 -7 
-7 -7 
-7 7 
9 0 
-9 0 
0 9 
0 -9


Here's some more test data:

Here's some test data:

Test 1

8 
7 7 
7 -7 
-7 -7 
-7 7 
9 0 
-9 0 
0 9 
0 -9

Test 2

16 
7 7 
7 -7 
-7 -7 
-7 7 
9 0 
-9 0 
0 9 
0 -9 
0 0 
1 2 
-2 1 
-1 -1 
3 4 
4 3 
-5 4 
6 5


Test 3

72 = n
0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 0 0 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 1 1 2 2 3 3 4 4 5 5 6 6 1 -1 2 -2 3 -3 4 -4 5 -5 6 -6 -1 1 -2 2 -3 3 -4 4 -5 5 -6 6 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 -6

All answers are the same: 
8 
(0, -9) 
(7, -7) 
(9, 0) 

(7, 7) 
(0, 9) 
(-7, 7) 

(-9, 0) 
(-7, -7)

*/