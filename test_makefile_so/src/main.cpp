/*************************************************************************
    > File Name: main.cpp
    > Author:cheng yingbin
    > Mail: 703477993@qq.com 
    > Created Time: Thu Nov  2 16:28:57 2023
 ************************************************************************/
#include<iostream>
using namespace std;
#include"add.h"
#include"sub.h"
#include"mul.h"
#include"sdiv.h"
int main(int argc,char *argv[]){
	int a=10;
	int b=2;
	std::cout<<a<<"+"<<b<<"="<<add(a,b)<<std::endl;
	std::cout<<a<<"-"<<b<<"="<<sub(a,b)<<std::endl;
	std::cout<<a<<"*"<<b<<"="<<mul(a,b)<<std::endl;
	std::cout<<a<<"/"<<b<<"="<<sdiv(a,b)<<std::endl;
	return 0;
}



