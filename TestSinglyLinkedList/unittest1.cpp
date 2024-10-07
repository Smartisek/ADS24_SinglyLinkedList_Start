#include "CppUnitTest.h"
#include "../SinglyLinkedList/SListNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSinglyLinkedList
{		
	TEST_CLASS(TestSListNode)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			SListNode<int> node(4);
			Assert::AreEqual(4, node.getData());
			Assert::IsNull(node.getNext());
		}

		TEST_METHOD(TestInsertAfterEnd)
		{
			SListNode<int> node(4);
			node.insertAfter(5);
			Assert::IsNotNull(node.getNext());
			SListNode<int> *next = node.getNext();
			Assert::AreEqual(5, next->getData());
			Assert::IsNull(next->getNext());
		}
		TEST_METHOD(TestInsertAfterMiddle)
		{
			SListNode<int> node(4);
			node.insertAfter(6);
			Assert::IsNotNull(node.getNext());
			SListNode<int> *next = node.getNext();
			Assert::AreEqual(6, next->getData());
			Assert::IsNull(next->getNext());

			node.insertAfter(5);
			next = node.getNext();
			Assert::AreEqual(5, next->getData());
			Assert::IsNotNull(next->getNext());
			Assert::AreEqual(6, next->getNext()->getData());
		}
	};
}