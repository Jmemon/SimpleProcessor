module programcounter(input clk, input rst, input [7:0] immediate, 
	     	      input take_branch, output [7:0] pc
	);

	reg [7:0] PC = 8'b0;
	assign pc = PC;

	always @(posedge clk, posedge rst, posedge take_branch) begin
		if (rst) begin
			PC <= 8'b0;
		end
		else if (take_branch) begin
			PC <= PC + immediate;
		end
		else if (clk) begin
			PC <= PC + 1;
		end
	end

endmodule