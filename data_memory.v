`timescale 1ns / 1ps

module data_memory(input clk, input rst, input we,
    input [7:0] a, input [8:0] d, output [8:0] spo);
    
    integer i;
    reg [8:0] mem [255:0];
    
    assign spo = mem[a];
    
    initial begin
        for (i=0; i<256; i=i+1) begin
            mem[i] = 9'd0;
        end
    end
    
    // write on posedge of clk
    always @(posedge rst, posedge clk) begin
        if (rst) begin
            for (i=0; i<256; i=i+1) begin
                mem[i] = 9'd0;
            end
        end else if (we) begin
            mem[a] <= d;
        end
    end
    
endmodule
