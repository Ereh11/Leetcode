using namespace std;

struct DSU {
    int parent[100005];
    int nodeRank[100005];

    void make_set(int v) {
        parent[v] = v;
        nodeRank[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    int union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (nodeRank[a] < nodeRank[b])
                swap(a, b);
            parent[b] = a;
            if (nodeRank[a] == nodeRank[b])
                ++nodeRank[a];
            return 1;
        }
        return 0;
    }
};


class Solution {
public:
    static int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        DSU d1 = DSU();
        DSU d2 = DSU();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            d1.make_set(i);
            d2.make_set(i);
        }
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == 3) {
                sum += (d2.union_sets(edges[i][1], edges[i][2]) | d1.union_sets(edges[i][1], edges[i][2]));
            }
        }
        
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == 1) {
                sum += d1.union_sets(edges[i][1], edges[i][2]);
            }
            if (edges[i][0] == 2) {
                sum += d2.union_sets(edges[i][1], edges[i][2]);
            }
        }
        set<int> s1, s2;
        for (int i = 0; i < n; i++) {
            s1.insert(d1.find_set(i));
            s2.insert(d2.find_set(i));
        }
        if (s1.size() != 1 || s2.size() != 1) {
            return -1;
        }
        return edges.size() - sum;
    }
};