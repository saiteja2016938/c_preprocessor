a.out: main.o read_file.o comment_removal.o print_heap.o save_file.o header_inclusion.o macro_replacment.o
	gcc main.o read_file.o comment_removal.o print_heap.o save_file.o header_inclusion.o macro_replacment.o

main.o: main.c
	gcc -c main.c

read_file.o: read_file.c
	gcc -c read_file.c

comment_removal.o: comment_removal.c
	gcc -c comment_removal.c

print_heap.0: print_heap.c
	gcc -c print_heap.c

save_file.o: save_file.c
	gcc -c save_file.c

header_inclusion.o: header_inclusion.c
	gcc -c header_inclusion.c

macro_replacment.o: macro_replacment.c
	gcc -c macro_replacment.c





