#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MaxROW = 8;
const int MaxCOL = 8;
const char BLANK = 254;
const char QUEEN = 234;
void resetPlacedArray();
void resetConflictsArray();
void readPlacedArray();
void readConflictsArray();


int conflictsArray[MaxROW][MaxCOL];
char placedArray[MaxROW][MaxCOL];

void fillCol(int rowPar, int colPar);
void fillRow(int rowPar, int colPar);
void subCol(int rowPar, int colPar);
void subRow(int rowPar, int colPar);
/***********************Functions to Fill Diagonals**************************************/
void PlaceQueenFill(int rowPar, int colPar);

void NWDiagonalLeftFill(int rowPar, int colPar);
void NWDiagonalRightFill(int rowPar, int colPar);

void NEDiagonalLeftFill(int rowPar, int colPar);
void NEDiagonalRightFill(int rowPar, int colPar);

/***********************Functions to Subtract Diagonals**************************************/
void RemoveQueenSub(int rowPar, int colPar);

void NWDiagonalLeftSub(int rowPar, int colPar);
void NWDiagonalRightSub(int rowPar, int colPar);

void NEDiagonalLeftSub(int rowPar, int colPar);
void NEDiagonalRightSub(int rowPar, int colPar);

int main()
{
	//Fill the arrays to intialize them.
	resetPlacedArray();
	resetConflictsArray();

	srand(time(0));
	int initialQueenCol = 0;
	int initialQueenRow = rand() % 8;
	cout << initialQueenCol << initialQueenRow << endl;
	//Place first Queen
	PlaceQueenFill(initialQueenRow, initialQueenCol);

	readConflictsArray();
	cout << endl;
	readPlacedArray();
	cout << endl;


	//place next queens



	int col;
	int row;



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
void PlaceQueenFill(int rowPar, int colPar)
{
	//Placement Array
	placedArray[rowPar][colPar]=QUEEN;

	//Conflicts Array
	NWDiagonalLeftFill(rowPar, colPar);
	NWDiagonalRightFill(rowPar, colPar);
	NEDiagonalLeftFill(rowPar, colPar);
	NEDiagonalRightFill(rowPar, colPar);
	fillCol(rowPar, colPar);
	fillRow(rowPar, colPar);
	//The spot where the queen went has a value of 4 at the end of this so let's subtract 3 from the position;
	conflictsArray[rowPar][colPar]-=5;
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
void RemoveQueenSub(int rowPar, int colPar)
{
	//Placed array
	placedArray[rowPar][colPar] = BLANK;
	//COnflicts array
	NWDiagonalLeftSub(rowPar, colPar);
	NWDiagonalRightSub(rowPar, colPar);
	NEDiagonalLeftSub(rowPar, colPar);
	NEDiagonalRightSub(rowPar, colPar);
	subCol(rowPar, colPar);
	subRow(rowPar, colPar);
	//The spot where the queen went has a value of -3 at the end of this so let's add 3 from the position;
	conflictsArray[rowPar][colPar] += 5;
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



void subCol(int rowPar, int colPar)
{
	for (int i = 0; i < 8; i++)
	{
		conflictsArray[i][colPar]--;
	}
}
void fillCol(int rowPar, int colPar)
{
	for (int i = 0; i < 8; i++)
	{
		conflictsArray[i][colPar]++;
	}
}
void fillRow(int rowPar, int colPar)
{
	for (int i = 0; i < 8; i++)
	{
		conflictsArray[rowPar][i]++;
	}
}
void subRow(int rowPar, int colPar)
{
	for (int i = 0; i < 8; i++)
	{
		conflictsArray[rowPar][i]--;
	}
}