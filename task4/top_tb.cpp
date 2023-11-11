#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"     // include vbuddy code
#include "bin_bcd.cpp"
#define MAX_SIM_CYC 1000000

#include "iostream"

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T4:F1LIGHTS");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 1;
  top->trigger = 0;
  top->n = 31;

  bool prev_full = false;
  bool read = false;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // Display toggle neopixel
    vbdBar(top->data_out & 0xFF);

    if(prev_full && (int)top->data_out == 0){
      // std::cout << "start" << std::endl;
      vbdInitWatch();

      prev_full = false;
      read = true;
    }
    else if((int)top->data_out == 255){
      prev_full = true;
    }

    if(read && vbdFlag()){
      int time = vbdElapsed();
      prev_full = false;
      read = false;

      int bcd_time = bin_bcd(time);

      std::cout << time << std::endl;

      vbdHex(4, (bcd_time >> 16) & 0xF);
      vbdHex(3, (bcd_time >> 8) & 0xF);
      vbdHex(2, (bcd_time >> 4) & 0xF);
      vbdHex(1, (bcd_time & 0xF));

    }
    

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->trigger = (simcyc > 2 && vbdFlag());
    vbdCycle(simcyc);

    if (Verilated::gotFinish())  {
      exit(0);
      tfp->close(); 
    }
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
