.PHONY: debug clean run

PROGRAM_NAME := MyProgram
SRC_DIR := source
BLD_DBG_DIR := build-debug

debug:
	mkdir ${BLD_DBG_DIR} && cd ${BLD_DBG_DIR} && cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug ../${SRC_DIR}
	cmake --build ${BLD_DBG_DIR} --config Debug

run: 
	.\build-debug\Debug\MyThing.exe

clean:
	rmdir /s /q ${BLD_DBG_DIR}