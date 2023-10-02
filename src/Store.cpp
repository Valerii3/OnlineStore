//
// Created by Valerii.Ovchinnikov on 01.10.23.
//

#include "../include/Store.h"

namespace OnlineStore {

void Store::add(const std::string &product) {
    if (!get_product(product)) {
        products[product] = std::vector<int64_t>();
    }
}

void Store::add_purchase(const std::string &product, int64_t timestamp) {
    if (!get_product(product)) {
        throw std::runtime_error("No such product in our system");
    }
    products[product].push_back(timestamp);
}

int Store::count(const std::string &product,
                 int64_t count_from,
                 int64_t count_to) {
    if (!get_product(product)) {
        throw std::runtime_error("No such product in our system");
    }
    auto lower = std::lower_bound(products[product].begin(),
                                  products[product].end(), count_from);
    auto upper = std::upper_bound(products[product].begin(),
                                  products[product].end(), count_to);

    return std::distance(lower, upper);
}

}  // namespace OnlineStore
