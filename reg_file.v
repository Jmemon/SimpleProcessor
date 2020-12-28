module reg_file(input clk, input rst, input wr_en, 
    input [1:0] wr_addr, input [8:0] wr_data,
    input [1:0] rd0_addr, input [1:0] rd1_addr, 
    output [8:0] rd0_data, output [8:0] rd1_data);
    
    reg [8:0] reg0;
    reg [8:0] reg1;
    reg [8:0] reg2;
    reg [8:0] reg3;
    
    // flip flops are always showing output on Qs, so we don't need to put them in sync with the clock
    assign rd0_data = (rd0_addr[1] == 0) ? (rd0_addr[0] == 0 ? reg0 : reg1) : 
                                           (rd0_addr[0] == 0 ? reg2 : reg3);
    
    assign rd1_data = (rd1_addr[1] == 0) ? (rd1_addr[0] == 0 ? reg0 : reg1) :
                                           (rd1_addr[0] == 0 ? reg2 : reg3);
    
    initial begin
        reg0 = 9'd0;
        reg1 = 9'd0;
        reg2 = 9'd0;
        reg3 = 9'd0;
    end
    
    // write on posedge of clk
    always @(posedge rst, posedge clk) begin
        if (rst) begin
            reg0 = 9'd0;
            reg1 = 9'd0;
            reg2 = 9'd0;
            reg3 = 9'd0;
        end else if (wr_en) begin
            case (wr_addr)
                2'd0: reg0 <= wr_data;
                2'd1: reg1 <= wr_data;
                2'd2: reg2 <= wr_data;
                2'd3: reg3 <= wr_data;
            endcase
        end
    end
    
endmodule
