#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Display Board
int displayboard( char (*board)[10] ){
	printf(" ");
	for(int i = 0; i<10; i++)
		printf(" %d", i);
	printf("\n");

	for(int i = 0; i<10; i++){
		printf("%d ", i);
		for(int j = 0; j<10; j++){
				printf("%c ", (char) board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Display Ships
int displayship( int (*ship)[10]){
	printf("  ");
	for(int i = 0; i<10; i++)
		printf("%d ", i);
	printf("\n");

	for(int i = 0; i<10; i++){
		printf("%d ", i);
		for(int j = 0; j<10; j++){
				printf("%d ", ship[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//Verify location is viable
//Provide options/guidance on where to place ships
int checkspace( int (*ship)[10], int length){
	int row, col;
	int valid, empty, choice, options;
	int left, right, up, down;

	do{
		do{
			valid=0;
			empty=0;
			choice=0;
			options=0;
			left=0;
			right=0;
			up=0;
			down=0;
			
			//Take user input for coordinates
			//Ensure Coordinates are viable
			do{
				printf("\nPlease enter the row value from 0-9: ");
				scanf("%d", &row);
				if(row >= 0 && row <= 9)
					valid = 1;
				else
					printf("Invalid entry\n");
			} while(valid==0);
			valid = 0;
			do{
				printf("\nPlease enter the column value from 0-9: ");
				scanf("%d", &col);
				if(col >= 0 && col <= 9)
					valid = 1;
				else
					printf("Invalid entry\n");
			} while(valid==0);
			valid = 0;
			
			//Alert player if position is occupied already
			if (ship[row][col] == 1)
				printf("Ship already exists in selected position. Please select empty position.\n");
			else
				empty = 1;

		}while(empty == 0);

		printf("\nSelect an Option:\n");
		empty = 0;

		// Ensure placements occur within board dimensions
		if (row >= 0 && row <= 9 && col >= 0 && col <= 9){
			// Check Left
			if(col >= length-1){
				for (int i = col ; i > col-length ; i-- ){
					if (ship[row][i] == 1)
						empty = 1;
				}
				if (empty==0){
					printf("1.  ");
					for (int i = col ; i > col-length ; i-- )
						printf("%d,%d ", row, i);
					printf("  [left]\n");
					left = 1;
					options++;
				}
			}
			empty = 0;
			// Check Right
			if(col <= 10-length){
				for (int i = col ; i < col+length ; i++ ){
					if (ship[row][i] == 1)
						empty = 1;
				}
				if (empty == 0){
					printf("2.  ");
					for (int i = col ; i < col+length ; i++ )
						printf("%d,%d ", row, i);
					printf("  [right]\n");
					right = 1;
					options++;
				}
			}
			empty=0;
			// Check Up
			if(row >= length-1){
				for (int i = row ; i > row-length ; i-- ){
					if (ship[i][col] == 1)
						empty = 1;
				}
				if (empty==0){
					printf("3.  ");
					for (int i = row ; i > row-length ; i-- )
						printf("%d,%d ", i, col);
					printf("  [up]\n");
					up = 1;
					options++;
				}
			}
			empty=0;
			// Check Down
			if(row <= 10-length){
				for (int i = row ; i < row+length ; i++ ){
					if (ship[i][col] == 1)
						empty = 1;
				}
				if(empty==0){
					printf("4.  ");
					for (int i = row ; i < row+length ; i++ )
						printf("%d,%d ", i, col);
					printf("  [down]\n");
					down = 1;
					options++;
				}
			}
			valid = 1;
		}
	}while(valid = 0 && options==0); 
		
	// Place piece at specified location
	do{
		scanf("%d", &choice);
		if (choice == 1 && left == 1){
			for(int i = 0 ; i < length ; i++){
				ship[row][col-i] = 1;
			}
		}
		else if (choice == 2 && right == 1){
			for(int i = 0 ; i < length ; i++){
				ship[row][col+i] = 1;
			}
		}
		else if(choice == 3 && up == 1){
			for(int i = 0 ; i < length ; i++){
				ship[row-i][col] = 1;
			}
		}
		else if(choice == 4 && down == 1){
			for(int i = 0 ; i < length ; i++){
				ship[row+i][col] = 1;
			}
		}
		else{
			printf("Error, invalid entry.\n");
			choice = 0;
		}
	}while(choice == 0);
}

//Ship occupying 5 spaces
int place5( int (*ship)[10]){
	printf("1x5 piece\n");
	checkspace( ship, 5);
	printf("1x5 piece successfully placed.\n");

}

//Ship occupying 4 spaces
int place4( int (*ship)[10]){
	printf("1x4 Piece\n");
	checkspace( ship, 4);
	printf("1x4 piece successfully placed.\n");

}

//Ship occupying 3 spaces
int place3( int (*ship)[10]){
	printf("1x3 Piece\n");
	checkspace( ship, 3);
	printf("1x3 piece successfully placed.\n\n");

}

int main(){

	char shipcount1, shipcount2;
	char clear = 'a';
	int row, col;
	int turn = 1;
	int valid = 0;
	shipcount1 = 12;
	shipcount2 = 12;

	// Create boards
	char board1[10][10], board2[10][10];
	int ships1[10][10] = {{0}};
	int ships2[10][10] = {{0}};

	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
				board1[i][j] = 'O';
				board2[i][j] = 'O';
		}
	}


	// Create board for Player 1
	printf("PLAYER 1:\n");
	displayship( ships1 );

	place5(ships1);
	displayship( ships1 );

	place4(ships1);
	displayship( ships1 );

	place3(ships1);
	displayship(ships1);

	printf("Press enter to clear the screen: ");
	scanf("%c", &clear);
	scanf("%c", &clear);
	system("clear");


	// Create board for Player 2
	printf("PLAYER 2:\n");
	displayship( ships2 );

	place5(ships2);
	displayship( ships2 );

	place4(ships2);
	displayship( ships2 );

	place3(ships2);
	displayship(ships2);

	printf("Press enter to clear the screen: ");
	scanf("%c", &clear);
	scanf("%c", &clear);
	system("clear");

	// Attacking
	do{
		// Player 1's turn
		if (turn == 1){
			printf("Player 1's Turn!\n");
			displayboard( board2 );
			do{
				printf("Attack your opponent!");
				printf("\nPlease enter the row value from 0-9: ");
				scanf("%d", &row);
				if(row >= 0 && row <= 9)
					valid = 1;
				else
					printf("Invalid entry\n");
			} while(valid==0);
			valid = 0;
			do{
				printf("\nPlease enter the column value from 0-9: ");
				scanf("%d", &col);
				if(col >= 0 && col <= 9)
					valid = 1;
				else
					printf("Invalid entry\n");
			} while(valid==0);
			valid = 0;
			
			//Hit occured
			if (ships2[row][col] == 1){
				if (board2[row][col] == 'O'){
					board2[row][col] = 'H';
					printf("---HIT---\n");
					shipcount2--;
				}
				else{
					printf("You already selected that coordinate. Turn wasted.\n");
				}
				displayboard( board2 );
				
			}
			//Missed
			else{
				board2[row][col] = 'X';
				printf("---MISS---\n");
				displayboard( board2 );
			}
		}

		//Player 2's turn
		if (turn == 2){
			printf("Player 2's Turn!\n");
			displayboard( board1 );
			do{
				printf("Attack your opponent!");
				printf("\nPlease enter the row value from 0-9: ");
				scanf("%d", &row);
				if(row >= 0 && row <= 9)
					valid = 1;
				else
					printf("Invalid entry\n");
			} while(valid==0);
			valid = 0;
			do{
				printf("\nPlease enter the column value from 0-9: ");
				scanf("%d", &col);
				if(col >= 0 && col <= 9)
					valid = 1;
				else
					printf("Invalid entry\n");
			} while(valid==0);
			valid = 0;
			//Ship Hit
			if (ships1[row][col] == 1){
				if (board1[row][col] == 'O'){
					board1[row][col] = 'H';
					printf("---HIT---\n");
					shipcount1--;
				}
				else{
					printf("You already selected that coordinate. Turn wasted.\n");
				}
				displayboard( board1 );
				
			}
			//Missed
			else{
				board1[row][col] = 'X';
				printf("---MISS---\n");
				displayboard( board1 );
			}

		}

		printf("Press enter to clear the screen: ");
		scanf("%c", &clear);
		scanf("%c", &clear);
		system("clear");

		if (turn ==	1)
			turn = 2;
		else
			turn = 1;
	} while(shipcount1 > 0 && shipcount2 > 0);

	// PLAYER 1 WINS
	if (shipcount2 == 0)
		printf("Player 1 wins!\n");

	// PLAYER 2 WINS
	if (shipcount1 == 0)
		printf("Player 2 wins!\n");
}
