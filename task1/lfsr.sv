module lfsr(
    input logic clk,
    input logic en,
    input logic rst,
    output logic [3:0] data_out
);

    logic [4:1] sreg;

    always_ff @(posedge clk)
        if (rst) sreg <= {4{1'b1}};
        else if (en) begin
            sreg[4:2] <= sreg[3:1];
            sreg[1] <= sreg[4] ^ sreg[3];
        end


    // try this ontop of always ff
    assign data_out = sreg;    
    
endmodule
