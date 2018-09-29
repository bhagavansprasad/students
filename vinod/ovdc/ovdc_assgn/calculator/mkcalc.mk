calc:calc.o add_nums.o sub_nums.o mul_nums.o div_nums.o
	gcc calc.o add_nums.o sub_nums.o mul_nums.o div_nums.o -o calc
add_nums.o:add_nums.c
	gcc -c add_nums.c
sub_nums.o:sub_nums.c
	gcc -c sub_nums.c
mul_nums.o:mul_nums.c
	gcc -c mul_nums.c
div_nums.o:div_nums.c
	gcc -c div_nums.c
