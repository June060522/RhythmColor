#include <iostream>
#include <vector>

using namespace std;
//람다: 함수객체를 복잡하면 한 1~2분 걸리는걸 10초 짜리로 만들어주는 문법이다.
enum class ItemType
{
	None,
	Weapon,
	Armor
};


class Item
{
public:
	Item(int _itemid, int _rarity, ItemType _type)
		: m_itemid(_itemid)
		, m_rarity(_rarity)
		, m_type(_type)
	{     }
	//void Test();
public:
	int m_itemid;
	int m_rarity;
	ItemType m_type;
};
//[](Item& _item){return _item}
//typedef void (Item::*TEST_FUNC)();

int main()
{
	vector<Item> v;
	v.push_back(Item(1, 1, ItemType::None));
	/*TEST_FUNC fn;
	fn = &Item::Test;
	Item i1;
	(i1.*fn)();
	Item* i2 = new Item;
	(*(i2).*fn)();
	(i2->*fn)();*/
}

//void Item::Test()
//{
//}
