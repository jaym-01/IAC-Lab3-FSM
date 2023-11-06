// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay.h for the primary calling header

#include "verilated.h"

#include "Vdelay__Syms.h"
#include "Vdelay___024root.h"

void Vdelay___024root___ctor_var_reset(Vdelay___024root* vlSelf);

Vdelay___024root::Vdelay___024root(Vdelay__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdelay___024root___ctor_var_reset(this);
}

void Vdelay___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vdelay___024root::~Vdelay___024root() {
}
