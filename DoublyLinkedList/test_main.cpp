#include <iostream>
#include <assert.h>

#include "DoublyLinkedList.h"

class CTestClass
{
public:
	CTestClass() = default;
   ~CTestClass() = default;

   int m_Value = 0;
};


void test_PopBack()
{
	List::CDoublyLinkedList<CTestClass> TestInstance;

	CTestClass TestClass1;
	CTestClass TestClass2;
	CTestClass TestClass3;
	CTestClass TestClass4;
	CTestClass TestClass5;

	TestClass1.m_Value = 10;
	TestClass2.m_Value = 15;
	TestClass3.m_Value = 20; //<-- 2
	TestClass4.m_Value = 25; 
	TestClass5.m_Value = 30;

	TestInstance.PushBack(&TestClass1);
	TestInstance.PushBack(&TestClass2);
	TestInstance.PushBack(&TestClass3);
	TestInstance.PushBack(&TestClass4);
	TestInstance.InsertAtIndex(0,&TestClass5);

	CTestClass* a = TestInstance.PopFront();
	std::cout << a->m_Value << std::endl;
}

int main()
{
	test_PopBack();

	return 0;
}