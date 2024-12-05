/*
* 
    Signals in use:
        start_game  <- runs initialization code and changes scene to main game scene

*/






#ifndef SIGNALS_H
#define SIGNALS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <string>

class Signals {
private:
    // Map signal names to their corresponding functions
    std::unordered_map<std::string, std::function<void()>> signal_callbacks;

public:
    // Register a signal with a corresponding callback
    void register_signal(const std::string& signal_name, std::function<void()> callback);

    // Send (trigger) a signal
    void send_signal(const std::string& signal_name);

    // Call the function associated with the signal (if registered)
    void on_signal_received(const std::string& signal_name);

    void unregister_signal(const std::string& signal_name);
};

#endif
