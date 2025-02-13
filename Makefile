
all: 

%: src/%.c
	@gcc -o bin/$@ $<

