//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//class Functor
//{
//public:
//	void operator()(int val)
//	{
//		cout << "ÇÔ¼ö °´Ã¼" << endl;
//		m_val += val;
//		cout << m_val << endl;
//	}
//public:
//	int m_val = 0;
//};
//
////typedef Test t;
////class Test {
////
////};
//
//typedef int (FUNC_TYPE)(int, int);
////using FUNC_TYPE = int(int, int);
//
//class Item 
//{
//public:
//	Item()
//		: m_itemid(0)
//		, m_rarity(0)
//		, m_userid(0)
//	{     }
//	void Upgrade(int _val)
//	{
//		m_rarity += 1;
//	}
//public:
//	int m_itemid;
//	int m_rarity;
//	int m_userid;
//};
//
//bool IsRareitem(Item* _item)
//{
//	return _item->m_rarity >= 2;
//}
//
//bool IsUseritem(Item* _item, int _userid)
//{
//	return _item->m_userid == _userid;
//}
//
//typedef bool (SELECTOR)(Item*, int);
//
//Item* Finditem(Item _item[], int _itemcnt, SELECTOR* _select)
//{
//	for (int i = 0; i < _itemcnt; i++)
//	{
//		Item* item = &_item[i];
//		if(_select(item,5))
//			return item;
//	}
//	return nullptr;
//}
//
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//void Test2()
//{
//
//}
//
//int main()
//{
//	Test2();
//	Functor func;
//	func(10);
//
////	int a = 10;
////	//t;
////	int* ptr = &a;
////	*ptr = 5;
//	//cout << Add(1, 2) << endl;
//	//cout << Add << endl;
//	/*Item items[5] = {};
//	items[1].m_rarity = 3;
//	items[2].m_userid = 5;
//	Item*find =  Finditem(items, 5, IsUseritem);
//	cout << find->m_userid << endl;*/
//	/*int a;
//	float b;
//	FUNC_TYPE* t;
//	t = Add;
//	int result = t(1, 2);
//	int result2 = (*t)(1, 2);
//	cout << result << endl;
//	cout << result2 << endl;
//	int test = 0;*/
//
//
//}