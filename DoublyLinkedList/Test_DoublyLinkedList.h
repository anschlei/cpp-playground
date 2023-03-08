/**
*	@Autor	: Andy Schleising
*	@Date	: 08.03.2023
*
*	@Description
*	A small an simple testing header, which test all function from the list.
*/

#pragma once
#include <assert.h>

#include "DoublyLinkedList.h"

//----------------------------------------------------------------------------------
//				*TestClasses*
//----------------------------------------------------------------------------------

namespace
{
	class CTestClass
	{
	public:
		CTestClass()  	= default;
		~CTestClass() 	= default;
		int m_Value 	= 0;
	};
}

//----------------------------------------------------------------------------------
//			*List::CDoublyLinkedList TestCases*
//----------------------------------------------------------------------------------
namespace ListTest
{
	void Test_PushBack()
	{
		List::CDoublyLinkedList<CTestClass> TestInstance;

		CTestClass TestClass1;
		CTestClass TestClass2;
		CTestClass TestClass3;
		CTestClass TestClass4;
		CTestClass TestClass5;

		TestClass1.m_Value = 10;
		TestClass2.m_Value = 15;
		TestClass3.m_Value = 20;
		TestClass4.m_Value = 25;
		TestClass5.m_Value = 30;

		TestInstance.PushBack(&TestClass1);

		assert(TestInstance.At(0) == &TestClass1);

		TestInstance.PushBack(&TestClass2);

		assert(TestInstance.At(1) == &TestClass2);

		TestInstance.PushBack(&TestClass3);
		
		assert(TestInstance.At(2) == &TestClass3);

		TestInstance.PushBack(&TestClass4);
		
		assert(TestInstance.At(3) == &TestClass4);

		TestInstance.PushBack(&TestClass5);

		assert(TestInstance.At(4) == &TestClass5);

		assert(TestInstance.Size() == 5);
	}

	void Test_PushFront()
	{
		List::CDoublyLinkedList<CTestClass> TestInstance;

		CTestClass TestClass1;
		CTestClass TestClass2;
		CTestClass TestClass3;
		CTestClass TestClass4;
		CTestClass TestClass5;

		TestClass1.m_Value = 10;
		TestClass2.m_Value = 15;
		TestClass3.m_Value = 20;
		TestClass4.m_Value = 25;
		TestClass5.m_Value = 30;

		TestInstance.PushFront(&TestClass1);
		assert(TestInstance.At(0) == &TestClass1);

		TestInstance.PushFront(&TestClass2);
		assert(TestInstance.At(0) == &TestClass2);
		assert(TestInstance.At(1) == &TestClass1);

		TestInstance.PushFront(&TestClass3);
		assert(TestInstance.At(0) == &TestClass3);
		assert(TestInstance.At(1) == &TestClass2);
		assert(TestInstance.At(2) == &TestClass1);

		TestInstance.PushFront(&TestClass4);
		assert(TestInstance.At(0) == &TestClass4);
		assert(TestInstance.At(1) == &TestClass3);
		assert(TestInstance.At(2) == &TestClass2);
		assert(TestInstance.At(3) == &TestClass1);

		TestInstance.PushFront(&TestClass5);
		assert(TestInstance.At(0) == &TestClass5);
		assert(TestInstance.At(1) == &TestClass4);
		assert(TestInstance.At(2) == &TestClass3);
		assert(TestInstance.At(3) == &TestClass2);
		assert(TestInstance.At(4) == &TestClass1);

		assert(TestInstance.Size() == 5);
	}

	void Test_PopBack()
	{
		List::CDoublyLinkedList<CTestClass> TestInstance;

		CTestClass TestClass1;
		CTestClass TestClass2;
		CTestClass TestClass3;
		CTestClass TestClass4;
		CTestClass TestClass5;

		TestClass1.m_Value = 10;
		TestClass2.m_Value = 15;
		TestClass3.m_Value = 20;
		TestClass4.m_Value = 25;
		TestClass5.m_Value = 30;

		TestInstance.PushBack(&TestClass1);
		TestInstance.PushBack(&TestClass2);
		TestInstance.PushBack(&TestClass3);
		TestInstance.PushBack(&TestClass4);
		TestInstance.PushBack(&TestClass5);

		assert(TestInstance.PopBack()->m_Value == TestClass5.m_Value);
		assert(TestInstance.Size() == 4);

		assert(TestInstance.PopBack()->m_Value == TestClass4.m_Value);
		assert(TestInstance.Size() == 3);

		assert(TestInstance.PopBack()->m_Value == TestClass3.m_Value);
		assert(TestInstance.Size() == 2);

		assert(TestInstance.PopBack()->m_Value == TestClass2.m_Value);
		assert(TestInstance.Size() == 1);

		assert(TestInstance.PopBack()->m_Value == TestClass1.m_Value);
		assert(TestInstance.Size() == 0);
	}

	void Test_PopFront()
	{
		List::CDoublyLinkedList<CTestClass> TestInstance;

		CTestClass TestClass1;
		CTestClass TestClass2;
		CTestClass TestClass3;
		CTestClass TestClass4;
		CTestClass TestClass5;

		TestClass1.m_Value = 10;
		TestClass2.m_Value = 15;
		TestClass3.m_Value = 20;
		TestClass4.m_Value = 25;
		TestClass5.m_Value = 30;

		TestInstance.PushBack(&TestClass1);
		TestInstance.PushBack(&TestClass2);
		TestInstance.PushBack(&TestClass3);
		TestInstance.PushBack(&TestClass4);
		TestInstance.PushBack(&TestClass5);

		assert(TestInstance.Size() == 5);
		assert(TestInstance.PopFront()->m_Value == TestClass1.m_Value);
		assert(TestInstance.Size() == 4);

		assert(TestInstance.PopFront()->m_Value == TestClass2.m_Value);
		assert(TestInstance.Size() == 3);

		assert(TestInstance.PopFront()->m_Value == TestClass3.m_Value);
		assert(TestInstance.Size() == 2);

		assert(TestInstance.PopFront()->m_Value == TestClass4.m_Value);
		assert(TestInstance.Size() == 1);

		assert(TestInstance.PopFront()->m_Value == TestClass5.m_Value);
		assert(TestInstance.Size() == 0);
	}

	void Test_RemoveAt()
	{
		List::CDoublyLinkedList<CTestClass> TestInstance;

		CTestClass TestClass1;
		CTestClass TestClass2;
		CTestClass TestClass3;
		CTestClass TestClass4;
		CTestClass TestClass5;

		TestClass1.m_Value = 10;
		TestClass2.m_Value = 15;
		TestClass3.m_Value = 20;
		TestClass4.m_Value = 25;
		TestClass5.m_Value = 30;

		TestInstance.PushBack(&TestClass1);
		TestInstance.PushBack(&TestClass2);
		TestInstance.PushBack(&TestClass3);
		TestInstance.PushBack(&TestClass4);
		TestInstance.PushBack(&TestClass5);

		assert(TestInstance.RemoveAt(4));
		assert(TestInstance.Size() == 4);

		assert(TestInstance.RemoveAt(3));
		assert(TestInstance.Size() == 3);

		assert(TestInstance.RemoveAt(2));
		assert(TestInstance.Size() == 2);

		assert(TestInstance.RemoveAt(1));
		assert(TestInstance.Size() == 1);

		assert(TestInstance.RemoveAt(0));
		assert(TestInstance.Size() == 0);
	}

	void Test_InsertAtIndex()
	{
		List::CDoublyLinkedList<CTestClass> TestInstance;

		CTestClass TestClass1;
		CTestClass TestClass2;
		CTestClass TestClass3;
		CTestClass TestClass4;
		CTestClass TestClass5;

		TestClass1.m_Value = 10;
		TestClass2.m_Value = 15;
		TestClass3.m_Value = 20;
		TestClass4.m_Value = 25;
		TestClass5.m_Value = 30;

		TestInstance.PushBack(&TestClass1);
		TestInstance.PushBack(&TestClass2);
		TestInstance.PushBack(&TestClass3);
		TestInstance.PushBack(&TestClass4);
		
		assert(TestInstance.InsertAtIndex(3, &TestClass5));
		assert(TestInstance.At(3)->m_Value == TestClass5.m_Value);
		assert(TestInstance.At(2)->m_Value == TestClass3.m_Value);
		assert(TestInstance.At(4)->m_Value == TestClass4.m_Value);

		assert(TestInstance.RemoveAt(0));
		assert(TestInstance.At(0)->m_Value != TestClass1.m_Value);
		assert(TestInstance.At(0)->m_Value == TestClass2.m_Value);

		assert(TestInstance.InsertAtIndex(3, &TestClass1));
		assert(TestInstance.At(3)->m_Value == TestClass1.m_Value);
		assert(TestInstance.At(4)->m_Value == TestClass4.m_Value);
	}

}// namespace ListTest
