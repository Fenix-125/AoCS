//
// Created by fenix on 5/10/20.
//

#include <map>
#include <mutex>

template<class Key, class Val>
class map_mt {
    std::map<Key, Val> map_m;
    mutable std::mutex mux;
public:
    explicit map_mt(const std::map<Key, Val> map) : map_m(std::copy(map)) {}

    explicit map_mt(std::map<Key, Val> &&map) : map_m(std::move(map)) {}

    Val get(const Key &key) const {
        std::lock_guard<std::mutex> lock_g{mux};
        return map_m.at(key);
    }

    void set(Key key, Val val) const {
        std::lock_guard<std::mutex> lock_g{mux};
        return map_m.insert(key, val);
    }

    Val operator[](Key key) const {
        std::lock_guard<std::mutex> lock_g{mux};
        return map_m[key];
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock_g{mux};
        return map_m.size();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock_g{mux};
        return map_m.empty();
    }
};

