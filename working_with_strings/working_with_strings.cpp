#include <iostream>
#include <cstring>

using namespace std;

//функция strlen измеряет длину строки
//strlen1 работает через while пока не наткнется на символ '\0'
//strlen2 работает через while пока не посчитает все символы в строке
//streln3 работает через for пока не посчитает все символы в строке
//strlen 4 работает через for с указателем пока не найдет '\0'.
void strlen1(char OurStr[]) {
	int amount = 0;
	while (OurStr[amount] != '\0')
		amount++;
	cout << "Длина строки: " << amount << endl;
}
void strlen2(char OurStr[]) {
	int amount = 0;
	while (OurStr[amount])
		amount++;
	cout << "Длина строки: " << amount << endl;
}
void strlen3(char OurStr[]) {
	int amount = 0;
	for (int i = 0; OurStr[i]; i++)
		amount++;

	cout << "Длина строки: " << amount << endl;
}
void strlen4(const char* OurStr) {
	int count = 0;
	for (; *OurStr++ != '\0'; ++count);
	cout << "Длина строки: " << count;
}

//функция strcat склеивает строки
//strcat1 работает через while пока не наткнется на символ '\0'
//strcat2 работает через while пока не посчитает все символы в строке
//strcat3 работает через for пока не посчитает все символы в строке
//strcat4 пока не написана
//проблема в том, что по отдельности функции работают, но если их вызывать друг за другом подряд, то строки слипаются
void strcat1(char OurStr[], char OurStr2[]) {
	int amount1 = 0;
	int amount2 = 0;
	while (OurStr[amount1] != '\0')
		amount1++;
	while (OurStr2[amount2] != '\0') {
		OurStr[amount1] = OurStr2[amount2];
		amount1++;
		amount2++;
	}
	OurStr[amount1] = '\0';
	cout << OurStr << endl;
}
void strcat2(char OurStr[], char OurStr2[]) {
	int amount1 = 0;
	int amount2 = 0;
	while (OurStr[amount1])
		amount1++;
	while (OurStr2[amount2]) {
		OurStr[amount1] = OurStr2[amount2];
		amount1++;
		amount2++;
	}
	OurStr[amount1] = '\0';
	cout << OurStr << endl;
}
void strcat3(char OurStr[], char OurStr2[]) {
	int amount1 = 0;
	int amount2 = 0;
	for (int i = 0; OurStr[i]; i++)
		amount1++;
	for (int j = 0; OurStr2[j]; j++) {
		OurStr[amount1] = OurStr2[amount2];
		amount1++;
		amount2++;
	}
	OurStr[amount1] = '\0';
	cout << OurStr << endl;
}
void strcat4(char* OurStr, char* OurStr2) {
	char* result = OurStr;
	while (*OurStr) {
		OurStr++;
	}
	while (*OurStr2) {
		*OurStr = *OurStr2;
		OurStr++;
		OurStr2++;
	}
	*OurStr = '\0';
	cout << result << endl;
}


//функция strcpy копирует одну строку в другую
//strcpy1 работает через while пока не наткнется на символ '\0'
//strcpy2 работает через while пока не посчитает все символы в строке
//strcpy3 работает через for пока не посчитает все символы в строке
//strcpy4 работает через while с указателем

void strcpy1(char OurStr[], char OurStr2[]) {
	int count = 0;
	while (true) {
		OurStr[count] = OurStr2[count];
		if (OurStr2[count] == '\0')
			break;
		count++;
	}
	cout << OurStr << endl;
}
void strcpy2(char OurStr[], char OurStr2[]) {
	int count = 0;
	while (OurStr[count]) {
		OurStr[count] = OurStr2[count];
		count++;
	}
	cout << OurStr << endl;
}
void strcpy3(char OurStr[], char OurStr2[]) {
	for (int i = 0; OurStr[i]; i++)
		OurStr[i] = OurStr2[i];
	cout << OurStr << endl;
}
void strcpy4(char* OurStr, const char* OurStr2) {
	int count = 0;
	while (OurStr2[count] != '\0') {
		OurStr[count] = OurStr2[count];
		++count;
	}
	OurStr[count] = '\0';
	cout << OurStr << endl;
}


//функция strcpm стравнивает длинну строк
//strcmp1 работает через цикл while
//strcmp2 работает через цикл for
//strcmp3 пока не написана
//strcmp4 работает через while с указателем
void strcmp1(char OurStr[], char OurStr2[]) {
	int compare = 0; //для длинных строк
	int count = 0;
	while (true) {
		if (strlen(OurStr) < strlen(OurStr2)) {
			cout << "Строки не равны. Вторая строка длиннее. " << --compare << endl;
			break;
		}
		else if (strlen(OurStr) > strlen(OurStr2)) {
			cout << "Строки не равны. Первая строка длиннее. " << ++compare << endl;
			break;
		}
		else {
			if (strlen(OurStr) == strlen(OurStr2))
				count++;
			if (OurStr[count] == '\0' && OurStr2[count] == '\0') {
				cout << "Строки равны. Длина строки равна: " << strlen(OurStr) << endl;
				break;
			}
		}
	}
}
void strcmp2(char OurStr[], char OurStr2[]) {
	int compare = 0; //для длинных строк
	int count = 0;

	for (int i = 0; ; i++) {
		if (strlen(OurStr) < strlen(OurStr2)) {
			cout << "Строки не равны. Вторая строка длиннее. " << --compare << endl;
			break;
		}
		else if (strlen(OurStr) > strlen(OurStr2)) {
			cout << "Строки не равны. Первая строка длиннее. " << ++compare << endl;
			break;
		}
		else {
			if (strlen(OurStr) == strlen(OurStr2)) {
				count++;
				if (OurStr[count] == '\0' && OurStr2[count] == '\0') {
					cout << "Строки равны. Длина строки равна: " << strlen(OurStr) << endl;
					break;
				}
			}
		}
	}
}
void strcmp3(char OurStr[], char OurStr2[]) {
	int compare = 0; //для длинных строк
	int count = 0;
	while (OurStr[count] != '\0' && OurStr2[count] != '\0') {
		if (strlen(OurStr) < strlen(OurStr2)) {
			cout << "Строки не равны. Вторая строка длиннее. " << --compare << endl;
			break;
		}
		else if (strlen(OurStr) > strlen(OurStr2)) {
			cout << "Строки не равны. Первая строка длиннее. " << ++compare << endl;
			break;
		}
		else {
			if (strlen(OurStr) == strlen(OurStr2))
				count++;
			if (OurStr[count] == '\0' && OurStr2[count] == '\0') {
				cout << "Строки равны. Длина строки равна: " << strlen(OurStr) << endl;
				break;
			}
		}
	}
}
void strcmp4(char* OurStr, char* OurStr2) {
	int compare = 0;
	int count = 0;
	while (true) {
		if (strlen(OurStr) < strlen(OurStr2)) {
			cout << "Строки не равны. Вторая строка длиннее. " << --compare << endl;
			break;
		}
		else if (strlen(OurStr) > strlen(OurStr2)) {
			cout << "Строки не равны. Первая строка длиннее. " << ++compare << endl;
			break;
		}
		else {
			if (strlen(OurStr) == strlen(OurStr2)) {
				count++;
				if (*(OurStr + count) == '\0' && *(OurStr2 + count) == '\0') {
					cout << "Строки равны. Длина строки равна: " << strlen(OurStr) << endl;
					break;
				}
			}
		}
	}
}

//strpos ищет подстроку в строке и возвращает ее позицию
//strpos1 работает через for
//strpos2 работает через for без указателя
//strpos3 работает через while 
//strpos4 работает через while без указателя
int strpos1(const char* OurStr, const char* OurStr2) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	for (int i = 0; i <= len1; i++) {
		int j;
		for (j = 0; j < len2; j++) {
			if (OurStr[i + j] != OurStr2[j])
				break;
		}
		if (j == len2)
			return i;
	}
	return -1;
}
int strpos2(const char OurStr[], const char OurStr2[]) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	int i = 0;
	while (i <= len1 - len2) {
		int j = 0;
		while (j < len2 && OurStr[i + j] == OurStr2[j])
			j++;

		if (j == len2)
			return i;

		i++;
	}
	return -1;
}
int strpos3(const char* OurStr, const char* OurStr2) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	int i = 0;
	while (i <= len1 - len2) {
		int j = 0;
		while (j < len2 && OurStr[i + j] == OurStr2[j])
			j++;

		if (j == len2)
			return i;

		i++;
	}
	return -1;
}
int strpos4(const char OurStr[], const char OurStr2[]) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	int i = 0;
	while (i <= len1 - len2) {
		int j = 0;
		while (j < len2 && OurStr[i + j] == OurStr2[j])
			j++;

		if (j == len2)
			return i;

		i++;
	}
	return -1;
}


//функция strdel удаляет подстроку из строки
//strdel1 работает через for с указателями
//strdel2 работает через for без указателя
//strdel3 работает через while с указателями
//strdel4 работает через while без указателей
void strdel1(char* OurStr, char* OurStr2) {
	int position = strpos1(OurStr, OurStr2);
	if (position != -1) {
		int len1 = strlen(OurStr);
		int len2 = strlen(OurStr2);
		for (int i = position; i <= len1 - len2; i++)
			OurStr[i] = OurStr[i + len2];
		cout << "Обновленная строка: " << OurStr << endl;
	}
	else
		cout << "Строка не найдена\n";
}
void strdel2(char OurStr[], char OurStr2[]) {
	int position = strpos1(OurStr, OurStr2);
	if (position != -1) {
		int len1 = strlen(OurStr);
		int len2 = strlen(OurStr2);
		for (int i = position; i <= len1 - len2; i++)
			OurStr[i] = OurStr[i + len2];
		cout << "Обновленная строка: " << OurStr << endl;
	}
	else
		cout << "Строка не найдена\n";
}
void strdel3(char* OurStr, char* OurStr2) {
	int position = strpos1(OurStr, OurStr2);
	if (position != -1) {
		int len1 = strlen(OurStr);
		int len2 = strlen(OurStr2);
		int i = position;

		while (i <= len1 - len2) {
			OurStr[i] = OurStr[i + len2];
			i++;
		}
		cout << "Обновленная строка: " << OurStr << endl;
	}
	else
		cout << "Строка не найдена\n";
}
void strdel4(char OurStr[], char OurStr2[]) {
	int position = strpos1(OurStr, OurStr2);
	if (position != -1) {
		int len1 = strlen(OurStr);
		int len2 = strlen(OurStr2);
		int i = position;

		while (i <= len1 - len2) {
			OurStr[i] = OurStr[i + len2];
			i++;
		}
		cout << "Обновленная строка: " << OurStr << endl;
	}
	else
		cout << "Строка не найдена\n";
}


void strins1(char* OurStr, char* OurStr2, int pos) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	if (pos < 0 || pos > len1)
		cout << "Неверная позиция: \n";

	for (int i = len1; i >= pos; --i)
		OurStr[i + len2] = OurStr[i];

	for (int i = 0; i < len2; ++i)
		OurStr[pos + i] = OurStr2[i];


	OurStr[len1 + len2] = '\0';
}
void strins2(char OurStr[], char OurStr2[], int pos) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	if (pos < 0 || pos > len1)
		cout << "Неверная позиция: \n";

	for (int i = len1; i >= pos; --i)
		OurStr[i + len2] = OurStr[i];

	for (int i = 0; i < len2; ++i)
		OurStr[pos + i] = OurStr2[i];


	OurStr[len1 + len2] = '\0';
}
void strins3(char* OurStr, char* OurStr2, int pos) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	if (pos < 0 || pos > len1) {
		cout << "Неверная позиция: \n";
		return;
	}
	int i = len1;
	while (i >= pos) {
		OurStr[i + len2] = OurStr[i];
		--i;
	}
	i = 0;
	while (i < len2) {
		OurStr[pos + i] = OurStr2[i];
		++i;
	}
	OurStr[len1 + len2] = '\0';
}
void strins4(char OurStr[], char OurStr2[], int pos) {
	int len1 = strlen(OurStr);
	int len2 = strlen(OurStr2);

	if (pos < 0 || pos > len1) {
		cout << "Неверная позиция: \n";
		return;
	}
	int i = len1;
	while (i >= pos) {
		OurStr[i + len2] = OurStr[i];
		--i;
	}
	i = 0;
	while (i < len2) {
		OurStr[pos + i] = OurStr2[i];
		++i;
	}
	OurStr[len1 + len2] = '\0';
}


int main()
{
	setlocale(LC_ALL, "Ru");
	int answer;
	cout << "Привет! Сегодня у нас на выбор 6 функций для работы со строками. Какую будем использовать?\n";
	cout << "1 - Strlen, 2 - Strcat, 3 - Strcpy, 4 - Strcmp, 5 - Strpos, 6 - Strdel, 7 - Strins\n";
	cin >> answer;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (answer)
	{
	case 1:
	{
		char OurStr[128];
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr, sizeof(OurStr));
		strlen1(OurStr);
		strlen2(OurStr);
		strlen3(OurStr);
		strlen4(OurStr);
	}
	break;

	case 2:
	{
		char OurStr[128];
		char OurStr2[128];
		char OrigStr[128];
		int i = 0;
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr, sizeof(OurStr));
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr2, sizeof(OurStr2));

		for (i = 0; OurStr[i] != '\0'; ++i) {
			OrigStr[i] = OurStr[i];
		} // Сохранение оригинальной строки
		OrigStr[i] = '\0';
		strcat1(OurStr, OurStr2);

		for (i = 0; OrigStr[i] != '\0'; ++i) {
			OurStr[i] = OrigStr[i];
		} // Восстановление оригинальной строки
		OurStr[i] = '\0';
		strcat2(OurStr, OurStr2);

		for (i = 0; OrigStr[i] != '\0'; ++i) {
			OurStr[i] = OrigStr[i];
		}
		OurStr[i] = '\0';
		strcat3(OurStr, OurStr2);

		for (i = 0; OrigStr[i] != '\0'; ++i) {
			OurStr[i] = OrigStr[i];
		}
		OurStr[i] = '\0';
		strcat4(OurStr, OurStr2);
	}
	break;

	case 3:
	{
		char OurStr[128];
		char OurStr2[128];
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr, sizeof(OurStr));
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr2, sizeof(OurStr2));
		strcpy1(OurStr, OurStr2);
		strcpy2(OurStr, OurStr2);
		strcpy3(OurStr, OurStr2);
		strcpy4(OurStr, OurStr2);
	}
	break;

	case 4:
	{
		char OurStr[128];
		char OurStr2[128];
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr, sizeof(OurStr));
		cout << "Введите строку (не больше 128 символов и латинскими буквами)\n";
		cin.getline(OurStr2, sizeof(OurStr2));
		strcmp1(OurStr, OurStr2);
		strcmp2(OurStr, OurStr2);
		strcmp3(OurStr, OurStr2);
		strcmp4(OurStr, OurStr2);
	}
	break;

	case 5:
	{
		char OurStr[128];
		char OurStr2[128];
		cout << "Введите строку: \n";
		cin.getline(OurStr, sizeof(OurStr));
		cout << "Введите подстроку: \n";
		cin.getline(OurStr2, sizeof(OurStr2));

		int pos1 = strpos1(OurStr, OurStr2);
		if (pos1 != -1)
			cout << "Подстрока найдена в позиции: " << pos1 << "\n";
		else
			cout << "Подстрока не найдена\n";


		int pos2 = strpos2(OurStr, OurStr2);
		if (pos1 != -1)
			cout << "Подстрока найдена в позиции: " << pos1 << "\n";
		else
			cout << "Подстрока не найдена\n";

		int pos3 = strpos2(OurStr, OurStr2);
		if (pos3 != -1)
			cout << "Подстрока найдена в позиции: " << pos3 << "\n";
		else
			cout << "Подстрока не найдена\n";

		int pos4 = strpos2(OurStr, OurStr2);
		if (pos4 != -1)
			cout << "Подстрока найдена в позиции: " << pos4 << "\n";
		else
			cout << "Подстрока не найдена\n";
	}
	break;

	case 6:
	{
		char OurStr[128];
		char OurStr2[128];
		char OrigStr[128];
		int i = 0;
		cout << "Введите строку: \n";
		cin.getline(OurStr, sizeof(OurStr));
		cout << "Введите подстроку: \n";
		cin.getline(OurStr2, sizeof(OurStr2));

		for (i = 0; OurStr[i] != '\0'; ++i)
			OrigStr[i] = OurStr[i];
		OrigStr[i] = '\0';
		strdel1(OurStr, OurStr2);

		for (i = 0; OrigStr[i] != '\0'; ++i)
			OurStr[i] = OrigStr[i];
		OrigStr[i] = '\0';
		strdel2(OurStr, OurStr2);

		for (i = 0; OrigStr[i] != '\0'; ++i)
			OurStr[i] = OrigStr[i];
		OrigStr[i] = '\0';
		strdel3(OurStr, OurStr2);

		for (i = 0; OrigStr[i] != '\0'; ++i)
			OurStr[i] = OrigStr[i];
		OrigStr[i] = '\0';
		strdel4(OurStr, OurStr2);
	}
	break;

	case 7:
	{
		char OurStr[128];
		char OurStr2[128];
		char OrigStr[128];
		int pos;
		int i = 0;

		cout << "Введите строку: \n";
		cin.getline(OurStr, sizeof(OurStr));
		cout << "Введите подстроку: \n";
		cin.getline(OurStr2, sizeof(OurStr2));
		cout << "Введите позицию: \n";
		cin >> pos;

		for (i = 0; OurStr[i] != '\0'; ++i)
			OrigStr[i] = OurStr[i];
		OrigStr[i] = '\0';
		strins1(OurStr, OurStr2, pos);
		cout << OurStr << endl;

		for (i = 0; OrigStr[i] != '\0'; ++i)
			OurStr[i] = OrigStr[i];
		OurStr[i] = '\0';
		strins2(OurStr, OurStr2, pos);
		cout << OurStr << endl;

		for (i = 0; OrigStr[i] != '\0'; ++i)
			OurStr[i] = OrigStr[i];
		OurStr[i] = '\0';
		strins2(OurStr, OurStr2, pos);
		cout << OurStr << endl;

		for (i = 0; OrigStr[i] != '\0'; ++i)
			OurStr[i] = OrigStr[i];
		OurStr[i] = '\0';
		strins2(OurStr, OurStr2, pos);
		cout << OurStr << endl;



	}
	}






}