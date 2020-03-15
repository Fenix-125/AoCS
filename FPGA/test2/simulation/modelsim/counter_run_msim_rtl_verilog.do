transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+/home/fenix/pr/subj/AoCS/FPGA/test2 {/home/fenix/pr/subj/AoCS/FPGA/test2/counter.v}

