#include<bits/stdc++.h>
using namespace std;

vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    vector<vector<pair<int, int>>> adja(n);
    for (auto& edge : edges) {
        int ab = edge[0];
        int ac = edge[1];
        int len = edge[2];
        adja[ab].push_back({ac, len});
        adja[ac].push_back({ab, len});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push({0, 0});
    vector<int> answer(n, -1);
    while (!queue.empty()) {
        auto current = queue.top();
        queue.pop();
        int no = current.first;
        int ti = current.second;
        if (answer[no] != -1) continue;
        answer[no] = ti;
        for (auto& neighbor : adja[no]) {
            int Node = neighbor.first;
            int et = neighbor.second;
            int nt = ti + et;
            if (nt < disappear[Node]) {
                queue.push({Node, nt});
            }
        }
    }
    return answer;
}