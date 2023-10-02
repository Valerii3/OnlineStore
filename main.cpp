#include <iostream>
#include <sstream>
#include "include/Store.h"

std::vector<std::string> parseArguments(const std::string &input) {
    std::istringstream stream(input);
    std::vector<std::string> args;
    std::string arg;
    while (stream >> arg) {
        args.push_back(arg);
    }
    return args;
}

int parse_timestamp(const std::string &timestamp) {
    size_t pos = 0;

    int number = std::stoi(timestamp, &pos);
    if (pos < timestamp.size()) {  // Check if the entire string was processed
        throw std::invalid_argument("The string contains non-digit characters");
    }
    return number;
}

void execute_command(const std::vector<std::string> &commands,
                     OnlineStore::Store &store) {
    if (commands.empty()) {
        throw std::runtime_error("Empty command");
    }

    const std::string &command = commands[0];

    if (command == "ADD") {
        if (commands.size() < 2) {
            throw std::runtime_error("ADD command requires a product argument");
        }
        store.add(commands[1]);
    } else if (command == "BUY") {
        if (commands.size() < 2) {
            throw std::runtime_error(
                "BUY command requires a timestamp and product argument");
        }
        int number = parse_timestamp(commands[1]);
        store.add_purchase(commands[2], number);

    } else if (command == "COUNT") {
        if (commands.size() < 4) {
            throw std::runtime_error(
                "COUNT command requires a product argument and timestamps");
        }

        int count_from = parse_timestamp(commands[2]);
        int count_to = parse_timestamp(commands[3]);
        int result = store.count(commands[1], count_from, count_to);
        std::cout << result << '\n';

    } else {
        throw std::runtime_error("Unknown command");
    }
}

int main() {
    OnlineStore::Store store;
    std::string input;
    while (std::getline(std::cin, input, '\n')) {
        std::vector<std::string> commands = parseArguments(input);
        try {
            execute_command(commands, store);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
