/*************************************************************************
    > File Name: main.cpp
    > Author:cheng yingbin
    > Mail: 703477993@qq.com 
    > Created Time: Sun Nov  5 14:00:15 2023
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include"test_class.h"
int main(int argc,char **argv){
	(void)argc;
	(void)argv;
	
	printf("hello world\n");
	TestClass o;
	int a=1;
	int b=2;
	int c=o.sum(a,b);

	char buff[256];
	memset(buff,0x00,sizeof(buff));
	snprintf(buff,sizeof(buff),"sum:%d+%d=%d",a,b,c);
	printf("%s\n",buff);

	for(int i=1;i<10;i++){
		int f=i;
		int fv=o.fib(f);

		int fv2=o.fib2(f);
		
		memset(buff,0x00,sizeof(buff));
		snprintf(buff,sizeof(buff),"fib:%d=%d %d\n",f,fv,fv2);
		printf("%s\n",buff);
	}
	
}
