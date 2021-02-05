// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ top__DOT__ALU_tb;
    CData/*1:0*/ top__DOT__WriteAddr;
    CData/*7:0*/ top__DOT__ALU_RegFile__DOT__in0;
    CData/*7:0*/ top__DOT__ALU_RegFile__DOT__in1;
    CData/*1:0*/ top__DOT__ALU_RegFile__DOT__alu__DOT__t_branch;
    CData/*0:0*/ top__DOT__ALU_RegFile__DOT__alu__DOT__oflow;
    CData/*7:0*/ top__DOT__ALU_RegFile__DOT__alu__DOT__out;
    CData/*7:0*/ top__DOT__PCount__DOT__pcount;
    SData/*15:0*/ top__DOT__instruction;
    SData/*8:0*/ top__DOT__WriteData;
    SData/*8:0*/ top__DOT__ALU_RegFile__DOT__rd1_data;
    SData/*8:0*/ top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0;
    SData/*8:0*/ top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1;
    SData/*8:0*/ top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2;
    SData/*8:0*/ top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3;
    IData/*31:0*/ top__DOT__DataMem__DOT__i;
    IData/*31:0*/ top__DOT__InstrMem__DOT__i;
    IData/*22:0*/ top__DOT__InstrDec__DOT__settings;
    SData/*8:0*/ top__DOT__DataMem__DOT__mem[256];
    SData/*15:0*/ top__DOT__InstrMem__DOT__i_mem[256];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __VinpClk__TOP__top__DOT__ALU_tb;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__top__DOT__ALU_tb;
    CData/*0:0*/ __Vchglast__TOP__top__DOT__ALU_tb;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
