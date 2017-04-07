#include<iostream>

using namespace std;

const int MaxROW = 8;
const int MaxCOL = 8;
const char BLANK = 254;
const char Queen = 234;
void resetPlacedArray();
void resetConflictsArray();
void readPlacedArray();
void readConflictsArray();


int conflictsArray[MaxROW][MaxCOL];
char placedArray[MaxROW][MaxCOL];


/***********************Functions to Fill Diagonals**************************************/
void DiagonalFill(int rowPar, int colPar);

void NWDiagonalLeftFill(int rowPar, int colPar);
void NWDiagonalRightFill(int rowPar, int colPar);

void NEDiagonalLeftFill(int rowPar, int colPar);
void NEDiagonalRightFill(int rowPar, int colPar);

/***********************Functions to Subtract Diagonals**************************************/
void DiagonalSub(int rowPar, int colPar);

void NWDiagonalLeftSub(int rowPar, int colPar);
void NWDiagonalRightSub(int rowPar, int colPar);

void NEDiagonalLeftSub(int rowPar, int colPar);
void NEDiagonalRightSub(int rowPar, int colPar);

int main()
{
	//Fill the arrays to intialize them.
	resetPlacedArray();
	resetConflictsArray();
	int col = 4;
	int row = 5;
	char userChar;
	while (1)
	{
		cout << "Enter Col: ";
		cin >> col;
		cout << "Enter Row: ";
		cin >> row;

		DiagonalFill(row, col);
		readConflictsArray();
		cout << endl << endl;
		DiagonalSub(row, col);
		readConflictsArray();
		cout << "Y to clear: ";
		cin >> userChar;

		if (userChar == 'y' || userChar == 'Y')
		{
			system("cls");
		}
	}






	/***************************Test for fill diagonal
	int col = 4;
	int row = 5;
	//Test diagonal algorithm
	cout << "Row: " << row << " Col: " << col << endl;
	DiagonalFill(row, col);//We only need to call once to fill both NW and NE diagonals
	readConflictsArray();
	*/


	system("pause");
	return 0;
}


void resetPlacedArray()
{
	for (int i = 0; i < MaxROW; i++)
	{
		for (int j = 0; j < MaxCOL; j++)
		{
			placedArray[i][j] = BLANK;
		}
	}
}
void resetConflictsArray()
{
	for (int i = 0; i < MaxROW; i++)
	{
		for (int j = 0; j < MaxCOL; j++)
		{
			conflictsArray[i][j] = 0;
		}
	}
}
void readConflictsArray()
{
	for (int i = 0; i < MaxROW; i++)
	{
		for (int j = 0; j < MaxCOL; j++)
		{
			cout << conflictsArray[i][j] << " ";
		}
		cout << endl;
	}
}
void readPlacedArray()
{
	for (int i = 0; i < MaxROW; i++)
	{
		for (int j = 0; j < MaxCOL; j++)
		{
			cout << placedArray[i][j] << " ";
		}
		cout << endl;
	}
}





/***********************Functions to Fill Diagonals**************************************/
void DiagonalFill(int rowPar, int colPar)
{
	NWDiagonalLeftFill(rowPar, colPar);
	NWDiagonalRightFill(rowPar, colPar);
	NEDiagonalLeftFill(rowPar, colPar);
	NEDiagonalRightFill(rowPar, colPar);
	//The spot where the queen went has a value of 4 at the end of this so let's subtract 3 from the position;
	conflictsArray[rowPar][colPar]-=3;
}
//Goes NW towards the left and fills in.
void NWDiagonalLeftFill(int rowPar, int colPar)
{
	//Program broke with intial setup of 0,0
	if (rowPar == 0 || colPar == 0)//base case
	{
		conflictsArray[rowPar][colPar]++;
	}
	else
	{
		NWDiagonalLeftFill(rowPar - 1, colPar - 1);
		conflictsArray[rowPar][colPar]++;
	}
}
//Goes NW towards the right and fills in.
void NWDiagonalRightFill(int rowPar, int colPar)
{
	if (rowPar == 7 || colPar == 7)//base case
	{
		conflictsArray[rowPar][colPar]++;
	}
	else
	{
		NWDiagonalRightFill(rowPar + 1, colPar + 1);
		conflictsArray[rowPar][colPar]++;
	}
}
//Goes NE towards the left and fills in.
void NEDiagonalLeftFill(int rowPar, int colPar)
{
	if (rowPar == 7 || colPar == 0)//base case
	{
		conflictsArray[rowPar][colPar]++;
	}
	else
	{

		NEDiagonalLeftFill(rowPar + 1, colPar - 1);
		conflictsArray[rowPar][colPar]++;
	}
}
//Goes NE towards the right and fills in.
void NEDiagonalRightFill(int rowPar, int colPar)
{
	if (rowPar == 0 || colPar == 7)//base case
	{
		conflictsArray[rowPar][colPar]++;
	}
	else
	{
		NEDiagonalRightFill(rowPar - 1, colPar + 1);
		conflictsArray[rowPar][colPar]++;
	}
}



/***********************Functions to Subtract Diagonals**************************************/
void DiagonalSub(int rowPar, int colPar)
{
	NWDiagonalLeftSub(rowPar, colPar);
	NWDiagonalRightSub(rowPar, colPar);
	NEDiagonalLeftSub(rowPar, colPar);
	NEDiagonalRightSub(rowPar, colPar);
	//The spot where the queen went has a value of -3 at the end of this so let's add 3 from the position;
	conflictsArray[rowPar][colPar] += 3;
}
//Goes NW towards the left and subtract
void NWDiagonalLeftSub(int rowPar, int colPar)
{
	//Program broke with intial setup of 0,0
	if (rowPar == 0 || colPar == 0)//base case
	{
		conflictsArray[rowPar][colPar]--;
	}
	else
	{
		NWDiagonalLeftSub(rowPar - 1, colPar - 1);
		conflictsArray[rowPar][colPar]--;
	}
}
//Goes NW towards the right and subtract
void NWDiagonalRightSub(int rowPar, int colPar)
{
	if (rowPar == 7 || colPar == 7)//base case
	{
		conflictsArray[rowPar][colPar]--;
	}
	else
	{
		NWDiagonalRightSub(rowPar + 1, colPar + 1);
		conflictsArray[rowPar][colPar]--;
	}
}
//Goes NE towards the left and subtract
void NEDiagonalLeftSub(int rowPar, int colPar)
{
	if (rowPar == 7 || colPar == 0)//base case
	{
		conflictsArray[rowPar][colPar]--;
	}
	else
	{

		NEDiagonalLeftSub(rowPar + 1, colPar - 1);
		conflictsArray[rowPar][colPar]--;
	}
}
//Goes NE towards the right and subtract
void NEDiagonalRightSub(int rowPar, int colPar)
{
	if (rowPar == 0 || colPar == 7)//base case
	{
		conflictsArray[rowPar][colPar]--;
	}
	else
	{
		NEDiagonalRightSub(rowPar - 1, colPar + 1);
		conflictsArray[rowPar][colPar]--;
	}
}