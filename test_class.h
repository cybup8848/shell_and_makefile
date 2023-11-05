/*************************************************************************
    > File Name: test_class.h
    > Author:cheng yingbin
    > Mail: 703477993@qq.com 
    > Created Time: Sun Nov  5 13:52:37 2023
 ************************************************************************/
#ifndef __test_class_h__
#define __test_class_h__
class TestClass{
	public:
		TestClass();
		virtual ~ TestClass();
	public:
		int sum(int a,int b);
		int fib(int n);
		int fib2(int n);
};
#endif
