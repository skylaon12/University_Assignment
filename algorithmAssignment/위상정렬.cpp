//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct Edge {
//    int src, dest;
//};
//
//class Graph
//{
//public:
//    vector<vector<int>> adjList;
//
//    vector<int> indegree;
//
//    Graph(vector<Edge> const& edges, int n)
//    {
//        adjList.resize(n);
//
//        vector<int> temp(n, 0);
//        indegree = temp;
//
//        for (auto& edge : edges)
//        {
//            adjList[edge.src].push_back(edge.dest);
//
//            indegree[edge.dest]++;
//        }
//    }
//};
//
//vector<int> doTopologicalSort(Graph const& graph)
//{
//    vector<int> L;
//
//    int n = graph.adjList.size();
//
//    vector<int> indegree = graph.indegree;
//
//    vector<int> S;
//    for (int i = 0; i < n; i++)
//    {
//        if (!indegree[i]) {
//            S.push_back(i);
//        }
//    }
//
//    while (!S.empty())
//    {
//        int n = S.back();
//        S.pop_back();
//        L.push_back(n);
//
//        for (int m : graph.adjList[n])
//        {
//            indegree[m] -= 1;
//            if (!indegree[m]) {
//                S.push_back(m);
//            }
//        }
//    }
//
//
//    for (int i = 0; i < n; i++)
//    {
//        if (indegree[i]) {
//            return {};
//        }
//    }
//
//    return L;
//}
//
//int main()
//{
//
//    int n, m, a, b;
//    vector<Edge> e;
//
//    cin >> n;
//    cin >> m;
//
//    for (int i = 0; i < m; i++) {
//        cin >> a;
//        cin >> b;
//        e.push_back({ a - 1, b - 1});
//    }
//
//
//    Graph graph(e, n);
//
//
//    vector<int> L = doTopologicalSort(graph);
//
//
//    if (L.size()) {
//        cout << "No";
//    }
//    else {
//        cout << "Yes";
//    }
//
//    return 0;
//}