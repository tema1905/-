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
	void lad(int startx, int starty, int endx, int endy, int& newx, int& newy)
	{
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
						return; // Если нашли подходящие значения, просто выходим
					}
				}
			}


		}

		newx = -1; // Если ничего не нашли
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
			}
			for (int t = 1; t < 8; ++t) {
				newx = startx + dx[i] * t;
				newy = starty + dy[i] * t;
				{
					for (int j = 0; j < 4; ++j)
					{
						for (int r = 1; r < 8; ++r) {
							int newEx = endx + dx[j] * r;
							int newEy = endy + dy[j] * r;

							if (newEx == newx && newEy == newy && newx >= 0 && newx < 8 && newy >= 0 && newy < 8) {
								return; // Если нашли подходящие значения, просто выходим
							}
						}
					}

				}


			}
		}


		newx = -1; // Если ничего не нашли
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

	while (true)
	{
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

		cout << "Добро пожаловать в программу по расчету ходов в игре шахматы!" << "\n" <<
			"Вам необходимо корректно вводить запрашиваемые данные." << "\n" <<
			"Буква клетки от A до H английского языка. Её номер от 1 до 8" << "\n" <<
			"Название фигуры должно соответствовать предложенным вариантам. Адрес клетки вводится без пробелов!" << endl << endl;

		string kl1, kl2, tip;
		bukva pol;
		int pb1, vb1, pb2, vb2;
		cout << "Введите адрес первой фигуры: ";
		cin >> kl1;

		
		pb1 = pol.buk(kl1[0]);

		if (pb1 < 0 or pb1 > 7)
		{
			cout << "Введённая буква первой фигуры некорректна" << endl << endl;
			continue;
		}

		vb1 = int(kl1[1] - '0');

		if (vb1 < 1 or vb1 > 8)
		{
			cout << "Введённая цифра первой фигуры некорректна" << endl << endl;
			continue;
		}

		cout << "Укажите тип фигуры (ладья / конь / слон / ферзь): ";
		cin >> tip;

		if (tip != "ладья" && tip != "конь" && tip != "слон" && tip != "ферзь")
		{
			cout << "Введённая фигура некорректна" << endl << endl;
			continue;
		}

		cout << "Введите адрес второй фигуры: ";
		cin >> kl2;

		pb2 = pol.buk(kl2[0]);

		if (pb2 < 0 or pb2 > 7)
		{
			cout << "Введённая буква второй фигуры некорректна" << endl << endl;
			continue;
		}

		vb2 = int(kl2[1] - '0');

		if (vb2 < 1 or vb2 > 8)
		{
			cout << "Введённая цифра второй фигуры некорректна" << endl << endl;
			continue;
		}
		
		if (pb1 == pb2 && vb1 == vb2)
		{
			cout << "Фигуры не могут находится на одной клетке" << endl << endl;
			continue; 
		}


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

		string cv1, cv2;

		if (arr[pb1][vb1] == 1)
		{
			cv1 = "Белый";
		}
		else
		{
			cv1 = "Черный";
		}

		if (arr[pb2][vb2] == 1)
		{
			cv2 = "Белый";
		}
		else
		{
			cv2 = "Черный";
		}

		if (cv1 == cv2)
		{
			cout << endl << "Клетки одного цвета" << endl;
		}
		else
		{
			cout << endl << "Клетки разного цвета" << endl;
		}

		cout << endl << "Цвет клетки, на которой стоит первая фигура: " << cv1 << endl;
		cout << "Цвет клетки, на которой стоит вторая фигура: " << cv2 << endl << endl;

		if (tip == "ладья")
		{
			ladya hod;
			int xk;
			int yk;
			obrb bk;
			hod.lad(pb1, vb1, pb2, vb2, xk, yk);

			if (xk == -2)
			{
				cout << "Угроза уже существует!" << endl;
			}
			else
			{
				cout << "Нужно переместить ладью на клетку " << bk.buko(xk) << obrch(yk) << endl;
			}

		}

		if (tip == "конь")
		{
			Kon hod;
			int xk;
			int yk;

			obrb bk;
			hod.koni(pb1, vb1, pb2, vb2, xk, yk);

			if (xk == -2)
			{
				cout << "Угроза уже существует!" << endl;
			}
			else
			{
				if (xk == -1)
				{
					cout << "Нет возможных комбинаций для коня" << endl;
				}
				else
				{
					cout << "Нужно переместить коня на клетку " << bk.buko(xk) << obrch(yk) << endl;
				}
			}


		}

		if (tip == "слон")
		{
			Slon hod;
			int xk;
			int yk;

			obrb bk;
			hod.slo(pb1, vb1, pb2, vb2, xk, yk);


			if (xk == -2)
			{
				cout << "Угроза уже существует!" << endl;
			}
			else
			{
				if (cv1 != cv2)
				{
					cout << "Нет возможных комбинаций для слона" << endl;
				}
				else
				{
					cout << "Нужно переместить слона на клетку " << bk.buko(xk) << obrch(yk) << endl;
				}
			}
		}

		if (tip == "ферзь")
		{
			Ferz hod;
			int xk;
			int yk;

			obrb bk;
			hod.fer(pb1, vb1, pb2, vb2, xk, yk);

			if (xk == -2)
			{
				cout << "Угроза уже существует!" << endl;
			}
			else
			{
				cout << "Нужно переместить ферзя на клетку " << bk.buko(xk) << obrch(yk) << endl;
			}
		}
		break;
	}
		
}
