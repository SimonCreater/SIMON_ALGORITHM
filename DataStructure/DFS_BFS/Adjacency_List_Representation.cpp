#include <iostream>
#include <vector>
using namespace std;

struct vertex {
    int v;
    vertex() {}
    vertex(int v) { this->v = v; }
};

struct edge {
    int s, d;
    edge(int s, int d) { this->s = s; this->d = d; }
};

class Graph {
public:
    vector<vertex> vertexes[101];
    vector<edge> edges[101];
    Graph() {}

    void InsertVertex(int id, int s) {
        for (vertex v1 : vertexes[id]) {
            if (v1.v == s) {
                cout << "ERRORCODE 01" << '\n';
                return;
            }
        }
        vertex v1 = vertex(s);
        vertexes[id].push_back(v1);
    }

    void InsertEdge(int id, int s, int d) {
        bool flagd = false;
        bool flags = false;
        for (vertex v1 : vertexes[id]) {
            if (v1.v == s) {
                flags = true;
            }
            if (v1.v == d) {
                flagd = true;
            }
        }
        if (!flags || !flagd) {
            cout << "ERRORCODE 03" << '\n';
            return;
        }

        for (edge e : edges[id]) {
            if ((e.s == s && e.d == d) || (e.s == d && e.d == s)) {
                cout << "ERRORCODE 02" << '\n';
                return;
            }
        }
        edge newedge = edge(s, d);
        edges[id].push_back(newedge);
    }

    void EraseVertex(int id, int s) {
        bool flag = false;
        for (int i = 0; i < vertexes[id].size(); i++) {
            if (vertexes[id][i].v == s) {
                flag = true;
                vertexes[id].erase(vertexes[id].begin() + i);
                break; 
            }
        }
        if (!flag) {
            cout << "ERRORCODE 03" << '\n';
            return;
        }

        vector<edge> remainingEdges;
        for (edge e : edges[id]) {
            if (e.s != s && e.d != s) {
                remainingEdges.push_back(e);
            }
        }
        edges[id] = remainingEdges;
    }

    void EraseEdge(int id, int s, int d) {
        bool flagd = false;
        bool flags = false;
        for (vertex v1 : vertexes[id]) {
            if (v1.v == s) {
                flags = true;
            }
            if (v1.v == d) {
                flagd = true; 
            }
        }
        if (!flags || !flagd) {
            cout << "ERRORCODE 03" << '\n';
            return;
        }

        bool flagedge = false;
        for (int i = 0; i < edges[id].size(); i++) {
            if ((edges[id][i].s == s && edges[id][i].d == d) || (edges[id][i].s == d && edges[id][i].d == s)) {
                flagedge = true;
                edges[id].erase(edges[id].begin() + i);
                break; 
            }
        }
        if (!flagedge) {
            cout << "ERRORCODE 04" << '\n';
            return;
        }
    }

    void PrintAdjSum(int id, int s) {
        int sum = 0;
        int cnt = 0;
        bool flags = false;
        for (vertex v1 : vertexes[id]) {
            if (v1.v == s) {
                flags = true;
                break; 
            }
        }
        if (!flags) {
            cout << "ERRORCODE 03" << '\n';
            return;
        }

        for (edge e : edges[id]) {
            if (e.s == s) {
                cnt++;
                sum += e.d;
            }
            else if (e.d == s) {
                cnt++;
                sum += e.s; 
            }
        }
        if (cnt == 0) {
            cout << "0 0" << '\n';
            return;
        }
        cout << cnt << " " << sum << '\n';
    }

    void PrintAdjMin(int id, int s) {
        int min = 1000001;
        bool flags = false;
        for (vertex v1 : vertexes[id]) {
            if (v1.v == s) {
                flags = true;
                break; 
            }
        }
        if (!flags) {
            cout << "ERRORCODE 03" << '\n';
            return;
        }

        bool flagedge = false;
        for (edge e : edges[id]) {
            if (e.s == s) {
                flagedge = true;
                if (e.d < min) {
                    min = e.d;
                }
            }
            else if (e.d == s) {
                flagedge = true;
                if (e.s < min) {
                    min = e.s; 
                }
            }
        }
        if (!flagedge) {
            cout << "-1" << '\n';
            return;
        }
        cout << min << '\n';
    }
};

int main() {
    int n;
    cin >> n;
    Graph g;
    for (int i = 0; i < n; i++) {
        string cmd;
        int id, s, d;
        cin >> cmd;
        if (cmd == "Graph") {
            int x;
            cin >> x;
        }
        else if (cmd == "InsertVertex") {
            cin >> id >> s;
            g.InsertVertex(id, s);
        }
        else if (cmd == "InsertEdge") {
            cin >> id >> s >> d;
            g.InsertEdge(id, s, d);
        }
        else if (cmd == "EraseVertex") {
            cin >> id >> s;
            g.EraseVertex(id, s);
        }
        else if (cmd == "EraseEdge") {
            cin >> id >> s >> d;
            g.EraseEdge(id, s, d);
        }
        else if (cmd == "PrintAdjSum") {
            cin >> id >> s;
            g.PrintAdjSum(id, s);
        }
        else if (cmd == "PrintAdjMin") {
            cin >> id >> s;
            g.PrintAdjMin(id, s);
        }
    }
}