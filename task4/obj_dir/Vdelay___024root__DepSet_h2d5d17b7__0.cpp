// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay.h for the primary calling header

#include "verilated.h"

#include "Vdelay___024root.h"

VL_INLINE_OPT void Vdelay___024root___sequent__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->delay__DOT__current_state = ((IData)(vlSelf->rst)
                                          ? 0U : vlSelf->delay__DOT__next_state);
    vlSelf->delay__DOT__count = (0x3ffU & ((((IData)(vlSelf->rst) 
                                             | (IData)(vlSelf->trigger)) 
                                            | (0U == (IData)(vlSelf->delay__DOT__count)))
                                            ? ((IData)(vlSelf->n) 
                                               - (IData)(1U))
                                            : ((IData)(vlSelf->delay__DOT__count) 
                                               - (IData)(1U))));
    vlSelf->time_out = ((0U != vlSelf->delay__DOT__current_state) 
                        & ((1U != vlSelf->delay__DOT__current_state) 
                           & (2U == vlSelf->delay__DOT__current_state)));
}

VL_INLINE_OPT void Vdelay___024root___combo__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->delay__DOT__next_state = ((0U == vlSelf->delay__DOT__current_state)
                                       ? ((IData)(vlSelf->trigger)
                                           ? 1U : vlSelf->delay__DOT__current_state)
                                       : ((1U == vlSelf->delay__DOT__current_state)
                                           ? ((0U == (IData)(vlSelf->delay__DOT__count))
                                               ? 2U
                                               : vlSelf->delay__DOT__current_state)
                                           : ((2U == vlSelf->delay__DOT__current_state)
                                               ? ((IData)(vlSelf->trigger)
                                                   ? 3U
                                                   : 0U)
                                               : ((3U 
                                                   == vlSelf->delay__DOT__current_state)
                                                   ? 
                                                  ((IData)(vlSelf->trigger)
                                                    ? vlSelf->delay__DOT__current_state
                                                    : 0U)
                                                   : 0U))));
}

void Vdelay___024root___eval(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vdelay___024root___sequent__TOP__0(vlSelf);
    }
    Vdelay___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vdelay___024root___eval_debug_assertions(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((vlSelf->n & 0xfc00U))) {
        Verilated::overWidthError("n");}
}
#endif  // VL_DEBUG
