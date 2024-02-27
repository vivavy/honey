__main:
	@clear
	@rm -f main out
	@gcc -g -Wno-discarded-qualifiers -g -std=c99 -fdiagnostics-color=always -Iinclude main.c -o out
	@./out abc def ghi jkl mno pqr stu vwx yz
	@rm out
