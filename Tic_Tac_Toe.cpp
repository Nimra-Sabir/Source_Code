#include<iostream>
using namespace std;
char turn='x';
int r,c,ch;
bool draw=false;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void display_code(){
	system("cls");
   cout<<"\n\n\n\tT i c k  C r o s s G a m e ";	
   cout<<"\n\t\tGame Members ";
   cout<<"\n\t\tPlayer x ";	
   cout<<"\n\t\tPlayer 0 "; 	
   cout<<"\n\t\t     |     |     ";
   cout<<"\n\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |   "<<board[0][2]<<" ";
   cout<<"\n\t\t_____|_____|_____";
   cout<<"\n\t\t     |     |     ";
   cout<<"\n\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |   "<<board[1][2]<<" ";
   cout<<"\n\t\t_____|_____|_____";
   cout<<"\n\t\t     |     |     ";
   cout<<"\n\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |   "<<board[2][2]<<" ";
   cout<<"\n\t\t     |     |     ";
   
	
}
void player_turn(){
	if(turn=='x')
    cout<<"\n\t\tPlayer 1 [x] Turn: ";
    if(turn=='0')
   cout<<"\n\t\tPlayer 2 [0]Turn: ";
   cin>>ch;
	
   switch(ch)
   {
   	case 1:
   		r=0,c=0;
   		break;
   	case 2:
   		r=0,c=1;
   		break;	
   	case 3:
   		r=0,c=2;
   		break;	
   	case 4:
   		r=1,c=0;
   		break;
	case 5:
   		r=1,c=1;
   		break;
    case 6:
   	    r=1,c=2;
   		break;
    case 7:
   		r=2,c=0;
   		break;
    case 8:
   		r=2,c=1;
   		break;
    case 9:
   		r=2,c=2;
   		break;	
	default:
	cout<<"\t\tInvalid Choice!";
	break;	   	   		   		   		   
	}
	if(turn=='x' && board[r][c]!='x' && board[r][c]!='0')
	   {
	   	board[r][c]='x';
	   	turn='0';
	   }
	else if(turn=='0'&& board[r][c]!='x'&& board[r][c]!='0')
	   {
	   	board[r][c]='0';
	   	turn='x';
	   }  
	else
	{ 
	   cout<<"\t\tBOX is aleady filled please try again!\n";
	   player_turn();
	}
display_code();	 
	
}
bool gameover()
{
	 
    //check win
	for(int i=0;i<3;i++)
	{
	if(board[i][0]==board[i][1] && board[i][0]==board[i][2]||board[0][i]==board[1][i] && board[0][i]==board[2][i])
	 return false;
	 if(board[0][0]==board[1][1] && board[0][0]==board[2][2]||board[0][2]==board[1][1] && board[0][2]==board[2][0])
	 return false;
   }
   
   
   for(int i=0;i<3;i++)      //If there is any box is not filled  
      for(int j=0;j<3;j++)
	  {
	     if(board[i][j]!='x' && board[i][j]!='0')
            return true;
      }
      
//Draw
draw=true;
return false;
}
int main()
{   
    int con;       // variable to continue game 
    display_code();
	cout<<"\n\tEnter Your Turn 'x' for player 1 and '0' for player 2 : ";
	cin>>turn;
    while(gameover())
	{
		    display_code();
		    player_turn(); 
		    gameover();
	}
		if(turn =='x' && draw == false){
		cout<<"\n\t Player2 [0] wins!! \n\tCongratulations! " ;
		
		  }
		else if(turn=='0'&& draw == false)
		{
			cout<<"\n\t Player1 [x] wins!! \n\tCongratulations! " ;	
	    	
		}
        else{
	       cout<<"\nGame Draw!!\n";
	      }
        return 0;
}
 
