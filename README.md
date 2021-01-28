# SimpleProcessor

In SimpleProcessor/:
Verilator -Wall --cc top.v --exe --build sim_main.cpp

In obj_dir/:
make -f Vtop.mk
./Vtop
