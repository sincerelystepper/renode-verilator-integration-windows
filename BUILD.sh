#!/bin/bash
echo "=============================================="
echo " BUILDING AGRIGUARD - FINAL"
echo "=============================================="

rm -f *.o Agriguard.exe

# Fix corrupted src/renode_bus.h
if head -1 src/renode_bus.h 2>/dev/null | grep -q "Check if"; then
    cp src/IntegrationLibrary/src/renode_bus.h src/renode_bus.h
    sed -i 's|#include "src/|#include "|g' src/renode_bus.h
    sed -i 's|#include ".*Infrastructure.*renode_imports.h"|// not available|g' src/renode_bus.h
fi

# Fix EXTERNAL_AS
sed -i 's|EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr);|extern "C" void HandleMainMessage(void* ptr) { handleMainMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, HandleSenderMessage, handleSenderMessage, voidptr);|extern "C" void HandleSenderMessage(void* ptr) { handleSenderMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, Receive, receive, voidptr);|extern "C" void Receive(void* ptr) { receive(ptr); }|g' src/renode_bus.cpp

# Fix includes
find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec sed -i 's|#include "src/|#include "|g' {} \;

# Setup dirs
mkdir -p hdl/includes src/communication
cp src/IntegrationLibrary/hdl/includes/renode_action_enumerators.svh hdl/includes/ 2>/dev/null
cp src/IntegrationLibrary/src/communication/communication_channel.h src/communication/ 2>/dev/null

V="C:/msys64/ucrt64/share/verilator/include"

g++ -Wall -Os -std=c++17 \
  -include cstring -include string.h \
  -I. -Iobj_dir -Isrc -Isrc/peripherals -Isrc/buses -Isrc/communication \
  -Isrc/IntegrationLibrary/src \
  -Isrc/IntegrationLibrary/src/communication \
  -Isrc/IntegrationLibrary/src/buses \
  -Isrc/IntegrationLibrary/src/peripherals \
  -Isrc/IntegrationLibrary/libs/socket-cpp/Socket \
  -Ihdl/includes -I"$V" \
  dpi_stubs.cpp \
  sim_main.cpp \
  src/renode_bus.cpp \
  src/renode_dpi.cpp \
  src/buses/bus.cpp \
  src/IntegrationLibrary/src/communication/socket_channel.cpp \
  src/IntegrationLibrary/libs/socket-cpp/Socket/TCPClient.cpp \
  src/IntegrationLibrary/libs/socket-cpp/Socket/Socket.cpp \
  obj_dir/Vagriguard_top.cpp \
  obj_dir/Vagriguard_top___024root__0.cpp \
  obj_dir/Vagriguard_top___024root__Slow.cpp \
  obj_dir/Vagriguard_top__Syms__Slow.cpp \
  obj_dir/Vagriguard_top___024root__0__Slow.cpp \
  "$V/verilated.cpp" \
  "$V/verilated_vcd_c.cpp" \
  "$V/verilated_threads.cpp" \
  -o Agriguard.exe \
  -lws2_32 -Wno-unknown-pragmas 2>&1 | tee build.log

if [ ${PIPESTATUS[0]} -eq 0 ]; then
    echo "=============================================="
    echo "  ✓ BUILD SUCCESSFUL!"
    echo "=============================================="
    ls -la Agriguard.exe
    echo ""
    echo "Run: ./Agriguard.exe"
else
    echo "=============================================="
    grep "undefined reference\|error:" build.log | head -15
fi
