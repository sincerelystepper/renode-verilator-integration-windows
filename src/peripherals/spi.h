#ifndef SPI_H
#define SPI_H

#include "../renode.h"

// Minimal placeholder for the AgriGuard SPI integration agent
class SPI : public RenodeAgent {
public:
    SPI(BufferLink *bus) : RenodeAgent(bus) {}
};

#endif // SPI_H
