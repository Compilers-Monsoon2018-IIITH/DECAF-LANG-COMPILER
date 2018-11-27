make clean
make
./parser < fact.dcf > fact_ir
llvm-as-6.0 fact_ir -o fact
lli-6.0 fact
rm fact
rm fact_ir
make clean
