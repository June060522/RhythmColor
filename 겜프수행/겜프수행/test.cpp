#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));// 랜덤 돌리기
	cout << "=======================" << endl;
	cout << "|    GGM 카드 게임    |" << endl;
	cout << "=======================" << endl;
	cout << "게임설명: 상대방의 카드를 총으로 쏘고, 평균 값을 낮춰 게임에 승리하세요!" << endl;
	cout << "게임을 시작하려면 아무키나 누르세요." << endl;
	char ch = _getch();//아무키 입력받으면 시작

	//--------------------------------------------------------------------------------------------셋팅

	int phase = 1;//페이즈
	int maxLife = 2;//최대 라이프
	int playerLife = 2;//플레이어 라이프
	int aiLife = 2;//ai라이프
	int playerArr[5];//플레이어 배열
	int aiArr[5];//ai배열
	int playerAvg = 0;//평균 계산
	int aiAvg = 0;
	int numArr[20];//숫자카드
	int input = 0; //그냥 입력받는 변수

	while (true)
	{
		for (int i = 0; i < 20; i++)//숫자카드 값 할당
			numArr[i] = i + 1;

		for (int i = 0; i < 100; i++)//셔플 알고리즘
		{
			int idx = rand() % 20;
			int idx1 = rand() % 20;
			swap(numArr[idx], numArr[idx1]);
		}
		for (int i = 0; i < 5; i++)//플레이어 카드 배분
			playerArr[i] = numArr[i];

		for (int i = 0; i < 5; i++)//ai 카드 배분
			aiArr[i] = numArr[i + 5];

		for (int round = 2; round <= 7; round++)
		{
			system("cls");
			//============================================================================출력
			cout << "[[[ 현재 페이즈: " << phase << " ]]]" << endl;
			cout << ">>> 현재 페이즈: " << round / 2 << " <<<" << endl;
			cout << endl;
			cout << "현재 PLAYER 라이프 : ";
			for (int i = 0; i < playerLife; i++)//하트갯수만큼♥ 까인만큼♡출력
				cout << "♥";
			for (int i = playerLife; i < maxLife; i++)
				cout << "♡";
			cout << endl;

			cout << "====================Player==========================" << endl;
			cout << "Player의 현재 평균: ";
			playerAvg = 0;
			for (int i = 0; i < 5; i++)//평균 계산
				playerAvg += playerArr[i];
			cout << playerAvg / 5 << endl;
			for (int i = 0; i < 5; i++)//숫자 출력
				cout << playerArr[i] << "   ";
			cout << endl << endl;

			cout << "현재 AI 라이프 : ";
			for (int i = 0; i < aiLife; i++)//하트갯수만큼♥ 까인만큼♡출력
				cout << "♥";
			for (int i = aiLife; i < maxLife; i++)
				cout << "♡";
			cout << endl;

			cout << "====================AI==========================" << endl;
			cout << "AI의 현재 평균: ";
			aiAvg = 0;
			for (int i = 0; i < 5; i++)//평균 계산
				aiAvg += aiArr[i];
			cout << aiAvg / 5 << endl;
			for (int i = 0; i < 5; i++)//숫자 출력
				cout << aiArr[i] << "   ";
			cout << endl << endl;
			if (round % 2 == 0)
			{
				cout << "이번 라운드에 무엇을 할 꺼요?" << endl;
				cout << "1. 공격, 2. 스킵" << endl;
				cin >> input;
				if (input != 1 && input != 2)//잘못 입력됐을때 다시 돌리기(예외처리)
				{
					round--;
					continue;
				}
				else if (input == 1)//공격일떼
				{
					cout << "공격할 숫자: ";
					cin >> input;
					if (find(aiArr, aiArr + 5, input) == aiArr + 5)
					{
						cout << "잘못된 수를 입력하셨습니다";
						Sleep(2000);
						round--;
						continue;
					}
					//else
					{
						for (int i = 0; i < 5; i++)
							if (aiArr[i] == input)
								aiArr[i] = 0;
					}
				}
				else if (input == 2)//스킵일때
					continue;
			}
			else
			{
				cout << "적이 공격을 합니다." << endl;
				int input = rand() % 5;
				while (playerArr[input] != 0)
				{
					input = rand() % 5;
				}
				cout << "적이 공격한 숫자 : " << playerArr[input];
				playerArr[input] = 0;
				Sleep(2000);
			}
		}
		phase++;
		if (playerAvg > aiAvg)
			playerLife--;
		else if (playerAvg < aiAvg)
			aiLife--;

		if (playerLife == 0 || aiLife == 0)//둘중하나가 죽으면
			break;
	}

	if (playerLife == 0)//플레이어 라이프가 0이면
		cout << "Player가 패배하셨습니다" << endl;
	else
		cout << "Player가 승리하셨습니다" << endl;

	cout << "게임을 종료합니다" << endl;
	for (int i = 3; i >= 1; i--)//321출력
	{
		cout << '\r' << i << "...";
		Sleep(1000);
	}
}