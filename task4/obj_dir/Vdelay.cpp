// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdelay.h"
#include "Vdelay__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdelay::Vdelay(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdelay__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , trigger{vlSymsp->TOP.trigger}
    , time_out{vlSymsp->TOP.time_out}
    , n{vlSymsp->TOP.n}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdelay::Vdelay(const char* _vcname__)
    : Vdelay(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdelay::~Vdelay() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vdelay___024root___eval_initial(Vdelay___024root* vlSelf);
void Vdelay___024root___eval_settle(Vdelay___024root* vlSelf);
void Vdelay___024root___eval(Vdelay___024root* vlSelf);
#ifdef VL_DEBUG
void Vdelay___024root___eval_debug_assertions(Vdelay___024root* vlSelf);
#endif  // VL_DEBUG
void Vdelay___024root___final(Vdelay___024root* vlSelf);

static void _eval_initial_loop(Vdelay__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vdelay___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vdelay___024root___eval_settle(&(vlSymsp->TOP));
        Vdelay___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vdelay::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdelay::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdelay___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vdelay___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vdelay::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vdelay::final() {
    Vdelay___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdelay::hierName() const { return vlSymsp->name(); }
const char* Vdelay::modelName() const { return "Vdelay"; }
unsigned Vdelay::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vdelay::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdelay___024root__trace_init_top(Vdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay___024root*>(voidSelf);
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdelay___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdelay___024root__trace_register(Vdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdelay::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdelay___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
