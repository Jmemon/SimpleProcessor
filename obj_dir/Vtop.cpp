// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__top__DOT__DataMem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__DataMem__DOT__mem__v0;
    SData/*8:0*/ __Vdlyvval__top__DOT__DataMem__DOT__mem__v0;
    // Body
    __Vdlyvset__top__DOT__DataMem__DOT__mem__v0 = 0U;
    if (vlTOPp->rst) {
        vlTOPp->top__DOT__DataMem__DOT__i = 0U;
        while (VL_GTS_III(1,32,32, 0x100U, vlTOPp->top__DOT__DataMem__DOT__i)) {
            vlTOPp->top__DOT__DataMem__DOT__mem[(0xffU 
                                                 & vlTOPp->top__DOT__DataMem__DOT__i)] = 0U;
            vlTOPp->top__DOT__DataMem__DOT__i = ((IData)(1U) 
                                                 + vlTOPp->top__DOT__DataMem__DOT__i);
        }
    }
    if (vlTOPp->rst) {
        vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0 = 0U;
    } else {
        if ((0x200000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__WriteAddr) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__WriteAddr)))) {
                    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0 
                        = vlTOPp->top__DOT__WriteData;
                }
            }
        }
    }
    if (vlTOPp->rst) {
        vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1 = 0U;
    } else {
        if ((0x200000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__WriteAddr) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__WriteAddr))) {
                    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1 
                        = vlTOPp->top__DOT__WriteData;
                }
            }
        }
    }
    if (vlTOPp->rst) {
        vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2 = 0U;
    } else {
        if ((0x200000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            if ((2U & (IData)(vlTOPp->top__DOT__WriteAddr))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__WriteAddr)))) {
                    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2 
                        = vlTOPp->top__DOT__WriteData;
                }
            }
        }
    }
    if (vlTOPp->rst) {
        vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3 = 0U;
    } else {
        if ((0x200000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            if ((2U & (IData)(vlTOPp->top__DOT__WriteAddr))) {
                if ((1U & (IData)(vlTOPp->top__DOT__WriteAddr))) {
                    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3 
                        = vlTOPp->top__DOT__WriteData;
                }
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->rst)))) {
        if ((0x80U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            __Vdlyvval__top__DOT__DataMem__DOT__mem__v0 
                = vlTOPp->top__DOT__ALU_RegFile__DOT__rd1_data;
            __Vdlyvset__top__DOT__DataMem__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__DataMem__DOT__mem__v0 
                = vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out;
        }
    }
    if (__Vdlyvset__top__DOT__DataMem__DOT__mem__v0) {
        vlTOPp->top__DOT__DataMem__DOT__mem[__Vdlyvdim0__top__DOT__DataMem__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__DataMem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__top__DOT__PCount__DOT__pcount;
    // Body
    __Vdly__top__DOT__PCount__DOT__pcount = vlTOPp->top__DOT__PCount__DOT__pcount;
    if (vlTOPp->rst) {
        __Vdly__top__DOT__PCount__DOT__pcount = 0U;
    } else {
        if (vlTOPp->top__DOT__ALU_tb) {
            __Vdly__top__DOT__PCount__DOT__pcount = 
                (0xffU & ((IData)(vlTOPp->top__DOT__PCount__DOT__pcount) 
                          + (vlTOPp->top__DOT__InstrDec__DOT__settings 
                             >> 0xdU)));
        } else {
            if (vlTOPp->clk) {
                __Vdly__top__DOT__PCount__DOT__pcount 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__PCount__DOT__pcount)));
            }
        }
    }
    vlTOPp->top__DOT__PCount__DOT__pcount = __Vdly__top__DOT__PCount__DOT__pcount;
    vlTOPp->top__DOT__instruction = vlTOPp->top__DOT__InstrMem__DOT__i_mem
        [vlTOPp->top__DOT__PCount__DOT__pcount];
    if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                               >> 0xcU))) | (1U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__instruction) 
                                                 >> 0xcU)))) 
              | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                >> 0xcU)))) | (3U == 
                                               (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__instruction) 
                                                   >> 0xcU)))) 
            | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                              >> 0xcU)))) | (5U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__instruction) 
                                                 >> 0xcU)))) 
          | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                            >> 0xcU)))) | (7U == (0xfU 
                                                  & ((IData)(vlTOPp->top__DOT__instruction) 
                                                     >> 0xcU))))) {
        if ((0U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                            >> 0xcU)))) {
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = (0x200000U | (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings));
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                   | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                   << 0xdU)));
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = (0x840U | (0x7fe03fU & vlTOPp->top__DOT__InstrDec__DOT__settings));
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                   | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                               >> 6U)));
        } else {
            if ((1U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                >> 0xcU)))) {
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                       | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                       << 0xdU)));
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = (0x880U | (0x7fe03fU & vlTOPp->top__DOT__InstrDec__DOT__settings));
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                       | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                                   >> 6U)));
            } else {
                if ((2U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                    >> 0xcU)))) {
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = (0x600000U | vlTOPp->top__DOT__InstrDec__DOT__settings);
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = (0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = (0x7fe03fU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                           | (0x3fU & ((IData)(vlTOPp->top__DOT__instruction) 
                                       >> 6U)));
                } else {
                    if ((3U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                        >> 0xcU)))) {
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = (0x600000U | vlTOPp->top__DOT__InstrDec__DOT__settings);
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                               | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                               << 0xdU)));
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = (0x800U | (0x7fe03fU 
                                         & vlTOPp->top__DOT__InstrDec__DOT__settings));
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                               | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                                           >> 6U)));
                    } else {
                        if ((4U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                            >> 0xcU)))) {
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = (0x600000U | vlTOPp->top__DOT__InstrDec__DOT__settings);
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = (0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = (0x1100U | (0x7fe03fU 
                                              & vlTOPp->top__DOT__InstrDec__DOT__settings));
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                   | (0x3fU & ((IData)(vlTOPp->top__DOT__instruction) 
                                               >> 6U)));
                        } else {
                            if ((5U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                                >> 0xcU)))) {
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = (0x600000U | vlTOPp->top__DOT__InstrDec__DOT__settings);
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = (0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = (0x200U | (0x7fe03fU 
                                                 & vlTOPp->top__DOT__InstrDec__DOT__settings));
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                       | (0x3fU & ((IData)(vlTOPp->top__DOT__instruction) 
                                                   >> 6U)));
                            } else {
                                if ((6U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__instruction) 
                                             >> 0xcU)))) {
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = (0x200000U 
                                           | (0x1fffffU 
                                              & vlTOPp->top__DOT__InstrDec__DOT__settings));
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = ((0x601fffU 
                                            & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                           | (0x1fe000U 
                                              & ((IData)(vlTOPp->top__DOT__instruction) 
                                                 << 0xdU)));
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = (0xa00U | 
                                           (0x7fe03fU 
                                            & vlTOPp->top__DOT__InstrDec__DOT__settings));
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = ((0x7fffc0U 
                                            & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                           | (0x3cU 
                                              & ((IData)(vlTOPp->top__DOT__instruction) 
                                                 >> 6U)));
                                } else {
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = (0x600000U 
                                           | vlTOPp->top__DOT__InstrDec__DOT__settings);
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = (0x601fffU 
                                           & vlTOPp->top__DOT__InstrDec__DOT__settings);
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = (0x300U | 
                                           (0x7fe03fU 
                                            & vlTOPp->top__DOT__InstrDec__DOT__settings));
                                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                                        = ((0x7fffc0U 
                                            & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                           | (0x3fU 
                                              & ((IData)(vlTOPp->top__DOT__instruction) 
                                                 >> 6U)));
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((8U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                            >> 0xcU)))) {
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = (0x200000U | (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings));
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                   | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                   << 0xdU)));
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = (0xb00U | (0x7fe03fU & vlTOPp->top__DOT__InstrDec__DOT__settings));
            vlTOPp->top__DOT__InstrDec__DOT__settings 
                = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                   | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                               >> 6U)));
        } else {
            if ((9U == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                >> 0xcU)))) {
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = (0x200000U | (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings));
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                       | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                       << 0xdU)));
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = (0xc00U | (0x7fe03fU & vlTOPp->top__DOT__InstrDec__DOT__settings));
                vlTOPp->top__DOT__InstrDec__DOT__settings 
                    = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                       | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                                   >> 6U)));
            } else {
                if ((0xaU == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                      >> 0xcU)))) {
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = (0x200000U | (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings));
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                           | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                           << 0xdU)));
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = (0xd00U | (0x7fe03fU & vlTOPp->top__DOT__InstrDec__DOT__settings));
                    vlTOPp->top__DOT__InstrDec__DOT__settings 
                        = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                           | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                                       >> 6U)));
                } else {
                    if ((0xbU == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                          >> 0xcU)))) {
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                               | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                               << 0xdU)));
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = (0x600U | (0x7fe03fU 
                                         & vlTOPp->top__DOT__InstrDec__DOT__settings));
                        vlTOPp->top__DOT__InstrDec__DOT__settings 
                            = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                               | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                                           >> 6U)));
                    } else {
                        if ((0xcU == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                              >> 0xcU)))) {
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = ((0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                   | (0x1fe000U & ((IData)(vlTOPp->top__DOT__instruction) 
                                                   << 0xdU)));
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = (0x700U | (0x7fe03fU 
                                             & vlTOPp->top__DOT__InstrDec__DOT__settings));
                            vlTOPp->top__DOT__InstrDec__DOT__settings 
                                = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                   | (0x3cU & ((IData)(vlTOPp->top__DOT__instruction) 
                                               >> 6U)));
                        } else {
                            if ((0xdU == (0xfU & ((IData)(vlTOPp->top__DOT__instruction) 
                                                  >> 0xcU)))) {
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = (0x200000U | 
                                       (0x1fffffU & vlTOPp->top__DOT__InstrDec__DOT__settings));
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = (0x601fffU & vlTOPp->top__DOT__InstrDec__DOT__settings);
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = (0x1200U | (0x7fe03fU 
                                                  & vlTOPp->top__DOT__InstrDec__DOT__settings));
                                vlTOPp->top__DOT__InstrDec__DOT__settings 
                                    = ((0x7fffc0U & vlTOPp->top__DOT__InstrDec__DOT__settings) 
                                       | (0x3fU & ((IData)(vlTOPp->top__DOT__instruction) 
                                                   >> 6U)));
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x400000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
        if ((0x400000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            vlTOPp->top__DOT__WriteAddr = (3U & vlTOPp->top__DOT__InstrDec__DOT__settings);
        }
    } else {
        vlTOPp->top__DOT__WriteAddr = (3U & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                             >> 2U));
    }
    if ((0x1000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
        if ((0x1000U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            vlTOPp->top__DOT__ALU_RegFile__DOT__in0 = 0U;
        }
    } else {
        vlTOPp->top__DOT__ALU_RegFile__DOT__in0 = (0xffU 
                                                   & ((0x20U 
                                                       & vlTOPp->top__DOT__InstrDec__DOT__settings)
                                                       ? 
                                                      ((0x10U 
                                                        & vlTOPp->top__DOT__InstrDec__DOT__settings)
                                                        ? (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3)
                                                        : (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2))
                                                       : 
                                                      ((0x10U 
                                                        & vlTOPp->top__DOT__InstrDec__DOT__settings)
                                                        ? (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1)
                                                        : (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0))));
    }
    vlTOPp->top__DOT__ALU_RegFile__DOT__rd1_data = 
        ((8U & vlTOPp->top__DOT__InstrDec__DOT__settings)
          ? ((4U & vlTOPp->top__DOT__InstrDec__DOT__settings)
              ? (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3)
              : (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2))
          : ((4U & vlTOPp->top__DOT__InstrDec__DOT__settings)
              ? (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1)
              : (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0)));
    if ((0x800U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
        if ((0x800U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            vlTOPp->top__DOT__ALU_RegFile__DOT__in1 
                = (0xffU & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                            >> 0xdU));
        }
    } else {
        vlTOPp->top__DOT__ALU_RegFile__DOT__in1 = (0xffU 
                                                   & (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__rd1_data));
    }
    if ((0x400U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
        if ((0x200U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__t_branch 
                = ((0x100U & vlTOPp->top__DOT__InstrDec__DOT__settings)
                    ? (((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                        != (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1))
                        ? 2U : 0U) : (((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                                       == (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1))
                                       ? 1U : 0U));
        }
    }
    if ((0x400U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
        vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out 
            = ((0x200U & vlTOPp->top__DOT__InstrDec__DOT__settings)
                ? 0U : ((0x100U & vlTOPp->top__DOT__InstrDec__DOT__settings)
                         ? (0xfeU & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                                     << 1U)) : ((0x80U 
                                                 & (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0)) 
                                                | (0x7fU 
                                                   & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                                                      >> 1U)))));
    } else {
        if ((0x200U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out 
                = ((0x100U & vlTOPp->top__DOT__InstrDec__DOT__settings)
                    ? ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                       | (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1))
                    : ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                       & (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1)));
        } else {
            if ((0x100U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
                vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out 
                    = (0xffU & (~ (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1)));
            } else {
                vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out 
                    = (0xffU & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                                + (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1)));
                vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__oflow 
                    = (((1U & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                               >> 7U)) == (1U & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in1) 
                                                 >> 7U))) 
                       & ((1U & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__in0) 
                                 >> 7U)) != (1U & ((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out) 
                                                   >> 7U))));
            }
        }
    }
    vlTOPp->top__DOT__ALU_tb = (1U & (((((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__t_branch) 
                                         & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                            >> 0xaU)) 
                                        & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                           >> 9U)) 
                                       & (~ (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                             >> 8U))) 
                                      | (((((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__t_branch) 
                                            >> 1U) 
                                           & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                              >> 0xaU)) 
                                          & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                             >> 9U)) 
                                         & (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                            >> 8U))));
    if ((0x40U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
        if ((0x40U & vlTOPp->top__DOT__InstrDec__DOT__settings)) {
            vlTOPp->top__DOT__WriteData = vlTOPp->top__DOT__DataMem__DOT__mem
                [vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out];
        }
    } else {
        vlTOPp->top__DOT__WriteData = ((((((IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__oflow) 
                                           & (~ (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                                 >> 0xaU))) 
                                          & (~ (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                                >> 9U))) 
                                         & (~ (vlTOPp->top__DOT__InstrDec__DOT__settings 
                                               >> 8U))) 
                                        << 8U) | (IData)(vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out));
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
          | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst)))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__ALU_tb) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__ALU_tb))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__ALU_tb 
        = vlTOPp->__VinpClk__TOP__top__DOT__ALU_tb;
    vlTOPp->__VinpClk__TOP__top__DOT__ALU_tb = vlTOPp->top__DOT__ALU_tb;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->top__DOT__ALU_tb ^ vlTOPp->__Vchglast__TOP__top__DOT__ALU_tb));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__ALU_tb ^ vlTOPp->__Vchglast__TOP__top__DOT__ALU_tb))) VL_DBG_MSGF("        CHANGE: top.v:13: top.ALU_tb\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__ALU_tb = vlTOPp->top__DOT__ALU_tb;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
