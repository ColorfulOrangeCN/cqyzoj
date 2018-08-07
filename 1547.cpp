#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 50005;

struct node{
	int parent, deep;
	vector<int> child;
} nodes[maxn];

vector<int>::size_type maxd = 0;

int ans1(int now,int deep){
	int maxdeep = deep + 1;
	nodes[now].deep = deep + 1;
	if(nodes[now].child.size() > maxd){
		maxd = nodes[now].child.size();
	}
	for(int i = 0; i < nodes[now].child.size();++i){
		int ret = ans1(nodes[now].child[i], deep+1);
		if(ret > maxdeep){
			maxdeep = ret;
		}
	}
	return maxdeep;
}

int cnt_child(int now){
	int ret = nodes[now].child.size();
	for(int i = 0 ; i < nodes[now].child.size(); ++i){
		ret += cnt_child(nodes[now].child[i]);
	}
	return ret;
}

void print_parent(int now){
	if(now != 1){
		print_parent(nodes[now].parent);
		cout << nodes[now].parent << " ";
	} else {
		return;
	}
}

int main(){
	int N;
	cin >> N;
	int x,y;
	for(int i = 1; i < N; ++i){
		cin >> x >> y;
		nodes[x].child.push_back(y);
		nodes[y].parent = x;
	}
	cout << ans1(1,0) <<" ";
	cout << maxd << endl;
	cin >> x;
	cout << nodes[x].deep << " ";
	cout << (nodes[x].child.empty()?"Yes":"No") << endl;
	cin >> y;
	cout << nodes[y].child.size() << " " << cnt_child(y) << endl;
	cin >> x;
	print_parent(x);
	return 0;
}
