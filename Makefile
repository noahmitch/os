tmp=$(wildcard arch/x86/*)


make:
	@tools/copy $(tmp)
	@make -f phase2.mk
	

clean:
	@rm -rf .hashes
	@rm -fv $(subst arch/x86/,,$(tmp))
	@make -f phase2.mk clean
	@rm -f boot.iso

