`timescale 1ns / 1ps

module Lab8_Datapath(
		input wire clk,
		input wire top_pb_clk,
        input wire rst_general,
		output [3:0] disp_en,
		output [6:0] seg7_output
    );
	
	wire [7:0] alu_input1, alu_input2;
    wire [7:0] alu_output;
    wire [2:0] ALUOp;
    wire       alu_ovf;
    wire       take_branch;
	
    
    wire [15:0] instruction;
    //insturction fields
    wire [3:0] opcode;
    wire [1:0] rs_addr;
    wire [1:0] rt_addr;
    wire [1:0] rd_addr;
    wire [7:0] immediate;
    //control signals
    wire RegDst;
    wire RegWrite;
    wire ALUSrc1;
    wire ALUSrc2;
    wire MemWrite;
    wire MemToReg;

    wire [1:0] regfile_write_address;//destination register address
    wire [8:0] regfile_write_data;//result data
    wire [8:0] read_data1;//source register1 data
    wire [8:0] read_data2;//source register2 data

    wire [8:0] alu_result;
    wire [7:0] zero_register;
    wire [8:0] data_mem_out;

    wire pb_clk_debounced;
	wire [7:0] pc;

	assign zero_register = 8'b0;//ZERO constant
	assign alu_result = {alu_ovf, alu_output};


		// Debounce
		debounce debounce_clk(
						.clk_in(clk),
						.rst_in(rst_general),
						.sig_in(top_pb_clk),
						.sig_debounced_out(pb_clk_debounced)
						);		
  
		// 7-Segment display module
	   	Adaptor_display display(.clk(clk), 				// system clock
							.input_value(alu_output),		// 8-bit input [7:0] value to display
							.disp_en(disp_en),			// output [3:0] 7 segment display enable
							.seg7_output(seg7_output));		// output [6:0] 7 segment signals
							
		/* Instantiate all other modules */
		alu_regfile alu_regfile (.clk(pb_clk_debounced), .rst(rst_general), .wr_en(RegWrite),
		      .wr_addr(regfile_write_address), .wr_data(regfile_write_data),
		      .rd0_addr(rs_addr), .rd1_addr(rt_addr), .instr_i(immediate),
		      .alu_op(ALUOp), .alu_s0(ALUSrc1), .alu_s1(ALUSrc2),
		      .f(alu_output), .ovf(alu_ovf), .take_branch(take_branch),
		      .alu_in0(alu_input1), .alu_in1(alu_input2),
		      .ReadData1(read_data1), .ReadData2(read_data2)
        );
		
		data_memory datamem (.clk(pb_clk_debounced), .rst(rst_general), .we(MemWrite),
		      .a(alu_output), .d(read_data2), .spo(data_mem_out)
        );
        
        instr_mem instr_mem (
              .a(pc),      // input wire [7 : 0] a
              .spo(instruction)  // output wire [15 : 0] spo
        );
		
		instr_decoder instdec (.instruction(instruction), .RegWrite(RegWrite), 
		      .RegDst(RegDst), .instr_i(immediate), 
		      .ALUSrc1(ALUSrc1), .ALUSrc2(ALUSrc2), .ALUOp(ALUOp),
		      .MemWrite(MemWrite), .opcode(opcode), .MemToReg(MemToReg),
		      .rs_addr(rs_addr), .rt_addr(rt_addr), .rd_addr(rd_addr)
        );
		
		programcounter pcount (.clk(pb_clk_debounced), .rst(rst_general), .immediate(immediate),
		      .take_branch(take_branch), .pc(pc)
		);
		
		reg [8:0] WriteData;
		assign regfile_write_data = WriteData;
		
		reg [1:0] WriteAddr;
		assign regfile_write_address = WriteAddr;
		
		// MUX for regfile_writedata
		always @(*) begin
		  case (MemToReg)
		      1'b0: WriteData <= alu_result;
		      1'b1: WriteData <= data_mem_out;
		  endcase
		end
		
		// MUX for RegDst
		always @(*) begin
		  case (RegDst) 
		      1'b0: WriteAddr <= rt_addr;
		      1'b1: WriteAddr <= rd_addr;
		  endcase
		end
		
		vio_0 vio (
            .clk(clk),                // input wire clk
            .probe_in0(alu_output),    // input wire [7 : 0] probe_in0
            .probe_in1(alu_ovf),    // input wire [0 : 0] probe_in1
            .probe_in2(take_branch),    // input wire [0 : 0] probe_in2
            .probe_in3(read_data1),    // input wire [7 : 0] probe_in3
            .probe_in4(read_data2),    // input wire [7 : 0] probe_in4
            .probe_in5(alu_input1),    // input wire [7 : 0] probe_in5
            .probe_in6(alu_input2),    // input wire [7 : 0] probe_in6
            .probe_in7(regfile_write_data),    // input wire [8 : 0] probe_in7
            .probe_in8(data_mem_out),    // input wire [8 : 0] probe_in8
            .probe_in9(opcode),    // input wire [3 : 0] probe_in9
            .probe_in10(rs_addr),  // input wire [1 : 0] probe_in10
            .probe_in11(rt_addr),  // input wire [1 : 0] probe_in11
            .probe_in12(rd_addr),  // input wire [1 : 0] probe_in12
            .probe_in13(immediate),  // input wire [7 : 0] probe_in13
            .probe_in14(RegDst),  // input wire [0 : 0] probe_in14
            .probe_in15(RegWrite),  // input wire [0 : 0] probe_in15
            .probe_in16(ALUSrc1),  // input wire [0 : 0] probe_in16
            .probe_in17(ALUSrc2),  // input wire [0 : 0] probe_in17
            .probe_in18(ALUOp),  // input wire [2 : 0] probe_in18
            .probe_in19(MemWrite),  // input wire [0 : 0] probe_in19
            .probe_in20(MemToReg),  // input wire [0 : 0] probe_in20
            .probe_in21(pc),  // input wire [7 : 0] probe_in21
            .probe_in22(instruction)  // input wire [15 : 0] probe_in22
        );
    
endmodule
