
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class Key, class Value>
class SymbolTable {
private:
    vector<Key> keysArray;
    vector<Value> valuesArray;

    int rank(Key key) const {
        int lo = 0;
        int hi = (int)keysArray.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (key < keysArray[mid]) {
                hi = mid - 1;
            }
            else if (keysArray[mid] < key) {
                lo = mid + 1;
            }
            else {
                return mid;
            }
        }

        return lo;
    }

public:
    SymbolTable() {}

    void put(Key key, Value value) {
        int i = rank(key);

        if (i < (int)keysArray.size() &&
            !(key < keysArray[i]) &&
            !(keysArray[i] < key)) {
            valuesArray[i] = value;
            return;
        }

        keysArray.insert(keysArray.begin() + i, key);
        valuesArray.insert(valuesArray.begin() + i, value);
    }

    bool get(Key key, Value& value) const {
        if (isEmpty()) {
            return false;
        }

        int i = rank(key);

        if (i < (int)keysArray.size() &&
            !(key < keysArray[i]) &&
            !(keysArray[i] < key)) {
            value = valuesArray[i];
            return true;
        }

        return false;
    }

    bool contains(Key key) const {
        Value value;
        return get(key, value);
    }

    void deleteKey(Key key) {
        int i = rank(key);

        if (i < (int)keysArray.size() &&
            !(key < keysArray[i]) &&
            !(keysArray[i] < key)) {
            keysArray.erase(keysArray.begin() + i);
            valuesArray.erase(valuesArray.begin() + i);
        }
    }

    bool isEmpty() const {
        return keysArray.empty();
    }

    int size() const {
        return (int)keysArray.size();
    }

    vector<Key> keys() const {
        return keysArray;
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
