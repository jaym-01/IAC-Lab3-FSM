module top(
    input logic [15:0] N,
    input logic rst,
    input logic clk,
    output logic [7:0] data_out,
);

    logic tick;

    clktick clkTick(
        .clk(clk),
        .rst(rst),
        .en(1),
        .N(N),
        .tick(tick)
    );

    f1_fsm f1Fsm(
        .clk(clk),
        .en(tick),
        .rst(rst),
        .data_out(data_out)
    );

endmodule
