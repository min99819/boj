#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t, n, k;
int main() {
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> k;
        vector<int> time(n+1);
        vector<int> degree(n+1);
        vector<int> sum(n+1);
        for(int j=1; j<=n; j++) {
            cin >> time[j];
            sum[j] = time[j];
        }
        vector<vector<int>> graph(n+1);
        for(int j=0; j<k; j++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            degree[b]++;
        }
        int last;
        cin >> last;
        queue<int> q;
        for(int j=1; j<=n; j++) {
            if(degree[j] == 0) q.push(j);
        }
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int x=0; x<graph[cur].size(); x++) {
                int next = graph[cur][x];
                degree[next]--;
                if(sum[next] < sum[cur] + time[next]) sum[next] = sum[cur] + time[next];
                if(degree[next] == 0) {
                    q.push(next);
                }
            }
        }
        cout << sum[last] << '\n';
    }
}