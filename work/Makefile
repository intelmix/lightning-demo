CC=gcc
LD=gcc

CFLAGS=-I$(INC_DIR)
LDFLAGS=-lm -ldl -lz

INC_DIR=inc
LIB_DIR=lib
OBJ_DIR=obj
SRC_DIR=src
APP_DIR=app

#this will include dependencies such as header files
DEPS := $(shell find $(INC_DIR) -name '*.h')

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#find all .c files and create .o file pattern accordingly
_OBJ := $(shell find $(SRC_DIR) -name '*.c')
_OBJ := $(subst .c,.o, $(_OBJ))
OBJ := $(subst src, obj, $(_OBJ))

#generation of output application is dependent on .o files
work: $(OBJ)
	$(CC) -o $(APP_DIR)/$@ $^ ./lib/lightning.o ./lib/jit_size.o ./lib/jit_print.o ./lib/jit_note.o ./lib/jit_names.o ./lib/jit_disasm.o ./lib/jit_memory.o $(LDFLAGS) 
	@echo ""
	@echo ""
	@./app/work

.PHONY: clean


clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(OUT_DIR)/work
