#include <iostream>
#include "Core.h"

using namespace std;

int main()
{
	if (!Core::GetInst()->Init())
	{
		std::cout << "���� �ʱ�ȭ ����;;;";
		Core::DestroyInst();
		return 0;
	}
	Core::GetInst()->Run();

	Core::DestroyInst();
}