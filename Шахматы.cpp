#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<Windows.h>

using namespace std;



int obrch(int a) {
	int viv;
	for (int i = 7; i >= 0; --i)
	{
		if (a == i)
		{
			viv = 8 - i;
			return viv;
			break;
		}
	}
};


class bukva {
public:
	int sc = 0;
	int buk(char q)
	{
		for (char letter = 'A'; letter <= 'H'; ++letter)
		{
			if (q == letter)
			{
				sc = int(q - 65);
				return sc;
			}

		}

	}
};

class obrb {
public:
	char viv;
	char letter = 'A';
	char buko(int a)
	{
		for (int i = 0; i < 8; ++i)
		{
			if (a == i)
			{
				viv = letter;
				return letter;
			}
			++letter;
		}
	}
};



class ladya {
public:
	int lad(int a, int b, int c, int d)
	{
		if (a == c or b == d)
		{
			cout << "������ ��� ����������!" << endl;
		}
		else
		{
			if (a < c)
			{
				while (a < c)
				{
					++a;
				}
			}
			else if (a > c)
			{
				while (a > c)
				{
					--a;
				}
			}
			return a;
		}
	}
};

class Kon {
public:
	void koni(int startx, int starty, int endx, int endy, int& newx, int& newy) {
		int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
		int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

		for (int i = 0; i < 8; ++i) {
			newx = startx + dx[i];
			newy = starty + dy[i];

			if (newx == endx && newy == endy)
			{
				newx = -2;
				newy = -2;
				return;
			}
			else
			{
				for (int j = 0; j < 8; ++j) {
					int newEx = endx + dx[j];
					int newEy = endy + dy[j];

					if (newEx == newx && newEy == newy && newx >= 0 && newx < 8 && newy >= 0 && newy < 8) {
						return; // ���� ����� ���������� ��������, ������ �������
					}
				}
			}


		}

		newx = -1; // ���� ������ �� �����
		newy = -1;
	}
};

class Slon {
public:
	void slo(int startx, int starty, int endx, int endy, int& newx, int& newy) {
		int dx[4] = { 1, 1, -1, -1 };
		int dy[4] = { 1, -1, 1, -1 };
		for (int i = 0; i < 4; ++i) {

			for (int t = 1; t < 8; ++t) {
				newx = startx + dx[i] * t;
				newy = starty + dy[i] * t;

				if (newx == endx && newy == endy)
				{
					newx = -2;
					newy = -2;
					return;
				}
				else
				{
					for (int j = 0; j < 4; ++j)
					{
						for (int r = 1; r < 8; ++r) {
							int newEx = endx + dx[j] * r;
							int newEy = endy + dy[j] * r;

							if (newEx == newx && newEy == newy && newx >= 0 && newx < 8 && newy >= 0 && newy < 8) {
								return; // ���� ����� ���������� ��������, ������ �������
							}
						}
					}

				}


			}
		}


		newx = -1; // ���� ������ �� �����
		newy = -1;
	}

};

class Ferz {
public:
	void fer(int startx, int starty, int endx, int endy, int& newx, int& newy)
	{
		int dx[4] = { 1, 1, -1, -1 };
		int dy[4] = { 1, -1, 1, -1 };
		for (int i = 0; i < 4; ++i)
		{
			for (int t = 1; t < 8; ++t) {
				newx = startx + dx[i] * t;
				newy = starty + dy[i] * t;

				if (newx == endx && newy == endy)
				{
					newx = -2;
					newy = -2;
					return;
				}
			}
		}


		if (startx == endx or starty == endy)
		{
			newx = -2;
			newy = -2;
			return;
		}
		else
		{
			if (startx < endx)
			{
				while (startx < endx)
				{
					++startx;
				}
			}
			else if (startx > endx)
			{
				while (startx > endx)
				{
					--startx;
				}
			}
			newx = startx;
			newy = starty;
			return;
		}

	}
};


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");


	int arr[8][8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (i % 2 != 0 and j % 2 == 0)
			{
				arr[i][j] = 1;
			}
			if (i % 2 != 0 and j % 2 != 0)
			{
				arr[i][j] = 0;
			}
			if (i % 2 == 0 and j % 2 == 0)
			{
				arr[i][j] = 0;
			}
			if (i % 2 == 0 and j % 2 != 0)
			{
				arr[i][j] = 1;
			}
			//cout << arr[i][j]<<"\t";
		}
		//cout << endl << endl;
	}

	cout << "����� ���������� � ��������� �� ������� ����� � ���� �������!" << "\n" <<
		"��� ���������� ��������� ������� ������������� ������." << "\n" <<
		"����� ������ �� A �� H ����������� �����.Ÿ ����� �� 1 �� 8" << "\n" <<
		"�������� ������ ������ ��������������� ������������ ���������. ����� ������ �������� ��� ��������!" << endl << endl;

	string kl1, kl2, tip;
	int pb1, vb1, pb2, vb2;
	cout << "������� ����� ������ ������: ";
	cin >> kl1;

	cout << "������� ��� ������ (����� / ���� / ���� / �����): ";
	cin >> tip;

	cout << "������� ����� ������ ������: ";
	cin >> kl2;


	vb1 = int(kl1[1] - '0');
	vb2 = int(kl2[1] - '0');


	for (int i = 1; i < 9; ++i)
	{
		if (vb1 == i) {
			vb1 = 8 - i;
			break;
		}

	}

	for (int i = 1; i < 9; ++i)
	{
		if (vb2 == i) {
			vb2 = 8 - i;
			break;
		}
	}


	bukva pol;
	pb1 = pol.buk(kl1[0]);
	pb2 = pol.buk(kl2[0]);


	string cv1, cv2;

	if (arr[pb1][vb1] == 1)
	{
		cv1 = "�����";
	}
	else
	{
		cv1 = "������";
	}

	if (arr[pb2][vb2] == 1)
	{
		cv2 = "�����";
	}
	else
	{
		cv2 = "������";
	}

	if (cv1 == cv2)
	{
		cout << endl << "������ ������ �����" << endl;
	}
	else
	{
		cout << endl << "������ ������� �����" << endl;
	}

	cout << endl << "���� ������, �� ������� ����� ������ ������: " << cv1 << endl;
	cout << "���� ������, �� ������� ����� ������ ������: " << cv2 << endl << endl;

	if (tip == "�����")
	{
		ladya hod;

		obrb bk;
		cout << "����� ����������� ����� �� ������ " << bk.buko(hod.lad(pb1, vb1, pb2, vb2)) << obrch(vb1) << endl;
	}

	if (tip == "����")
	{
		Kon hod;
		int xk;
		int yk;

		obrb bk;
		hod.koni(pb1, vb1, pb2, vb2, xk, yk);

		if (xk == -2)
		{
			cout << "������ ��� ����������!" << endl;
		}
		else
		{
			if (xk == -1)
			{
				cout << "��� ��������� ���������� ��� ����" << endl;
			}
			else
			{
				cout << "����� ����������� ���� �� ������ " << bk.buko(xk) << obrch(yk) << endl;
			}
		}


	}

	if (tip == "����")
	{
		Slon hod;
		int xk;
		int yk;

		obrb bk;
		hod.slo(pb1, vb1, pb2, vb2, xk, yk);


		if (xk == -2)
		{
			cout << "������ ��� ����������!" << endl;
		}
		else
		{
			if (cv1 != cv2)
			{
				cout << "��� ��������� ���������� ��� �����" << endl;
			}
			else
			{
				cout << "����� ����������� ����� �� ������ " << bk.buko(xk) << obrch(yk) << endl;
			}
		}



	}

	if (tip == "�����")
	{
		Ferz hod;
		int xk;
		int yk;

		obrb bk;
		hod.fer(pb1, vb1, pb2, vb2, xk, yk);

		if (xk == -2)
		{
			cout << "������ ��� ����������!" << endl;
		}
		else
		{
			cout << "����� ����������� ����� �� ������ " << bk.buko(xk) << obrch(yk) << endl;
		}
	}

}