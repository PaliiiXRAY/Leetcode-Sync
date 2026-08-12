class LRUCache {
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
        }
    };
    
    int cap;
    unordered_map<int, Node*> map;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    void addNode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deleteNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            Node* resnode = map[key];
            int res = resnode->val;
            map.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            map[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* existingnode = map[key];
            map.erase(key);
            deleteNode(existingnode);
        }
        if (map.size() == cap) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        map[key] = head->next;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */