class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;

        if (mp.find(node) != mp.end())
            return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for (auto neigh : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neigh));
        }
        return clone;
    }
};