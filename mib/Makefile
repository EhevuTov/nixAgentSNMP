mib_compile :
	echo "I'm compiling"
	env MIBDIRS="+." MIBS="+MYCORP-PRODUCT-MYPRODUCT-MIB" mib2c -c mib2c.mfd.conf linkTable
	env MIBDIRS="+." MIBS="+MYCORP-PRODUCT-MYPRODUCT-MIB" mib2c -c mfd-makefile.m2m linkTable
	env MIBDIRS="+." MIBS="+MYCORP-PRODUCT-MYPRODUCT-MIB" mib2c -c subagent.m2c linkTable

clean:
	rm -rf *.c *.h *.o *.txt defaults linkTable_Makefile
