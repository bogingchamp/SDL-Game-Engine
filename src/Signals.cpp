#include "Signals.h"

// Register a signal and its associated callback
void Signals::register_signal(const std::string& signal_name, std::function<void()> callback) {
    std::cout << "registering signal\n";
    if (!callback) {
        std::cerr << "Error: Attempted to register an empty callback for signal '" << signal_name << "'\n";
        return;
    }
    
    signal_callbacks[signal_name] = callback;
    std::cout << "Registered signal: " << signal_name << "\n";
}

// Trigger a signal
void Signals::send_signal(const std::string& signal_name) {
    // Check if the signal has an associated callback
    if (signal_callbacks.find(signal_name) != signal_callbacks.end()) {
        on_signal_received(signal_name);
    }
    else {
        std::cerr << "No callback registered for signal: " << signal_name << std::endl;
    }
}

// Call the function associated with the signal
void Signals::on_signal_received(const std::string& signal_name) {
    auto it = signal_callbacks.find(signal_name);
    if (it == signal_callbacks.end()) {
        std::cerr << "Error: Signal '" << signal_name << "' not found.\n";
        return;
    }
    if (!it->second) {
        std::cerr << "Error: Signal '" << signal_name << "' has no valid callback.\n";
        return;
    }

    std::cout << "Signal '" << signal_name << "' received and executing callback\n";
    it->second(); // Execute the callback
}

void Signals::unregister_signal(const std::string& signal_name) {
    signal_callbacks.erase(signal_name);
}
