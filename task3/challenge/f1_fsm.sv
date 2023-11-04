module f1_fsm(
    input logic clk,
    input logic en,
    input logic rst,
    output logic [7:0] data_out
);

    typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} state;

    state current_state, next_state;

    initial current_state = S0;

    always_ff @(posedge clk)
        if(rst) current_state <= S0;
        else if(en) begin
            current_state <= next_state;
        end
    
    always_comb
        case(current_state)
            S0: begin
                next_state = S1;
                data_out = 8'b0;
            end
            S1: begin
                next_state = S2;
                data_out = 8'b1;
            end
            S2: begin
                next_state = S3;
                data_out = 8'b11;
            end
            S3: begin
                next_state = S4;
                data_out = 8'b111;
            end
            S4: begin
                next_state = S5;
                data_out = 8'b1111;
            end
            S5: begin
                next_state = S6;
                data_out = {{3{1'b0}}, {5{1'b1}}};
            end
            S6: begin
                next_state = S7;
                data_out = {{2{1'b0}}, {6{1'b1}}};
            end
            S7: begin
                next_state = S8;
                data_out = {1'b0, {7{1'b1}}};
            end
            S8: begin
                next_state = S0;
                data_out = {8{1'b1}};
            end
            default: begin
                next_state = S0;
                data_out = 8'b0;
            end
        endcase
    
endmodule
