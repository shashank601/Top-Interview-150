class Node {
public:
    int key;
    int value;

    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int k, int v) : key(k), value(v) {}
};


class LRUCache {
public:
    unordered_map<int, Node*> m;

    Node* head;
    Node* tail;

    int capacity = 0;
    int sz = 0;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

        this->capacity = capacity;
    }

    void unlink(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    
    void move_to_front(Node* node) {
        unlink(node);

        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }


    void evict() {
        if (head->next == tail) return;

        sz--;
        m.erase(tail->prev->key);

        Node* node = tail->prev;
        unlink(tail->prev);

        delete node;
    }

    void insert_at_front(Node* node) {
        node->next = head->next;
        node->prev = head;

        node->next->prev = node;
        head->next = node;
    }

    
    int get(int key) {
        if (!m.count(key) || sz == 0) {
            return -1;
        }

        move_to_front(m[key]);

        return m[key]->value;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {

            m[key]->value = value;
            move_to_front(m[key]);

            return;
        }

        if (sz == capacity) {
            evict();
        }


        Node* node = new Node(key, value);
        m[key] = node;

        insert_at_front(node);
        sz++;
    }


};

