#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
    };

bool comp(Edge a, Edge b) {
    return a.weight < b.weight;
    }

int findParent(int v, int* parent) {
    if (parent[v] == v) return v;
    return findParent(parent[v], parent);
    }

void kruskalMST(Edge* edges, int n, int e) {
    sort(edges, edges+e, comp);
    Edge* mst = new Edge[n-1];
    int* parent = new int[n];
    for (int i = 0; i < n; i++) parent[i] = i;
    int cnt = 0, i = 0;
    while (cnt < n-1 && i < e) {
        Edge curr = edges[i++];
        int srcParent = findParent(curr.src, parent);
        int destParent = findParent(curr.dest, parent);
        if (srcParent != destParent) {
            mst[cnt++] = curr;
            parent[srcParent] = destParent;
        }
    }
    int minWeight = 0;
    for (int i = 0; i < n-1; i++) {
        minWeight += mst[i].weight;
        cout << "Edge " << i+1 << ": " << mst[i].src << " - " << mst[i].dest << " (Weight = " << mst[i].weight << ")" << endl;
    }
    cout << "Minimum weight of MST: " << minWeight << endl;
}

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "File not found." << endl;
        return 0;
    }
    int n, e;
    file >> n >> e;
    Edge* edges = new Edge[e];
    for (int i = 0; i < e; i++) {
        file >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    kruskalMST(edges, n, e);
    return 0;
}

