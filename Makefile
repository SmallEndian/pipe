

all: hello pipe

%:%.c
	gcc -o $@ $<

.PHONY: all

