#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>(); 
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
 unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        if(visited[node])
            return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        for(auto nei: node->neighbors){
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        return cloned;
    }