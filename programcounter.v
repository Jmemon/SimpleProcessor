`timescale 1ns / 1ps

module programcounter(input clk, input rst, input [7:0] immediate, 
	     	      input take_branch, output [7:0] pc
	);

	reg [7:0] pcount = 8'b0; 
	assign pc = pcount;

	always @(posedge clk, posedge rst, posedge take_branch) begin
		if (rst) begin
			pcount <= 8'b0;
		end
		else if (take_branch) begin
			pcount <= pcount + immediate;
		end
		else if (clk) begin
			pcount <= pcount + 1;
		end
	end

endmodule
