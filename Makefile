main:
	@clear
	@g++ -I./include -g -std=c++20 -o out main.cpp
	@./out abc def ghi jkl mno pqr stu vwx yz
	@rm out
