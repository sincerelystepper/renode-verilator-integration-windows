// renode_agent.h
#ifndef RENODE_AGENT_H
#define RENODE_AGENT_H

#include <string>
#include <vector>
#include <functional>
#include <cstdint>
#include <stdexcept>

// Forward declare socket channel from your communication folder
// We'll handle this properly based on what's in your project
#ifdef USE_SOCKET_CHANNEL
#include "communication/socket_channel.h"
#endif

class RenodeAgent {
public:
    RenodeAgent() : initialized(false) {}
    ~RenodeAgent() {}

    void init();

    // Add input signal (Renode writes to this)
    template<typename T>
    void addInput(T* signal_ptr, const std::string& name) {
        signals.push_back({
            reinterpret_cast<void*>(signal_ptr),
            name,
            true,
            sizeof(T)
            });
    }

    // Add output signal (Renode reads this)
    template<typename T>
    void addOutput(T* signal_ptr, const std::string& name) {
        signals.push_back({
            reinterpret_cast<void*>(signal_ptr),
            name,
            false,
            sizeof(T)
            });
    }

    // Set the evaluation function (called each simulation step)
    void setEvaluateModel(std::function<void()> func) {
        eval_func = func;
    }

    // For compatibility with agent->evaluateModel = &eval_model syntax
    void operator=(std::function<void()> func) {
        setEvaluateModel(func);
    }

    // Main simulation loop
    void simulate(int input_port, int output_port);

private:
    struct SignalInfo {
        void* signal_ptr;
        std::string name;
        bool is_input;
        size_t width_bytes;
    };

    std::vector<SignalInfo> signals;
    std::function<void()> eval_func;
    bool initialized;

    void receiveInputs();
    void sendOutputs();
};

#endif // RENODE_AGENT_H