module counter(clk, reset, out);

input clk, reset;
output reg[3:0] out = 0;

always @(/* triger on raice front of clock */posedge clk, /* ',' is equal to 'or' */ 
			/* triger on faling front of clock */ negedge reset) begin
	if (~reset)
		out <= 0;
	else
	/* 			  + {n bit number}'{format, dicimal, hex, binar}{actual number}*/
		out <= out + 1'b1;
end

endmodule
