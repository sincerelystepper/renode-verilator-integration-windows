// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vagriguard_top.h for the primary calling header

#include "Vagriguard_top__pch.h"

void Vagriguard_top___024root___eval_triggers_vec__act(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___eval_triggers_vec__act\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk_16mhz) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk_16mhz__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk_16mhz__0 = vlSelfRef.clk_16mhz;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

bool Vagriguard_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vagriguard_top___024root___nba_sequent__TOP__0(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___nba_sequent__TOP__0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*18:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    CData/*2:0*/ __Vdly__agriguard_top__DOT__pdm_div_cnt;
    __Vdly__agriguard_top__DOT__pdm_div_cnt = 0;
    SData/*8:0*/ __Vdly__agriguard_top__DOT__pcm_strobe_cnt;
    __Vdly__agriguard_top__DOT__pcm_strobe_cnt = 0;
    CData/*2:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__sck_r;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__sck_r = 0;
    CData/*2:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__csn_r;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__csn_r = 0;
    CData/*1:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__mosi_r;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__mosi_r = 0;
    CData/*7:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly = 0;
    CData/*2:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt = 0;
    CData/*0:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase = 0;
    CData/*7:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift = 0;
    CData/*7:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__rx_shift;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__rx_shift = 0;
    CData/*7:0*/ __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo = 0;
    IData/*18:0*/ __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0;
    __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0 = 0;
    IData/*18:0*/ __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1;
    __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1 = 0;
    IData/*18:0*/ __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2;
    __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v3;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v3 = 0;
    IData/*18:0*/ __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0;
    __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0 = 0;
    IData/*18:0*/ __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1;
    __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1 = 0;
    IData/*18:0*/ __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2;
    __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2 = 0;
    CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v3;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v3 = 0;
    // Body
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__sck_r 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__mosi_r 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r;
    __Vdly__agriguard_top__DOT__pcm_strobe_cnt = vlSelfRef.agriguard_top__DOT__pcm_strobe_cnt;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt 
        = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt;
    __Vdly__agriguard_top__DOT__pdm_div_cnt = vlSelfRef.agriguard_top__DOT__pdm_div_cnt;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__csn_r 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v3 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2 = 0U;
    __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v3 = 0U;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_a;
    vlSelfRef.__Vdly__agriguard_top__DOT__mag_out = vlSelfRef.agriguard_top__DOT__mag_out;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__samp_cnt 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_b 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_b;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__twa 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__twa;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__energy_acc 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__out_cnt 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt;
    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__bit_cnt;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__rx_shift 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__byte_phase;
    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift 
        = vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__tx_shift;
    if (vlSelfRef.rst_n) {
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__sck_r 
            = ((6U & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r) 
                      << 1U)) | (IData)(vlSelfRef.spi_sck));
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__mosi_r 
            = ((2U & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r) 
                      << 1U)) | (IData)(vlSelfRef.spi_mosi));
        if ((0x3fU == (IData)(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt))) {
            vlSelfRef.__Vdly__agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt = 0U;
            __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0 
                = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[2U];
            __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0 = 1U;
            vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_hf1fe9153__0 
                = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[0U];
            __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1 
                = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_hf1fe9153__0;
            __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1 = 1U;
            vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_hf1fe9153__0 
                = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[1U];
            __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2 
                = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_hf1fe9153__0;
            __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2 = 1U;
        } else {
            vlSelfRef.__Vdly__agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt 
                = (0x0000003fU & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt)));
        }
        if ((4U == (IData)(vlSelfRef.agriguard_top__DOT__pdm_div_cnt))) {
            vlSelfRef.pdm_clk_out = (1U & (~ (IData)(vlSelfRef.pdm_clk_out)));
            __Vdly__agriguard_top__DOT__pdm_div_cnt = 0U;
        } else {
            __Vdly__agriguard_top__DOT__pdm_div_cnt 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__pdm_div_cnt)));
        }
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__csn_r 
            = ((6U & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r) 
                      << 1U)) | (IData)(vlSelfRef.spi_csn));
        __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0 
            = (0x0007ffffU & (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[0U] 
                              + (1U | (- (IData)((1U 
                                                  & (~ (IData)(vlSelfRef.pdm_data))))))));
        __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0 = 1U;
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_h451ecbf8__0 
            = (0x0007ffffU & (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[1U] 
                              + vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[0U]));
        __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1 
            = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_h451ecbf8__0;
        __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1 = 1U;
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_h451ecbf8__0 
            = (0x0007ffffU & (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[2U] 
                              + vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[1U]));
        __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2 
            = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_h451ecbf8__0;
        __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2 = 1U;
        if ((0x014cU == (IData)(vlSelfRef.agriguard_top__DOT__pcm_strobe_cnt))) {
            __Vdly__agriguard_top__DOT__pcm_strobe_cnt = 0U;
            vlSelfRef.agriguard_top__DOT__pcm_strobe = 1U;
        } else {
            __Vdly__agriguard_top__DOT__pcm_strobe_cnt 
                = (0x000001ffU & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__pcm_strobe_cnt)));
            vlSelfRef.agriguard_top__DOT__pcm_strobe = 0U;
        }
        vlSelfRef.agriguard_top__DOT__threshold_valid = 0U;
        if (vlSelfRef.agriguard_top__DOT__faw_pulse) {
            __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly = 1U;
            vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__irq_latch = 1U;
            vlSelfRef.fpga_irq = 1U;
        }
        if ((2U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r))) {
            __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt = 0U;
            __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase = 0U;
            __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift = 0xffU;
        } else {
            if ((1U == (3U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r)))) {
                __Vdly__agriguard_top__DOT__u_spi_slave__DOT__rx_shift 
                    = ((0x000000feU & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                       << 1U)) | (1U 
                                                  & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r)));
                if ((7U == (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__bit_cnt))) {
                    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt = 0U;
                    if (vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__byte_phase) {
                        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase = 0U;
                        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift = 0xffU;
                        if ((1U & (~ (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__is_read)))) {
                            if ((0x21U == (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch))) {
                                __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo 
                                    = ((0x000000feU 
                                        & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                           << 1U)) 
                                       | (1U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r)));
                            } else if ((0x22U == (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch))) {
                                vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_hi 
                                    = ((0x000000feU 
                                        & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                           << 1U)) 
                                       | (1U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r)));
                                vlSelfRef.agriguard_top__DOT__threshold_valid = 1U;
                                vlSelfRef.agriguard_top__DOT__faw_threshold 
                                    = ((0x0000fe00U 
                                        & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                           << 9U)) 
                                       | ((0x00000100U 
                                           & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r) 
                                              << 8U)) 
                                          | (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo)));
                            } else if ((0x7fU == (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch))) {
                                vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__irq_latch = 0U;
                                vlSelfRef.fpga_irq = 0U;
                                __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly = 0U;
                            }
                        }
                    } else {
                        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase = 1U;
                        vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__is_read 
                            = (1U & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                     >> 6U));
                        vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch 
                            = ((0x0000007eU & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                               << 1U)) 
                               | (1U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r)));
                        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift 
                            = ((0x00000040U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift))
                                ? ((0U == ((0x0000007eU 
                                            & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                               << 1U)) 
                                           | (1U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r))))
                                    ? (IData)(vlSelfRef.agriguard_top__DOT__faw_detected)
                                    : ((0x20U == ((0x0000007eU 
                                                   & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift) 
                                                      << 1U)) 
                                                  | (1U 
                                                     & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r))))
                                        ? (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly)
                                        : 0xdeU)) : 0xffU);
                    }
                } else {
                    __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__bit_cnt)));
                }
            }
            if ((2U == (3U & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r)))) {
                __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift 
                    = (1U | (0x000000feU & ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__tx_shift) 
                                            << 1U)));
            }
        }
    } else {
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__sck_r = 7U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__mosi_r = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt = 0U;
        vlSelfRef.pdm_clk_out = 0U;
        __Vdly__agriguard_top__DOT__pdm_div_cnt = 0U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__csn_r = 7U;
        __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v3 = 1U;
        __VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v3 = 1U;
        __Vdly__agriguard_top__DOT__pcm_strobe_cnt = 0U;
        vlSelfRef.agriguard_top__DOT__pcm_strobe = 0U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift = 0xffU;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly = 0U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo = 0U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__rx_shift = 0U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt = 0U;
        __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase = 0U;
        vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__is_read = 0U;
        vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__addr_latch = 0U;
        vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_hi = 8U;
        vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__irq_latch = 0U;
        vlSelfRef.fpga_irq = 0U;
        vlSelfRef.agriguard_top__DOT__threshold_valid = 0U;
        vlSelfRef.agriguard_top__DOT__faw_threshold = 0x0800U;
    }
    vlSelfRef.agriguard_top__DOT__pdm_div_cnt = __Vdly__agriguard_top__DOT__pdm_div_cnt;
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[0U] 
            = __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v0;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[1U] 
            = __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v1;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[2U] 
            = __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v2;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__integ__v3) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[0U] = 0U;
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[1U] = 0U;
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[2U] = 0U;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[0U] 
            = __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v0;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[1U] 
            = __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v1;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[2U] 
            = __VdlyVal__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v2;
    }
    if (__VdlySet__agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly__v3) {
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[0U] = 0U;
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[1U] = 0U;
        vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[2U] = 0U;
    }
    vlSelfRef.agriguard_top__DOT__pcm_strobe_cnt = __Vdly__agriguard_top__DOT__pcm_strobe_cnt;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__bit_cnt 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__bit_cnt;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__sck_r 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__sck_r;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__mosi_r 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__mosi_r;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__rx_shift 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__rx_shift;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__csn_r;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__byte_phase 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__byte_phase;
    vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__tx_shift 
        = __Vdly__agriguard_top__DOT__u_spi_slave__DOT__tx_shift;
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[0U] 
        = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[2U];
    __VdfgRegularize_h6e95ff9d_0_0 = (0x0007ffffU & 
                                      (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__integ[2U] 
                                       - vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[0U]));
    vlSelfRef.spi_miso = (1U & ((~ ((~ ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__csn_r) 
                                        >> 1U)) & (IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__byte_phase))) 
                                | ((IData)(vlSelfRef.agriguard_top__DOT__u_spi_slave__DOT__tx_shift) 
                                   >> 7U)));
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[1U] 
        = __VdfgRegularize_h6e95ff9d_0_0;
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[0U] 
        = __VdfgRegularize_h6e95ff9d_0_0;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 = (0x0007ffffU 
                                                & (__VdfgRegularize_h6e95ff9d_0_0 
                                                   - vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[1U]));
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_in[2U] 
        = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1;
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[1U] 
        = vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1;
}

void Vagriguard_top___024root___nba_sequent__TOP__1(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___nba_sequent__TOP__1\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__agriguard_top__DOT__u_fft_engine__DOT__br__v0 = 0U;
    vlSelfRef.__VdlySet__agriguard_top__DOT__u_fft_engine__DOT__bi__v0 = 0U;
    if (vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe) {
        vlSelfRef.__VdlyVal__agriguard_top__DOT__u_fft_engine__DOT__br__v0 
            = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r;
        vlSelfRef.__VdlyDim0__agriguard_top__DOT__u_fft_engine__DOT__br__v0 
            = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa;
        vlSelfRef.__VdlySet__agriguard_top__DOT__u_fft_engine__DOT__br__v0 = 1U;
        vlSelfRef.__VdlyVal__agriguard_top__DOT__u_fft_engine__DOT__bi__v0 
            = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i;
        vlSelfRef.__VdlyDim0__agriguard_top__DOT__u_fft_engine__DOT__bi__v0 
            = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa;
        vlSelfRef.__VdlySet__agriguard_top__DOT__u_fft_engine__DOT__bi__v0 = 1U;
    }
}

void Vagriguard_top___024root___nba_sequent__TOP__2(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___nba_sequent__TOP__2\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*7:0*/ __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__Vfuncout;
    __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x;
    __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x = 0;
    // Body
    if (vlSelfRef.rst_n) {
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe = 0U;
        vlSelfRef.agriguard_top__DOT__bin_valid = 0U;
        vlSelfRef.agriguard_top__DOT__faw_pulse = 0U;
        if ((4U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state))) {
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state))) {
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a 
                    = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt;
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__out_cnt 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt)));
                if ((0U < (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt))) {
                    vlSelfRef.__Vdly__agriguard_top__DOT__mag_out 
                        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__mag_v;
                    vlSelfRef.agriguard_top__DOT__bin_index 
                        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_bin;
                    vlSelfRef.agriguard_top__DOT__bin_valid = 1U;
                    if (vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__in_faw) {
                        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__energy_acc 
                            = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_sat;
                    }
                }
                if (((0U == (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt)) 
                     & (0U != (IData)(vlSelfRef.agriguard_top__DOT__mag_out)))) {
                    vlSelfRef.agriguard_top__DOT__faw_pulse 
                        = ((0x00040000U <= vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc) 
                           & (~ (IData)(vlSelfRef.agriguard_top__DOT__faw_detected)));
                    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__samp_cnt = 0U;
                    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 0U;
                    vlSelfRef.agriguard_top__DOT__faw_detected 
                        = (0x00040000U <= vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc);
                }
            } else {
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe = 1U;
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa 
                    = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_bot;
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, 
                                                    (0x0000ffffU 
                                                     & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_r) 
                                                        - (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_r))), 1U));
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, 
                                                    (0x0000ffffU 
                                                     & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_i) 
                                                        - (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_i))), 1U));
                if ((0x7fU == (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt))) {
                    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt = 0U;
                    if ((7U == (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass))) {
                        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__out_cnt = 0U;
                        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__energy_acc = 0U;
                        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a = 0U;
                        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 5U;
                    } else {
                        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)));
                        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 1U;
                    }
                } else {
                    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt 
                        = (0x0000007fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt)));
                    vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state))) {
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe = 1U;
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa 
                    = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_top;
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, 
                                                    (0x0000ffffU 
                                                     & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_r) 
                                                        + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_r))), 1U));
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, 
                                                    (0x0000ffffU 
                                                     & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_i) 
                                                        + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_i))), 1U));
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 4U;
            } else {
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_r 
                    = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a;
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_i 
                    = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a;
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m0 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqr)), 
                                  VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_b)));
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m1 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqi)), 
                                  VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_b)));
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m2 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqr)), 
                                  VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_b)));
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m3 
                    = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqi)), 
                                  VL_EXTENDS_II(32,16, (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_b)));
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state))) {
            vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a 
                = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_top;
            vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_b 
                = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_bot;
            vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__twa 
                = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tw_addr;
            vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_top 
                = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_top;
            vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_bot 
                = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_bot;
            vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 2U;
        } else if (vlSelfRef.agriguard_top__DOT__pcm_valid) {
            __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x 
                = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt;
            __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__Vfuncout 
                = (((((2U & ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                             << 1U)) | (1U & ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                              >> 1U))) 
                     << 6U) | (((2U & ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                       >> 1U)) | (1U 
                                                  & ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                                     >> 3U))) 
                               << 4U)) | ((((2U & ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                                   >> 3U)) 
                                            | (1U & 
                                               ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                                >> 5U))) 
                                           << 2U) | 
                                          ((2U & ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                                  >> 5U)) 
                                           | (1U & 
                                              ((IData)(__Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__x) 
                                               >> 7U)))));
            vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe = 1U;
            vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa 
                = __Vfunc_agriguard_top__DOT__u_fft_engine__DOT__br8__0__Vfuncout;
            vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r 
                = vlSelfRef.agriguard_top__DOT__pcm_data;
            vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i = 0U;
            vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__samp_cnt 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt)));
            if ((0xffU == (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt))) {
                vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass = 0U;
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt = 0U;
                vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 1U;
            }
        }
        if ((0x3fU == (IData)(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt))) {
            vlSelfRef.agriguard_top__DOT__pcm_data 
                = (0x0000ffffU & (vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result 
                                  >> 3U));
        }
    } else {
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__samp_cnt = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__out_cnt = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwe = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwa = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_r = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bwd_i = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_b = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__twa = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_top = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sv_bot = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_r = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__la_i = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m0 = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m1 = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m2 = 0U;
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m3 = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__mag_out = 0U;
        vlSelfRef.agriguard_top__DOT__bin_index = 0U;
        vlSelfRef.agriguard_top__DOT__bin_valid = 0U;
        vlSelfRef.agriguard_top__DOT__faw_detected = 0U;
        vlSelfRef.agriguard_top__DOT__faw_pulse = 0U;
        vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__energy_acc = 0U;
        vlSelfRef.agriguard_top__DOT__pcm_data = 0U;
    }
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__state 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__state;
    vlSelfRef.agriguard_top__DOT__mag_out = vlSelfRef.__Vdly__agriguard_top__DOT__mag_out;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__samp_cnt 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__samp_cnt;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__energy_acc;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__out_cnt;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_r 
        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, (vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m0 
                                                   - vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m1), 0x0000000fU));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__wb_i 
        = (0x0000ffffU & VL_SHIFTRS_III(16,32,32, (vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m2 
                                                   + vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__m3), 0x0000000fU));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_bin 
        = (0x000000ffU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                          - (IData)(1U)));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__in_faw 
        = ((0x1bU <= (0x000000ffU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                     - (IData)(1U)))) 
           & (0x40U >= (0x000000ffU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__out_cnt) 
                                       - (IData)(1U)))));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos 
        = ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt) 
           & (((IData)(1U) << (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)) 
              - (IData)(1U)));
    vlSelfRef.agriguard_top__DOT__pcm_valid = ((IData)(vlSelfRef.rst_n) 
                                               && (0x3fU 
                                                   == (IData)(vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt)));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tw_addr 
        = (0x0000007fU & ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos) 
                          << (7U & ((IData)(7U) - (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)))));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_top 
        = (0x000000ffU & ((((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bf_cnt) 
                            >> (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)) 
                           << (7U & ((IData)(1U) + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)))) 
                          | (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pos)));
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt;
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result 
        = (0x0007ffffU & (vlSelfRef.__VdfgRegularize_h6e95ff9d_0_1 
                          - vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly[2U]));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_bot 
        = (0x000000ffU & (((IData)(1U) << (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__pass)) 
                          + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__addr_top)));
    vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__comb_out[2U] 
        = vlSelfRef.agriguard_top__DOT__u_pdm_decimator__DOT__cic_result;
}

void Vagriguard_top___024root___nba_sequent__TOP__3(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___nba_sequent__TOP__3\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqr 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tr
        [vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__twa];
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__tqi 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__ti
        [vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__twa];
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_b 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__br
        [vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_b];
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_b 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bi
        [vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_b];
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__br
        [vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_a];
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a 
        = vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bi
        [vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_a];
    if (vlSelfRef.__VdlySet__agriguard_top__DOT__u_fft_engine__DOT__br__v0) {
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__br[vlSelfRef.__VdlyDim0__agriguard_top__DOT__u_fft_engine__DOT__br__v0] 
            = vlSelfRef.__VdlyVal__agriguard_top__DOT__u_fft_engine__DOT__br__v0;
    }
    if (vlSelfRef.__VdlySet__agriguard_top__DOT__u_fft_engine__DOT__bi__v0) {
        vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bi[vlSelfRef.__VdlyDim0__agriguard_top__DOT__u_fft_engine__DOT__bi__v0] 
            = vlSelfRef.__VdlyVal__agriguard_top__DOT__u_fft_engine__DOT__bi__v0;
    }
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_r 
        = (0x0000ffffU & ((0x00008000U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a))
                           ? ((IData)(1U) + (~ (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a)))
                           : (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqr_a)));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_i 
        = (0x0000ffffU & ((0x00008000U & (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a))
                           ? ((IData)(1U) + (~ (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a)))
                           : (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bqi_a)));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__mag_v 
        = (0x0000ffffU & (((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_r) 
                           + (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_i)) 
                          | (- (IData)(((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_r) 
                                        > (0x0000ffffU 
                                           & ((IData)(0xffffU) 
                                              - (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__abs_i))))))));
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val 
        = ((IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__mag_v) 
           * (IData)(vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__mag_v));
}

void Vagriguard_top___024root___nba_sequent__TOP__4(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___nba_sequent__TOP__4\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__twa 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__twa;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_b 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_b;
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__bra_a 
        = vlSelfRef.__Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a;
}

void Vagriguard_top___024root___nba_comb__TOP__0(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___nba_comb__TOP__0\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_sat 
        = ((vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc 
            + vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val) 
           | (- (IData)((((IData)(0xffffffffU) - vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__energy_acc) 
                         < vlSelfRef.agriguard_top__DOT__u_fft_engine__DOT__sq_val))));
}

void Vagriguard_top___024root___eval_nba(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___eval_nba\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vagriguard_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vagriguard_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vagriguard_top___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vagriguard_top___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vagriguard_top___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vagriguard_top___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vagriguard_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vagriguard_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vagriguard_top___024root___eval_phase__act(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___eval_phase__act\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vagriguard_top___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vagriguard_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vagriguard_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vagriguard_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vagriguard_top___024root___eval_phase__nba(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___eval_phase__nba\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vagriguard_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vagriguard_top___024root___eval_nba(vlSelf);
        Vagriguard_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vagriguard_top___024root___eval(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___eval\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vagriguard_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("agriguard_top.sv", 49, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vagriguard_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("agriguard_top.sv", 49, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vagriguard_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vagriguard_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vagriguard_top___024root___eval_debug_assertions(Vagriguard_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vagriguard_top___024root___eval_debug_assertions\n"); );
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_16mhz & 0xfeU)))) {
        Verilated::overWidthError("clk_16mhz");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.pdm_data & 0xfeU)))) {
        Verilated::overWidthError("pdm_data");
    }
    if (VL_UNLIKELY(((vlSelfRef.spi_sck & 0xfeU)))) {
        Verilated::overWidthError("spi_sck");
    }
    if (VL_UNLIKELY(((vlSelfRef.spi_mosi & 0xfeU)))) {
        Verilated::overWidthError("spi_mosi");
    }
    if (VL_UNLIKELY(((vlSelfRef.spi_csn & 0xfeU)))) {
        Verilated::overWidthError("spi_csn");
    }
}
#endif  // VL_DEBUG
