/**
*	@Autor	: Andy Schleising
*	@Date	: 08.03.2023
*
*	@Description
*	Test Main for testing the DoublyLinkedList functions.
*/
#include "Test_DoublyLinkedList.h"

int main()
{
	ListTest::Test_PushBack();
	ListTest::Test_PushFront();
	ListTest::Test_PopBack();
	ListTest::Test_PopFront();
	ListTest::Test_RemoveAt();
	ListTest::Test_InsertAtIndex();

	return 0;
}