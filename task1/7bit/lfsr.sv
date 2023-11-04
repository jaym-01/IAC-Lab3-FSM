module lfsr(
    input logic clk,
    input logic en,
    input logic rst,
    output logic [6:0] data_out
);

    logic [7:1] sreg;

    always_ff @(posedge clk)
        if (rst) sreg <= {7{1'b1}};
        else if (en) begin
            sreg[7:2] <= sreg[6:1];
            sreg[1] <= sreg[7] ^ sreg[3];
        end

    assign data_out = sreg;    
    
endmodule
