//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <numeric>
//#define DUMMY 0
//#define INF 1e9 // use this to represent the infinity
//
//using namespace std;
//
//class MinHeap {
//private:
//    struct Index {
//        int cost; int i;
//        Index(int cost, int i) { this->cost = cost; this->i = i; }
//    };
//
//    vector<int> array;     // array:   heap_index -> node
//    vector<Index> indices; // indices: node -> (cost, heap index)
//
//    int PARENT(int i) { return i / 2; }
//    int LEFT(int i) { return 2 * i; }
//    int RIGHT(int i) { return 2 * i + 1; }
//
//    // i: heap_index, array[i] is node, and its cost is key
//    int key(int i) { return indices[array[i]].cost; }
//    
//    void swap(int i, int j) { // i, j: heap_index
//        std::swap(array[i], array[j]);
//        indices[array[i]] = Index(key(i), i); //index(int cost, int i) 
//        indices[array[j]] = Index(key(j), j);
//    }
//public:
//    MinHeap(int n) { //n개의 더미노드를 indices에 넣는다.
//        array.push_back(DUMMY);
//        for (int i = 0; i <= n; i++)
//            indices.push_back(Index(DUMMY, DUMMY));
//    }
//
//    // return true if this queue is empty
//    bool empty() { return array.size() - 1 == 0; } //heap에는 dummy node가 필수로 1개 있기에 -1을 붙인 것.
//
//    // return true if node is in this queue
//    bool has(int node) { return indices[node].i != DUMMY; }
//
//    void insert(int cost, int node) {
//        array.push_back(node);
//        int i = array.size() - 1; // index of node in the heap array
//        indices[node] = Index(cost, i);
//        //up-heap
//        while (i != 1 && key(i) < key(PARENT(i))) {
//            this->swap(i, PARENT(i));
//            i = PARENT(i);
//        }
//    }
//
//    // return node having the smallest cost (or distance)
//    int remove() {
//        int u = array[1];
//        indices[u] = Index(DUMMY, DUMMY);
//
//        array[1] = array[array.size() - 1];
//        indices[array[1]] = Index(key(1), 1);
//
//        array.pop_back(); // size - 1
//
//        int i = 1;
//        int n = array.size() - 1;
//
//        while (i <= n) { // down-heap
//            int smallest = i;
//            if (LEFT(i) <= n && key(LEFT(i)) < key(smallest))  smallest = LEFT(i);
//            if (RIGHT(i) <= n && key(RIGHT(i)) < key(smallest)) smallest = RIGHT(i);
//
//            if (smallest != i) {
//                this->swap(i, smallest);
//                i = smallest;
//            }
//            else break;
//        }
//
//        return u;
//    }
//
//    void decrease_key(int node, int new_cost) {
//        int i = indices[node].i;
//        if (key(i) > new_cost) {
//            indices[node] = Index(new_cost, i);
//            // up-heap
//               while (i > 1 && key(i) < key(PARENT(i))) {
//                this->swap(i, PARENT(i));
//                i = PARENT(i);
//            }
//        }
//    }
//};
//
//class Graph {
//private:
//    struct Node {
//        int v; int w; //v는 간선(u->v꼴), w는 가중치
//        Node(int v, int w) : v(v), w(w) { }
//        bool operator < (const Node& node) const { return this->v < node.v; }
//    };
//
//    vector<vector<Node>> adj_list; //adjacency list used for Prim's algorithm
//    int n;                         //number of edges
//public:
//    Graph(int n) : n(n) { //연결리스트 기반 그래프
//        adj_list = vector<vector<Node>>(n + 1, vector<Node>()); //n+1개의 원소를 가지고, 그 원소들을 vector<node>로 초기화한다. //2차원 벡터
//    }
//
//    void insert_edge(int u, int v, int w) { //무방향 그래프를 나타냄.
//        adj_list[u].push_back(Node(v, w)); 
//        adj_list[v].push_back(Node(u, w));
//    }
//
//    void sort_neighbors() {
//        for (auto& neighbors : adj_list)
//            std::sort(neighbors.begin(), neighbors.end());
//    }
//
//    vector<int> prim(int s) { // s is the source node(s는 시작 노드)
//        vector<int> prim_sequence(1, DUMMY); // store the weight of an edge(가중치 저장)
//        MinHeap Q(n);//(가중치를 기준으로 minHeap)
//        vector<bool> visited(n + 1, false);
//        int u;
//        vector<int> c(1, DUMMY);
//        
//        for (int i = 1; i <= n; i++) {
//            if (i != s) {
//                c.push_back(INF);//시작 정점을 제외한 나머지 노드는 INF
//                Q.insert(c.at(i), i); //(가중치, 노드번호)
//            }
//            else {
//                c.push_back(0); 
//                Q.insert(c.at(i), i);
//            }
//            
//        }
//
//
//        while (!Q.empty()) {
//            u = Q.remove(); //가중치가 가장 낮은 노드 반환
//            if (u != 1) {
//            prim_sequence.push_back(c[u]);
//
//            }
//            visited[u] = true; //방문 여부
//            for (int v = 0; v < (int)adj_list[u].size(); v++) { //u노드의 인접노드 방문
//                if (visited[adj_list[u][v].v] == false && adj_list[u][v].w < c.at(adj_list[u][v].v)) {
//                    c.at(adj_list[u][v].v) = adj_list[u][v].w;
//                    Q.decrease_key(adj_list[u][v].v, c.at(adj_list[u][v].v));
//                }
//            }
//        }
//
//        // fill in here
//        //  - the set R of remaining nodes can be replaced with the min heap Q
//        //  - you can sequentially iterate out-neighbors of node u as follows:
//        //     - for(Node v : adj_list[u]){ ... }
//        //  - push back the weight of an edge selected by Prim into prim_sequence
//        //    (use prim_sequence.push_back(int weight))
//
//        return prim_sequence;
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
//    // to guarantee that neighbors of a node are iterated in the increasing order
//    graph.sort_neighbors();
//
//    vector<int> prim_sequence = graph.prim(1);
//
//    // sum all entries of prim_sequence
//    long long cost = std::accumulate(prim_sequence.begin(), prim_sequence.end(), 0L);
//
//    cout << cost << endl;
//    cout << prim_sequence[i] << endl;
//
//    return 0;
//}