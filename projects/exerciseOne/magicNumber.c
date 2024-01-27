// 206598146
// Musa Abu Alhawa
// OS: Ubuntu 64bit (Linux)
// Date: 27-01-2024
// #################

#include <stdio.h>
#include <stdlib.h>

// This function takes the num and returns 10^(len(num)-1)
int calMyPower(int num){
	num /= 10;
	int counter = 1;
	while(num > 0){
		counter *= 10;
		num /= 10;
	}
	return counter;
}
// This function takes num and returns the reversed version,
// taking into consideration numbers less than 3 digits.
int reversedNumber(int num){
	int result = 0;
	int my_power = calMyPower(num);
	int tmp = num;
	while (tmp > 0){
		result += (tmp%10)*my_power;
		tmp /= 10;
		my_power /= 10;
	}
	// 3 digits we return nth added [111]
	if (num >= 100 && num <= 999){
		return result;
	}
	// 2 digits, return value * 10 (added [11]0)
	else if (num >= 10 && num <= 99){
		return result*10;
	}
	// 1 digit, return value * 100 (added [1]00)
	else if (num >= 0 && num <= 9){
		return result*100;
	}
	// not taking numbers that are more than 3 digits
	else{
		return 0;
	}
}

// Takes num, returns if its a magic number
int isMagicNumber(int num){
	// var init
	int result, tmp, myReturn;
	// tmp is absolute value of the difference between num and reversed(num)
	tmp = abs(num - reversedNumber(num));
	// result is tmp + reversed(tmp)
	result = tmp + reversedNumber(tmp);
	// result is 1089 if num is magic, as per definition
	// return 1 if magic, 0 otherwise.
	myReturn = result == 1089 ? 1 : 0;
	return myReturn;
}	



int main(int argc, char *argv[]) {
	// var init
	int does = 0, doesnt = 0, skipped = 0;
	// loop goes through all 3 digit numbers
	for (int i = 100; i < 1000; i++){
		// checking numbers with same start and finish digits
		if(i%10 == (i/100)%10){
			skipped += 1;
		}else{
			// tmp = 1 if [i] is magic, 0 otherwise.
			int tmp = isMagicNumber(i);
			// if num is magic, we add 1 to does else we do nth
			does = tmp == 1 ? does+1 : does;
			// if num is not magic, we add 1 to doesnt, else we do nth
			doesnt = tmp == 0 ? doesnt+1: doesnt;
		}
	}
	// printing final result.
	printf("%d\n%d\n%d\n", does, doesnt, skipped);
	return 0;
}