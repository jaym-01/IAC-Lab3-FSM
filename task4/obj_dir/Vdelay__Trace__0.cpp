// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdelay__Syms.h"


void Vdelay___024root__trace_chg_sub_0(Vdelay___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdelay___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_chg_top_0\n"); );
    // Init
    Vdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay___024root*>(voidSelf);
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdelay___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vdelay___024root__trace_chg_sub_0(Vdelay___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgBit(oldp+2,(vlSelf->trigger));
    bufp->chgSData(oldp+3,(vlSelf->n),10);
    bufp->chgBit(oldp+4,(vlSelf->time_out));
    bufp->chgSData(oldp+5,(vlSelf->delay__DOT__count),10);
    bufp->chgIData(oldp+6,(vlSelf->delay__DOT__current_state),32);
    bufp->chgIData(oldp+7,(((0U == vlSelf->delay__DOT__current_state)
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
                                             : 0U) : 0U))))),32);
}

void Vdelay___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root__trace_cleanup\n"); );
    // Init
    Vdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay___024root*>(voidSelf);
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
