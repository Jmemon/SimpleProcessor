// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_WRITEF("[%0t] Model Running...\n\n",64,(0x3e8ULL 
                                               * (QData)(VL_TIME_UNITED_Q(1000))));
    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0 = 0U;
    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1 = 0U;
    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2 = 0U;
    vlTOPp->top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3 = 0U;
    VL_READMEM_N(true, 16, 256, 0, std::string("code.dat")
                 , vlTOPp->top__DOT__InstrMem__DOT__i_mem
                 , 0, ~0ULL);
    vlTOPp->top__DOT__InstrMem__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x100U, vlTOPp->top__DOT__InstrMem__DOT__i)) {
        VL_WRITEF("%x\n",16,vlTOPp->top__DOT__InstrMem__DOT__i_mem
                  [(0xffU & vlTOPp->top__DOT__InstrMem__DOT__i)]);
        vlTOPp->top__DOT__InstrMem__DOT__i = ((IData)(1U) 
                                              + vlTOPp->top__DOT__InstrMem__DOT__i);
    }
    vlTOPp->top__DOT__DataMem__DOT__i = 0U;
    while (VL_GTS_III(1,32,32, 0x100U, vlTOPp->top__DOT__DataMem__DOT__i)) {
        vlTOPp->top__DOT__DataMem__DOT__mem[(0xffU 
                                             & vlTOPp->top__DOT__DataMem__DOT__i)] = 0U;
        vlTOPp->top__DOT__DataMem__DOT__i = ((IData)(1U) 
                                             + vlTOPp->top__DOT__DataMem__DOT__i);
    }
    vlTOPp->top__DOT__ALU_RegFile__DOT__alu__DOT__out = 0U;
    vlTOPp->top__DOT__PCount__DOT__pcount = 0U;
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__ALU_tb 
        = vlTOPp->__VinpClk__TOP__top__DOT__ALU_tb;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    top__DOT__ALU_tb = VL_RAND_RESET_I(1);
    top__DOT__instruction = VL_RAND_RESET_I(16);
    top__DOT__WriteData = VL_RAND_RESET_I(9);
    top__DOT__WriteAddr = VL_RAND_RESET_I(2);
    top__DOT__ALU_RegFile__DOT__rd1_data = VL_RAND_RESET_I(9);
    top__DOT__ALU_RegFile__DOT__in0 = VL_RAND_RESET_I(8);
    top__DOT__ALU_RegFile__DOT__in1 = VL_RAND_RESET_I(8);
    top__DOT__ALU_RegFile__DOT__regFile__DOT__reg0 = VL_RAND_RESET_I(9);
    top__DOT__ALU_RegFile__DOT__regFile__DOT__reg1 = VL_RAND_RESET_I(9);
    top__DOT__ALU_RegFile__DOT__regFile__DOT__reg2 = VL_RAND_RESET_I(9);
    top__DOT__ALU_RegFile__DOT__regFile__DOT__reg3 = VL_RAND_RESET_I(9);
    top__DOT__ALU_RegFile__DOT__alu__DOT__t_branch = VL_RAND_RESET_I(2);
    top__DOT__ALU_RegFile__DOT__alu__DOT__oflow = VL_RAND_RESET_I(1);
    top__DOT__ALU_RegFile__DOT__alu__DOT__out = VL_RAND_RESET_I(8);
    top__DOT__DataMem__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        top__DOT__DataMem__DOT__mem[__Vi0] = VL_RAND_RESET_I(9);
    }
    top__DOT__InstrMem__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        top__DOT__InstrMem__DOT__i_mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    top__DOT__InstrDec__DOT__settings = VL_RAND_RESET_I(23);
    top__DOT__PCount__DOT__pcount = VL_RAND_RESET_I(8);
    __VinpClk__TOP__top__DOT__ALU_tb = VL_RAND_RESET_I(1);
    __Vchglast__TOP__top__DOT__ALU_tb = VL_RAND_RESET_I(1);
}
