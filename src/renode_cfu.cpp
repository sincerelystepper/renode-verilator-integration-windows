#include "Vagriguard_top.h"
#include "verilated.h"
#include "renode.h" // This is the header that defines RenodeAgent

int cfu_main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vagriguard_top* top = new Vagriguard_top;

    // The Agent facilitates the connection to Renode
    RenodeAgent* agent = new RenodeAgent();

    // You must initialize the agent to open the socket
    agent->init();

    // Now, instead of a manual loop, you give control to the agent
    while (!Verilated::gotFinish()) {
        agent->step(top); // This drives the clock and handles Renode messages
    }

    delete top;
    return 0;
}