rm -r obj_dir
sudo rm lfsr.vcd

verilator -Wall --cc --trace lfsr.sv --exe lfsr_tb.cpp

make -j -C obj_dir/ -f Vlfsr.mk Vlfsr

# require super user privledges to access port?
sudo obj_dir/Vlfsr