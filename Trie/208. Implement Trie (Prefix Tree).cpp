class Node {
public:
    Node* arr[26] = {};
    bool end = false;
};

class Trie {
public:
    Node* head;

    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node* root = head;

        for (auto& ch : word) {
            int i = ch - 'a';

            if (!root->arr[i]) {
                root->arr[i] = new Node();
            }
             
            root = root->arr[i];
        }

        root->end = true;
         
    }
    
    bool search(string word) {
        Node* root = head;

        for (auto& ch : word) {
            int i = ch - 'a';

            if (!root->arr[i]) {
                return false;
            }
             
            root = root->arr[i];
        }

        return root->end;
    }
    
    bool startsWith(string prefix) {
        Node* root = head;

        for (auto& ch : prefix) {
            int i = ch - 'a';

            if (!root->arr[i]) {
                return false;
            }
             
            root = root->arr[i];
        }

        return true;
    }
};
