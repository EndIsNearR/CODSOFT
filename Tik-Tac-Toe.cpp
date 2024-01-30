
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void fill(int board[][3]);
void end (char winner);
bool checkwin(int board[][3],char &winner);
void input(int board[][3]);
void displayBoard(int board[][3]);
void displayBoardend(int board[][3]);
void game();
int main()
{
    int choice;
    int count=0;
    srand(time(0));

    cout<<setw(30)<<setfill('*')<<" "<<endl;
    cout<<"WELCOME TO TIC-TAC TOE GAME\n";
    cout<<setw(30)<<setfill('*')<<" "<<endl;
    cout<<"Enter 1 to Play\n\tOR\nEnter 0 to Exit\n";
    cin>>choice;
    
    
    
    do
    {
        if(count>0)
        {
            cout<<"Would you like to Play Another Game?"<<endl;
            cin>>choice;
            while(choice != 1 && choice != 0)
            {
                cout<<"Invalid Input\nPlease Enter Again"<<endl;
                cin>>choice;
            }
        }
        system("clear");
        if(choice)
        {
            game();
            count++;
        }
        else
        {
            cout<<"THANK YOU FOR PLAYING"<<endl;
            
        }
    }while(choice!= 0);
    
    
    

}
void end (char winner)
{
    
    if(winner== 'P')
    {
        cout<<"The winner is Player 1."<<endl;
    }
    else
    {
        cout<<"The winner is Player 2."<<endl;
    }
    
}
void fill(int board[][3])
{
    for(int i=0;i<3;i++)
    {
        for (int j=0; j < 3; j++)
        {
            board[i][j] = ((i+1) *10) + (j+1);
        }
        
    }
}
bool checkwin(int board[][3],char &winner)
{
    bool r[3]={0},c[3]={0},diagonal[2]={0};
    int j=2,k=0;
        for(int i=0;i<3;i+=2)
        {
            diagonal[k] = (board[0][i] == board [1][1]) && board[0][i] == board [2][j];
            j -= 2;
            k++;
        }
    for(int i=0;i<3;i++)
    {
        
        for (int j = 1; j<= 1; j++)
        {
            if(board[i][0] == board [i][j] && board[i][0] == board [i][j+1])
            {
                r[i] = true;
            }
            else
            {
                r[i] = false;
            }
            if(board[0][i] == board [j][i] && board[0][i] == board [j+1][i])
            {
                c[i] = true;
            }
            else
            {
                c[i] = false;
            }
        }
    }
    for(int i=0;i<3;i+=1)
    {
        if(r[i])
        {
            if(board[i][0] == 'X')
                winner = 'P';
            else
                winner = 'C';
            
            return true;
        }
        if(c[i])
        {
            if(board[0][i] == 'X')
                winner = 'P';
            else
                winner = 'C';
            
            return true;
        }
        for(int j=0;j<2;j++)
        {
            if(diagonal[j])
            {
                if(board[1][1] == 'X')
                    winner = 'P';
                else
                    winner = 'C';
                
                return true;
            }
        }
            
    }
    return false;
}
void input(int board[][3], char playerSymbol)
{
    int row, col, userin;

    cout << "Player " << playerSymbol << ", enter the square you would like to choose (Use space for input of two numbers): ";
    cin >> row >> col;

    // Validate input
    while ((row < 1 || row > 3) || (col < 1 || col > 3) || board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O')
    {
        cout << "Invalid input. Enter again: ";
        cin >> row >> col;
    }

    board[row - 1][col - 1] = playerSymbol;
}

void displayBoard(int board[][3])
{
    int rnum,cnum;
    
    for(int i=0;i<3;i++)
    {
        for (int j=0; j < 3; j++)
        {
            if(board[i][j] != 79 && board[i][j] != 88)
            {
                rnum = board[i][j]/10;
                cnum = board[i][j]%10;
                cout<<rnum<<","<<cnum<<"\t";
            }
            else
            {
                if(board[i][j] == 79)
                    cout<<"O\t";
                else
                    cout<<"X\t";
            }
        }
        cout<<endl;
    }
}
void displayBoardend(int board[][3])
{
    cout<<setw(20)<<setfill('*')<<" "<<endl;
    cout<<"Final Board : "<<endl;
    cout<<setw(20)<<setfill('*')<<" "<<endl;
    displayBoard(board);
}
void game()
{
    int board[3][3] = {0}, counter = 0;
    char winner;
    fill(board);
    bool check = false;

    while (!check && counter < 9)  // Changed the loop condition to consider a filled board
    {
        cout << setw(20) << setfill('*') << " " << endl;
        cout << "Current Board : " << endl;
        cout << setw(20) << setfill('*') << " " << endl;
        displayBoard(board);

        // Player 'X' move
        input(board, 'X');
        system("clear");
        check = checkwin(board, winner);
        counter++;

        if (!check && counter < 9)  // Ensure the next move is only taken if the game is still ongoing
        {
            cout << setw(20) << setfill('*') << " " << endl;
            cout << "Current Board : " << endl;
            cout << setw(20) << setfill('*') << " " << endl;
            displayBoard(board);

            // Player 'O' move
            input(board, 'O');
            system("clear");
            check = checkwin(board, winner);
            counter++;
        }
    }

    displayBoardend(board);
    end(winner);
}

