#include <iostream>

using namespace std;

int Hash(const string &key) {
    int sumation = 0;
    int hash;
    for (int i = 0; i < key.length(); i++) {
        sumation += int(key[i]) * (i + 1);
    }
    hash = (19 * sumation) % 101;
    return hash;
}

class SimpleHashTable {
public:
    string storage[101];
    int size = 0;

    void clear() {
        size = 0;
        fill(begin(storage), end(storage), "");
    }

    void add(const string &value) {
        int comparisonHash = Hash(value);
        int hashLocation = comparisonHash;

        if (storage[hashLocation] == value) {
            return;
        } else {
            for (int j = 1; j <= 19; j++) {
                hashLocation = (comparisonHash + (23 * j) + (j * j)) % 101;
                if (storage[hashLocation] == value) {
                    return;
                }
            }
        }
        hashLocation = comparisonHash;
        if (storage[hashLocation].empty()) {
            storage[hashLocation] = value;
            size++;
            return;
        } else {
            for (int j = 1; j <= 19; j++) {
                hashLocation = (comparisonHash + (23 * j) + (j * j)) % 101;
                if (storage[hashLocation].empty()) {
                    storage[hashLocation] = value;
                    size++;
                    return;
                }
            }
        }

        return;
    }

    bool dell(const string &value) {
        for (auto &i : storage) {
            if (i == value) {
                i = "";
                size--;
                return true;
            }
        }
        return false;
    }

};

int main() {
    string str_builder;

    SimpleHashTable hashTable;

    int numb_of_cases;
    int numb_of_query;

    string raw_input;

    scanf("%d\n", &numb_of_cases);

    for (int i = 0; i < numb_of_cases; ++i) {
        scanf("%d\n", &numb_of_query);

        for (int j = 0; j < numb_of_query; ++j) {
            cin >> raw_input;
            string value(raw_input.begin() + 4, raw_input.end());
            char comand = raw_input[0];
            switch (comand) {
                case 'A':
                    hashTable.add(value);
                    break;
                case 'D':
                    hashTable.dell(value);
                    break;
                default:
                    break;
            }
        }

        str_builder += to_string(hashTable.size) + "\n";
        for (int j = 0; j < 101; ++j) {
            if (hashTable.storage[j] != "") {
                str_builder += to_string(j) + ":" + hashTable.storage[j] + "\n";
            }
        }
        hashTable.clear();
    }
    str_builder.pop_back();
    cout << str_builder;
    return 0;
}