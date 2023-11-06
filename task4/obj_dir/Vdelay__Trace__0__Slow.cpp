// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdelay__Syms.h"


VL_ATTR_COLD void Vdelay___024root__trace_init_sub__TOP__0(Vdelay___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"trigger", false,-1);
    tracep->declBus(c+4,"n", false,-1, 9,0);
    tracep->declBit(c+5,"time_out", false,-1);
    tracep->pushNamePrefix("delay ");
    tracep->declBus(c+9,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"trigger", false,-1);
    tracep->declBus(c+4,"n", false,-1, 9,0);
    tracep->declBit(c+5,"time_out", false,-1);
    tracep->declBus(c+6,"count", false,-1, 9,0);
    tracep->declBus(c+7,"current_state", false,-1, 31,0);
    tracep->declBus(c+8,"next_state", false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vdelay___024root__trace_init_top(Vdelay___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_init_top\n"); );
    // Body
    Vdelay___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdelay___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdelay___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdelay___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdelay___024root__trace_register(Vdelay___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vdelay___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vdelay___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vdelay___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdelay___024root__trace_full_sub_0(Vdelay___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdelay___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_full_top_0\n"); );
    // Init
    Vdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay___024root*>(voidSelf);
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdelay___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdelay___024root__trace_full_sub_0(Vdelay___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullBit(oldp+3,(vlSelf->trigger));
    bufp->fullSData(oldp+4,(vlSelf->n),10);
    bufp->fullBit(oldp+5,(vlSelf->time_out));
    bufp->fullSData(oldp+6,(vlSelf->delay__DOT__count),10);
    bufp->fullIData(oldp+7,(vlSelf->delay__DOT__current_state),32);
    bufp->fullIData(oldp+8,(((0U == vlSelf->delay__DOT__current_state)
                              ? ((IData)(vlSelf->trigger)
                                  ? 1U : vlSelf->delay__DOT__current_state)
                              : ((1U == vlSelf->delay__DOT__current_state)
                                  ? ((0U == (IData)(vlSelf->delay__DOT__count))
                                      ? 2U : vlSelf->delay__DOT__current_state)
                                  : ((2U == vlSelf->delay__DOT__current_state)
                                      ? ((IData)(vlSelf->trigger)
                                          ? 3U : 0U)
                                      : ((3U == vlSelf->delay__DOT__current_state)
                                          ? ((IData)(vlSelf->trigger)
                                              ? vlSelf->delay__DOT__current_state
                                              : 0U)
                                          : 0U))))),32);
    bufp->fullIData(oldp+9,(0xaU),32);
}
