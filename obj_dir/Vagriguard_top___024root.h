// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vagriguard_top.h for the primary calling header

#ifndef VERILATED_VAGRIGUARD_TOP___024ROOT_H_
#define VERILATED_VAGRIGUARD_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vagriguard_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vagriguard_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_16mhz,0,0);
        VL_IN8(rst_n,0,0);
        VL_OUT8(pdm_clk_out,0,0);
        VL_IN8(pdm_data,0,0);
        VL_IN8(spi_sck,0,0);
        VL_IN8(spi_mosi,0,0);
        VL_OUT8(spi_miso,0,0);
        VL_IN8(spi_csn,0,0);
        VL_OUT8(fpga_irq,0,0);
        CData/*2:0*/ agriguard_top__DOT__pdm_div_cnt;
        CData/*0:0*/ agriguard_top__DOT__pcm_strobe;
        CData/*0:0*/ agriguard_top__DOT__pcm_valid;
        CData/*0:0*/ agriguard_top__DOT__faw_detected;
        CData/*0:0*/ agriguard_top__DOT__faw_pulse;
        CData/*7:0*/ agriguard_top__DOT__bin_index;
        CData/*0:0*/ agriguard_top__DOT__bin_valid;
        CData/*0:0*/ agriguard_top__DOT__threshold_valid;
        CData/*5:0*/ agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt;
        CData/*2:0*/ agriguard_top__DOT__u_fft_engine__DOT__state;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__samp_cnt;
        CData/*2:0*/ agriguard_top__DOT__u_fft_engine__DOT__pass;
        CData/*6:0*/ agriguard_top__DOT__u_fft_engine__DOT__bf_cnt;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__out_cnt;
        CData/*6:0*/ agriguard_top__DOT__u_fft_engine__DOT__pos;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__addr_top;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__addr_bot;
        CData/*6:0*/ agriguard_top__DOT__u_fft_engine__DOT__tw_addr;
        CData/*0:0*/ agriguard_top__DOT__u_fft_engine__DOT__bwe;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__bwa;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__bra_a;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__bra_b;
        CData/*6:0*/ agriguard_top__DOT__u_fft_engine__DOT__twa;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__sv_top;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__sv_bot;
        CData/*7:0*/ agriguard_top__DOT__u_fft_engine__DOT__out_bin;
        CData/*0:0*/ agriguard_top__DOT__u_fft_engine__DOT__in_faw;
        CData/*2:0*/ agriguard_top__DOT__u_spi_slave__DOT__sck_r;
        CData/*2:0*/ agriguard_top__DOT__u_spi_slave__DOT__csn_r;
        CData/*1:0*/ agriguard_top__DOT__u_spi_slave__DOT__mosi_r;
        CData/*7:0*/ agriguard_top__DOT__u_spi_slave__DOT__reg_anomaly;
        CData/*7:0*/ agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_lo;
        CData/*7:0*/ agriguard_top__DOT__u_spi_slave__DOT__reg_thresh_hi;
        CData/*0:0*/ agriguard_top__DOT__u_spi_slave__DOT__irq_latch;
        CData/*7:0*/ agriguard_top__DOT__u_spi_slave__DOT__rx_shift;
        CData/*7:0*/ agriguard_top__DOT__u_spi_slave__DOT__tx_shift;
        CData/*2:0*/ agriguard_top__DOT__u_spi_slave__DOT__bit_cnt;
        CData/*0:0*/ agriguard_top__DOT__u_spi_slave__DOT__byte_phase;
        CData/*0:0*/ agriguard_top__DOT__u_spi_slave__DOT__is_read;
        CData/*6:0*/ agriguard_top__DOT__u_spi_slave__DOT__addr_latch;
        CData/*5:0*/ __Vdly__agriguard_top__DOT__u_pdm_decimator__DOT__decim_cnt;
        CData/*2:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__state;
        CData/*7:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_a;
        CData/*7:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__out_cnt;
        CData/*7:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__samp_cnt;
        CData/*6:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__bf_cnt;
        CData/*7:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__bra_b;
        CData/*6:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__twa;
        CData/*7:0*/ __VdlyDim0__agriguard_top__DOT__u_fft_engine__DOT__br__v0;
        CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_fft_engine__DOT__br__v0;
        CData/*7:0*/ __VdlyDim0__agriguard_top__DOT__u_fft_engine__DOT__bi__v0;
        CData/*0:0*/ __VdlySet__agriguard_top__DOT__u_fft_engine__DOT__bi__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk_16mhz__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*8:0*/ agriguard_top__DOT__pcm_strobe_cnt;
        SData/*15:0*/ agriguard_top__DOT__pcm_data;
        SData/*15:0*/ agriguard_top__DOT__mag_out;
        SData/*15:0*/ agriguard_top__DOT__faw_threshold;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__bwd_r;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__bwd_i;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__bqr_a;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__bqi_a;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__bqr_b;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__bqi_b;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__tqr;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__tqi;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__la_r;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__la_i;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__wb_r;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__wb_i;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__abs_r;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__abs_i;
        SData/*15:0*/ agriguard_top__DOT__u_fft_engine__DOT__mag_v;
        SData/*15:0*/ __Vdly__agriguard_top__DOT__mag_out;
        SData/*15:0*/ __VdlyVal__agriguard_top__DOT__u_fft_engine__DOT__br__v0;
        SData/*15:0*/ __VdlyVal__agriguard_top__DOT__u_fft_engine__DOT__bi__v0;
        IData/*18:0*/ agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_hf1fe9153__0;
        IData/*18:0*/ agriguard_top__DOT__u_pdm_decimator__DOT____Vlvbound_h451ecbf8__0;
        IData/*18:0*/ agriguard_top__DOT__u_pdm_decimator__DOT__cic_result;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__m0;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__m1;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__m2;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__m3;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__energy_acc;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__sq_val;
        IData/*31:0*/ agriguard_top__DOT__u_fft_engine__DOT__sq_sat;
        IData/*18:0*/ __VdfgRegularize_h6e95ff9d_0_1;
        IData/*31:0*/ __Vdly__agriguard_top__DOT__u_fft_engine__DOT__energy_acc;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*18:0*/, 3> agriguard_top__DOT__u_pdm_decimator__DOT__integ;
        VlUnpacked<IData/*18:0*/, 3> agriguard_top__DOT__u_pdm_decimator__DOT__comb_in;
        VlUnpacked<IData/*18:0*/, 3> agriguard_top__DOT__u_pdm_decimator__DOT__comb_dly;
        VlUnpacked<IData/*18:0*/, 3> agriguard_top__DOT__u_pdm_decimator__DOT__comb_out;
        VlUnpacked<SData/*15:0*/, 256> agriguard_top__DOT__u_fft_engine__DOT__br;
        VlUnpacked<SData/*15:0*/, 256> agriguard_top__DOT__u_fft_engine__DOT__bi;
        VlUnpacked<SData/*15:0*/, 128> agriguard_top__DOT__u_fft_engine__DOT__tr;
        VlUnpacked<SData/*15:0*/, 128> agriguard_top__DOT__u_fft_engine__DOT__ti;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vagriguard_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vagriguard_top___024root(Vagriguard_top__Syms* symsp, const char* namep);
    ~Vagriguard_top___024root();
    VL_UNCOPYABLE(Vagriguard_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
