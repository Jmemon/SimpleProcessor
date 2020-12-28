module instr_decoder(input [15:0] instruction, output RegWrite, output RegDst, 
                     output [7:0] instr_i, output ALUSrc1, output ALUSrc2, output [2:0] ALUOp, 
                     output MemWrite, output [3:0] opcode, output MemToReg, 
                     output [1:0] rs_addr, output [1:0] rt_addr, output [1:0] rd_addr
    );
                   
    reg [22:0] settings; 
    // RegWrite [22], RegDst [21], instr_i [20:13], ALUSrc1[12], ALUSrc2[11], ALUOp[10:8], 
    //  MemWrite [7], MemToReg [6], rs_addr[5:4], rt_addr[3:2], rd_addr[1:0]
                              
    assign RegDst = settings[22];
    assign RegWrite = settings[21];
    assign instr_i = settings[20:13];
    assign ALUSrc1 = settings[12];
    assign ALUSrc2 = settings[11];
    assign ALUOp = settings[10:8];
    assign MemWrite = settings[7];
    assign MemToReg = settings[6];
    assign rs_addr = settings[5:4];
    assign rt_addr = settings[3:2];
    assign rd_addr = settings[1:0];
                   
    assign opcode = instruction [15:12];
                    
    always @(*) begin
        case (instruction[15:12])
            4'b0000: begin
                settings[22:21] = 2'b01;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_000_01;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b0001: begin
                settings[22:21] = 2'b00;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_000_10;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b0010: begin
                settings[22:21] = 2'b11;
                settings[20:13] = 8'b0;
                settings[12:6] = 7'b00_000_00;
                settings[5:0] = instruction[11:6];
            end
            4'b0011: begin
                settings[22:21] = 2'b11;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_000_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b0100: begin
                settings[22:21] = 2'b11;
                settings[20:13] = 8'b0;
                settings[12:6] = 7'b10_001_00;
                settings[5:0] = instruction[11:6];
            end
            4'b0101: begin
                settings[22:21] = 2'b11;
                settings[20:13] = 8'b0;
                settings[12:6] = 7'b00_010_00;
                settings[5:0] = instruction[11:6];
            end
            4'b0110: begin
                settings[22:21] = 2'b01;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_010_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b0111: begin
                settings[22:21] = 2'b11;
                settings[20:13] = 8'b0;
                settings[12:6] = 7'b00_011_00;
                settings[5:0] = instruction[11:6];
            end
            4'b1000: begin
                settings[22:21] = 2'b01;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_011_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b1001: begin
                settings[22:21] = 2'b01;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_100_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b1010: begin
                settings[22:21] = 2'b01;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b01_101_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b1011: begin
                settings[22:21] = 2'b00;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b00_110_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b1100: begin
                settings[22:21] = 2'b00;
                settings[20:13] = instruction[7:0];
                settings[12:6] = 7'b00_111_00;
                settings[5:0] = {instruction[11:8], 2'b00};
            end
            4'b1101: begin
                settings[22:21] = 2'b01;
                settings[20:13] = 8'b0;
                settings[12:6] = 7'b10_010_00;
                settings[5:0] = instruction[11:6];
            end
        endcase
    end
    
endmodule
