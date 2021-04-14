#include <stdio.h>

//Function Declarations
void printBoard();
void handleTurn();

//Global Variables
char board[3][3] = { {'E', 'E', 'E'}, {'E', 'E', 'E'}, {'E', 'E', 'E'}}; //create an empty board
int turn = 0;
int turnsTaken = 0;
int winner = -1;    //-1 to note that no winner currently exists
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clearInput()
{
    while (getchar() != '\n');
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
main() {
    printf("Welcome to tic-tac-toe! A classic game programmed by Rachel Quijano.\n");
    printBoard();
    printf("Above is the empty board. First player = X, Second Player = O. Begin turn by specifying 0-2 row & "
           "0-2 column for\n where you would like to place your piece. Example move looks like 0 0 to place your piece "
           "in the up-left corner.\n");
    handleTurn();
    clearInput();
    getchar();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void handleTurn(){
    char piece;
    int column, row;
    if(turn == 0){
        piece = 'X';
    }else{
        piece = 'O';
    }
    printf("Player %c, please take your turn...\n", piece);
    scanf("%d %d", &column, &row);

    if(board[column][row] == 'E'){
        board[column][row] = piece;
        if(turn == 0){
            turn = 1;
        }else{
            turn = 0;
        }
        turnsTaken++;
        printBoard();
    }else{
        printf("Invalid move! Ensure the cell is empty\n");
    }
    //Check if a win condition was established this turn

    //Horizontal Rows
    int condition1 = board[0][0] == piece && board[0][1] == piece && board[0][2] == piece;
    int condition2 = board[1][0] == piece && board[1][1] == piece && board[1][2] == piece;
    int condition3 = board[2][0] == piece && board[2][1] == piece && board[2][2] == piece;
    //Vertical Columns
    int condition4 = board[0][0] == piece && board[1][0] == piece && board[2][0] == piece;
    int condition5 = board[0][1] == piece && board[1][1] == piece && board[2][1] == piece;
    int condition6 = board[0][2] == piece && board[1][2] == piece && board[2][2] == piece;
    //Diagonals
    int condition7 = board[0][0] == piece && board[1][1] == piece && board[2][2] == piece;
    int condition8 = board[0][2] == piece && board[1][1] == piece && board[2][0] == piece;

    if(condition1 == 1 || condition2 || condition3 || condition4 || condition5 || condition6 || condition7 || condition8){
        printf("We have a winner... it is Player %c! Thanks for playing! Press enter key to exit", piece);
        winner = 0;
    }else if(turnsTaken == 9){
        printf("We have a tie.. Thanks for playing! Press enter key to exit", piece);
        winner = 0;
    }else if(winner == -1) {
        handleTurn();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printBoard(){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
