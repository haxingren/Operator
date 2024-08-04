#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//结构体引用操作符有两种
//1点操作符. ： 结构体对象.结构成员
//2箭头操作符-> ： 结构体指针->结构成员

struct Stu
{
	char name[20];
	int age;
	double score;
};

void set_Stu(struct Stu* ps)
{
	////用点操作符
	//strcpy((*ps).name, "xiaoming");
	//(*ps).age = 20;
	//(*ps).score = 100.0;
	//用箭头操作符
	strcpy(ps->name, "xiaoming");
	ps->age = 20;
	ps->score = 100.0;
}

void print_Stu(struct Stu ss)
{
	printf("%s %d % lf\n", ss.name, ss.age, ss.score);
}
int main()
{
	struct Stu s = { 0 };
	set_Stu(&s);//传参不能直接传值，如果传值，函数里的形参只会是一份实参的临时拷贝，在函数内对形参进行的任何修改都影响不了实参
	//所以需要使用传址，这样才能通过地址找到对象并对其修改
	print_Stu(s);//print函数不需要对实参进行修改，所以直接传值就可以了
	return 0;
}