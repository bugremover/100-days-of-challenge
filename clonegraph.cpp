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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> copies; // Map original nodes to their copies
        return cloneNode(node, copies);
    }

private:
    Node* cloneNode(Node* node, unordered_map<Node*, Node*>& copies) {
        if (copies.find(node) != copies.end()) {
            // If the node is already copied, return the copy
            return copies[node];
        }
        
        // Create a new copy for the current node
        Node* copy = new Node(node->val);
        copies[node] = copy; // Map the original node to its copy

        // Iterate through all neighbors of the current node
        for (Node* neighbor : node->neighbors) {
            // Recursively clone each neighbor and add it to the current node's neighbors
            copy->neighbors.push_back(cloneNode(neighbor, copies));
        }

        return copy;
    }
};