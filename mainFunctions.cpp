/*
 * If 4 'x's are found in the same col, row, diagonal, declare the 'x' user the winner.
 * If 4 'o's are found in the same col, row, diagonal, declare the 'o' user the winner.
 * End the game and declare the winner.
 * If the grid is filled (each player gets 8 turns) 
 * and there is not a row, column, diagonal
 * with 4 of the same symbol, the game is tied. Declare a tie game.
 */
#include "mainClasses.cpp"
#include <iostream>

using namespace std;

void printAll(GameBoard gameBoard);
int tie(GameBoard gameBoard);
int fourInSpace(GameBoard gameBoard);

void printAll(GameBoard gameBoard)
{
	cout<<"\n"<<"*--GameBoard--*"<<"\n";
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{	
			gameBoard.printInfo(i, j);
			cout<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

int tie(GameBoard gameBoard)
{
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			if (gameBoard.getGameSpace(i, j)=='-') {return 0;}
		}
	}
	return 1;
}

int fourInSpace(GameBoard gameBoard)
{
	int r = gameBoard.fourInRow();
	int c = gameBoard.fourInColumn();
	int d = gameBoard.fourInDiagonal();

	if (r==1 || c==1 || d==1)
	{
		return 1;
	}
	if (r==2 || c==2 || d==2)
	{
		return 2;
	}
	if (r==0 && c==0 && d==0)
	{
		if (tie(gameBoard)) {cout<<"Tie game. GG..."; exit(1);}
	}
	return 0;
}
