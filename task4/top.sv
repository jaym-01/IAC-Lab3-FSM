module top(
    input logic clk,
    input logic rst,
    input logic [4:0] n,
    input logic trigger,
    output logic [7:0] data_out
);

    logic cmd_seq;
    logic cmd_delay;
    logic mux_out;
    logic tick;
    logic time_out;
    logic [6:0] k;
    

    f1_fsm f1Fsm(
        .rst(rst),
        .en(mux_out),
        .trigger(trigger),
        .clk(clk),
        .data_out(data_out),
        .cmd_delay(cmd_delay),
        .cmd_seq(cmd_seq)
    );

    clktick #(5) clkTick(
        .n(n),
        .en(cmd_seq),
        .rst(rst),
        .clk(clk),
        .tick(tick)
    );

    lfsr LFSR(
        .data_out(k),
        .clk(clk),
        .en(1),
        .rst(rst)
    );

    delay #(7) delayComp(
        .n(k),
        .trigger(cmd_delay),
        .rst(rst),
        .clk(clk),
        .time_out(time_out)
    );

    always_comb
        if(cmd_seq)
            mux_out = tick;
        else
            mux_out = time_out;

endmodule
