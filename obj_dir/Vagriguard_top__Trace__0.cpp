// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vagriguard_top__Syms.h"


void Vagriguard_top___024root__trace_chg_0_sub_0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vagriguard_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_chg_0\n"); );
    // Body
    Vagriguard_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vagriguard_top___024root*>(voidSelf);
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vagriguard_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vagriguard_top___024root__trace_chg_dtype____0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar);
void Vagriguard_top___024root__trace_chg_dtype____1(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar);

void Vagriguard_top___024root__trace_chg_0_sub_0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_chg_0_sub_0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.agriguard_top__DOT__pdm_div_cnt),3);
        bufp->chgSData(oldp+1,(vlSelfRef.agriguard_top__DOT__pcm_strobe_cnt),9);
        bufp->chgBit(oldp+2,(vlSelfRef.agriguard_top__DOT__pcm_strobe));
        bufp->chgSData(oldp+3,(vlSelfRef.agriguard_top__DOT__faw_threshold),16);
        bufp->chgBit(oldp+4,(vlSelfRef.agriguard_top__DOT__threshold_valid));
        Vagriguard_top___024root__trace_chg_dtype____0(vlSelf, bufp, 5, vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ);
        bufp->chgIData(oldp+8,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[0]),19);
        bufp->chgIData(oldp+9,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[1]),19);
        bufp->chgIData(oldp+10,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[2]),19);
        Vagriguard_top___024root__trace_chg_dtype____1(vlSelf, bufp, 11, vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly);
        bufp->chgCData(oldp+14,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r),3);
        bufp->chgCData(oldp+15,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r),3);
        bufp->chgCData(oldp+16,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r),2);
        bufp->chgBit(oldp+17,((1U == (3U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r)))));
        bufp->chgBit(oldp+18,((2U == (3U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r)))));
        bufp->chgBit(oldp+19,((1U & (~ ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r) 
                                        >> 1U)))));
        bufp->chgBit(oldp+20,((1U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r))));
        bufp->chgCData(oldp+21,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly),8);
        bufp->chgCData(oldp+22,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo),8);
        bufp->chgCData(oldp+23,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_hi),8);
        bufp->chgBit(oldp+24,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__irq_latch));
        bufp->chgCData(oldp+25,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift),8);
        bufp->chgCData(oldp+26,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__tx_shift),8);
        bufp->chgCData(oldp+27,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__bit_cnt),3);
        bufp->chgBit(oldp+28,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__byte_phase));
        bufp->chgBit(oldp+29,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__is_read));
        bufp->chgCData(oldp+30,(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch),7);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgSData(oldp+31,(vlSelfRef.agriguard_top__DOT__pcm_data),16);
        bufp->chgBit(oldp+32,(vlSelfRef.agriguard_top__DOT__pcm_valid));
        bufp->chgBit(oldp+33,(vlSelfRef.agriguard_top__DOT__faw_detected));
        bufp->chgBit(oldp+34,(vlSelfRef.agriguard_top__DOT__faw_pulse));
        bufp->chgSData(oldp+35,(vlSelfRef.agriguard_top__DOT__mag_out),16);
        bufp->chgCData(oldp+36,(vlSelfRef.agriguard_top__DOT__bin_index),8);
        bufp->chgBit(oldp+37,(vlSelfRef.agriguard_top__DOT__bin_valid));
        bufp->chgCData(oldp+38,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state),3);
        bufp->chgCData(oldp+39,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt),8);
        bufp->chgCData(oldp+40,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass),3);
        bufp->chgCData(oldp+41,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt),7);
        bufp->chgCData(oldp+42,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt),8);
        bufp->chgCData(oldp+43,((0x000000ffU & ((IData)(1U) 
                                                << (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)))),8);
        bufp->chgCData(oldp+44,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos),7);
        bufp->chgCData(oldp+45,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_top),8);
        bufp->chgCData(oldp+46,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_bot),8);
        bufp->chgCData(oldp+47,((0x0000007fU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos) 
                                                << 
                                                (7U 
                                                 & ((IData)(7U) 
                                                    - (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)))))),7);
        bufp->chgBit(oldp+48,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe));
        bufp->chgCData(oldp+49,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa),8);
        bufp->chgSData(oldp+50,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r),16);
        bufp->chgSData(oldp+51,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i),16);
        bufp->chgCData(oldp+52,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_top),8);
        bufp->chgCData(oldp+53,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_bot),8);
        bufp->chgSData(oldp+54,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_r),16);
        bufp->chgSData(oldp+55,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_i),16);
        bufp->chgIData(oldp+56,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m0),32);
        bufp->chgIData(oldp+57,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m1),32);
        bufp->chgIData(oldp+58,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m2),32);
        bufp->chgIData(oldp+59,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m3),32);
        bufp->chgSData(oldp+60,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_r),16);
        bufp->chgSData(oldp+61,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_i),16);
        bufp->chgIData(oldp+62,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc),32);
        bufp->chgCData(oldp+63,((0x000000ffU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                                - (IData)(1U)))),8);
        bufp->chgBit(oldp+64,(((0x1bU <= (0x000000ffU 
                                          & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                             - (IData)(1U)))) 
                               & (0x40U >= (0x000000ffU 
                                            & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                               - (IData)(1U)))))));
        bufp->chgSData(oldp+65,(vlSelfRef.agriguard_top__DOT__pcm_data),16);
        bufp->chgCData(oldp+66,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt),6);
        bufp->chgBit(oldp+67,((0x3fU == (IData)(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt))));
        bufp->chgIData(oldp+68,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result),19);
        bufp->chgSData(oldp+69,((0x0000ffffU & (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result 
                                                >> 3U))),16);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[3U]))) {
        bufp->chgSData(oldp+70,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a),16);
        bufp->chgSData(oldp+71,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a),16);
        bufp->chgSData(oldp+72,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_b),16);
        bufp->chgSData(oldp+73,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_b),16);
        bufp->chgSData(oldp+74,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqr),16);
        bufp->chgSData(oldp+75,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqi),16);
        bufp->chgSData(oldp+76,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_r),16);
        bufp->chgSData(oldp+77,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_i),16);
        bufp->chgSData(oldp+78,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__mag_v),16);
        bufp->chgIData(oldp+79,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgCData(oldp+80,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_a),8);
        bufp->chgCData(oldp+81,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_b),8);
        bufp->chgCData(oldp+82,(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__twa),7);
    }
    bufp->chgBit(oldp+83,(vlSelfRef.clk_16mhz));
    bufp->chgBit(oldp+84,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+85,(vlSelfRef.pdm_clk_out));
    bufp->chgBit(oldp+86,(vlSelfRef.pdm_data));
    bufp->chgBit(oldp+87,(vlSelfRef.spi_sck));
    bufp->chgBit(oldp+88,(vlSelfRef.spi_mosi));
    bufp->chgBit(oldp+89,(vlSelfRef.spi_miso));
    bufp->chgBit(oldp+90,(vlSelfRef.spi_csn));
    bufp->chgBit(oldp+91,(vlSelfRef.fpga_irq));
    bufp->chgIData(oldp+92,(((vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc 
                              + vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val) 
                             | (- (IData)((((IData)(0xffffffffU) 
                                            - vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc) 
                                           < vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val))))),32);
    bufp->chgIData(oldp+93,((0x0007ffffU & (1U | (- (IData)(
                                                            (1U 
                                                             & (~ (IData)(vlSelfRef.pdm_data)))))))),19);
    bufp->chgIData(oldp+94,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[0]),19);
    bufp->chgIData(oldp+95,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[1]),19);
    bufp->chgIData(oldp+96,(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[2]),19);
}

void Vagriguard_top___024root__trace_chg_dtype____0(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_chg_dtype____0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),19);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),19);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),19);
}

void Vagriguard_top___024root__trace_chg_dtype____1(Vagriguard_top___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*18:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_chg_dtype____1\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),19);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),19);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),19);
}

void Vagriguard_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root__trace_cleanup\n"); );
    // Body
    Vagriguard_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vagriguard_top___024root*>(voidSelf);
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
