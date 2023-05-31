//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <numeric>
//#define DUMMY 0
//#define INF 1e9 // use this to represent the infinity
//
//using namespace std;
//
//class DisjointSet {
//private:
//    vector<int> p;
//    vector<int> rank;
//public:
//    DisjointSet(int n) {
//        p = vector<int>(n + 1);
//        rank = vector<int>(n + 1);
//    }
//
//    void make(int u) { p[u] = u; rank[u] = 0; }
//
//    int find(int u) {
//        if (p[u] != u) p[u] = find(p[u]);
//        return p[u];
//    }
//
//    bool merge(int u, int v) {
//        int ur = find(u);
//        int vr = find(v);
//        if (ur == vr) return false;
//        if (rank[ur] > rank[vr]) p[vr] = ur;
//        else {
//            p[ur] = vr;
//            if (rank[ur] == rank[vr]) rank[vr] = rank[vr] + 1;
//        }
//        return true;
//    }
//};
//
//
//class Graph {
//private:
//    struct Edge {
//        int u; int v; int w;
//        Edge(int u, int v, int w) : u(u), v(v), w(w) { }
//        bool operator < (const Edge& edge) const { return this->w < edge.w; }
//    };
//
//    vector<Edge> edges;            //edge list used for Kruskal's algorithm
//    int n;                         //number of edges
//public:
//    Graph(int n) : n(n) {
//        edges = vector<Edge>();
//    }
//
//    void insert_edge(int u, int v, int w) {
//        edges.push_back(Edge(u, v, w));
//    }
//
//    static bool cmp(const Edge & a, const Edge & b) {
//        if (a.w < b.w) {
//            return true;
//        }
//        return false;
//    }
//
//    vector<int> kruskal() { // 반환형이 vector인 함수. 리턴값으로 가중치를 모아두게 만든다.
//        vector<int> kruskal_sequence(1, DUMMY); //가중치 정보가 저장될 vector
//        DisjointSet set(n);
//        
//        vector<Edge> kEdge(edges);
//
//        for (int i = 1; i < n; i++) {
//            set.make(i);
//        }
//
//        sort(kEdge.begin(), kEdge.end(), cmp);
//
//        for (int i = 0; i < kEdge.size(); i++) {
//            if (set.find(kEdge.at(i).u) != set.find(kEdge.at(i).v)) {
//                kruskal_sequence.push_back(kEdge.at(i).w);
//                set.merge(kEdge.at(i).u, kEdge.at(i).v);
//            }
//        }
//
//
//        // fill in here
//        //  - you can use std::sort() to sort edges
//        //  - you can sequentially iterate each edge as follows:
//        //     - for(Edge edge : edges)
//        //  - push back the weight of an edge selected by Kruskal into kruskal_sequence
//        //    (use kruskal_sequence.push_back(int weight))
//
//        return kruskal_sequence;
//    }
//};
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n; // # of nodes
//    int m; // # of edges
//    int i; // index of a sequence to be printed
//    cin >> n >> m >> i;
//
//    Graph graph(n);
//
//    for (int j = 0; j < m; j++) {
//        int s, t, w;
//        cin >> s >> t >> w;
//        graph.insert_edge(s, t, w);
//    }
//
//    vector<int> kruskal_sequence = graph.kruskal();
//
//    // sum all entries of kruskal_sequence
//    long long cost = std::accumulate(kruskal_sequence.begin(), kruskal_sequence.end(), 0L);
//
//    cout << cost << endl;
//    cout << kruskal_sequence[i] << endl;
//    
//   
//    return 0;
//}
