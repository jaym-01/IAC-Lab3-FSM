#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#include "Vf1_fsm.h"

#include "iostream"

int main(int argc, char **argv, char **env){
    int i, clk;

    Verilated::commandArgs(argc, argv);
    
    Vf1_fsm *top = new Vf1_fsm;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("f1_fsm.vcd");

    if(vbdOpen() != 1) return -1;

    vbdHeader("Lab 3: Task 2");

    vbdSetMode(1);

    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    for(i = 0; i < 1000000; i++){
        for(clk = 0; clk < 2; clk++){
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        // std::cout << (int)top->data_out << std::endl;
        vbdBar(top->data_out & 0xFF);
        vbdCycle(i + 1);

        top->rst = (i < 2);

        top->en = (i >= 2 && vbdFlag());

        if(Verilated::gotFinish()) exit(0);
    }

    vbdClose();
    tfp->close();
    exit(0);

}