module alu_regfile(input clk, input rst, input wr_en, 
                   input [1:0] wr_addr, input [8:0] wr_data,
                   input [1:0] rd0_addr, input [1:0] rd1_addr, 
                   input [7:0] instr_i, input [2:0] alu_op, 
                   input alu_s0, input alu_s1,
                   output [7:0] f, output ovf, output take_branch,
                   output [7:0] alu_in0, output [7:0] alu_in1,
		           output [8:0] ReadData1, output [8:0] ReadData2
    );
                   
    wire [8:0] rd0_data;
    wire [8:0] rd1_data;
    
    reg [7:0] in0;
    reg [7:0] in1;
    
    assign alu_in0 = in0;
    assign alu_in1 = in1;

    assign ReadData1 = rd0_data;
    assign ReadData2 = rd1_data;
                   
    reg_file regFile (.clk(clk), .rst(rst), .wr_en(wr_en), .wr_addr(wr_addr), .wr_data(wr_data), 
            .rd0_addr(rd0_addr), .rd1_addr(rd1_addr), .rd0_data(rd0_data), .rd1_data(rd1_data));
       
    always @(*) begin
        case (alu_s0) 
            0: in0 <= rd0_data[7:0];
            1: in0 <= 8'd0;
        endcase
        case (alu_s1)
            0: in1 <= rd1_data[7:0];
            1: in1 <= instr_i;
        endcase
    end
                            
    alu8 alu (.a(alu_in0), .b(alu_in1), .sel(alu_op), .f(f), .ovf(ovf), .take_branch(take_branch));
                   
endmodule
