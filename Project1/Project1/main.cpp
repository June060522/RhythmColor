#include <iostream>
#include "Core.h"

using namespace std;

int main()
{
	if (!Core::GetInst()->Init())
	{
		std::cout << "게임 초기화 실패;;;";
		Core::DestroyInst();
		return 0;
	}
	Core::GetInst()->Run();

	Core::DestroyInst();
}