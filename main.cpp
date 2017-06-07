#include <iostream>
#include "head.h"

int functionReturnInRunTime(int arg) {
	return arg;
}

//initialize a global const
extern const int variable_c = 1;

int main() {

//	Const variables always need initialize.
//	const int variable_a; // wrong
	const int variable_a = 1; // right
//	It's legal to init one by runtime function.
	const int variable_b = functionReturnInRunTime(1);

//	read only const var
	int var = 1;
	const int &variable_d = var;
	var = 2;

//	low-level const
	const int *low_level_const = &var;
//	std::cout <<  (*low_level_const)++ << std::endl; // wrong

	int *const high_level_const = &var;
	std::cout << ++(*high_level_const) << std::endl;
//	high_level_const = &variable_b; // wrong


	//	global const var
	int ret = functionTestGlobalVariable();
	//std::cout << variable_c << std::endl;
	return 0;
}