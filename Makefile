

all: hello

%:%.c
	gcc -o $@ $<

.PHONY: all

