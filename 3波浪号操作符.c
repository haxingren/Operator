﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//1
int main()
{
	//~ 是按二进制位取反
	//将补码里的0变为1，1变为0
	int a = 0;
	printf("%d\n", ~a);
	//00000000000000000000000000000000 - 原码
	//~a后
	//11111111111111111111111111111111 - 新的补码
	//11111111111111111111111111111110 - 反码
	//10000000000000000000000000000001 - 新的原码（得-1）

	int b = 5;
	printf("%d\n", ~b);
	//00000000000000000000000000000101 - 原码
	//11111111111111111111111111111010 - 新的补码
	//11111111111111111111111111111001 - 反码
	//10000000000000000000000000000110 - 新的原码（得-6）


	//用于例子
	int c = 15;
	//00000000000000000000000000001101 - 原码
	//如果想要在这个原码中的某一位插上一个1，就可以通过在该位按位或|一个1
	//00000000000000000000000000001111
	//00000000000000000000000000010000
	//怎么得到00000000000000000000000000000010呢，通过左移00000000000000000000000000000001多少位来得到
	c |= (1 << 4);
	printf("%d\n", c);
	//00000000000000000000000000011111 - 按位与后的结果（31）

	//那么如果要再换回来呢
	//那就在该位按位与&0来获得
	//00000000000000000000000000011111 - 原码
	//11111111111111111111111111101111
	//怎么得到这个二进制呢，使用（1 << 4）00000000000000000000000000010000的反位就可以了，即~(1 << 4)
	c &= ~(1 << 4);
	printf("%d\n", c);

	return 0;
}