#include <iostream>
#include <windows.h> // CoutCentered()
#undef max           //  characters in the input buffer1.  
// If Visual Studio Community is not accepting this line,
 //  it could be due to a conflict with the max macro defined in windows.h
//  or another Windows header file2.
//  This macro can interfere with the max function in std::numeric_limits
// Disable min / max macros : If you’re including windows.h,
//  define NOMINMAX before including it to disable its min / max macros3
//  : #define NOMINMAX
//  #include <windows.h>
#include <thread>    // Timing
#include <chrono>    // Timing
#include <cstdlib>   // srand() & rand()
#include <iomanip>   // setw()
#include <cctype>    // isdigit() Func
#include <string>    // stoi() Func
#include <limits>    // cin.ignore(streamsize)
using namespace std;

void CoutCentered(string text)
{
	// This function will only center the text if it is less than the length of the console!
	// Otherwise it will just display it on the console without centering it.

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                           // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);                          // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize;                                      // Gets the size of the screen
	if (NewSBSize.X > text.size())
	{
		int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
		for (int i = 0; i < newpos; i++)
			cout << " "; // Prints the spaces
	}
	cout << text << endl; // Prints the text centered :]
}

bool is_not_digit(string& input_user_num)
{
	for (char c : input_user_num)
	{
		if (!isdigit(c))
		{
			return true;
		}
	}

	return false;
}

bool Difficulty_Level_VALIDATION(string& input_user_num)
{

	if (stoi(input_user_num) < 1 || stoi(input_user_num) > 4)
	{
		return true;
	}

	return false;
}

bool Play_Again_VALIDATION(string& input_user_num)
{

	if (stoi(input_user_num) < 1 || stoi(input_user_num) > 2)
	{
		return true;
	}

	return false;
}

void green_text()
{
	system("Color 2");
}
void white_text()
{
	system("Color 7");
}
void Red_text()
{
	system("Color 4");
}

void Red_Color_Screen()
{
	system("color 4F");
}
void Green_Color_Screen()
{
	system("color 2F");
}
void Yellow_Color_Screen()
{
	system("color 6F");
}
void Black_Color_Screen()
{
	system("color 0F");
}

enum enlevels
{
	LevelEasy = 1,
	LevelMedium = 2,
	LevelHard = 3,
	LevelInsane = 4
};
enum operations
{
	en_add = 1,
	en_minus = 2,
	en_multiplication = 3,
	en_division = 4
};

int Easy()
{
	short From = 0;
	short To = 50;
	return rand() % (To - From + 1) + From;
}
int Medium()
{
	int From = 50;
	int To = 999;
	return rand() % (To - From + 1) + From;
}
int Hard()
{
	int From = 1000;
	int To = 9999;
	return rand() % (To - From + 1) + From;
}
int Insane()
{
	int From = 10000;
	int To = 100000;
	return rand() % (To - From + 1) + From;
}
int Operation()
{
	short From = 1;
	short To = 4;
	return rand() % (To - From + 1) + From;
}

struct st_game_varaible
{
	unsigned short Number_Of_Questions = 5;
	unsigned short How_many_Games_You_Played = 0;
	unsigned short Game_counter = 0;
	string Difficulty_Level_String = "";
	unsigned short Difficulty_Level = 0;
	unsigned short First_Num = 1;
	unsigned short Second_Num = 0;
	double Result = 0;      // the biggest possible number is 1 Billion as Insane 10K * 100K = 1B
	double user_result = 0; // the biggest possible number is 1 Billion as Insane 10K * 100K = 1B
	string user_result_string = "";
	unsigned short win = 0;
	unsigned short lose = 0;
	string Play_again_string = "";
	unsigned short Play_again = 0;
};

st_game_varaible Game;

void Game_logic()
{
	do
	{
		if (Operation() == operations::en_add)
		{
			Game.Result = Game.First_Num + Game.Second_Num;
			cout << "[" << Game.Game_counter + 1 << "] " << Game.First_Num << " + " << Game.Second_Num << " = ";
		}
		else if (Operation() == operations::en_minus)
		{
			Game.Result = Game.First_Num - Game.Second_Num;
			cout << "[" << Game.Game_counter + 1 << "] " << Game.First_Num << " - " << Game.Second_Num << " = ";
		}
		else if (Operation() == operations::en_division)
		{
			Game.Result = Game.First_Num / Game.Second_Num;
			cout << "[" << Game.Game_counter + 1 << "] " << Game.First_Num << " / " << Game.Second_Num << " = ";
		}
		else
		{
			Game.Result = Game.First_Num * Game.Second_Num;
			cout << "[" << Game.Game_counter + 1 << "] " << Game.First_Num << " * " << Game.Second_Num << " = ";
		}
		cin >> Game.user_result_string;
		if (is_not_digit(Game.user_result_string))
		{
			cout << "Please Enter A valid Answer";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.clear();
			this_thread::sleep_for(chrono::seconds(1));
			system("CLS");
		}

	} while (is_not_digit(Game.user_result_string));

	try
	{
		Game.user_result = stoi(Game.user_result_string);
	}
	catch (...)
	{

	}


	if (Game.Result == Game.user_result)
	{
		green_text();
		cout << "Great job ! "
			<< "\a";
		this_thread::sleep_for(chrono::seconds(2));
		Game.win += 1;
		system("CLS");
	}

	else
	{
		Red_text();
		cout << "Wrong Answer :( "
			<< "\a";
		this_thread::sleep_for(chrono::seconds(2));
		Game.lose += 1;
		system("CLS");
	}

	Game.Game_counter++;
	white_text();
}

void Screen_Record()
{
	if (Game.win > Game.lose)
	{
		Green_Color_Screen();
	}
	else if (Game.win == Game.lose)
	{
		Yellow_Color_Screen();
	}
	else
	{
		Red_Color_Screen();
	}

	cout << setw(75) << "----------------------------------------------------\n";
	cout << setw(75) << "                       Your Score                   \n";
	cout << setw(75) << "----------------------------------------------------\n";
	cout << setw(60) << " The Number Of Times You Have Won  " << setw(8) << ": " << Game.win << endl;
	cout << setw(60) << " The Number Of Times You Have Lose " << setw(8) << ": " << Game.lose << endl;
	cout << setw(68) << " The Number Of Questions You Have Solved : " << Game.How_many_Games_You_Played << endl;
	cout << setw(75) << "                                                    \n";
	cout << setw(75) << "----------------------------------------------------\n";
	this_thread::sleep_for(chrono::seconds(5));
}

void Easy_Choice()
{
	for (int i = 0; i < Game.Number_Of_Questions; i++)
	{
		do
		{
			Game.First_Num = Easy();
			Game.Second_Num = Easy();
		} while (Game.First_Num < Game.Second_Num || Game.Second_Num == 0);
		Game_logic();
	}
}
void Medium_Choice()
{
	for (int i = 0; i < Game.Number_Of_Questions; i++)
	{
		do
		{
			Game.First_Num = Medium();
			Game.Second_Num = Medium();
		} while (Game.First_Num < Game.Second_Num || Game.Second_Num == 0);

		Game_logic();
	}
}
void Hard_Choice()
{
	for (int i = 0; i < Game.Number_Of_Questions; i++)
	{
		do
		{
			Game.First_Num = Hard();
			Game.Second_Num = Hard();
		} while (Game.First_Num < Game.Second_Num || Game.Second_Num == 0);

		Game_logic();
	}
}
void Insane_Choice()
{
	for (int i = 0; i < Game.Number_Of_Questions; i++)
	{
		do
		{
			Game.First_Num = Insane();
			Game.Second_Num = Insane();
		} while (Game.First_Num < Game.Second_Num || Game.Second_Num == 0);

		Game_logic();
	}
}

void Start()
{
	CoutCentered("Welcome To The Game");
	this_thread::sleep_for(chrono::seconds(1));
}

void Play_again()
{
	CoutCentered("Do You Want To Play Again");
	cout << endl;
	CoutCentered("[1] Yes : [2] No");

	cin >> Game.Play_again_string;

	while (is_not_digit(Game.Play_again_string) || Play_Again_VALIDATION(Game.Play_again_string))
	{
		cout << "Please choose a valid choice ";
		this_thread::sleep_for(chrono::seconds(1));
		system("CLS");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		CoutCentered("Do You Want To Play Again");
		cout << endl;
		CoutCentered("[1] Yes : [2] No");
		cin >> Game.Play_again_string;
	}
		Game.Play_again = stoi(Game.Play_again_string);
}

void Play()
{
	do
	{
		Game.How_many_Games_You_Played += 5;
		system("CLS");
		cout << "Choose The Difficulty Level\n";
		cout << "[1] Easy "
			<< "[2] Medium "
			<< "[3] Hard "
			<< "[4] Insane \n";
		cin >> Game.Difficulty_Level_String;

		while (is_not_digit(Game.Difficulty_Level_String) || Difficulty_Level_VALIDATION(Game.Difficulty_Level_String) || Game.Difficulty_Level_String.length() > 1)
		{
			cout << "Please choose a valid choice ";
			this_thread::sleep_for(chrono::seconds(1));
			system("CLS");
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Choose The Difficulty Level\n";
			cout << "[1] Easy "
				<< "[2] Medium "
				<< "[3] Hard "
				<< "[4] Insane \n";
			cin >> Game.Difficulty_Level_String;
		}

		Game.Difficulty_Level = stoi(Game.Difficulty_Level_String);


		system("CLS");
		if (Game.Difficulty_Level == enlevels::LevelEasy)
		{
			Easy_Choice();
		}
		else if (Game.Difficulty_Level == enlevels::LevelMedium)
		{
			Medium_Choice();
		}
		else if (Game.Difficulty_Level == enlevels::LevelHard)
		{
			Hard_Choice();
		}
		else
		{
			Insane_Choice();
		}
		Play_again();
	} while (Game.Play_again == 1);
}

void Exit()
{
	if (Game.Play_again == 2)
	{
		system("CLS");
		Screen_Record();
	}
}

void Credits()
{
	Black_Color_Screen();
	system("CLS");
	CoutCentered("Thanks For Playing !");
	CoutCentered("Made By \"Ahmed Mohamed\"");
	this_thread::sleep_for(chrono::seconds(2));
}

int main()
{
	srand((unsigned)(time(NULL)));
	Start();
	Play();
	Exit();
	Credits();
	return 0;
}
