__main:
	@clear
	@rm -f main out
	@g++ -g -fconcepts -Iinclude main.cpp -o out
	@./out abc def ghi jkl mno pqr stu vwx yz
	@rm out
