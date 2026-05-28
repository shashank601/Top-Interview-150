class Node {
public:
    Node* arr[26] = {};
    bool end = false;
};

class WordDictionary {
public:
    Node* head;

    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node* root = head;
        for (auto& ch : word) {
            int i = ch  - 'a';

            if (!root->arr[i]) {
                root->arr[i] = new Node();
            }
            root = root->arr[i];
        }
        root->end = true;
    }


    bool g(int p, string& word, Node* root) {
        if (!root) return false;
        if (p == word.length()) return root->end;
        

        for (int idx = p; idx < word.length(); idx++) {
            char ch = word[idx];

            if (ch == '.') {
                
                for (int i = 0; i < 26; i++) {
                    if (root->arr[i] && g(idx + 1, word, root->arr[i])) {
                        return true;
                    }
                }

                return false;

            } else {

                int i = ch - 'a';

                if (!root->arr[i]) {
                    return false;
                }

                root = root->arr[i];

            }
        }

        return root->end;
    }
    
    bool search(string word) {
        
        return g(0, word, head);
    }
};


=========

this hybrid is poor,

use dfs on every idx instead of doing iteration + recursion
