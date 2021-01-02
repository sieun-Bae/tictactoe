/*
 * Create a 4x4 game board
 * Prompt the first user (the 'x' user) to enter their name
 * Prompt the second user (the 'o' user) to enter their name
 * Prompt the 'x' user to select a grid position where they would like to place an 'x'.
 * Prompt the 'o' user to select a grid position where they would like to place an 'o'.
 * After each user has a turn, check for any row, column, diagonal that has 4 'x's or 4 'o's.
 */
#include "mainFunctions.cpp"
#include <iostream>

using namespace std;

int main()
{
	string user1;
	string user2;
	cout<<"Please enter user1 name: ";
	getline(cin, user1);
	cout<<"Please enter user2 name: ";
	getline(cin, user2);
	
	GameBoard gameBoard;

	for(int i=0;i<8;i++)
	{
		int row=-1;
		int column=-1;
		do {
			cout<<user1<<"\n";
			cout<<"Enter row you would like to place \'x\': ";
			cin>>row;
			cout<<"Enter column you would like to place \'x\': ";
			cin>>column;
		} while(gameBoard.invalid(row, column));
		gameBoard.setGameSpace(row, column, 'x');

		printAll(gameBoard);
		int result = fourInSpace(gameBoard);
		if (result==1) {cout<<"Winner: "<<user1<<". Congrats!\n"; exit(1);}
		else if (result==2) {cout<<"Winner: "<<user2<<". Congrats!\n"; exit(1);}
		
		do {
			cout<<user2<<"\n";
			cout<<"Enter row you would like to place \'o\': ";
			cin>>row;
			cout<<"Enter column you would like to place \'o\': ";
			cin>>column;
		} while(gameBoard.invalid(row, column));
		gameBoard.setGameSpace(row, column, 'o');

		printAll(gameBoard);
		result = fourInSpace(gameBoard);
		if (result==1) {cout<<"Winner: "<<user1<<". Congrats!\n"; exit(1);}
		else if (result==2) {cout<<"Winner: "<<user2<<". Congrats!\n"; exit(1);}
	}
	
	return 0;
}