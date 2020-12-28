module alu8(input [7:0] a, input [7:0] b, input [2:0] sel,
                    output [7:0] f, output ovf, output take_branch);
    
    reg [1:0] t_branch;
    reg oflow;
    reg [7:0] out = 8'd0;
    
    always @(*) begin
        case (sel) 
            3'd0: begin     // adder
                out = a + b;
                if ((a[7] == b[7]) && (a[7] != out[7])) begin
                    oflow = 1;
                end else begin
                    oflow = 0;
                end
            end
            3'd1: out = ~b;     // Bitwise Invert
            3'd2: out = a & b;  // Bitwise AND
            3'd3: out = a | b;  // Bitwsie OR
            3'd4: out = {a[7], a[7], a[6], a[5], a[4], a[3], a[2], a[1]};   // SRA
            3'd5: out = {a[6], a[5], a[4], a[3], a[2], a[1], a[0], 1'b0};   // SLL
            3'd6: begin             // BEQ
                out = 8'd0;
                if (a == b) begin
                    t_branch = 2'b01;
                end else begin
                    t_branch = 2'b00;
                end
            end
            3'd7: begin             // BNEQ
                out = 8'd0;
                if (a != b) begin
                    t_branch = 2'b10;
                end else begin
                    t_branch = 2'b00;
                end
            end
        endcase
    end
    
    assign ovf = oflow & ~sel[2] & ~sel[1] & ~sel[0];
    assign take_branch = (t_branch[0] & sel[2] & sel[1] & ~sel[0]) |
                         (t_branch[1] & sel[2] & sel[1] &  sel[0]);
    assign f = out;

endmodule