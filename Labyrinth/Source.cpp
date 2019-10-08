#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

void GoToXY(int column, int line);
bool loginCtrl();
void makeBox();
void loader(int color);
void loadingScreen();
void menuScreen();
void menuCtrl();


WORD GetConsoleTextAttribute(HANDLE hCon)
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}

int main(void)
{
	if (loginCtrl()) {
		
		loadingScreen();
		menuScreen();
	}

	


	return 0;

}

void GoToXY(int column, int line){

	COORD coord;
	coord.X = column;
	coord.Y = line;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!SetConsoleCursorPosition(hConsole, coord)) {

	}
}


/* Login Screen */
bool loginCtrl() {

	system("color 7");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);

	makeBox();

	GoToXY(5, 5);

	//cout << "\n" << endl;
	Sleep(50);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\t\t\t\t\t\t\t╔══╦══╦══╗" << endl;
	cout << "\t\t\t\t\t\t\t╠═ ╠═════╣" << endl;
	cout << "\t\t\t\t\t\t\t║ ═╝ ╠═╝ ║" << endl;
	cout << "\t\t\t\t\t\t\t╠════╣ ══╣" << endl;
	cout << "\t\t\t\t\t\t\t╚════════╝\n" << endl;
	Sleep(50);
	cout << "\t\t\t\t\t\t    PROJECT LABYRINTH" << endl;
	SetConsoleTextAttribute(hConsole, 8);
	Sleep(50);
	cout << "\t\t\t\t\t\t    Encrypted Journal\n\n" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	Sleep(50);
	cout << "\t\t\t\t\t\t   ╔═════════════════╗" << endl;
	cout << "\t\t\t\t\t\t   ┃                 ┃" << endl;
	cout << "\t\t\t\t\t\t   ╚═════════════════╝" << endl;
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\t\t\t\t\t\t    [enter password]\n\n" << endl;


	GoToXY(53, 16);
	
	
	string password;
	getline(cin, password);

	cout << "\n\n\n\n\n\n\n" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	if (password == "password") {
		return true;
	}
	else {
		return false;
	}
}

void makeBox() {
	system("color 7");
	cout << "\t╔═══════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
	for (int i = 0; i < 27; i++) {
		cout << "\t┃                                                                                                       ┃" << endl;
		Sleep(25);
	}
	cout << "\t╚═══════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
}

void loader(int color) {
	system("color 7");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);

	SetConsoleTextAttribute(hConsole, color);
	for (int i = 0; i < 40; i++) {

		cout << "█";
		Sleep(50);
	}

	SetConsoleTextAttribute(hConsole, saved_colors);
}

void loadingScreen() {
	system("cls");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);

	makeBox();
	GoToXY(5, 14);
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\t\t\t\t\t\t\tLoading\n\n" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	GoToXY(40, 16);
	loader(68);
}

void menuScreen() {
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	const int saved_colors = GetConsoleTextAttribute(hConsole);

	makeBox();
	GoToXY(5, 5);
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\t\t\t\t\t\t    Welcome Commander!\n\n" << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\t\t\t\t\t        ╔════════════════════════╗" << endl;
	cout << "\t\t\t\t\t        ┃   INPUT [1] ADD ENTRY  ┃" << endl;
	cout << "\t\t\t\t\t        ╚════════════════════════╝" << endl;
	cout << "\t\t\t\t\t        ╔════════════════════════╗" << endl;
	cout << "\t\t\t\t\t        ┃   INPUT [2] VIEW ENTRY ┃" << endl;
	cout << "\t\t\t\t\t        ╚════════════════════════╝" << endl;
	cout << "\n" << endl;
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\t\t\t\t\t        ╔════════════════════════╗" << endl;
	cout << "\t\t\t\t\t        ┃     INPUT [0] EXIT     ┃" << endl;
	cout << "\t\t\t\t\t        ╚════════════════════════╝" << endl;
	cout << "\n\n\n" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "\t\t\t\t\t\t   ╔═════════════════╗" << endl;
	cout << "\t\t\t\t\t\t   ┃                 ┃" << endl;
	cout << "\t\t\t\t\t\t   ╚═════════════════╝" << endl;
	SetConsoleTextAttribute(hConsole, 8);
	cout << "\t\t\t\t\t\t      [enter choice]\n\n" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	GoToXY(60, 24);

	menuCtrl();

}

void menuCtrl() {

	bool fail;
	int input;

	do {

		cin >> input;
		fail = cin.fail();

		switch (input) {
		case 1:
			system("cls");
			cout << "add" << endl;
			break;
		case 2:
			system("cls");
			cout << "view" << endl;
		}

		cin.clear();
		cin.ignore(100, '\n');

		if (input == 0) {
			break;
		}

		menuScreen();

	} while (input != 0 || fail);

}