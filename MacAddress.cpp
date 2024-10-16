
#include <iostream>
#include <string>
using namespace std;

const short MAX_SIZE = 6;

short RandomNumbers(short From, short To)
{
	short RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithChars(char Letters[MAX_SIZE])
{
	for (short i = 0; i < MAX_SIZE; i++)
	{
		Letters[i] = char(RandomNumbers(65, 70));
	}
}

void FillArrayWithNumbers(short Numbers[MAX_SIZE])
{
	for (short i = 0; i < MAX_SIZE; i++)
	{
		Numbers[i] = RandomNumbers(0, 9);
	}
}

string ConcatenationNumbersAndString(short Numbers[MAX_SIZE], char Letters[MAX_SIZE])
{
	string MacAddress = "";
	for (short i = 0; i < MAX_SIZE; i++)
	{
		MacAddress += to_string(Numbers[i]) + Letters[i];
		
		if (i < MAX_SIZE - 1)
		{
			MacAddress += ":";
		}
	}
	return MacAddress;
}

int main()
{
	srand((unsigned)time(NULL));

	short Numbers[MAX_SIZE];
	char Letters[MAX_SIZE];
	
	FillArrayWithChars(Letters);
	FillArrayWithNumbers(Numbers);

	cout << "New Mac: " << ConcatenationNumbersAndString(Numbers, Letters);

	return 0;
}