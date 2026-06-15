// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vagriguard_top__Syms.h"


VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype____0(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype____2(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_sub__TOP__0(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_sub__TOP__0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"clk_16mhz",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+85,0,"pdm_clk_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+86,0,"pdm_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"spi_sck",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"spi_mosi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"spi_miso",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"spi_csn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"fpga_irq",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "agriguard_top", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"clk_16mhz",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+85,0,"pdm_clk_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+86,0,"pdm_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"spi_sck",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"spi_mosi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"spi_miso",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"spi_csn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"fpga_irq",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"pdm_div_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"pcm_strobe_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"pcm_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+97,0,"PCM_STROBE_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 8,0);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"pcm_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"pcm_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"faw_detected",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"faw_pulse",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"mag_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"bin_index",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"bin_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"faw_threshold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"threshold_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fft_engine", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"pcm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"pcm_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"mag_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"bin_index",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"bin_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"faw_detected",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"faw_pulse",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+98,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+99,0,"FAW_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+100,0,"FAW_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"THRESH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"S_COLLECT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"S_BF_FETCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+104,0,"S_BF_MUL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"S_BF_WTOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"S_BF_WBOT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+107,0,"S_OUTPUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"samp_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"bf_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"out_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"half_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"pos",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"addr_top",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"addr_bot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"tw_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"bwe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"bwa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"bwd_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"bwd_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"bra_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"bra_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+70,0,"bqr_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+71,0,"bqi_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+72,0,"bqr_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+73,0,"bqi_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"twa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"tqr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+75,0,"tqi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"sv_top",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"sv_bot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"la_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+55,0,"la_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"m0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"m1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+58,0,"m2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+59,0,"m3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+60,0,"wb_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+61,0,"wb_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"abs_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"abs_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"mag_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"energy_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"out_bin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"in_faw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"sq_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+92,0,"sq_sat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_pdm_decimator", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+86,0,"pdm_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"pcm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"pcm_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"DECIM_RATIO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"CIC_ORDER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"CIC_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+111,0,"DECIM_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);

    Vagriguard_top___024root__trace_init_dtype____0(vlSelf, tracep, "integ", 0, c+5, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"pdm_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 18,0);
    VL_TRACE_DECL_BUS(tracep,c+66,0,"decim_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+67,0,"decim_strobe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "comb_in", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+8+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 18,0);
    }
    VL_TRACE_POP_PREFIX(tracep);

    Vagriguard_top___024root__trace_init_dtype____2(vlSelf, tracep, "comb_dly", 0, c+11, VerilatedTraceSigDirection::NONE);
    VL_TRACE_PUSH_PREFIX(tracep, "comb_out", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+94+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 18,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+68,0,"cic_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 18,0);
    VL_TRACE_DECL_BUS(tracep,c+69,0,"cic_truncated",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_spi_slave", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"spi_sck",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"spi_mosi",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"spi_miso",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"spi_csn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"faw_detected",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"faw_pulse",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"fpga_irq",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"faw_threshold_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"threshold_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"ADDR_STATUS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"ADDR_ANOMALY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+114,0,"ADDR_THRESH_LO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"ADDR_THRESH_HI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"ADDR_CLEAR_IRQ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"sck_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"csn_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"mosi_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+17,0,"sck_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+18,0,"sck_fall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+19,0,"cs_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"mosi_bit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"reg_anomaly",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"reg_thresh_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"reg_thresh_hi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"irq_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+25,0,"rx_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"tx_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+27,0,"bit_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"byte_phase",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+29,0,"is_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"addr_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____0(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype____0(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype____0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vagriguard_top___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____0(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype_sub____0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 18,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____1(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype____1(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype____1\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vagriguard_top___024root__trace_init_dtype_sub____1(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____1(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype_sub____1\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 18,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____2(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype____2(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype____2\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vagriguard_top___024root__trace_init_dtype_sub____2(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____2(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype_sub____2\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 18,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____3(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype____3(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype____3\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vagriguard_top___024root__trace_init_dtype_sub____3(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_dtype_sub____3(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_dtype_sub____3\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (i + 0), 18,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_init_top(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_init_top\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vagriguard_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vagriguard_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vagriguard_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vagriguard_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vagriguard_top___024root__trace_register(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_register\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vagriguard_top___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vagriguard_top___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vagriguard_top___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vagriguard_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_const_0_sub_0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vagriguard_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_const_0\n"); );
    // Body
    Vagriguard_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vagriguard_top___024root*>(voidSelf);
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vagriguard_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_const_0_sub_0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_const_0_sub_0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullSData(oldp+97,(0x014cU),9);
    bufp->fullIData(oldp+98,(0x00000100U),32);
    bufp->fullIData(oldp+99,(0x0000001bU),32);
    bufp->fullIData(oldp+100,(0x00000040U),32);
    bufp->fullIData(oldp+101,(0x00040000U),32);
    bufp->fullCData(oldp+102,(0U),3);
    bufp->fullCData(oldp+103,(1U),3);
    bufp->fullCData(oldp+104,(2U),3);
    bufp->fullCData(oldp+105,(3U),3);
    bufp->fullCData(oldp+106,(4U),3);
    bufp->fullCData(oldp+107,(5U),3);
    bufp->fullIData(oldp+108,(0x00000040U),32);
    bufp->fullIData(oldp+109,(3U),32);
    bufp->fullIData(oldp+110,(0x00000013U),32);
    bufp->fullIData(oldp+111,(6U),32);
    bufp->fullCData(oldp+112,(0U),7);
    bufp->fullCData(oldp+113,(0x20U),7);
    bufp->fullCData(oldp+114,(0x21U),7);
    bufp->fullCData(oldp+115,(0x22U),7);
    bufp->fullCData(oldp+116,(0x7fU),7);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_full_0_sub_0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vagriguard_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_full_0\n"); );
    // Body
    Vagriguard_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vagriguard_top___024root*>(voidSelf);
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vagriguard_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_full_dtype____0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar);
VL_ATTR_COLD void Vagriguard_top___024root__trace_full_dtype____1(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar);

VL_ATTR_COLD void Vagriguard_top___024root__trace_full_0_sub_0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_full_0_sub_0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.agriguard_top__DOT__pdm_div_cnt),3);
    bufp->fullSData(oldp+1,(vlSelfRef.agriguard_top__DOT__pcm_strobe_cnt),9);
    bufp->fullBit(oldp+2,(vlSelfRef.agriguard_top__DOT__pcm_strobe));
    bufp->fullSData(oldp+3,(vlSelfRef.agriguard_top__DOT__faw_threshold),16);
    bufp->fullBit(oldp+4,(vlSelfRef.agriguard_top__DOT__threshold_valid));
    Vagriguard_top___024root__trace_full_dtype____0(vlSelf, bufp, 5, vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ);
    bufp->fullIData(oldp+8,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[0]),19);
    bufp->fullIData(oldp+9,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[1]),19);
    bufp->fullIData(oldp+10,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[2]),19);
    Vagriguard_top___024root__trace_full_dtype____1(vlSelf, bufp, 11, vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly);
    bufp->fullCData(oldp+14,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r),3);
    bufp->fullCData(oldp+15,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r),3);
    bufp->fullCData(oldp+16,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r),2);
    bufp->fullBit(oldp+17,((1U == (3U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r)))));
    bufp->fullBit(oldp+18,((2U == (3U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r)))));
    bufp->fullBit(oldp+19,((1U & (~ ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r) 
                                     >> 1U)))));
    bufp->fullBit(oldp+20,((1U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r))));
    bufp->fullCData(oldp+21,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly),8);
    bufp->fullCData(oldp+22,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo),8);
    bufp->fullCData(oldp+23,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_hi),8);
    bufp->fullBit(oldp+24,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__irq_latch));
    bufp->fullCData(oldp+25,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift),8);
    bufp->fullCData(oldp+26,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__tx_shift),8);
    bufp->fullCData(oldp+27,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__bit_cnt),3);
    bufp->fullBit(oldp+28,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__byte_phase));
    bufp->fullBit(oldp+29,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__is_read));
    bufp->fullCData(oldp+30,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch),7);
    bufp->fullSData(oldp+31,(vlSelfRef.agriguard_top__DOT__pcm_data),16);
    bufp->fullBit(oldp+32,(vlSelfRef.agriguard_top__DOT__pcm_valid));
    bufp->fullBit(oldp+33,(vlSelfRef.agriguard_top__DOT__faw_detected));
    bufp->fullBit(oldp+34,(vlSelfRef.agriguard_top__DOT__faw_pulse));
    bufp->fullSData(oldp+35,(vlSelfRef.agriguard_top__DOT__mag_out),16);
    bufp->fullCData(oldp+36,(vlSelfRef.agriguard_top__DOT__bin_index),8);
    bufp->fullBit(oldp+37,(vlSelfRef.agriguard_top__DOT__bin_valid));
    bufp->fullCData(oldp+38,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state),3);
    bufp->fullCData(oldp+39,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt),8);
    bufp->fullCData(oldp+40,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass),3);
    bufp->fullCData(oldp+41,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt),7);
    bufp->fullCData(oldp+42,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt),8);
    bufp->fullCData(oldp+43,((0x000000ffU & ((IData)(1U) 
                                             << (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)))),8);
    bufp->fullCData(oldp+44,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos),7);
    bufp->fullCData(oldp+45,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_top),8);
    bufp->fullCData(oldp+46,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_bot),8);
    bufp->fullCData(oldp+47,((0x0000007fU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos) 
                                             << (7U 
                                                 & ((IData)(7U) 
                                                    - (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)))))),7);
    bufp->fullBit(oldp+48,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe));
    bufp->fullCData(oldp+49,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa),8);
    bufp->fullSData(oldp+50,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r),16);
    bufp->fullSData(oldp+51,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i),16);
    bufp->fullCData(oldp+52,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_top),8);
    bufp->fullCData(oldp+53,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_bot),8);
    bufp->fullSData(oldp+54,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_r),16);
    bufp->fullSData(oldp+55,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_i),16);
    bufp->fullIData(oldp+56,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m0),32);
    bufp->fullIData(oldp+57,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m1),32);
    bufp->fullIData(oldp+58,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m2),32);
    bufp->fullIData(oldp+59,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m3),32);
    bufp->fullSData(oldp+60,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_r),16);
    bufp->fullSData(oldp+61,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_i),16);
    bufp->fullIData(oldp+62,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc),32);
    bufp->fullCData(oldp+63,((0x000000ffU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                             - (IData)(1U)))),8);
    bufp->fullBit(oldp+64,(((0x1bU <= (0x000000ffU 
                                       & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                          - (IData)(1U)))) 
                            & (0x40U >= (0x000000ffU 
                                         & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                            - (IData)(1U)))))));
    bufp->fullSData(oldp+65,(vlSelfRef.agriguard_top__DOT__pcm_data),16);
    bufp->fullCData(oldp+66,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt),6);
    bufp->fullBit(oldp+67,((0x3fU == (IData)(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt))));
    bufp->fullIData(oldp+68,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result),19);
    bufp->fullSData(oldp+69,((0x0000ffffU & (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result 
                                             >> 3U))),16);
    bufp->fullSData(oldp+70,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a),16);
    bufp->fullSData(oldp+71,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a),16);
    bufp->fullSData(oldp+72,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_b),16);
    bufp->fullSData(oldp+73,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_b),16);
    bufp->fullSData(oldp+74,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqr),16);
    bufp->fullSData(oldp+75,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqi),16);
    bufp->fullSData(oldp+76,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_r),16);
    bufp->fullSData(oldp+77,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_i),16);
    bufp->fullSData(oldp+78,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__mag_v),16);
    bufp->fullIData(oldp+79,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val),32);
    bufp->fullCData(oldp+80,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_a),8);
    bufp->fullCData(oldp+81,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_b),8);
    bufp->fullCData(oldp+82,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__twa),7);
    bufp->fullBit(oldp+83,(vlSelfRef.clk_16mhz));
    bufp->fullBit(oldp+84,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+85,(vlSelfRef.pdm_clk_out));
    bufp->fullBit(oldp+86,(vlSelfRef.pdm_data));
    bufp->fullBit(oldp+87,(vlSelfRef.spi_sck));
    bufp->fullBit(oldp+88,(vlSelfRef.spi_mosi));
    bufp->fullBit(oldp+89,(vlSelfRef.spi_miso));
    bufp->fullBit(oldp+90,(vlSelfRef.spi_csn));
    bufp->fullBit(oldp+91,(vlSelfRef.fpga_irq));
    bufp->fullIData(oldp+92,(((vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc 
                               + vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val) 
                              | (- (IData)((((IData)(0xffffffffU) 
                                             - vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc) 
                                            < vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val))))),32);
    bufp->fullIData(oldp+93,((0x0007ffffU & (1U | (- (IData)(
                                                             (1U 
                                                              & (~ (IData)(vlSelfRef.pdm_data)))))))),19);
    bufp->fullIData(oldp+94,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[0]),19);
    bufp->fullIData(oldp+95,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[1]),19);
    bufp->fullIData(oldp+96,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[2]),19);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_full_dtype____0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_full_dtype____0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),19);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),19);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),19);
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_full_dtype____1(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_full_dtype____1\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[0]),19);
    bufp->fullIData(oldp+1,(__VdtypeVar[1]),19);
    bufp->fullIData(oldp+2,(__VdtypeVar[2]),19);
}
