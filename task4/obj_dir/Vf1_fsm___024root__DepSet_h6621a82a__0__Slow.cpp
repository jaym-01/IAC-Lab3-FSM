// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1_fsm.h for the primary calling header

#include "verilated.h"

#include "Vf1_fsm___024root.h"

VL_ATTR_COLD void Vf1_fsm___024root___initial__TOP__0(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___initial__TOP__0\n"); );
    // Body
    vlSelf->f1_fsm__DOT__current_state = 0U;
}

VL_ATTR_COLD void Vf1_fsm___024root___settle__TOP__0(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___settle__TOP__0\n"); );
    // Body
    if (((((((((1U == vlSelf->f1_fsm__DOT__current_state) 
               | (2U == vlSelf->f1_fsm__DOT__current_state)) 
              | (3U == vlSelf->f1_fsm__DOT__current_state)) 
             | (4U == vlSelf->f1_fsm__DOT__current_state)) 
            | (5U == vlSelf->f1_fsm__DOT__current_state)) 
           | (6U == vlSelf->f1_fsm__DOT__current_state)) 
          | (7U == vlSelf->f1_fsm__DOT__current_state)) 
         | (8U == vlSelf->f1_fsm__DOT__current_state))) {
        if ((1U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 2U;
            vlSelf->data_out = 0U;
        } else if ((2U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 3U;
            vlSelf->data_out = 1U;
        } else if ((3U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 4U;
            vlSelf->data_out = 3U;
        } else if ((4U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 5U;
            vlSelf->data_out = 7U;
        } else if ((5U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 6U;
            vlSelf->data_out = 0xfU;
        } else if ((6U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 7U;
            vlSelf->data_out = 0x1fU;
        } else if ((7U == vlSelf->f1_fsm__DOT__current_state)) {
            vlSelf->f1_fsm__DOT__next_state = 8U;
            vlSelf->data_out = 0x3fU;
        } else {
            vlSelf->f1_fsm__DOT__next_state = 9U;
            vlSelf->data_out = 0x7fU;
        }
    } else if ((9U == vlSelf->f1_fsm__DOT__current_state)) {
        vlSelf->f1_fsm__DOT__next_state = 0xaU;
        vlSelf->data_out = 0xffU;
    } else {
        vlSelf->f1_fsm__DOT__next_state = 0U;
        vlSelf->data_out = ((0xaU == vlSelf->f1_fsm__DOT__current_state)
                             ? 0xffU : 0U);
    }
    vlSelf->cmd_delay = ((0U != vlSelf->f1_fsm__DOT__current_state) 
                         & (0xaU == vlSelf->f1_fsm__DOT__current_state));
    vlSelf->cmd_seq = ((0U != vlSelf->f1_fsm__DOT__current_state) 
                       & (0xaU != vlSelf->f1_fsm__DOT__current_state));
}

VL_ATTR_COLD void Vf1_fsm___024root___eval_initial(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_initial\n"); );
    // Body
    Vf1_fsm___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vf1_fsm___024root___eval_settle(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_settle\n"); );
    // Body
    Vf1_fsm___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vf1_fsm___024root___final(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___final\n"); );
}

VL_ATTR_COLD void Vf1_fsm___024root___ctor_var_reset(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->data_out = VL_RAND_RESET_I(8);
    vlSelf->cmd_seq = VL_RAND_RESET_I(1);
    vlSelf->cmd_delay = VL_RAND_RESET_I(1);
    vlSelf->f1_fsm__DOT__current_state = 0;
    vlSelf->f1_fsm__DOT__next_state = 0;
}
