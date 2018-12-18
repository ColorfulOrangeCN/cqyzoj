// by c++
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 500 + 5;
const double inf = 1e16;
double G[maxn][maxn];
int s, n;
vector<pair<double, double> > point;
bool vis[maxn] = {};
double dis[maxn] = {};
vector<double> vec;

void Prim()
{
    dis[0] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        double _min = inf;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dis[j] < _min) {
                _min = dis[j];
                u = j;
            }
        }
        vis[u] = true;
        vec.push_back(_min);
        for (int j = 0; j < n; ++j) {
            if (G[u][j] < dis[j]) {
                dis[j] = G[u][j];
            }
        }
    }
}

int main()
{
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        dis[i] = 1e16;
        for (int j = 0; j < n; ++j) {
            G[i][j] = 1e16;
        }
    }
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        point.push_back(make_pair(x, y));
    }
    for (int i = 0; i < point.size(); ++i) {
        for (int j = 0; j < point.size(); ++j) {
            if (i == j) continue;
            double x1 = point[i].first, y1 = point[i].second;
            double x2 = point[j].first, y2 = point[j].second;
            G[i][j] = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        }
    }
    Prim();
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        if (i == n - s) printf("%.2f", vec[i]);
    }
}
