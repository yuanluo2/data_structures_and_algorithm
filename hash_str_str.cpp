#include <iostream>
#include <string>

constexpr size_t DEFAULT_BUCKET_SIZE = 101;

struct HashNode {
    std::string key;
    std::string value;
    HashNode* next;
};

class HashTable {
    HashNode* bucket[DEFAULT_BUCKET_SIZE];
    size_t length;

    unsigned int hash(const std::string& key) {
        // algorithm copied from K & R
        unsigned int hashval = 0;

        for (size_t i = 0; i < key.length(); ++i) {
            hashval = key[i] + hashval * 31;
        }

        return hashval % DEFAULT_BUCKET_SIZE;
    }

    HashNode* search(const std::string& key) {
        unsigned int hashval = hash(key);
        HashNode* node = bucket[hashval];

        if (node == nullptr) {
            return nullptr;
        }
        else {
            while (node != nullptr) {
                if (node->key == key) {
                    return node;
                }
                else {
                    node = node->next;
                }
            }

            return nullptr;
        }
    }
public:
    HashTable() : length{ 0 } {
        for (size_t i = 0; i < DEFAULT_BUCKET_SIZE; ++i) {
            bucket[i] = nullptr;
        }
    }

    ~HashTable() noexcept {
        HashNode* node;

        for (size_t i = 0; i < DEFAULT_BUCKET_SIZE; ++i) {
            while (bucket[i] != nullptr) {
                node = bucket[i]->next;
                delete bucket[i];
                bucket[i] = node;
            }
        }

        length = 0;
    }

    bool contains_key(const std::string& key) {
        return search(key) != nullptr;
    }

    const std::string& get(const std::string& key) {
        return search(key)->value;
    }

    size_t get_length() const noexcept {
        return length;
    }

    void add(const std::string& key, const std::string& value) {
        HashNode* node = search(key);

        if (node != nullptr) {
            node->value = value;
        }
        else {
            unsigned int hashval = hash(key);
            
            node = new HashNode;
            node->key = key;
            node->value = value;

            if (bucket[hashval] != nullptr) {
                node->next = bucket[hashval];
                bucket[hashval] = node;
            }
            else {
                bucket[hashval] = node;
                node->next = nullptr;
            }

            length += 1;
        }
    }
};

int main() {
    HashTable ht;

    ht.add("fed", "add");
    ht.add("abc3", "done");
    ht.add("fed", "def");

    if (ht.contains_key("fed")) {
        std::cout << ht.get("fed") << "\n";
    }
    else {
        std::cout << "not exist\n";
    }

    return 0;
}
