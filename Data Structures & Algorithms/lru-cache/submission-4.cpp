class LRUCache {

private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {};
    };
    int capacity;
    unordered_map<int, Node*> values;
    Node *head, *tail;
    void remove(Node* node) {
        // I was wrong about edge cases, null always work still...
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addToFront(Node* node) {
        auto nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        nextNode->prev = node;
        node->prev = head;
    }

public:
    int currSize;
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        currSize = 0;
    }

    ~LRUCache() {
        Node* curr = head;
        while(curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        if(!values.count(key)) {
            return -1;
        }
        // Now we know its there
        Node* node = values[key];
        remove(node);
        addToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(values.count(key)) {
            values[key]->val = value;
            remove(values[key]);
            addToFront(values[key]);
        }
        // it doesn't exist
        else {
            // Node needs to live on the heap... this wont work
            Node* n = new Node(key, value);
            addToFront(n);
            currSize++;
            if(currSize > capacity) {
                Node* last = tail->prev;
                remove(tail->prev);
                values.erase(last->key);
                delete last;
                currSize--;
            }
            
            values[key] = n;
        }
        
        
    }
};


