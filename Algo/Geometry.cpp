#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 3e5+10;

using T = double ;
const T INF = 1e100, EPS = 1e-9, PI = acos(-1.0);

int sign(T x)
{
    return (x>EPS)-(x<EPS);
}
typedef struct PT
{
    T x, y;
    PT() {};
    PT(T x, T y): x(x), y(y) {};
    PT(const PT &p): x(p.x), y(p.y) {};
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
    bool operator < (const PT &p )const
    {
        return x<p.x || x==p.x && y<p.y;
    }
    PT trunc(double t)const
    {
        double r = t/sqrt(x*x+y*y);

        if (sign(r)==0) return *this;
        return PT(x*r,y*r);
    }
} point;


struct circle
{
    PT p;
    double r;
};
typedef struct line
{
    PT p,q;
} segment;
typedef vector<PT> polygon;

T dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}
T dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
T norm2(PT p)
{
    return dot(p,p);
}
T norm(PT p)
{
    return sqrt(dot(p,p));
}
double distPoint(PT p, PT q)
{
    return sqrt(dot(p-q,p-q));
}
T cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
int orientation(PT a, PT b, PT c)
{
    return sign(cross(b-a,c-a));
}
PT orth(PT p)
{
    return PT(-p.y,p.x);
}
//------------------------------------------------------------------------
// rotate a point CCW or CW around the origin
//------------------------------------------------------------------------
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
PT RotateCW(PT p, double t)
{
    return PT(p.x*cos(t)+p.y*sin(t), -p.x*sin(t)+p.y*cos(t));
}
double angle(PT a, PT b)
{
    double costheta=dot(a,b)/a.val()/b.val();
    return acos(fmax(-1.0,fmin(1.0,costheta)));
}
double rad_to_deg(double r)
{
    return (r * 180.0 / PI);
}

double deg_to_rad(double d)
{
    return (d * PI / 180.0);
}
//Line Segment Utilities
//------------------------------------------------------------------------
// find a point from 'a' through 'b' with
// distance d
// use for better precision
//------------------------------------------------------------------------
PT PointAlongLine(PT a,PT b,double d)
{
    return a + (((b-a) / sqrt(dot(b-a,b-a))) * d);
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c)
{
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c)
{
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

// returns minimum distance from point p to line AB
double distToLine(PT p, PT A, PT B, PT &c)
{
    double scale = (double)(dot(p-A,B-A)) / (dot(B-A,B-A));
    c.x = A.x + scale * (B.x - A.x);
    c.y = A.y + scale * (B.y - A.y);
    return distPoint(p, c);
}
// return minimum distance from point p to line segment AB
double distToLineSegment(PT p, PT A, PT B, PT &c)
{
    if (dot(B-A,p-A) < EPS)
    {
        c.x = A.x;
        c.y = A.y;
        return distPoint(p, A);
    }
    if (dot(A-B,p-B) < EPS)
    {
        c.x = B.x;
        c.y = B.y;
        return distPoint(p, B);
    }
    return distToLine(p, A, B, c);
}

bool isPointOnSegment(PT p,PT a,PT b)
{
    if(fabs(cross(p-b,a-b))<EPS)
    {
        if(p.x<min(a.x,b.x)||p.x>max(a.x,b.x)) return false;
        if(p.y<min(a.y,b.y)||p.y>max(a.y,b.y)) return false;
        return true;
    }
    return false;
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d)
{
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d)
{
    return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d)
{
    return LinesParallel(a, b, c, d)
           && fabs(cross(a-b, a-c)) < EPS
           && fabs(cross(c-d, c-a)) < EPS;
}
//------------------------------------------------------------------------
// determine if line segment from a to b intersects with
// line segment from c to d
//------------------------------------------------------------------------
bool SegmentsIntersect(PT a, PT b, PT c, PT d)
{
    if (LinesCollinear(a, b, c, d))
    {
        if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
                dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
        if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
            return false;
        return true;
    }
    if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
    if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
    return true;
}
// check if two lines are same
bool areLinesSame(PT a, PT b, PT c, PT d)
{
    if(fabs(cross(a-c,c-d))<EPS && fabs(cross(b-c,c-d))<EPS) return true;
    return false;
}
// check if two lines are parallel
bool areLinesParallel(PT a, PT b, PT c, PT d)
{
    if(fabs(cross(a-b,c-d))<EPS) return true;
    return false;
}
//Line Line Intersection
//------------------------------------------------------------------------
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
//------------------------------------------------------------------------
PT ComputeLineIntersection(PT a, PT b, PT c, PT d)
{
    double a1,b1,c1,a2,b2,c2;
    a1 = a.y - b.y;
    b1 = b.x - a.x;
    c1 = cross(a, b);
    a2 = c.y - d.y;
    b2 = d.x - c.x;
    c2 = cross(c, d);
    double D = a1 * b2 - a2 * b1;
    return PT((b1 * c2 - b2 * c1) / D,(c1 * a2 - c2 * a1) / D);
}
///Parallel and Tangent Line of a LIne
//------------------------------------------------------------------------
// Return a parallel line of line ab in counterclockwise
// direction with d distance from ab
//------------------------------------------------------------------------
pair<PT,PT> getParallelLine(PT a,PT b,double d)
{
    return make_pair(PointAlongLine(a,RotateCCW90(b-a)+a,d),PointAlongLine(b,RotateCW90(a-b)+b,d));
}

//------------------------------------------------------------------------
// Return a tangent line of line ab which intersects
// with it at point c in counterclockwise direction
//------------------------------------------------------------------------
pair<PT,PT> getTangentLine(PT a,PT b,PT c)
{
    return make_pair(RotateCCW90(a-c)+c,RotateCCW90(b-c)+c);
}

//Point In Polygon
//------------------------------------------------------------------------
// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
//------------------------------------------------------------------------
bool PointInPolygon(const vector<PT> &p, PT q)
{
    bool c = 0;
    int s=p.size();
    for (int i = 0,j=s-1; i < s; j=i++)
    {
        if ( ( (p[i].y > q.y) != (p[j].y > q.y ) ) &&
                (q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y)))
            c = !c;
    }
    return c;
}
//-----------------------------------------------------------------------------
// polygon contains a point
// half-line crossing method
//-----------------------------------------------------------------------------
int contains(polygon ps, PT p)
{
    bool in = false;
    for (int i = 0; i < ps.size(); ++i)
    {
        int j = (i+1 == ps.size() ? 0 : i+1);
        point a = ps[i] - p, b = ps[j] - p;
        if (a.y > b.y) swap(a, b);
        if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
        if (!sign(cross(a, b)) && sign(dot(a, b)) <= 0)
            return 0; // point on the edge
    }
    return in ? -1 : 1; // point in:out the polygon
}
///Is Point on Polygon
//------------------------------------------------------------------------
// determine if point is on the boundary of a polygon
//------------------------------------------------------------------------
bool PointOnPolygon(const vector<PT> &p, PT q)
{
    int s=p.size();
    for (int i = 0,j=s-1; i < s; j=i++)
        if (isPointOnSegment(q,p[j],p[i]))
            return true;
    return false;
}

//------------------------------------------------------------------------
// tests whether or not a given polygon (in CW or CCW order) is simple
//------------------------------------------------------------------------
bool IsSimple(const vector<PT> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        for (int k = i+1; k < p.size(); k++)
        {
            int j = (i+1) % p.size();
            int l = (k+1) % p.size();
            if (i == l || j == k) continue;
            if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
                return false;
        }
    }
    return true;
}


//Centroid of Polygon
//------------------------------------------------------------------------
// This code computes the area or centroid of a (possibly non-convex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
//------------------------------------------------------------------------
double ComputeSignedArea(const vector<PT> &p)
{
    double area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area / 2.0;
}

double ComputeArea(const vector<PT> &p)
{
    return fabs(ComputeSignedArea(p));
}

PT ComputeCentroid(const vector<PT> &p)
{
    PT c(0,0);
    double scale = 6.0 * ComputeSignedArea(p);
    for (int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
    }
    return c / scale;
}
///Geometric Median
//------------------------------------------------------------------------
// geometric median, i.e., p in argmin sum |ps[i] - p|_2
// sum of distance from point p to all point is minimum
// Weiszfield's iterative reweighted method least squares
// with avoiding equal points
//------------------------------------------------------------------------
point geometric_median(vector<point> ps)
{
    point g = {0,0};
    double eta = 1000.0;
    for (int iter = 0; iter < 1000000; ++iter, eta /= 2)
    {
        double w = 0;
        point h = {0,0};
        for (point p: ps)
        {
            double a = eta + norm(p - g);
            h = h + p/a;
            w = w + 1/a;
        }
        h = h / w;
        swap(g, h);
        if (norm(g - h) < EPS) break;
    }
    return g;
}
///Polygon Half-Plane Intersection
//------------------------------------------------------------------------
// intersection of half-plane and polygon
//------------------------------------------------------------------------
vector<PT> polygonCut(const vector<PT> &poly, PT a, PT b)
{
    vector<PT> ret;
    int s=(int)poly.size();
    for(int i=0; i<s; i++)
    {
        double c1=cross(ln.second-ln.first,poly[i]-ln.first);
        double c2=cross(ln.second-ln.first,poly[(i+1)%s]-ln.first);
        if(sign(c1)>=0) ret.push_back(poly[i]);
        if(sign(c1*c2)<0)
        {
            if(!areLinesParallel(poly[i],poly[(i+1)%s],ln.first,ln.second))
            {
                ret.push_back(ComputeLineIntersection(poly[i],poly[(i+1)%s],ln.first,ln.second));
            }
        }
    }
    return ret;
}
///Convex Hull
void ConvexHull(vector<PT> &v)
{
    sort(v.begin(), v.end());
    vector<PT> up, dn;
    for (auto& p : v)
    {
        while (up.size() > 1 && orientation(up[up.size() - 2], up.back(), p) >= 0)
        {
            up.pop_back();
        }
        while (dn.size() > 1 && orientation(dn[dn.size() - 2], dn.back(), p) <= 0)
        {
            dn.pop_back();
        }
        up.push_back(p);
        dn.push_back(p);
    }
    v = dn;
    v.pop_back();
    reverse(up.begin(), up.end());
    up.pop_back();
    for (auto& p : up)
    {
        v.push_back(p);
    }
}
///Center of Circle Through 3 Points
//------------------------------------------------------------------------
// compute center of circle passing through three point a, b and c
// or circumcenter of triangle abc
//------------------------------------------------------------------------
PT ComputeCircleCenter(PT a, PT b, PT c)
{
    b=(a+b)/2;
    c=(a+c)/2;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}
///Circle Circle Intersection
//------------------------------------------------------------------------
// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
//------------------------------------------------------------------------
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}
///Circle Segment Intersection
//-----------------------------------------------------------------------------
// intersection of segment and circle
// number of points:
//   0 ==> no intersect
//   1 ==> touch
//   2 ==> contained
//   3 ==> penetrating single side
//   4 ==> penetrating both sides
// sorted from s.p to s.q; usually, one would use ans[0] and ans.back().
//-----------------------------------------------------------------------------
vector<point> CircleSegmentIntersection(circle c, segment s)
{
    point u = s.q - s.p, v = s.p - c.p;
    auto a = dot(u,u), b = dot(u,v)/a, t = (dot(v,v) - c.r*c.r)/a;
    auto det = b*b - t;
    if (sign(det) <  0) return {};          // no solution

    auto t1 = -b - sqrt(det), t2 = -b + sqrt(det);
    vector<point> ps;
    auto insert_if_possible = [&](point p)
    {
        for (auto q: ps) if (sign(dot(p-q, p-q)) == 0) return;
        ps.push_back(p);
    };
    if (sign(c.r - norm(s.p-c.p))   >= 0) insert_if_possible(s.p);
    if (sign(t1) >= 0 && sign(1-t1) >= 0) insert_if_possible(s.p+t1*u);
    if (sign(t2) >= 0 && sign(1-t2) >= 0) insert_if_possible(s.p+t2*u);
    if (sign(c.r - norm(s.q-c.p))   >= 0) insert_if_possible(s.q);
    return ps;
}
//Circle Circle Relation
//------------------------------------------------------------------------
// 5 - outside and do not intersect
// 4 - intersect outside in one point
// 3 - intersect in 2 points
// 2 - intersect inside in one point
// 1 - inside and do not intersect
//------------------------------------------------------------------------
int circle_circle_relation(PT a,double r,PT b,double R)
{
    double d=dist(a,b);
    if (sign(d-r-R)>0)  return 5;
    if (sign(d-r-R)==0) return 4;
    double l=fabs(r-R);
    if (sign(d-r-R)<0&&sign(d-l)>0) return 3;
    if (sign(d-l)==0) return 2;
    if (sign(d-l)<0) return 1;
}
//Circle Circle Intersection area
//------------------------------------------------------------------------
// returns area of intersection between two circles centered at a and b
// with radius r1 and r2 respectiveily
//------------------------------------------------------------------------
double circle_circle_area(PT a,double r1,PT b,double r2)
{
    circle u(a,r1),v(b,r2);
    int rel=circle_circle_relation(a,r1,b,r2);
    if (rel>=4) return 0.0;
    if (rel<=2) return min(PI*r1*r1,PI*r2*r2);
    double d=dist(a,b);
    double hf=(r1+r2+d)/2.0;
    double ss=2.0*sqrt(hf*(hf-r1)*(hf-r2)*(hf-d));
    double a1=acos((r1*r1+d*d-r2*r2)/(2.0*r1*d));
    a1=a1*r1*r1;
    double a2=acos((r2*r2+d*d-r1*r1)/(2.0*r2*d));
    a2=a2*r2*r2;
    return a1+a2-ss;
}
//Circle Polygon Intersection Area
//-----------------------------------------------------------------------------
// circle-polygon intersection area
//-----------------------------------------------------------------------------
double intersection_area(vector<point> ps, circle c)
{
    auto tri = [&](point p, point q)
    {
        point d = q - p;
        auto a = dot(d,p)/dot(d,d), b = (dot(p,p)-c.r*c.r)/dot(d,d);
        auto det = a*a - b;
        if (det <= 0) return arg(p,q) * c.r*c.r / 2;
        auto s = max(0.l, -a-sqrt(det)), t = min(1.l, -a+sqrt(det));
        if (t < 0 || 1 <= s) return c.r*c.r*arg(p,q)/2;
        point u = p + s*d, v = p + t*d;
        return arg(p,u)*c.r*c.r/2 + cross(u,v)/2 + arg(v,q)*c.r*c.r/2;
    };
    auto sum = 0.0;
    for (int i = 0; i < ps.size(); ++i)
        sum += tri(ps[i] - c.p, ps[(i+1)%ps.size()] - c.p);
    return sum;
}
//Tangent Lines of Circle From Point
//------------------------------------------------------------------------
// tangent lines from point q to circle with center p and radius r
//------------------------------------------------------------------------
int tangent_lines_from_point(PT p,double r,PT q,line &u,line &v)
{
    int x = sign(dist2(p,q)-r*r);
    if (x<0) return 0; //point in cricle
    if (x==0) //point on circle
    {
        u=line(q,q+rotateccw90(q-p));
        v=u;
        return 1;
    }
    double d=dist(p,q);
    double l=sqr(r)/d;
    double h=sqrt(sqr(r)-sqr(l));
    u=line(q,p+((q-p).trunc(l)+(rotateccw90(q-p).trunc(h))));
    v=line(q,p+((q-p).trunc(l)+(rotatecw90(q-p).trunc(h))));
    return 2;
}
//Common Tangent of Two Circle
//-----------------------------------------------------------------------------
// common tangents of two circles
//-----------------------------------------------------------------------------
vector<line> tangent(circle c, circle d)
{
    if (c.r < d.r) swap(c, d);
    auto g = dot(c.p-d.p, c.p-d.p);
    if (sign(g) == 0) return {}; // same origin
    point u = (d.p-c.p)/sqrt(g), v = orth(u); // coordinate systems
    vector<line> ls;
    for (int s = +1; s >= -1; s -= 2)
    {
        auto h = (c.r+s*d.r)/sqrt(g); // = cos(theta)
        if (sign(1 - h*h) == 0)   // touch inner/outer
        {
            ls.push_back({c.p+c.r*u, c.p+c.r*(u+v)});
        }
        else if (sign(1 - h*h) > 0)   // properly intersect
        {
            point uu = h*u, vv = sqrt(1-h*h)*v;
            ls.push_back({c.p+c.r*(uu+vv), d.p-d.r*(uu+vv)*s});
            ls.push_back({c.p+c.r*(uu-vv), d.p-d.r*(uu-vv)*s});
        }
    }
    return ls;
}
///Maximum Circle Cover
//-----------------------------------------------------------------------------
// find a circle of radius r that contains many points as possible
//-----------------------------------------------------------------------------
int maximum_circle_cover(vector<point> ps, double r)
{
    const double dx[] = {1,-1,-1,1}, dy[] = {1,1,-1,-1};
    point best_p;
    int best = 0;
    function<void(point,double,vector<point>)>
    rec = [&](point p, double w, vector<point> ps)
    {
        w /= 2;
        point qs[4];
        vector<point> pss[4];
        for (int i = 0; i < 4; ++i)
        {
            qs[i] = p + w * point({dx[i], dy[i]});
            int lo = 0;
            for (point q: ps)
            {
                auto d = dist(qs[i], q);
                if (sign(d - r) <= 0) ++lo;
                if (sign(d - w*sqrt(2) - r) <= 0) pss[i].push_back(q);
            }
            if (lo > best)
            {
                best = lo;
                best_p = qs[i];
            }
        }
        for (int i = 0, j; i < 4; ++i)
        {
            for (int j = i+1; j < 4; ++j)
                if (pss[i].size() < pss[j].size())
                    swap(pss[i], pss[j]), swap(qs[i], qs[j]);
            if (pss[i].size() <= best) break;
            rec(qs[i], w, pss[i]);
        }
    };
    double w = 0;
    for (point p: ps) w = max(w, max(abs(p.x), abs(p.y)));
    rec({0,0}, w, ps);
    return best; //best_p;
}


///Half-Plane Intersection
struct HP
{
    PT p, v;
    double arg;
    HP() {}
    HP(PT a, PT b): p(a), v(b-a), arg(atan2(v.y, v.x)) {}
    bool operator < (const HP &h) const
    {
        return arg < h.arg;
    }
    friend PT intersection(HP a, HP b)
    {
        double t = cross(b.v, a.p - b.p) / cross(a.v, b.v);
        return a.p + a.v*t;
    }
};
/*
    -> Consider half-plane of counter-clockwise side of each line
    -> If lines are not bounded add infinity rectangle
    -> Replace eps with -eps to include polygon of zero area (straight line)
    -> Colplexity O(n log(n))
*/
vector<PT> halfPlaneIntersection(vector<HP> h)
{
    int n = (int)h.size(), l=0, r=-1;
    sort(h.begin(), h.end());
    vector<PT> hull, p(n);
    HP q[n];
    q[++r] = h[0];
    for (int i = 1; i < n; i++)
    {
        while (l < r && cross(h[i].v, p[r-1] - h[i].p) < eps) r--; //-eps
        while (l < r && cross(h[i].v, p[l] - h[i].p) < eps) l++; //-eps
        q[++r] = h[i];
        if (fabs(cross(q[r].v, q[r-1].v)) < eps)
        {
            r--;
            if ( cross(q[r].v, h[i].p - q[r].p) >= eps) q[r] = h[i]; //-eps
        }
        if (l < r) p[r-1] = intersection(q[r-1], q[r]);
    }
    while (l < r && cross(q[l].v, p[r-1] - q[l].p) < eps) r--; //-eps
    if (r-l <= 1) return hull;
    p[r] = intersection(q[l], q[r]);
    while (l <= r) hull.push_back(p[l++]);
    return hull;
}
///Minkowski Sum
// a and b are Convex-Hull of distinct points
//Overload == operator of points
vector<PT> minkowskiSum(vector<PT>a, vector<PT> b)
{
    int n = (int)a.size(), m = (int)b.size();
    int i = 0, j = 0; //assuming a[i] and b[j] are left and bottom most point
    vector<PT> c;
    /*
    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            c.push_back(a[i]+b[j]);
        }
    }
    convexHull(c);
    return c;
    */
    c.push_back(a[i] + b[j]);
    while (i+1<n || j+1<m)
    {
        PT p1 = a[i] + b[(j + 1) % m];
        PT p2 = a[(i +1 ) % n] + b[j];
        int t = dir(c.back(), p1, p2);
        if (t >= 0) j = (j + 1) % m;
        if (t <= 0) i = (i + 1) % n, p1 = p2;
        if (t == 0) p1 = a[i] + b[j];
        if (p1 == c[0]) break;
        c.push_back(p1);
    }
    return c;
}

///Maximum Distance Between Two Convex Polygons
int maxDist2(vector<PT> u, vector<PT> v)
{
    convexHull(u);
    convexHull(v);
    int n = (int)u.size(), m = (int)v.size();
    int dist = 0;
    if (n<3 || m<3)
    {
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<m; j++)
                dist = max(dist, dist2(u[i], v[j]));
        }
        return dist;
    }
    if (u[0].x>v[0].x) swap(n,m), swap(u,v);
    int i = 0,j = 0,step = n+m+10;
    while (j+1<m && v[j].x<v[j+1].x) j++;
    while (step--)
    {
        if(cross(u[(i+1)%n]-u[i],v[(j+1)%m]-v[j])>=0) j = (j+1)%m;
        else i = (i+1)%n;
        dist = max(dist, dist2(u[i],v[j] ));
    }
    return dist;
}
///Minimum Distance Between Point and Convex Polygon
namespace PolyQuery
{
int pointInTriangle(PT a, PT b, PT c, PT p)
{
    if (sign(cross(b-a,c-a))<0) swap(b,c);
    int c1 = sign(cross(b-a,p-a));
    int c2 = sign(cross(c-b,p-b));
    int c3 = sign(cross(a-c,p-c));
    if (c1<0 || c2<0 || c3<0) return 1;//outside triangle
    if (c1+c2+c3!=3) return 0;//on boundary
    return -1;//strictly inside;
}
/*
    ->Polygon must be strictly convex
    -> returns -1: strictly inside, 0: on boundary , 1: outside of the polygon
*/
int pointInPolygon(vector<PT> &v, PT p)
{
    int n = (int)v.size();
    if (sign(cross(v[1]-v[0],p-v[0]))<0 || cross(v[n-1]-v[0],p-v[0])>0) return 1;
    int pw = 1,i = 1,j;
    while (pw<=n) pw<<=1;
    while ((pw>>=1)) if ((j=i+pw)<n)
        {
            if (sign(cross(v[j]-v[0],p-v[0]))>0) i = j;
        }
    j = (i+1);
    if (pointInTriangle(v[0],v[i],v[j],p)>0) return 1;
    if (i==1 && sign(cross(v[i]-v[0],p-v[0]))==0) return 0;
    if (sign(cross(v[j]-v[i],p-v[i]))==0) return 0;
    if (j==n-1 && sign(cross(v[0]-v[j],p-v[j]))==0) return 0;
    return -1;
}

double distFunc(PT a, PT b, PT c)
{
    double d = min(dist2(a,c),dist2(b,c));
    //return d; //for minimum vertex distance return here
    double t = dot(b-a,c-a)/dot(b-a,b-a);
    t = max(0.0,min(t,1.0));
    d = min(d, dist2(a+(b-a)*t, c));
    return d;
}
PT angleBisector(PT &a, PT &b, PT &c)
{
    PT p = a-b, q = c-b;
    return p + q*sqrt(dot(p,p)/dot(q,q));
}
//minimum distance between convex polygon and point
//assume point does not lie strictly inside the polygon
double minDist2(vector<PT> &v, PT p)
{
    int n = (int)v.size();
    PT bi,bl = angleBisector(v[n-1],v[0],v[1]);
    int ok, i, pw=1, l = 0, si, sl = sign(cross(bl,p-v[0]));
    while (pw<=n) pw<<=1;
    while ((pw>>=1)) if ((i=l+pw)<n)
        {
            bi = angleBisector(v[i-1],v[i],v[(i+1)%n]);
            si = sign(cross(bi,p-v[i]));
            ok = sign(cross(bl,bi))>=0? (sl>=0 || si<=0) : (sl>=0 && si<=0);
            if (ok) l = i, bl = bi, sl = si;
        }
    return distFunc(v[l], v[(l+1)%n],p);
}
}


///Closest Pair of Points
#define px second
#define py first
typedef pair<long long, long long> pairll;
pairll pnts [MAX];
int compare(pairll a, pairll b)
{
    return a.px<b.px;
}
double closest_pair(pairll pnts[],int n)
{
    sort(pnts,pnts+n,compare);
    double best=INF;
    set<pairll> box;
    box.insert(pnts[0]);
    int left = 0;
    for (int i=1; i<n; ++i)
    {
        while (left<i && pnts[i].px-pnts[left].px > best)
            box.erase(pnts[left++]);
        for(typeof(box.begin()) it=box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best)); it!=box.end() && pnts[i].py+best>=it->py; it++)
            best = min(best, sqrt(pow(pnts[i].py - it->py, 2.0)+pow(pnts[i].px - it->px, 2.0)));
        box.insert(pnts[i]);
    }
    return best;
}

//-----------------------------------------------------------------------------
// find the closest pair of points by sweepline
// remember to overload < and == operator of points
//-----------------------------------------------------------------------------
pair<point,point> closest_pair(vector<point> ps)
{
    sort(all(ps), [](point p, point q)
    {
        return p.y < q.y;
    });
    auto u = ps[0], v = ps[1];
    auto best = dot(u-v, u-v);
    auto update = [&](point p, point q)
    {
        auto dist = dot(p-q, p-q);
        if (best > dist)
        {
            best = dist;
            u = p;
            v = q;
        }
    };
    set<point> S;
    S.insert(u);
    S.insert(v);
    for (int l = 0, r = 2; r < ps.size(); ++r)
    {
        if (S.count(ps[r])) return {ps[r], ps[r]};
        if ((ps[l].y-ps[r].y)*(ps[l].y-ps[r].y) > best) S.erase(ps[l++]);
        auto i = S.insert(ps[r]).fst;
        for (auto j = i; ; ++j)
        {
            if (j == S.end() || (i->x-j->x)*(i->x-j->x) > best) break;
            if (i != j) update(*i, *j);
        }
        for (auto j = i; ; --j)
        {
            if (i != j) update(*i, *j);
            if (j == S.begin() || (i->x-j->x)*(i->x-j->x) > best) break;
        }
    }
    return {u, v};
}

//Delaunay Triangulation
//-----------------------------------------------------------------------------
// delaunay triangulation
// O(n^2) in the worst case, O(n log n) -- O(n sqrt(n)) in pratice.
// [verified: RUPC 2013 F]
//  1. The Euclidean minimum spanning tree of a set of points is a subset of
//     the Delaunay triangulation of the same points, and this can be exploited
//     to compute it efficiently.
//  2. The union of all simplices in the triangulation is the convex hull of the
//     points. The Delaunay triangulation contains O(n⌈d / 2⌉) simplices.
//  3. In the plane, the Delaunay triangulation maximizes the minimum angle.
//  4. A circle circumscribing any Delaunay triangle does not contain any other
//     input points in its interior.
//-----------------------------------------------------------------------------
struct delaunay
{
    struct edge
    {
        int src, dst;
    };
    int n;
    vector<point> ps;
    vector<vector<edge>> adj; // optional
    vector<int> inner;
    int incircle(int a, int b, int c, int p)
    {
        point u = ps[a]-ps[p], v = ps[b]-ps[p], w = ps[c]-ps[p];
        return sign(norm2(u)*cross(v,w)
                    +norm2(v)*cross(w,u)
                    +norm2(w)*cross(u,v)) > 0;
    }
    bool orient(int a, int b, int p)
    {
        point u = ps[a]-ps[b], v = ps[p]-ps[b];
        int s = sign(cross(u, v));
        return s ? s > 0 : sign(dot(u, v)) > 0;
    }
    delaunay(vector<point> ps) : n(ps.size()), ps(ps), adj(n), inner(n)
    {
        if (n <= 1) return;
        vector<unordered_map<int,int>> ccw(n); // ccw[u][v] is the third pt for (u,v)
        auto make_triangle = [&](int a, int b, int c)
        {
            ccw[a][b] = c;
            ccw[b][c] = a;
            ccw[c][a] = b;
        };
        vector<int> is(n);
        iota(all(is), 0);
        sort(all(is), [&](int i, int j)
        {
            return ps[i] < ps[j];
        });
        // delaunay flips
        function<void(int,int)> rec = [&](int a, int b)
        {
            if (!ccw[a].count(b) || !ccw[b].count(a)) return;
            int c = ccw[a][b], d = ccw[b][a];
            if (incircle(a, b, c, d) > 0)
            {
                ccw[a].erase(b);
                ccw[b].erase(a);
                make_triangle(d, c, a);
                make_triangle(c, d, b);
                rec(a, d);
                rec(d, b);
                rec(b, c);
                rec(c, a);
            }
        };
        // lexicographic triangulation
        vector<int> next(n,-1), prev(n,-1);
        next[is[0]] = prev[is[0]] = is[1];
        next[is[1]] = prev[is[1]] = is[0];
        for (int i = 2; i < n; ++i)
        {
            int h = is[i], u = is[i-1], v = u;
            while ( orient(u, next[u], h)) u = next[u];
            while (!orient(v, prev[v], h)) v = prev[v];
            for (int w = v; w != u; w = next[w])
                if (sign(cross(ps[next[w]]-ps[h], ps[w]-ps[h])) > 0)
                    make_triangle(w, h, next[w]);
            next[h] = u;
            prev[u] = h;
            prev[h] = v;
            next[v] = h;
        }
        for (int u: is)
        {
            auto nbh = ccw[u]; // hardcopy
            for (auto z: nbh) rec(z.fst, z.snd); // flip
        }
        // complete graph structure
        for (int u: is)
        {
            int v = ccw[u].begin()->fst, s = v;
            while (ccw[s].count(u))
            {
                s = ccw[s][u];
                if (s == v) break;
            } // v != s means that u is on the outer face
            if (v != s)
            {
                inner[u] = false;
                v = s;
            }
            do
            {
                adj[u].push_back({u, v});
                if (!ccw[u].count(v)) break;
                v = ccw[u][v];
            }
            while (v != s);
        }
    }
};

///Voronoi Diagram
//-----------------------------------------------------------------------------
// voronoi diagram (from delaunay triangulation)
// O(sum deg^2) = O(n^2) in worst case, O(n) for random input.
// [verified: RUPC 2013 F]
// * Voronoi diagrams can be used to find the largest empty circle amid a set
//   of points, and in an enclosing polygon;
//-----------------------------------------------------------------------------
struct voronoi
{
    struct edge
    {
        int src, dst;
        real len;
    };
    int n, m;
    vector<point> ps, qs; // qs is the voronoi vertices
    map<point,int> id;
    vector<vector<int>> cell;
    vector<vector<edge>> adj;
    void add_edge(int u, int v)
    {
        auto len = norm(qs[u] - qs[v]);
        adj[u].push_back({u, v, len});
        adj[v].push_back({v, u, len});
    }
    int node(point p)
    {
        if (!id.count(p))
        {
            id[p] = m++;
            qs.push_back(p);
            adj.push_back({});
        }
        return id[p];
    }
    voronoi(delaunay DT, vector<point> domain) :
        n(DT.n), m(0), ps(DT.ps), cell(n)
    {
        for (int u = 0; u < n; ++u)
        {
            vector<point> region = domain;
            for (auto e: DT.adj[u])
            {
                point s = (ps[e.src]+ps[e.dst])/2, d = orth(ps[e.dst]-ps[e.src]);
                region = convex_cut(region, {s, s+d});
            }
            for (int i = 0; i < region.size(); ++i)
            {
                add_edge(node(region[i]), node(region[(i+1)%region.size()]));
                cell[u].push_back(node(region[i]));
            }
        }
    }
    voronoi(vector<point> ps, vector<point> domain) :
        voronoi(delaunay(ps), domain) { }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

}
