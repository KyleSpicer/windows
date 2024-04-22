.PHONY: debug clean

SRC_DIR := source
BLD_DBG_DIR := build-debug

SILENT := /s /q

debug:
	mkdir $(BLD_DBG_DIR) && cd $(BLD_DBG_DIR) && cmake ../$(SRC_DIR)
	cmake --build $(BLD_DBG_DIR) --target MyProgram

clean:
	rmdir /s /q $(BLD_DBG_DIR)
