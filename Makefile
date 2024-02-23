main:
	@clear
	@g++ -I./include -g -std=c++20 -o out main.cpp
	@./out
	@rm out
