
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class Key, class Value>
class SymbolTable {
private:
    struct Node {
        Key key;
        Value value;
        Node* next;

        Node(Key k, Value v, Node* n) {
            key = k;
            value = v;
            next = n;
        }
    };

    Node* first;
    int n;

public:
    SymbolTable() {
        first = nullptr;
        n = 0;
    }

    ~SymbolTable() {
        while (first != nullptr) {
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

    void put(Key key, Value value) {
        for (Node* x = first; x != nullptr; x = x->next) {
            if (x->key == key) {
                x->value = value;
                return;
            }
        }

        first = new Node(key, value, first);
        n++;
    }

    bool get(Key key, Value& value) const {
        for (Node* x = first; x != nullptr; x = x->next) {
            if (x->key == key) {
                value = x->value;
                return true;
            }
        }
        return false;
    }

    bool contains(Key key) const {
        Value value;
        return get(key, value);
    }

    void deleteKey(Key key) {
        Node** current = &first;

        while (*current != nullptr) {
            if ((*current)->key == key) {
                Node* temp = *current;
                *current = temp->next;
                delete temp;
                n--;
                return;
            }
            current = &((*current)->next);
        }
    }

    bool isEmpty() const {
        return n == 0;
    }

    int size() const {
        return n;
    }

    vector<Key> keys() const {
        vector<Key> result;

        for (Node* x = first; x != nullptr; x = x->next) {
            result.push_back(x->key);
        }

        return result;
    }
};

int main() {
    SymbolTable<string, int> st;

    st.put("S", 0);
    st.put("E", 1);
    st.put("A", 2);
    st.put("R", 3);
    st.put("C", 4);
    st.put("H", 5);
    st.put("E", 6);

    int value;

    if (st.get("E", value)) {
        cout << "E: " << value << endl;
    }

    cout << "Size: " << st.size() << endl;

    st.deleteKey("A");

    cout << "After delete A:" << endl;

    for (string key : st.keys()) {
        if (st.get(key, value)) {
            cout << key << " " << value << endl;
        }
    }

    return 0;
}
