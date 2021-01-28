// Include
#include <verilated.h>

// Include verilated top.v
#include "obj_dir/Vtop.h"

// current simulation time (uint64)
vluint64_t main_time = 0;

// called by $time in Verilog
double sc_time_stamp() { 
	return main_time; 
}

int main (int argc, char **argv, char **env) {

	// avoid unused warnings
	if (false && argc && argv && env) {}

	// set debug level, highest is 9, lowest is 0
	// can be overriden using commandArgs
	Verilated::debug(0);

	// Verilator must compute traced signals
	Verilated::traceEverOn(true);

	// Pass args so verilated code can see them
	// Must be called before create model
	Verilated::commandArgs(argc, argv);

	// create logs directory in case we have traces to put under it
	Verilated::mkdir("logs");

	Vtop* top = new Vtop;

	while (!Verilated::gotFinish()) {
		main_time++;
		
		top->clk = !top->clk;

		top->eval();

	} // end while

	top->final();

	delete top;

#if VM_COVERAGE
	Verilated::mkdir("logs");
	VerilatedCov::write("logs/coverage.dat");
#endif

	return 0;
} // end main
