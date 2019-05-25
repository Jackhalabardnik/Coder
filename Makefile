.PHONY: clean All

All:
	@echo "----------Building project:[ Coder - Release ]----------"
	@cd "Coder" && "$(MAKE)" -f  "Coder.mk"
clean:
	@echo "----------Cleaning project:[ Coder - Release ]----------"
	@cd "Coder" && "$(MAKE)" -f  "Coder.mk" clean
