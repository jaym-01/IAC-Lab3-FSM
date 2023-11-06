// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdelay.h for the primary calling header

#ifndef VERILATED_VDELAY___024ROOT_H_
#define VERILATED_VDELAY___024ROOT_H_  // guard

#include "verilated.h"

class Vdelay__Syms;

class Vdelay___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    VL_OUT8(time_out,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN16(n,9,0);
    SData/*9:0*/ delay__DOT__count;
    IData/*31:0*/ delay__DOT__current_state;
    IData/*31:0*/ delay__DOT__next_state;

    // INTERNAL VARIABLES
    Vdelay__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdelay___024root(Vdelay__Syms* symsp, const char* name);
    ~Vdelay___024root();
    VL_UNCOPYABLE(Vdelay___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
