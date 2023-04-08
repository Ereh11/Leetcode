/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* DFS(Node* node, unordered_map<Node*, Node*> &ump)
    {
        Node* now = new Node(node->val);
        ump[node] = now;
        for (Node* it : node->neighbors)
        {
            Node* ngbh = NULL;
            
            if (ump.count(it)) 
                ngbh = ump[it]; 
            else 
                ngbh = DFS(it, ump);
            
            now->neighbors.push_back(ngbh);
        }
        return now;
    }
    
    Node* cloneGraph(Node* node) 
    {
        if (node == NULL) 
            return NULL;
        
        unordered_map<Node*, Node*> ump;
        
        return DFS(node, ump); 
    }
};