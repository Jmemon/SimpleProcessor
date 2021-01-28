`timescale 1ns / 1ps

module instr_memory (
	input [7:0] addr, 
	output [15:0] instr
);

	reg [15:0] i_mem [255:0];

	assign instr = i_mem[addr];

	initial begin
		// Read up to 256 16-bit instructions into i_mem
		$readmemh("code.dat", i_mem);
	end

endmodule
