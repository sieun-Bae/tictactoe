#include <iostream>
using namespace std;

class GameBoard
{
	char gameSpace[4][4];
public:
	GameBoard(){
	    for (int i=0;i<4;i++)
	    {
	        for (int j=0;j<4;j++)
	        {
	            gameSpace[i][j] = '-';
	        }
	    }
	}
	void setGameSpace(int row, int column, char user)
	{
		gameSpace[row][column] = user;
	}
	char getGameSpace(int row, int column)
	{
		return gameSpace[row][column];
	}
	int invalid(int row, int column)
	{
		if (gameSpace[row][column] != '-')
		{
			cout<<"invalid input. already charged. try again.. \n";
			return 1;
		}
		return 0;
	}
	int fourInRow()
	{
		for (int i=0;i<4;i++)
		{
			int cnt1=0;
			int cnt2=0;
			for (int j=0;j<4;j++)
			{
				if (gameSpace[i][j]=='x')
				{
					cnt1++;
				}
				if (gameSpace[i][j]=='o')
				{
					cnt2++;
				}
			}
			if (cnt1==4) {return 1;}
			if (cnt2==4) {return 2;}
		}
		return 0;
	}
	int fourInColumn()
	{
		for (int i=0;i<4;i++)
		{
			int cnt1=0;
			int cnt2=0;
			for (int j=0;j<4;j++)
			{
				if (gameSpace[j][i]=='x')
				{
					cnt1++;
				}
				if (gameSpace[j][i]=='o')
				{
					cnt2++;
				}
			}
			if (cnt1==4) {return 1;}
			if (cnt2==4) {return 2;}
		}
		return 0;
	}

	int fourInDiagonal()
	{
		int cnt1=0;
		int cnt2=0;
			
		for (int i=0;i<4;i++)
		{
			if (gameSpace[i][i]=='x')
			{
				cnt1++;
			}
			if (gameSpace[i][i]=='o')
			{
				cnt2++;
			}
			if (cnt1==4) {return 1;}
			if (cnt2==4) {return 2;}
		}
		return 0;
	}
	void printInfo(int row, int column)
	{
		cout<<gameSpace[row][column];
	}
};
/*
GameBoard::GameBoard()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            gameSpace[i][j] = '-';
        }
    }
}

void GameBoard::setGameSpace(int row, int column, char user)
{
	gameSpace[row][column] = user;
}

char GameBoard::getGameSpace(int row, int column)
{
	return gameSpace[row][column];
}

int GameBoard::fourInRow()
{
	for (int i=0;i<4;i++)
	{
		int cnt1=0;
		int cnt2=0;
		for (int j=0;j<4;j++)
		{
			if (gameSpace[i][j]=='x')
			{
				cnt1++;
			}
			if (gameSpace[i][j]=='o')
			{
				cnt2++;
			}
		}
		if (cnt1==4) {return 1;}
		if (cnt2==4) {return 2;}
	}
	return 0;
}

int GameBoard::fourInColumn()
{
	for (int i=0;i<4;i++)
	{
		int cnt1=0;
		int cnt2=0;
		for (int j=0;j<4;j++)
		{
			if (gameSpace[j][i]=='x')
			{
				cnt1++;
			}
			if (gameSpace[j][i]=='o')
			{
				cnt2++;
			}
		}
		if (cnt1==4) {return 1;}
		if (cnt2==4) {return 2;}
	}
	return 0;
}

int GameBoard::fourInDiagonal()
{
	int cnt1=0;
	int cnt2=0;
		
	for (int i=0;i<4;i++)
	{
		if (gameSpace[i][i]=='x')
		{
			cnt1++;
		}
		if (gameSpace[i][i]=='o')
		{
			cnt2++;
		}
		if (cnt1==4) {return 1;}
		if (cnt2==4) {return 2;}
	}
	return 0;
}

void GameBoard::printInfo(int row, int column)
{
	cout<<gameSpace[row][column];
}
*/