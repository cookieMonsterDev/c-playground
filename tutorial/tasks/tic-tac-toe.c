#include <stdio.h>
#include <stdbool.h>

#define RED "\033[31m"
#define RESET "\033[0m"

typedef struct
{
    int row;
    int col;
} Move;

char getYesOrNoChoice(char *question)
{
    char choice = '\0';

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        printf("%s ", question);
        scanf(" %c", &choice);

        if (!choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            printf(RED "Input error choice: %c; The only possible choice is Yes(Y)/No(n)\n" RESET, choice);
        }
    }

    return choice;
}

char getGameSign(int state)
{
    switch (state)
    {
    case 0:
        return 'O';
    case 1:
        return 'X';
    default:
        return ' ';
    }
}

char *getGameResolveMessage(int state)
{
    switch (state)
    {
    case 0:
        return "O won!";
    case 1:
        return "X won!";
    default:
        return "Draw!";
    }
};

Move getMove(int turn, int rows, int cols, int board[][cols])
{
    Move move = {3, 3};

    do
    {
        printf("Make a move for %c (row col): ", getGameSign(turn));

        if (scanf("%d %d", &move.row, &move.col) != 2)
        {
            printf(RED "Invalid input! Enter two numbers.\n" RESET);
            while (getchar() != '\n')
                ;
            continue;
        }

        move.row -= 1;
        move.col -= 1;

        if (move.col < 0 || move.col >= cols || move.row < 0 || move.row >= rows)
        {
            printf(RED "The row and col must be in range (1-%d)!\n" RESET, cols);
            continue;
        }

        if (board[move.row][move.col] != 3)
        {
            printf(RED "This cell is already occupied!\n" RESET);
            continue;
        }

        break;

    } while (1);

    return move;
}

bool checkWin(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)
        {
            return true;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0)
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)
    {
        return true;
    }
}

void drawBoard(int rows, int cols, int board[][cols])
{
    printf("\nGame board:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("|");
        for (int j = 0; j < cols; j++)
        {
            printf(" %c |", getGameSign(board[i][j]));
        }
        printf("\n-------------\n");
    }
}

void game()
{
    int move[2];
    int turn = 1;
    int moveCount = 0;
    bool isEnd = false;
    int board[3][3] = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};

    printf("\nWelcome to the Tic-Tac-Toe game\n");
    printf("\n---------------------Rules---------------------\n");
    printf(" 1) The X always starts first.\n 2) After draw or win game can be restarted.\n 3) The move must be like: (1 5) [row column].\n");
    printf("-----------------------------------------------\n");

    while (!isEnd)
    {
        drawBoard(3, 3, board);

        Move move = getMove(turn, 3, 3, board);

        board[move.row][move.col] = turn;
        turn = (turn == 1) ? 0 : 1;
        moveCount++;

        if (moveCount < 5)
            continue;

        if (checkWin(board))
        {
            turn = (turn == 1) ? 0 : 1;
            isEnd = true;
        }

        if (moveCount == 9)
        {
            turn = 3;
            isEnd = true;
        }
    }

    printf("\n%s\n\n", getGameResolveMessage(turn));
}

int main()
{
    char choice;

    do
    {
        game();
        choice = getYesOrNoChoice("Do you want to restart the game Yes(Y)/No(n)?");
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
