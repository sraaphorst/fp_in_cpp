/**
 * listing3_6.cpp
 *
 * By Sebastian Raaphorst, 2019.
 */

#include <iostream>
#include <memory>

// Error when working with move-only types.
struct NetworkConnection {
    NetworkConnection() = default;
    NetworkConnection(const NetworkConnection&) = delete;
    NetworkConnection(NetworkConnection&&) = delete;
    const NetworkConnection &operator=(const NetworkConnection &other) = delete;
};

int current_time() {
    return 0;
}

int main() {
    auto conn = std::make_unique<NetworkConnection>();

    // There's no copy constructor for std::unique_ptr<NetworkConnection>.
    // Nope: auto on_completed = [conn](const auto result) { std::cout << "Result!\n"; };
    // Instead, we can move.
    auto on_completed = [connection = std::move(conn), time=current_time()] {
        std::cout << "Do the things.\n";
    };

    on_completed();
}
