`timescale 1ns / 1ps

module top (
		input wire clk,
		input wire rst
	);

	// ALU I/O
	wire [7:0] ALU_in1, ALU_in2;
	wire [7:0] ALU_out;
	wire [2:0] ALU_op;
	wire 	   ALU_ovf;
	wire 	   ALU_tb;

	// Instruction
	wire [15:0] instruction;

	// Instruction Fields
	wire [3:0] opcode;
	wire [1:0] rs_addr;
	wire [1:0] rt_addr;
	wire [1:0] rd_addr;
	wire [7:0] immediate;

	// Control Signals
	wire RegDst;
	wire RegWrite;
	wire ALUSrc1;
	wire ALUSrc2;
	wire MemWrite;
	wire MemToReg;

	// Register File I/O
	wire [1:0] rf_waddr;
	wire [8:0] rf_wdata;
	wire [8:0] rf_rdata1;
	wire [8:0] rf_rdata2;

	// Data Memory
	wire [8:0] data_mem_out;

	// Program Counter
	wire [7:0] pc;

	// Instantiate Modules
	alu_regfile ALU_RegFile (
		.clk(clk), .rst(rst), .wr_en(RegWrite),
		.wr_addr(rf_waddr), .wr_data(rf_wdata), 
		.rd0_addr(rs_addr), .rd1_addr(rt_addr), .instr_i(immediate),
		.alu_op(ALU_op), .alu_s0(ALUSrc1), .alu_s1(ALUSrc2),
		.f(ALU_out), .ovf(ALU_ovf), .take_branch(ALU_tb),
		.alu_in0(ALU_in1), .alu_in1(ALU_in2), 
		.ReadData1(rf_rdata1), .ReadData2(rf_rdata2)
	);

	data_memory DataMem (
		.clk(clk), .rst(rst), .we(MemWrite),
		.a(ALU_out), .d(rf_rdata2), .spo(data_mem_out)
	);

	/*
	Instruction Memory Here
	- Need to figure out how to load it
	- how to use assembler
	- what docs to give
	- how much can I do on my own so I can take out credit to Northeastern
	*/
	instr_memory InstrMem (
		.addr(pc), .instr(instruction)
	);

	instr_decoder InstrDec (
		.instruction(instruction), .RegWrite(RegWrite), .RegDst(RegDst),
		.instr_i(immediate), 
		.ALUSrc1(ALUSrc1), .ALUSrc2(ALUSrc2), .ALUOp(ALU_op),
		.MemWrite(MemWrite), .opcode(opcode), .MemToReg(MemToReg),
		.rs_addr(rs_addr), .rt_addr(rt_addr), .rd_addr(rd_addr)
	);

	programcounter PCount (
		.clk(clk), .rst(rst),
		.immediate(immediate), .take_branch(ALU_tb), .pc(pc)
	);

	// Registers to Use in Always Blocks
	reg [8:0] WriteData;
	reg [1:0] WriteAddr;

	assign rf_wdata = WriteData;
	assign rf_waddr = WriteAddr;

	// MUX for rf_wdata
	always @(*) begin
		case (MemToReg)
			1'b0: WriteData = {ALU_ovf, ALU_out};
			1'b1: WriteData = data_mem_out;
		endcase
	end

	// MUX for rf_waddr
	always @(*) begin
		case (RegDst)
			1'b0: WriteAddr = rt_addr;
			1'b1: WriteAddr = rd_addr;
		endcase
	end

endmodule

