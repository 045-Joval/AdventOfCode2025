#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;
using ll = long long;

vector<pii> pts;


bool pointOnSegment(double px, double py, const pii &A, const pii &B) {
    if (A.first == B.first) { 
        if (fabs(px - A.first) > 1e-9) return false;
        double ymin = min((double)A.second, (double)B.second);
        double ymax = max((double)A.second, (double)B.second);
        return py >= ymin - 1e-9 && py <= ymax + 1e-9;
    } else { 
        if (fabs(py - A.second) > 1e-9) return false;
        double xmin = min((double)A.first, (double)B.first);
        double xmax = max((double)A.first, (double)B.first);
        return px >= xmin - 1e-9 && px <= xmax + 1e-9;
    }
}

bool pointInOrOnPolygon(double px, double py) {
    int n = (int)pts.size();
    for (int i = 0; i < n; ++i) {
        const pii &A = pts[i];
        const pii &B = pts[(i+1)%n];
        if (pointOnSegment(px, py, A, B)) return true;
    }
    bool inside = false;
    for (int i = 0; i < n; ++i) {
        const pii &A = pts[i];
        const pii &B = pts[(i+1)%n];
        double x1 = A.first, y1 = A.second;
        double x2 = B.first, y2 = B.second;
        if ( (y1 > py) != (y2 > py) ) {
            double xint = x1 + (py - y1) * (x2 - x1) / (y2 - y1);
            if (xint > px) inside = !inside;
        }
    }
    return inside;
}


bool polygonEdgeCutsInterior(ll x1, ll x2, ll y1, ll y2) {
    int n = (int)pts.size();
    for (int i = 0; i < n; ++i) {
        const pii &A = pts[i];
        const pii &B = pts[(i+1)%n];
        if (A.first == B.first) { 
            ll X = A.first;
            if (X > x1 && X < x2) {
                ll segL = min(A.second, B.second);
                ll segR = max(A.second, B.second);
                ll L = max(segL, y1);
                ll R = min(segR, y2);
                if (L < R) return true;
            }
        } else {
            ll Y = A.second;
            if (Y > y1 && Y < y2) {
                ll segL = min(A.first, B.first);
                ll segR = max(A.first, B.first);
                ll L = max(segL, x1);
                ll R = min(segR, x2);
                if (L < R) return true;
            }
        }
    }
    return false;
}

bool rectangleInsidePolygon(ll x1, ll x2, ll y1, ll y2) {
    double cx = (x1 + x2) / 2.0;
    double cy = (y1 + y2) / 2.0;
    if (!pointInOrOnPolygon(cx, cy)) return false;
    if (polygonEdgeCutsInterior(x1, x2, y1, y2)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while ( (cin >> s) ) {
        int x = 0, y = 0;
        int i = 0;
        bool negx = false, negy = false;
        if (s.size() == 0) continue;
        if (s[0] == '-') { negx = true; ++i; }
        while (i < (int)s.size() && s[i] != ',') {
            x = x * 10 + (s[i] - '0');
            ++i;
        }
        if (negx) x = -x;
        ++i; 
        if (i < (int)s.size() && s[i] == '-') { negy = true; ++i; }
        while (i < (int)s.size()) {
            y = y * 10 + (s[i] - '0');
            ++i;
        }
        if (negy) y = -y;
        pts.push_back({x, y});
    }

    int n = (int)pts.size();
    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    unsigned long long ans = 0ULL;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (pts[i].first == pts[j].first) continue;
            if (pts[i].second == pts[j].second) continue;

            ll x1 = min( (ll)pts[i].first, (ll)pts[j].first );
            ll x2 = max( (ll)pts[i].first, (ll)pts[j].first );
            ll y1 = min( (ll)pts[i].second, (ll)pts[j].second );
            ll y2 = max( (ll)pts[i].second, (ll)pts[j].second );

            unsigned long long width = (unsigned long long)(x2 - x1 + 1);
            unsigned long long height = (unsigned long long)(y2 - y1 + 1);
            unsigned long long area = width * height;
            if (area <= ans) continue;

            if (rectangleInsidePolygon(x1, x2, y1, y2)) {
                ans = area;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
