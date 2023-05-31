//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct disjointset {
//    vector<int> parent, rank;
//    bool found = false;
//    int dot;
//    int* dot_count;
//    int count = 0;
//    int* line_count;
//
//    disjointset(int spot) :parent(spot), rank(spot, 1) {
//        dot = spot;
//        dot_count = new int[dot + 1];
//        line_count = new int[dot + 1];
//        for (int i = 1; i <= spot; i++) {
//            parent[i] = i;
//        }
//
//    }
//    int find_set(int u) {
//        if (parent[u] == u) {
//            return u;
//        }
//        else {
//            return find_set(parent[u]);
//        }
//    }
//
//    void union_set(int u, int v) {
//        int ur = find_set(u);
//        int vr = find_set(v);
//        if (rank[ur] > rank[vr]) {
//            parent[vr] = ur;
//        }
//        else {
//            parent[ur] = vr;
//            if (rank[ur] == rank[vr]) {
//                rank[vr] = rank[vr] + 1;
//            }
//        }
//        if (ur == vr) {
//            found = true;
//        }
//    }
//    void countgraph() {
//        for (int i = 1; i <= dot; i++) {
//            dot_count[find_set(i)] = 1; //각 정점의 최상단 vertax를 찾아 1로 바꿔주면 graph의 갯수를 셀 수 있다. 
//        }
//        for (int i = 1; i <= dot; i++) {
//            if (dot_count[i] == 1) { 
//                count++;
//            }
//        }
//    }
//    void count_line() {
//        for (int i = 1; i <= dot; i++) {
//            line_count[i] = 0;
//        }
//        for (int i = 1; i <= dot; i++) {
//            line_count[find_set(i)]++; //line_count배열에서 이러한 루프를 돌면, 최상단 vertax를 idx로 가진 배열부분에 같은 set의 vertax들이 count된다.
//        }
//        int max = 0;
//        for (int i = 1; i <= dot; i++) {
//            if (max < line_count[i]) {
//                max = line_count[i];
//            }
//        }
//        cout << max << endl;
//    }
//
//    ~disjointset() {
//        delete[] dot_count;
//        delete[] line_count;
//    }
//
//};
//
//
//int main(void) {
//    int spot, line;
//
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> spot >> line;
//    int u, v;
//
//    disjointset test(spot);
//    for (int i = 0; i < line; i++)
//    {
//        cin >> u >> v;
//        test.union_set(u, v);
//    }
//
//    if (test.found == true) {
//        cout << "Found" << endl;
//    }
//    else {
//        cout << "Not found" << endl;
//    }
//    test.countgraph();
//    cout << test.count << endl;
//    test.count_line();
//
//    return 0;
//}