#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

string generateBars(int number);
int getUserInputInt(const int& min, const int& max);

void displayMainMenu();
void displayAddRemoveMenu();

namespace UI
{
	const int TERMINAL_WIDTH = 100;
	const int TERMINAL_HEIGHT = 40;

	const string BARS = "=";

	const string PROMPT_OPTION = "Pick an option: ";

	const string ERR_EXCEPTION_GENERIC = "ERROR: An exception occured.";
	const string ERR_EXCEPTION_INVALID_ARGUMENT = "ERROR: Invalid option, option is not a valid argument. Are you correctly typing a number or a string?";
	const string ERR_EXCEPTION_OUT_OF_RANGE = "ERROR: Invalid option, option is out of range.";
	const string ERR_INVALID_OPTION_RANGE = "ERROR: Invalid option, option must be between ";

	enum MAIN_MENU_OPTIONS { MAIN_NONE, MAIN_ADD, MAIN_SUBSTRACT, MAIN_TOTAL, MAIN_EMPTY, MAIN_EXIT };
	enum PICK_CURRENCY_OPTIONS { CURRENCY_NONE, CURRENCY_DOLLARS, CURRENCY_EUROS, CURRENCY_YEN, CURRENCY_RUPEE, CURRENCY_YUAN, CURRENCY_BACK};
}


int main() 
{
	//GET USER INPUT
	int inputMain;

	do
	{
		displayMainMenu();
		cout << UI::PROMPT_OPTION;
		cin >> inputMain;

		switch (inputMain)
		{
			int subMenuInput;
		case UI::MAIN_MENU_OPTIONS::MAIN_ADD:
			do
			{
				displayAddRemoveMenu();
				cout << UI::PROMPT_OPTION;
				inputMain = getUserInputInt(UI::MAIN_MENU_OPTIONS::MAIN_ADD, UI::MAIN_MENU_OPTIONS::MAIN_EXIT);

				switch (subMenuInput)
				{
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:
					break;
				default:
					break;
				}
			} while (subMenuInput != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
			break;

		case UI::MAIN_MENU_OPTIONS::MAIN_SUBSTRACT:
			do
			{
				displayAddRemoveMenu();
				cout << UI::PROMPT_OPTION;
				cin >> subMenuInput;
				switch (subMenuInput)
				{
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_DOLLARS:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_EUROS:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YEN:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_RUPEE:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_YUAN:

					break;
				case UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK:
					break;
				default:
					break;
				}
			} while (subMenuInput != UI::PICK_CURRENCY_OPTIONS::CURRENCY_BACK);
			break;
		default:
			break;
		}




	} while (inputMain != UI::MAIN_MENU_OPTIONS::MAIN_EXIT);
	



	system("pause");
	return 0;
}

void displayMainMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string walletText = "[ YOUR WALLET ]";
	const string addText = "[ 1 ] ADD CURRENCY";
	const string substractText = "[ 2 ] SUBSTRACT CURRENCY";
	const string totalText = "[ 3 ] TOTAL CURRENCY";
	const string emptyText = "[ 4 ] EMPTY WALLET";
	const string exitText = "[ 5 ] EXIT";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + walletText.length()) / 2;
	const size_t optionMargin = titleMargin - walletText.length();

	cout << right << setw(titleMargin) << walletText << endl << endl << bars << endl << endl;

	cout << setw(optionMargin + addText.length()) << addText << endl << endl
		<< setw(optionMargin + substractText.length()) << substractText << endl << endl
		<< setw(optionMargin + totalText.length()) << totalText << endl << endl
		<< setw(optionMargin + emptyText.length()) << emptyText << endl << endl
		<< setw(optionMargin + exitText.length()) << exitText << endl << endl
		<< bars << endl << endl;


	return;
}

void displayAddRemoveMenu()
{
	system("CLS");

	const string bars = generateBars(UI::TERMINAL_WIDTH);
	const string currencyText = "[ CURRENCY ]";
	const string dollarText = "[ 1 ] DOLLAR";
	const string eurosText = "[ 2 ] EURO";
	const string yenText = "[ 3 ] YEN";
	const string rupeeText = "[ 4 ] RUPEE";
	const string yuanText = "[ 5 ] YUAN";
	const string backText = "[ 6 ] BACK";

	const size_t titleMargin = (UI::TERMINAL_WIDTH + currencyText.length()) / 2;
	const size_t optionMargin = titleMargin - currencyText.length();

	cout << right << setw(titleMargin) << currencyText << endl << endl << bars << endl << endl;

	cout << setw(optionMargin + dollarText.length()) << dollarText << endl << endl
		<< setw(optionMargin + eurosText.length()) << eurosText << endl << endl
		<< setw(optionMargin + yenText.length()) << yenText << endl << endl
		<< setw(optionMargin + rupeeText.length()) << rupeeText << endl << endl
		<< setw(optionMargin + yuanText.length()) << yuanText << endl << endl
		<< setw(optionMargin + backText.length()) << backText << endl << endl
		<< bars << endl << endl;
}

/*************************
** HELPER FUNCTIONS
**************************/

string generateBars(int number)
{
	string bars = string();
	string bar = UI::BARS;

	for (int i = 0; i < number; i++)
	{
		bars.append(bar);
	}

	return bars;
}

int getUserInputInt(const int& min, const int& max)
{
	string input;
	int inputInt;
	bool err;

	do
	{
		err = false;

		getline(cin, input);

		//Exception handling
		try
		{
			inputInt = stoi(input);

			//Input must be between min and max
			if (inputInt < min || inputInt > max)
			{
				cerr << UI::ERR_INVALID_OPTION_RANGE << min << " and " << max << " inclusive." << endl;
				err = true;
			}
		}
		/*
		catch (invalid_argument&)
		{
			cerr << UI::ERR_EXCEPTION_INVALID_ARGUMENT << endl;
			err = true;
		}
		*/
		catch (out_of_range&)
		{
			cerr << UI::ERR_EXCEPTION_OUT_OF_RANGE << endl;
			err = true;
		}
		catch (...)
		{
			cerr << UI::ERR_EXCEPTION_GENERIC << endl;
			err = true;
		}

	} while (err || !cin);

	return inputInt;
}
