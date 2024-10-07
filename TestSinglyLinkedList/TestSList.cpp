#include "CppUnitTest.h"
#include "../SinglyLinkedList/SListNode.h"
#include "../SinglyLinkedList/SList.h"
#include "../SinglyLinkedList/SListIterator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<SListNode<int>>(const SListNode<int> &b)
			{
				return L"SListNode";
			};
		}
	}
}
namespace TestSinglyLinkedList
{
	TEST_CLASS(TestSList)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			SList<int> list;
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);

		}
		TEST_METHOD(TestAppendEmpty)
		{
			SList<int> list;
			list.append(4);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreSame(*list.head, *list.tail);
		}
		TEST_METHOD(TestAppendOneEntry)
		{
			SList<int> list;
			list.append(4);
			list.append(5);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(5, list.tail->getData());
			Assert::AreNotSame(*list.head, *list.tail);
		}
		TEST_METHOD(TestAppendMultipleEntry)
		{
			SList<int> list;
			list.append(4);
			list.append(5);
			list.append(6);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(5, list.head->getNext()->getData());
			Assert::AreEqual(6, list.tail->getData());
			Assert::AreNotSame(*list.head, *list.tail);
		}
		TEST_METHOD(TestPrependEmpty)
		{
			SList<int> list;
			list.prepend(4);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreSame(*list.head, *list.tail);
		}
		TEST_METHOD(TestPrependOneEntry)
		{
			SList<int> list;
			list.prepend(4);
			list.prepend(5);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(5, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreNotSame(*list.head, *list.tail);
		}
		TEST_METHOD(TestPrependMultipleEntry)
		{
			SList<int> list;
			list.prepend(4);
			list.prepend(5);
			list.prepend(6);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(6, list.head->getData());
			Assert::AreEqual(5, list.head->getNext()->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreNotSame(*list.head, *list.tail);
		}
		TEST_METHOD(TestRemoveHead1Item)
		{
			SList<int> list;
			list.prepend(4);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreSame(*list.head, *list.tail);
			list.removeHead();
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);

		}
		TEST_METHOD(TestRemoveHeadMultipleItem)
		{
			SList<int> list;
			list.prepend(4);
			list.prepend(3);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(3, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreNotSame(*list.head, *list.tail);
			list.removeHead();
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreSame(*list.head, *list.tail);

		}
		TEST_METHOD(TestRemoveTail1Item)
		{
			SList<int> list;
			list.prepend(4);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(4, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreSame(*list.head, *list.tail);
			list.removeTail();
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);

		}
		TEST_METHOD(TestRemoveTailMultipleItem)
		{
			SList<int> list;
			list.prepend(4);
			list.prepend(3);
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(3, list.head->getData());
			Assert::AreEqual(4, list.tail->getData());
			Assert::AreNotSame(*list.head, *list.tail);
			list.removeTail();
			Assert::IsNotNull(list.head);
			Assert::IsNotNull(list.tail);
			Assert::AreEqual(3, list.head->getData());
			Assert::AreEqual(3, list.tail->getData());
			Assert::AreSame(*list.head, *list.tail);

		}

		TEST_METHOD(TestInsertEmpty)
		{
			SList<int> list;
			SListIterator<int> iter = list.getIterator();
			list.insert(iter, 1);
			Assert::AreEqual(1, list.head->getData());
			Assert::AreSame(*list.head, *list.tail);


		}
		TEST_METHOD(TestInsertAtEnd)
		{
			SList<int> list;
			list.append(1);
			SListIterator<int> iter = list.getIterator();

			list.insert(iter, 2);
			Assert::AreEqual(1, list.head->getData());
			Assert::AreNotSame(*list.head, *list.tail);
			Assert::AreEqual(2, list.tail->getData());


		}
		TEST_METHOD(TestInsertMiddle)
		{
			SList<int> list;
			list.append(1);
			list.append(3);
			SListIterator<int> iter = list.getIterator();
			
			list.insert(iter, 2);
			Assert::AreEqual(1, list.head->getData());
			Assert::AreEqual(2, list.head->getNext()->getData());
			Assert::AreEqual(3, list.tail->getData());


		}
		TEST_METHOD(TestRemoveOneItem)
		{
			SList<int> list;
			list.append(1);
			SListIterator<int> iter = list.getIterator();
			list.remove(iter);
			Assert::IsNull(list.head);
			Assert::IsNull(list.tail);


		}
		TEST_METHOD(TestRemoveAtEnd)
		{
			SList<int> list;
			list.append(1);
			list.append(2);
			SListIterator<int> iter = list.getIterator();
			iter.advance();
			list.remove(iter);
			Assert::AreEqual(1, list.head->getData());
			Assert::AreSame(*list.head, *list.tail);
			
		}
		TEST_METHOD(TestRemoveMiddle)
		{
			SList<int> list;
			list.append(1);
			list.append(2);
			list.append(3);
			SListIterator<int> iter = list.getIterator();
			iter.advance();
			list.remove(iter);
			Assert::AreEqual(1, list.head->getData());
			Assert::AreEqual(3, list.tail->getData());
			Assert::AreSame(*list.tail, *list.head->getNext());


		}
		TEST_METHOD(TestRemoveHeadWithIterator)
		{
			SList<int> list;
			list.append(1);
			list.append(2);
			list.append(3);
			SListIterator<int> iter = list.getIterator();
			list.remove(iter);
			Assert::AreEqual(2, list.head->getData());
		}
	};
}