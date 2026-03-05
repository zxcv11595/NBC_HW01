#include<iostream>

using namespace std;

// HP, MP 포션의 개수 count만큼 충전
void SetPotion(int count, int* hpPotion, int* mpPotion)
{
	*hpPotion = count;
	*mpPotion = count;
}

// HP, MP 포션 1개씩 충전
void RefillPosion(int& hpPotion, int& mpPostion)
{
	++hpPotion;
	++mpPostion;
}

int main()
{
	// status[0] = HP, status[1] = MP, status[2] = 공격력, status[3] = 방어력
	int status[4] = { 0, 0, 0, 0 };
	int hp = 0, mp = 0;
	int attack = 0, defence = 0;

	while (true)
	{
		cout << "HP와 MP를 입력해주세요: ";
		cin >> hp >> mp;
		if (hp > 50 and mp > 50)
		{
			status[0] = hp;
			status[1] = mp;

			break;
		}
		else
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		}
	}

	while (true)
	{
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> attack >> defence;
		if (attack >= 0 and defence >= 0)
		{
			status[2] = attack;
			status[3] = defence;

			break;
		}
		else
		{
			cout << "공격력이나 방여력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		}
	}

	int level = 0;
	int hpPosionCount = 0;
	int mpPosionCount = 0;

	SetPotion(5, &hpPosionCount, &mpPosionCount);
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;

	cout << "=============================================" << endl;
	cout << "<스탯 관리 시스템>" << endl;
	cout << "1. HP UP" << endl;
	cout << "2. MP UP" << endl;
	cout << "3. 공격력 UP" << endl;
	cout << "4. 방어력 UP" << endl;
	cout << "5. 현재 능력치" << endl;
	cout << "6. Level UP" << endl;
	cout << "0. 나가기" << endl;

	while (true)
	{
		int input = 0;
		cout << "번호를 선택해주세요: ";
		cin >> input;
		if (input == 1)
		{
			if (hpPosionCount > 0)
			{
				status[0] += 20;
				--hpPosionCount;
				cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 HP: " << status[0] << endl;
				cout << "남은 포션 수: " << hpPosionCount << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (input == 2)
		{
			if (mpPosionCount > 0)
			{
				status[1] += 20;
				--mpPosionCount;
				cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 MP: " << status[1] << endl;
				cout << "남은 포션 수: " << mpPosionCount << endl;
			}
			else
			{
				cout << "포션이 부족합니다." << endl;
			}
		}
		else if (input == 3)
		{
			status[2] *= 2;
			cout << "* 공격력이 2배로 증가되었습니다." << endl;
			cout << "현재 공격력: " << status[2] << endl;
		}
		else if (input == 4)
		{
			status[3] *= 2;
			cout << "* 방어력이 2배로 증가되었습니다." << endl;
			cout << "현재 방어력: " << status[3] << endl;
		}
		else if (input == 5)
		{
			cout << "*HP : " << status[0] << ", MP : " << status[1]
				<< ", 공격력 : " << status[2] << ", 방어력 : " << status[3] << endl;
			cout << "현재 레벨 : " << level
				<< ", 남은 HP/MP 포션 수 : " << hpPosionCount << "/" << mpPosionCount << endl;
		}
		else if (input == 6)
		{
			++level;
			RefillPosion(hpPosionCount, mpPosionCount);
			cout << "*레벨업! HP/MP 포션이 지급됩니다. " << endl;
			cout << "현재 레벨 : " << level << endl;
			cout << "남은 HP/MP 포션 수 : " << hpPosionCount << "/" << mpPosionCount << endl;
		}
		else if (input == 0)
		{
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		else
		{
			cout << "다시 입력해주세요." << endl;
		}

		cout << endl;
	}
}