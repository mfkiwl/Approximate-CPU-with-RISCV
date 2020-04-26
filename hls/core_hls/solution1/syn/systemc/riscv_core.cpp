// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "riscv_core.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic riscv_core::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic riscv_core::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<2> riscv_core::ap_ST_fsm_state1 = "1";
const sc_lv<2> riscv_core::ap_ST_fsm_state2 = "10";
const sc_lv<32> riscv_core::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> riscv_core::ap_const_lv32_1 = "1";
const bool riscv_core::ap_const_boolean_1 = true;

riscv_core::riscv_core(sc_module_name name) : sc_module(name), mVcdFile(0) {
    grp_datapath_fu_14 = new datapath("grp_datapath_fu_14");
    grp_datapath_fu_14->ap_clk(ap_clk);
    grp_datapath_fu_14->ap_rst(ap_rst);
    grp_datapath_fu_14->ap_start(grp_datapath_fu_14_ap_start);
    grp_datapath_fu_14->ap_done(grp_datapath_fu_14_ap_done);
    grp_datapath_fu_14->ap_idle(grp_datapath_fu_14_ap_idle);
    grp_datapath_fu_14->ap_ready(grp_datapath_fu_14_ap_ready);
    grp_datapath_fu_14->PC(PC);
    grp_datapath_fu_14->ap_return(grp_datapath_fu_14_ap_return);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_PC_assign_i_fu_30_p2);
    sensitive << ( PC );
    sensitive << ( grp_datapath_fu_14_ap_return );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( grp_datapath_fu_14_ap_done );
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( grp_datapath_fu_14_ap_done );
    sensitive << ( ap_CS_fsm_state2 );

    SC_METHOD(thread_grp_datapath_fu_14_ap_start);
    sensitive << ( grp_datapath_fu_14_ap_start_reg );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( grp_datapath_fu_14_ap_done );
    sensitive << ( ap_CS_fsm_state2 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    ap_CS_fsm = "01";
    PC = "00000000000000000000000000000000";
    grp_datapath_fu_14_ap_start_reg = SC_LOGIC_0;
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "riscv_core_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, PC, "PC");
    sc_trace(mVcdFile, grp_datapath_fu_14_ap_start, "grp_datapath_fu_14_ap_start");
    sc_trace(mVcdFile, grp_datapath_fu_14_ap_done, "grp_datapath_fu_14_ap_done");
    sc_trace(mVcdFile, grp_datapath_fu_14_ap_idle, "grp_datapath_fu_14_ap_idle");
    sc_trace(mVcdFile, grp_datapath_fu_14_ap_ready, "grp_datapath_fu_14_ap_ready");
    sc_trace(mVcdFile, grp_datapath_fu_14_ap_return, "grp_datapath_fu_14_ap_return");
    sc_trace(mVcdFile, grp_datapath_fu_14_ap_start_reg, "grp_datapath_fu_14_ap_start_reg");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, PC_assign_i_fu_30_p2, "PC_assign_i_fu_30_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("riscv_core.hdltvin.dat");
    mHdltvoutHandle.open("riscv_core.hdltvout.dat");
}

riscv_core::~riscv_core() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
    delete grp_datapath_fu_14;
}

void riscv_core::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst.read() == ap_const_logic_1) {
        grp_datapath_fu_14_ap_start_reg = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
            grp_datapath_fu_14_ap_start_reg = ap_const_logic_1;
        } else if (esl_seteq<1,1,1>(ap_const_logic_1, grp_datapath_fu_14_ap_ready.read())) {
            grp_datapath_fu_14_ap_start_reg = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(grp_datapath_fu_14_ap_done.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()))) {
        PC = PC_assign_i_fu_30_p2.read();
    }
}

void riscv_core::thread_PC_assign_i_fu_30_p2() {
    PC_assign_i_fu_30_p2 = (!PC.read().is_01() || !grp_datapath_fu_14_ap_return.read().is_01())? sc_lv<32>(): (sc_biguint<32>(PC.read()) + sc_biguint<32>(grp_datapath_fu_14_ap_return.read()));
}

void riscv_core::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void riscv_core::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void riscv_core::thread_ap_done() {
    if ((esl_seteq<1,1,1>(grp_datapath_fu_14_ap_done.read(), ap_const_logic_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void riscv_core::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void riscv_core::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(grp_datapath_fu_14_ap_done.read(), ap_const_logic_1) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void riscv_core::thread_grp_datapath_fu_14_ap_start() {
    grp_datapath_fu_14_ap_start = grp_datapath_fu_14_ap_start_reg.read();
}

void riscv_core::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(grp_datapath_fu_14_ap_done.read(), ap_const_logic_1) && esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state2;
            }
            break;
        default : 
            ap_NS_fsm = "XX";
            break;
    }
}

void riscv_core::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

