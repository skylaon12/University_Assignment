//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//using namespace std;
//
//
//
//class Graph {
//private:
//    struct Node {
//        int v;
//        Node(int v) : v(v) { }
//    };
//
//    vector<vector<Node>> adj_list; //adjacency list used for Prim's algorithm
//    int n;                         //number of edges
//public:
//    Graph(int n) : n(n) { //���Ḯ��Ʈ ��� �׷���
//        adj_list = vector<vector<Node>>(n + 1, vector<Node>()); //n+1���� ���Ҹ� ������, �� ���ҵ��� vector<node>�� �ʱ�ȭ�Ѵ�. //2���� ����
//    }
//
//    void insert_edge(int u, int v) { //���� �׷���
//        adj_list[u].push_back(Node(v));
//    }
//
//    int get_node() {
//        return n;
//    }
//
//};
//
//vector<int> kahn(Graph G) {
//    vector<int> Q;
//    
//
//
//    }
//
//int main(void) {
//    int n, m, a, b;
//    cin >> n;
//    cin >> m;
//
//    Graph graph(n);
//
//    for (int i = 0; i < m; i++) {
//        cin >> a;
//        cin >> b;
//        graph.insert_edge(a, b);
//    }
//
//
//	return 0;
//}