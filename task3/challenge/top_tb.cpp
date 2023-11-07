#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"
#include "Vtop.h"

#include "iostream"

int main(int argc, char **argv, char **env){
    int i, clk;

    Verilated::commandArgs(argc, argv);
    
    Vtop *top = new Vtop;

    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    if(vbdOpen() != 1) return -1;

    vbdHeader("Lab 3: Task 3");

    // tested again -> required a diffferent value of N between each state transistion
    // to the previous task
    top->n = 46;
    top->clk = 1;
    top->rst = 1;

    for(i = 0; i < 1000000; i++){
        for(clk = 0; clk < 2; clk++){
            tfp->dump(2*i+clk);
            top->clk = !top->clk;
            top->eval();
        }

        vbdBar(top->data_out & 0xFF);
        vbdCycle(i + 1);

        top->rst = (i < 2);

        if(Verilated::gotFinish()) exit(0);
    }

    vbdClose();
    tfp->close();
    exit(0);

}