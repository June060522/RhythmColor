#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));// ���� ������
	cout << "=======================" << endl;
	cout << "|    GGM ī�� ����    |" << endl;
	cout << "=======================" << endl;
	cout << "���Ӽ���: ������ ī�带 ������ ���, ��� ���� ���� ���ӿ� �¸��ϼ���!" << endl;
	cout << "������ �����Ϸ��� �ƹ�Ű�� ��������." << endl;
	char ch = _getch();//�ƹ�Ű �Է¹����� ����

	//--------------------------------------------------------------------------------------------����

	int phase = 1;//������
	int maxLife = 2;//�ִ� ������
	int playerLife = 2;//�÷��̾� ������
	int aiLife = 2;//ai������
	int playerArr[5];//�÷��̾� �迭
	int aiArr[5];//ai�迭
	int playerAvg = 0;//��� ���
	int aiAvg = 0;
	int numArr[20];//����ī��
	int input = 0; //�׳� �Է¹޴� ����

	while (true)
	{
		for (int i = 0; i < 20; i++)//����ī�� �� �Ҵ�
			numArr[i] = i + 1;

		for (int i = 0; i < 100; i++)//���� �˰���
		{
			int idx = rand() % 20;
			int idx1 = rand() % 20;
			swap(numArr[idx], numArr[idx1]);
		}
		for (int i = 0; i < 5; i++)//�÷��̾� ī�� ���
			playerArr[i] = numArr[i];

		for (int i = 0; i < 5; i++)//ai ī�� ���
			aiArr[i] = numArr[i + 5];

		for (int round = 2; round <= 7; round++)
		{
			system("cls");
			//============================================================================���
			cout << "[[[ ���� ������: " << phase << " ]]]" << endl;
			cout << ">>> ���� ������: " << round / 2 << " <<<" << endl;
			cout << endl;
			cout << "���� PLAYER ������ : ";
			for (int i = 0; i < playerLife; i++)//��Ʈ������ŭ�� ���θ�ŭ�����
				cout << "��";
			for (int i = playerLife; i < maxLife; i++)
				cout << "��";
			cout << endl;

			cout << "====================Player==========================" << endl;
			cout << "Player�� ���� ���: ";
			playerAvg = 0;
			for (int i = 0; i < 5; i++)//��� ���
				playerAvg += playerArr[i];
			cout << playerAvg / 5 << endl;
			for (int i = 0; i < 5; i++)//���� ���
				cout << playerArr[i] << "   ";
			cout << endl << endl;

			cout << "���� AI ������ : ";
			for (int i = 0; i < aiLife; i++)//��Ʈ������ŭ�� ���θ�ŭ�����
				cout << "��";
			for (int i = aiLife; i < maxLife; i++)
				cout << "��";
			cout << endl;

			cout << "====================AI==========================" << endl;
			cout << "AI�� ���� ���: ";
			aiAvg = 0;
			for (int i = 0; i < 5; i++)//��� ���
				aiAvg += aiArr[i];
			cout << aiAvg / 5 << endl;
			for (int i = 0; i < 5; i++)//���� ���
				cout << aiArr[i] << "   ";
			cout << endl << endl;
			if (round % 2 == 0)
			{
				cout << "�̹� ���忡 ������ �� ����?" << endl;
				cout << "1. ����, 2. ��ŵ" << endl;
				cin >> input;
				if (input != 1 && input != 2)//�߸� �Էµ����� �ٽ� ������(����ó��)
				{
					round--;
					continue;
				}
				else if (input == 1)//�����϶�
				{
					cout << "������ ����: ";
					cin >> input;
					if (find(aiArr, aiArr + 5, input) == aiArr + 5)
					{
						cout << "�߸��� ���� �Է��ϼ̽��ϴ�";
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
				else if (input == 2)//��ŵ�϶�
					continue;
			}
			else
			{
				cout << "���� ������ �մϴ�." << endl;
				int input = rand() % 5;
				while (playerArr[input] != 0)
				{
					input = rand() % 5;
				}
				cout << "���� ������ ���� : " << playerArr[input];
				playerArr[input] = 0;
				Sleep(2000);
			}
		}
		phase++;
		if (playerAvg > aiAvg)
			playerLife--;
		else if (playerAvg < aiAvg)
			aiLife--;

		if (playerLife == 0 || aiLife == 0)//�����ϳ��� ������
			break;
	}

	if (playerLife == 0)//�÷��̾� �������� 0�̸�
		cout << "Player�� �й��ϼ̽��ϴ�" << endl;
	else
		cout << "Player�� �¸��ϼ̽��ϴ�" << endl;

	cout << "������ �����մϴ�" << endl;
	for (int i = 3; i >= 1; i--)//321���
	{
		cout << '\r' << i << "...";
		Sleep(1000);
	}
}