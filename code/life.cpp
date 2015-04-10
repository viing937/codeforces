#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define maxrow 20
#define maxcol 60

class Life
{
public:
	void initialize();
	void print();
	void update();
private:
	int grid[maxrow+2][maxcol+2];
	int neighbor_count( int row, int col );
};

void Life::initialize()
{
	//init
	int row, col;
	for ( row = 0; row <= maxrow + 1; row++ )
		for ( col = 0; col <= maxcol + 1; col++ )
			grid[row][col] = 0;
	row = 1, col = 1;

	//input
	cout << "If you want to load from a file, enter the path, or enter 'no'" << endl;

	char load_way[30];
	scanf( "%s", load_way );

	if ( strcmp(load_way, "no" ) != 0 )
		if ( freopen( load_way, "r", stdin ) == NULL )
		{
			cout << "Path error, load from keyboard" << endl;
			freopen( "/dev/tty", "r", stdin ); 
		}
	cout << endl;

	char ch;
	while ( scanf( "%c", &ch ) != EOF )
	{
		if ( ch == 'x' )
		{
			grid[row][col] = 1;
			col++;
		}
		else if ( ch == ' ' )
		{
			col++;
		}
		else if ( ch ==  '\n' )
		{
			row++;
			col = 1;
		}
	}
	freopen( "/dev/tty", "r", stdin ); 
}

void Life::print()
{
	int row, col;
	cout << "\nThe current Life configuration is:" << endl;
	for ( row = 1; row <= maxrow; row++ )
	{
		for ( col = 1; col <= maxcol; col++ )
		{
			if ( grid[row][col] == 1 )
				cout << 'x';
			else
				cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Life::update()
{
	int row, col;
	int new_grid[maxrow + 2][maxcol + 2];
	for ( row = 1; row <= maxrow; row++ )
		for ( col = 1; col <= maxcol; col++ )
			switch ( neighbor_count( row, col ) )
			{
			case 2:
				new_grid[row][col] = grid[row][col];
				break;
			case 3:
				new_grid[row][col] = 1;
				break;
			default:
				new_grid[row][col] = 0;
			}
	for ( row = 1; row <= maxrow; row++ )
		for ( col = 1; col <= maxcol; col++ )
			grid[row][col] = new_grid[row][col];
}

int Life::neighbor_count( int row, int col )
{
	int i, j;
	int count = 0;
	for ( i = row-1; i <= row+1; i++ )
		for ( j = col-1; j <= col+1; j++ )
			count += grid[i][j];
	count -= grid[row][col];
	return count;
}

bool user_says_yes()
{
	int c;
	bool initial_response = true;
	do {
		if ( initial_response )
			cout << "(y,n) " << flush;
		else
			cout << "Respond with either y or n:" << flush;
		do{
			c = cin.get();
		}while ( c == '\n' || c == ' ' || c == '\t' );
	}while ( c != 'y' && c != 'Y' && c != 'n' && c != 'N' );
	return ( c == 'y' || c == 'Y' );
}

void instructions()
{
	cout << "Welcome to Conway.s game of Life." << endl;
	cout << "This game uses a grid of size "
		 << maxrow << " by " << maxcol << " int which" << endl;
	cout << "each cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cells change from generation to generation" << endl;
	cout << "according to the number of neighboring cells which are alive.\n" << endl;
	cout << "'x' represents a living cell, and ' ' represents a dead cell" << endl;
	cout << "End with EOF" << endl;
}

int main()
{
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while ( user_says_yes() )
	//while ( 1 )
	{
		//sleep( 1 );
		system("clear");
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?" << endl;
	}
	return 0;
}
