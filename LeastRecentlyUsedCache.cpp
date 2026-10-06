#include <iostream>
#include <list>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

template <typename Key, typename Value>
class LRUCache {
private:
    // Front = most recently used
    // Back  = least recently used
    using ListNode = std::pair<Key, Value>;
    using List = std::list<ListNode>;
    using Iterator = typename List::iterator;

    std::size_t capacity_;
    List items_;

    // Maps a key to its position in the linked list.
    std::unordered_map<Key, Iterator> lookup_;

public:
    explicit LRUCache(std::size_t capacity)
        : capacity_(capacity)
    {
        if (capacity == 0) {
            throw std::invalid_argument("LRU cache capacity must be > 0");
        }
    }

    std::optional<Value> get(const Key& key)
    {
        auto it = lookup_.find(key);

        if (it == lookup_.end()) {
            return std::nullopt;
        }

        // Move the accessed item to the front.
        items_.splice(items_.begin(), items_, it->second);

        return it->second->second;
    }

    void put(const Key& key, const Value& value)
    {
        auto it = lookup_.find(key);

        // Key already exists.
        if (it != lookup_.end()) {
            it->second->second = value;

            // Existing key is now the most recently used.
            items_.splice(items_.begin(), items_, it->second);

            return;
        }

        // Add new item to the front.
        items_.emplace_front(key, value);

        lookup_[key] = items_.begin();

        // Remove least recently used item if capacity is exceeded.
        if (items_.size() > capacity_) {
            auto last = std::prev(items_.end());

            lookup_.erase(last->first);
            items_.pop_back();
        }
    }

    std::size_t size() const
    {
        return items_.size();
    }
};


int main()
{
    LRUCache<std::string, int> cache(3);

    cache.put("A", 1);
    cache.put("B", 2);
    cache.put("C", 3);

    std::cout << cache.get("A").value_or(-1) << '\n';

    cache.put("D", 4);

    // B should have been evicted.
    std::cout << cache.get("B").value_or(-1) << '\n';

    std::cout << cache.get("A").value_or(-1) << '\n';
    std::cout << cache.get("C").value_or(-1) << '\n';
    std::cout << cache.get("D").value_or(-1) << '\n';

    std::cout << "Size: " << cache.size() << '\n';

    return 0;
}