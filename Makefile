.PHONY: clean All

All:
	@echo "----------Building project:[ TestCoder - Release ]----------"
	@cd "TestCoder" && "$(MAKE)" -f  "TestCoder.mk"
clean:
	@echo "----------Cleaning project:[ TestCoder - Release ]----------"
	@cd "TestCoder" && "$(MAKE)" -f  "TestCoder.mk" clean
