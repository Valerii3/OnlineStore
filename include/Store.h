// Created by Valerii.Ovchinnikov on 01.10.23.

#ifndef ONLINE_STORE_H  // Include guard to prevent double inclusion
#define ONLINE_STORE_H

#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace OnlineStore {

struct Store {
private:
    std::unordered_map<std::string, std::vector<int64_t>> products;

    [[nodiscard]] bool get_product(const std::string &item) const {
        return products.find(item) != products.end();
    }

public:
    void add(const std::string &product);
    void add_purchase(const std::string &product, int64_t timestamp);
    int count(const std::string &product, int64_t count_from, int64_t count_to);
};

}  // namespace OnlineStore

#endif  // ONLINE_STORE_H
