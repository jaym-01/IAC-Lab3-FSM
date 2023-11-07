#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#include "Vlfsr.h"

#include "iostream"

int main(int argc, char **argv, char **env){
    int i, clk;

    Verilated::commandArgs(argc, argv);
    
    Vlfsr *top = new Vlfsr;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("lfsr.vcd");

    if(vbdOpen() != 1) return -1;

    vbdHeader("Lab 3: Task 1");

    vbdSetMode(1);

    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    for(i = 0; i < 100000; i++){
        for(clk = 0; clk < 2; clk++){
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        vbdHex(2, top->data_out & 0xF);
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