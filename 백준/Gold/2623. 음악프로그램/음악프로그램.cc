#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<int> v[1001];
int indegree[1001];
vector<int> res;
bool flag = true;
void topology_sort() {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    for(int i=0; i<n; i++) {
        if(q.empty()) {
            flag = false;
            return;
        }
        
        int x = q.front();
        q.pop();
        res.push_back(x);

        for(int k=0; k<v[x].size(); k++) {
            int nx = v[x][k];
            if(--indegree[nx] == 0) {
                q.push(nx);
            }
        }
    }
}
int main() { 
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        for(int j=0; j<a-1; j++) {
            int c;
            cin >> c;
            v[b].push_back(c);
            indegree[c]++;
            b = c;
        }
    }
    topology_sort();
    if(flag) {
        for(int i=0; i<n; i++) {
            cout << res[i] << '\n';
        }
    }
    else cout << 0;
}

