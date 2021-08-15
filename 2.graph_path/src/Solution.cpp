#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {

    static int makeKey(int node1, int node2) {
        string keyString = to_string(node1) + to_string(node2);
        return stoi(keyString);
    }
    
public:
    static bool doesPathExist(vector<vector<int>> vertices, int K) {

        map<int, bool> connections;

        for (int i=1; i < K; i++) {
            int key = makeKey(i, (i+1));
            connections.insert(make_pair(key, false));
        }

        for (int i=0; i < vertices.size(); i++) {
            for (int j=0; j < vertices[i].size(); j++) {
                int verticeKey = makeKey((i+1), vertices[i][j]);
                if (connections.find(verticeKey) != connections.end()) {
                    connections[verticeKey] = true;
                }
            }
        }

        for (auto connection: connections) {
            if (!connection.second) return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> vertices = {{2, 3},
                                    {3},
                                    {2,4}};

    const int targetNode = 4;
    cout << "Path to node " << targetNode; 
    if (Solution::doesPathExist(vertices, 4)) {
        cout << " exists" << endl;
    } else {
        cout << " does not exist" << endl;
    }
    return 0;
}