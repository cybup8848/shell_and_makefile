/*************************************************************************
    > File Name: test_class.cpp
    > Author:cheng yingbin
    > Mail: 703477993@qq.com 
    > Created Time: Sun Nov  5 13:54:24 2023
 ************************************************************************/
#include<stdio.h>
#include"test_class.h"
TestClass::TestClass(){

}

TestClass::~TestClass(){

}

int TestClass::sum(int a,int b){
	int c=a+b;
	return c;
}

int TestClass::fib(int n){
	if(n<=0)
		return 0;
	if(n==1){
		return 1;
	}
	int a1=fib(n-1);
	int a2=fib(n-2);
	int c=a1+a2;
	return c;
}

int TestClass::fib2(int n){
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	int tmp[]={0,1,1};
	for(int i=2;i<n;i++){
		tmp[0]=tmp[1];
		tmp[1]=tmp[2];
		tmp[2]=tmp[0]+tmp[1];
	}
	return tmp[2];
}
