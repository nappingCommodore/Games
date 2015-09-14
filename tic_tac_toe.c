//tic-tac-toe game

#include<stdio.h>

int player 	= 0;
int place 	= 0;

int matrix[9] = {0};


int won(){
	int i;
	int j;
	int count1;
	int count2;
	j=0;
	for(i=1;i<=3;i++){
		count1 = 0;
		count2 = 0;
		for(;j<i*3;j++){
			if(matrix[j] == 1)
				count1++;
			else
			if(matrix[j] == 2)
				count2++;
			else
			break;
		}
		
		if(count1 == 3 || count2 == 3)
			return 1;
	}
	
	for(i=0;i<3;i++){
		count1 = 0;
		count2 = 0;
		for(j=i;j<=i+6;j+=3){
			if(matrix[j] == 1)
				count1++;
			else
			if(matrix[j] == 2)
				count2++;
			else
				break;
		}
		
		if(count1 == 3 || count2 == 3)
			return 1;
			
	}
	
	if((matrix[0]==1 && matrix[4]==1 && matrix[8]==1) || (matrix[2]==1 && matrix[4]==1 && matrix[6]==1))
		return 1;
		
	if((matrix[0]==2 && matrix[4]==2 && matrix[8]==2) || (matrix[2]==2 && matrix[4]==2 && matrix[6]==2))
		return 1;
		
	return 0;
}



void print(){
	int i,j;
	
	printf("---------------------\n");			
	
	for(i=1;i<=9;i++){
		if(matrix[i-1]==1)
			printf("|  \x1b[32mX\x1b[0m  |");
		
		else
		if(matrix[i-1]==2)
			printf("|  \x1b[33mO\x1b[0m  |");
		
		else
			printf("|  %d  |",i);
		
		if(i%3==0)
			printf("\n---------------------\n");
	}
}


int main(){

	printf("\x1b[41mThis is Tic-Tac-Toe Game......\x1b[0m\n\n\x1b[41mYou have to enter numbers between 1 to 9......\x1b[0m\n\n\x1b[41mEach number represents a block.\x1b[0m\n\n\n");
	
	print();
	
	int i,j,c,flag=0;
	for(i=0;i<9 && !won();i++){
		if(i%2==0){
			printf("Player 1 enter your choice.\n");
			scanf("%d",&c);
		}
		
		else{
			printf("Player 2 enter your choice.\n");
			scanf("%d",&c);
		}
		
		
		if(i>9 && i<1){
			printf("That's a invalid choice, please enter numbers between 1 to 9\n");
			i--;
			continue;
		}
			
		
		else
		if(matrix[c-1] != 0){
			printf("This block is already filled\n");
			printf("Please enter valid block\n");
			i--;
			continue;
		}
		
		else
			(i%2)?(matrix[c-1] = 1) : (matrix[c-1] = 2);
		
		print();
		
		if(won()){
			if(i%2)
				printf("Congratulations!!!!! Player 1 won the game.\n\n");
			else
				printf("Congratulations!!!!! Player 2 won the game.\n\n");
				
			flag=1;
			break;
		}
	}
	
	if(!flag)
		printf("Sorry!!!! game is drawn..\n\n");
	
	return 0;
}
