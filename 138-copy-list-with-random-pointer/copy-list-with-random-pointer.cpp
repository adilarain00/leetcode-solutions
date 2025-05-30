class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step 1. copy the list
        Node* temp = head;
        Node* dummy = new Node(100);
        Node* dc = dummy;
        while (temp != NULL) {
            Node* newnode = new Node(temp->val);
            dc->next = newnode;
            dc = newnode;
            temp = temp->next;
        }
        // step 2 store it in the map
        Node* a = head;
        Node* b = dummy->next;
        unordered_map<Node*, Node*> mp;
        Node* tempa = a;
        Node* tempb = b;
        while (tempa != NULL) {
            mp[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        // step 3 now making random
        for (auto x : mp) {
            Node* helpa = x.first;
            Node* helpb = x.second;
            if (helpa->random != NULL) {
                Node* helparandom = helpa->random;
                Node* helpbrandom = mp[helparandom];
                helpb->random = helpbrandom;
            }
        }
        return b;
    }
};