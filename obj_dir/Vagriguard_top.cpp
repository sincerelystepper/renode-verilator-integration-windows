// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vagriguard_top__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vagriguard_top::Vagriguard_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vagriguard_top__Syms(contextp(), _vcname__, this)}
    , clk_16mhz{vlSymsp->TOP.clk_16mhz}
    , rst_n{vlSymsp->TOP.rst_n}
    , pdm_clk_out{vlSymsp->TOP.pdm_clk_out}
    , pdm_data{vlSymsp->TOP.pdm_data}
    , spi_sck{vlSymsp->TOP.spi_sck}
    , spi_mosi{vlSymsp->TOP.spi_mosi}
    , spi_miso{vlSymsp->TOP.spi_miso}
    , spi_csn{vlSymsp->TOP.spi_csn}
    , fpga_irq{vlSymsp->TOP.fpga_irq}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vagriguard_top::Vagriguard_top(const char* _vcname__)
    : Vagriguard_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vagriguard_top::~Vagriguard_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vagriguard_top___024root___eval_debug_assertions(Vagriguard_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vagriguard_top___024root___eval_static(Vagriguard_top___024root* vlSelf);
void Vagriguard_top___024root___eval_initial(Vagriguard_top___024root* vlSelf);
void Vagriguard_top___024root___eval_settle(Vagriguard_top___024root* vlSelf);
void Vagriguard_top___024root___eval(Vagriguard_top___024root* vlSelf);

void Vagriguard_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vagriguard_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vagriguard_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vagriguard_top___024root___eval_static(&(vlSymsp->TOP));
        Vagriguard_top___024root___eval_initial(&(vlSymsp->TOP));
        Vagriguard_top___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vagriguard_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vagriguard_top::eventsPending() { return false; }

uint64_t Vagriguard_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vagriguard_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vagriguard_top___024root___eval_final(Vagriguard_top___024root* vlSelf);

VL_ATTR_COLD void Vagriguard_top::final() {
    contextp()->executingFinal(true);
    Vagriguard_top___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vagriguard_top::hierName() const { return vlSymsp->name(); }
const char* Vagriguard_top::modelName() const { return "Vagriguard_top"; }
unsigned Vagriguard_top::threads() const { return 1; }
void Vagriguard_top::prepareClone() const { contextp()->prepareClone(); }
void Vagriguard_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vagriguard_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vagriguard_top___024root__trace_decl_types(VerilatedVcd* tracep);

void Vagriguard_top___024root__trace_init_top(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vagriguard_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vagriguard_top___024root*>(voidSelf);
    Vagriguard_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vagriguard_top___024root__trace_decl_types(tracep);
    Vagriguard_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vagriguard_top___024root__trace_register(Vagriguard_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vagriguard_top::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vagriguard_top::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 117);
    Vagriguard_top___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
