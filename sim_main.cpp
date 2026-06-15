#include "Vagriguard_top.h"
#include "verilated.h"
#include "renode_bus.h"
#include <cstdio>
#include <cstdlib>

// Global Verilator top instance
Vagriguard_top* top = nullptr;

// The Init function required by the Renode library
RenodeAgent* Init() {
    return new RenodeAgent();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    top = new Vagriguard_top;
    RenodeAgent* agent = Init();
    
    if (argc >= 3) {
        printf("Connecting to Renode on ports %s / %s...\n", argv[1], argv[2]);
        agent->connect(atoi(argv[1]), atoi(argv[2]), "127.0.0.1");
        agent->simulate();
    } else {
        printf("Standalone mode - AgriGuard simulation\n");
        printf("For Renode: %s <receiver_port> <sender_port>\n", argv[0]);
        
        top->clk_16mhz = 0;
        top->rst_n = 0;
        top->pdm_data = 0;
        top->spi_sck = 0;
        top->spi_mosi = 0;
        top->spi_csn = 1;
        
        for (int i = 0; i < 10; i++) {
            top->clk_16mhz = !top->clk_16mhz;
            top->eval();
        }
        top->rst_n = 1;
        
        for (int i = 0; i < 100; i++) {
            top->clk_16mhz = !top->clk_16mhz;
            top->eval();
            if (top->clk_16mhz) {
                printf("Cycle %d: pdm_clk_out=%d, fpga_irq=%d\n", 
                       i/2, top->pdm_clk_out, top->fpga_irq);
            }
        }
    }
    
    top->final();
    delete top;
    return 0;
}
