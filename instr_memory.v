`timescale 1ns / 1ps

module instr_memory (
	input [7:0] addr, 
	output [15:0] instr
);

	integer i;
	reg [15:0] i_mem [255:0];

	assign instr = i_mem[addr];

	initial begin
		// Read up to 256 16-bit instructions into i_mem
		$readmemh("code.dat", i_mem);
		for (i = 0; i < 256; i=i+1) begin
			$display("%h", i_mem[i]);
		end
	end

	always @(*) begin
		//$display("Executing: %h", i_mem[addr]);
		//$display("Address  : %h\n", addr);
	end

endmodule
