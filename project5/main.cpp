#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

#include <queue>

using std::queue;


int find_answer(vector<pair<int, vector<int>>> mapNodeVeighbor, unordered_map<int, int> mapToIndex) {

    int max_days = 0;
    vector<bool> visited(mapNodeVeighbor.size());
    for (int i = 0; i < mapNodeVeighbor.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue<int> holdNode;
            holdNode.push(i);
            int egeNumber = 0;
            int firstMax = 0;
            int secondMax = 0;
            int count = 0;
            while (!holdNode.empty()) {
                int next_vertex = holdNode.front();
                holdNode.pop();
                for (const auto &neighbor: mapNodeVeighbor[next_vertex].second) {
                    int index = mapToIndex[neighbor];
                    if (visited[index])
                        continue;
                    visited[index] = true;
                    holdNode.push(index);
                }
                if (mapNodeVeighbor[next_vertex].first > firstMax) {
                    secondMax = firstMax;
                    firstMax = mapNodeVeighbor[next_vertex].first;
                } else if (mapNodeVeighbor[next_vertex].first > secondMax &&
                           mapNodeVeighbor[next_vertex].first != firstMax)
                    secondMax = mapNodeVeighbor[next_vertex].first;
                count++;

                egeNumber += mapNodeVeighbor[next_vertex].second.size();
            }
            egeNumber /= 2;
            int current_days;
            if (egeNumber > count)
                return -1;
            else if (egeNumber == count)
                current_days = firstMax;
            else
                current_days = secondMax;
            max_days = max(current_days, max_days);
        }
    }
    return max_days;
}


int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> nodeNeighbor;
    int edgeNumber = 0;
    int a, b, i;
    for (i = 0; i < n; i++) {
        cin >> a >> b;
        nodeNeighbor[a].push_back(b);
        nodeNeighbor[b].push_back(a);
        edgeNumber++;
    }

    unordered_map<int, int> mapToIndex;
    // mapToIndex.reserve(nodeNeighbor.size());
    vector<pair<int, vector<int>>> mapNodeVeighbor(nodeNeighbor.size());

    i = 0;
    for (auto &n: nodeNeighbor) {
        mapNodeVeighbor[i].first = n.first;
        mapNodeVeighbor[i].second = move(n.second);
        mapToIndex[n.first] = i;
        i++;
    }
    // nodeNeighbor.clear();
    bool flag = true;
    int max_days = 0;
    vector<bool> visited(mapNodeVeighbor.size());
    for (int i = 0; i < mapNodeVeighbor.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            queue<int> holdNode;
            holdNode.push(i);
            int egeNumber = 0;
            int firstMax = 0;
            int secondMax = 0;
            int count = 0;
            while (!holdNode.empty()) {
                int next_vertex = holdNode.front();
                holdNode.pop();
                for (const auto &neighbor: mapNodeVeighbor[next_vertex].second) {
                    int index = mapToIndex[neighbor];
                    if (visited[index])
                        continue;
                    visited[index] = true;
                    holdNode.push(index);
                }
                if (mapNodeVeighbor[next_vertex].first > firstMax) {
                    secondMax = firstMax;
                    firstMax = mapNodeVeighbor[next_vertex].first;
                } else if (mapNodeVeighbor[next_vertex].first > secondMax &&
                           mapNodeVeighbor[next_vertex].first != firstMax)
                    secondMax = mapNodeVeighbor[next_vertex].first;
                count++;

                egeNumber += mapNodeVeighbor[next_vertex].second.size();
            }
            egeNumber /= 2;
            int current_days;
            if (egeNumber > count) {
                cout << -1;
                flag = false;
            } else if (egeNumber == count)
                current_days = firstMax;
            else
                current_days = secondMax;
            max_days = max(current_days, max_days);
        }
    }
    if (flag)
        cout << max_days;
}
