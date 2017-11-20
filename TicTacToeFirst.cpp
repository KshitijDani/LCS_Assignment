#include<iostream>


char board[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

int O1[]={0,1,7,9,3,0,3,9,7,3}; // Positions Player1 should play after Player2's first move

int O2[][2]={0,0,0,0,9,7,0,0,9,3,7,3};// Positions Player1 should play after Player2's second move

int PosCheck(int pos){
	

	if(board[pos-2]=='O'||board[pos]=='O'||board[pos+2]=='O'||board[pos-4]=='O'){
		if(board[pos-2]!=' '&&board[pos-4]!=' '&&board[pos+2]!=' '&&board[pos+4]!=' ')
			return 0;
		else			return 1;
		}
	else
		return 0;
}
	


int check(int i, int j){
	int sum=0,pos,space=0;
	for(int k=0;k<3;k++){
		if(board[i+j*k-1]=='X')
			sum++;
		if(board[i+j*k-1]==' '){
			pos=i+j*k;
			space=1;
		}

	}

	if(sum==2 && space==1)
		return pos;
	else
		return 0;
}

int winCheck(){

	int i;

	for(i=1;i<8;i=i+3)
		if(check(i,1)!=0){
			//std::cout<<"cond:"<<i<<"\n";
			return check(i,1);
		}

	for(i=1;i<4;i++)
		if(check(i,3)!=0){
			//std::cout<<"cond:"<<i+3<<"\n";
			return check(i,3);
		}

	if(check(1,4)!=0){
		//std::cout<<"cond:"<<"7\n";	
		return check(1,4);
	}
	else if(check(3,2)!=0){
		//std::cout<<"cond:8\n";
		return check(3,2);
	}
	else
		return 0;

		
}

		



void displayBoard(){
	std::cout<<"                                     "<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<"\n";
	std::cout<<"                                    "<<"-------"<<"\n";
	std::cout<<"                                     "<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<"\n";
	std::cout<<"                                    "<<"-------"<<"\n";
	std::cout<<"                                     "<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<"\n";
}

int main(){

	std::cout<<"Hello there. Computer Player1 and Mark is 'X'. You are Player2 and Mark is 'O'.\n\n";

	displayBoard();
	std::cout<<"\n\n";
	bool play=true;
	int pos2=1,moves=0,pos1;

	board[0]='X';
	do{
		
		std::cout<<"\n\nPlayer1 has put his mark in position "<<O1[pos2]<<"\n\n";	
		moves++;
		//std::cout<<"\nNumber of moves = "<<moves<<"\n";
		/**/displayBoard();

		L1:
		std::cout<<"\nEnter position number where you wish to place mark(1-9)\n";
		std::cin>>pos2;

		
		if(moves==3||moves==5){
			if(PosCheck(pos2)==1){
				std::cout<<"\nFollow rules!!!!";
				goto L1;
			}
		}
		// IF PLAYER2'S FIRST MOVE IS IN THE CENTER THEN GOTO L1
		if(moves==1 && pos2==5){
			
			board[pos2-1]='O';
			goto L2;
		}
		
		if(board[pos2-1]=='X' || board[pos2-1]=='O'){
			std::cout<<"\nThis cell is already occupied. Place somewhere else\n";
			goto L1;
		}
		else{
			board[pos2-1]='O';
			moves++;
		}


		/**/displayBoard();
		

		//CHECKING TO SEE IF A WINNING COMBINATION HAS BEEN ESTABLISHED
		if(winCheck()!=0){
			std::cout<<"\nPlayer1 wins by putting X at position "<<winCheck()<<"\n";
			board[winCheck()-1]='X'; //Putting X to show player2 the winning combination
			/**/displayBoard();
			play=false;
		}
		

		//PLAYER1'S SECOND MOVE CORRESPONDING TO PLAYER2'S FIRST MOVE
		if(moves==2){
			board[O1[pos2]-1]='X';
		}

				
		//PLAYER1'S THIRD MOVE CORRESPONDING TO PLAYER2'S SECOND MOVE
		if(moves==4){
			if((board[1]=='O'&&board[3]=='O')||(board[2]=='O'&&board[4]=='O')){                   
				board[O2[pos2][0]-1]='X';
				
			}
			else{                                     
				board[O2[pos2][1]-1]='X';
				
			}
		}

	
			
		
		
		
		
	}while(play==true);
	goto L5;

	//CASE WHEN PLAYER2'S FIRST MOVE IS IN THE MIDDLE

	L2:

	
	board[2]='X';
	std::cout<<"\n\nPlayer1 has put his mark in position 3"<<"\n\n";	
	moves++;
		
	/**/displayBoard();

	L3:
	std::cout<<"\nEnter position number where you wish to place mark3(1-9)\n";
	std::cin>>pos2;
	
	if(PosCheck(pos2)==1){
				std::cout<<"\nFollow rules!!!!";
				goto L3;
	}

	std::cout<<"\nPlayer1 wins by putting X at position "<<winCheck()<<"\n";
	board[winCheck()-1]='X'; //Putting X to show player2 the winning combination
	/**/displayBoard();
	

/*
	if( (pos2==2) || (pos2==4) || (pos2==6) || (pos2==8)){
		
		std::cout<<"\nFollow adjacency rule!!!!!!!!!!!\n"<<pos2<<"\n";
		goto L3;
	}

	if(board[pos2-1]=='X' || board[pos2-1]=='O'){
		std::cout<<"\nThe cell is already occupied, pick another position\n";
		goto L3;
	}
		

	board[pos2-1]='O';

	

	if(board[2]=='O')
		board[6]='X';
	else
		board[2]='X';
*/
	///**/displayBoard();

	/*L4:
	std::cout<<"\nEnter position number where you wish to place mark4(1-9)\n";
	std::cin>>pos2;*/
/*
	if(board[pos2-1]=='X' || board[pos2-1]=='O'){
		std::cout<<"\nThe cell is already occupied, pick another position\n";
		goto L4;
	}
*/
	//board[pos2-1]='O';
	///**/displayBoard();
	
	//std::cout<<"\nPlayer1 wins by putting X at position "<<winCheck()<<"\n";
	//board[winCheck()-1]='X'; //Putting X to show player2 the winning combination
	///**/displayBoard();
			
	L5:
	
	return 0;
}
