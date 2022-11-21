#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*int code=0; //code must be in global variable as it needs to be accessed from multiple func
void hot_deals(){
	//hot_deals will be in func as it needed to be recalled from order now/after log_in 
}*/

int main(){
    int code; //temporarily assigning code here, this will be moved into global in merged program
	srand(time(NULL)); //A random number generator
	int num=(rand()%5)+1; //This will generate a number between 1-5
	
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Hot Deals!!!---------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-Hurry up! When it's gone, it's gone\n\n\n");
    printf("Dear user, here's the offer for YOU ONLY:\n\n");
    if (num==1){
    	code=501;
    	printf("Discount code:%d\nCongratulations! You've got 5%% off on your purchase.\n",code);
	}
    if(num==2){
    	code=502;
    	printf("Discount code:%d\nCongratulations! You've got 3%% off on your purchase.\n",code);
	}
	if(num==3){
		code=503;
		printf("Discount code:%d\nCongratulations! You've got 10%% discount on purchasing more than 300 BDT.\n",code);
	}
	if(num==4){
		code=504;
		printf("Discount code:%d\nCongratulations! You've got BDT 50 off on your purchase.\n.",code);
		
	}
	if(num==5){
		code=505;
		printf("Discount code:%d\nCongratulations! You've got BDT 30 off on your purchase.\n.",code);
		
	}
	
	
	
	return 0;
	
}
//Below part will be in billing system to check if user already has a code or else run the function to get a code 
    /*if(!(501<=code<=505)){ //if code is not in this range then the user has't run the func yet
		hot_deals();
	}
	printf("Your discount code is %d",code);
	*/
	
