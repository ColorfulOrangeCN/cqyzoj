#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 5001;
struct side{
    int x, y, val;
    bool operator<(const side& s){
        return val < s.val;
    }
};
vector<side> sides;
vector<int> ss[maxn];
int n,m, uf[maxn], ins[maxn] = {0};
bool vis[maxn] = {false};
int get_father(int x){
    if(uf[x] == x){
        return x;
    }
    return uf[x] = get_father(uf[x]);
}
void doUnion(int x, int y){
    uf[get_father(x)] = get_father(y);
}
bool doCheck(int x, int y){
    return get_father(x) != get_father(y);
}
void dfs(int x){
    vis[x] = true;
    for(int i = 0; i < ss[x].size(); ++i){
        if(vis[i] == false)dfs(ss[x][i]);
    }
}
bool dos = false;
int main(){
    cin >> n >> m;
    for(int i = 0; i <= n; ++i){
        uf[i] = i;
    }
    for(int i = 1; i <= n; ++i){
        side t;
        cin >> t.x >> t.y >> t.val;
        ss[t.x].push_back(t.y);
        ss[t.y].push_back(t.x);
        sides.push_back(t);
        int tmp = t.x;
        t.x = t.y;
        t.y = tmp;
        sides.push_back(t);
    }
    int qq=0;
    for(int i = 1; i <= n; ++i){
        if (vis[i] == false) {
            dfs(i);
            ++qq;
        }
    }
        if(qq>1){
            cout << "orz" << endl;
            return 0;
        }
    int sum = 0, cnt = 0;
    sort (sides.begin(), sides.end());
    for(int i = 0; i < sides.size() && cnt < n; ++i){
        side v = sides[i];
        if(doCheck(v.x, v.y)){
            doUnion(v.x, v.y);
            sum += v.val;
            ++cnt;
        }
    }
    cout << sum << endl;
    return 0;
}
