//Во всех задачах необходимо использование битовых операций.
//Использование арифметических операций запрещено.
//Входное число лежит в диапазоне 0..232 - 1 и вводится в десятичном виде.
//
//1.1 Подсчитать кол - во единичных бит в входном числе, стоящих на четных позициях.Позиции битов нумеруются с 0.


#include <iostream>

int countEven(unsigned int number) {
	int compareNum = 1, result = 0;
	while (number != 0) {
		if ((number & compareNum) == 1) {
			++result;
		}
		number = number >> 2;
	}
	return result;
}

int main() {
	unsigned int numToCount = 0;
	std::cin >> numToCount;
	std::cout << countEven(numToCount) << std::endl;
	return 0;
}