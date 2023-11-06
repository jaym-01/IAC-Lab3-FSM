// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay.h for the primary calling header

#include "verilated.h"

#include "Vdelay___024root.h"

VL_ATTR_COLD void Vdelay___024root___initial__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->delay__DOT__count = 0U;
}

VL_ATTR_COLD void Vdelay___024root___settle__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->time_out = ((0U != vlSelf->delay__DOT__current_state) 
                        & ((1U != vlSelf->delay__DOT__current_state) 
                           & (2U == vlSelf->delay__DOT__current_state)));
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

VL_ATTR_COLD void Vdelay___024root___eval_initial(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    Vdelay___024root___initial__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vdelay___024root___eval_settle(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_settle\n"); );
    // Body
    Vdelay___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vdelay___024root___final(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___final\n"); );
}

VL_ATTR_COLD void Vdelay___024root___ctor_var_reset(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->n = VL_RAND_RESET_I(10);
    vlSelf->time_out = VL_RAND_RESET_I(1);
    vlSelf->delay__DOT__count = VL_RAND_RESET_I(10);
    vlSelf->delay__DOT__current_state = 0;
    vlSelf->delay__DOT__next_state = 0;
}
