/*Nusrat Farzana Choudhury
221-35-990
Sec-B*/

/*A number guessing game is a simple guessing game where a user is supposed to guess a number between 0 and N.
Write a C program that will generate a random number between 0-500. And take the guess as input from user. Give a user hint if his/her guess is lower or upper than the generated number. If the guess and the generated number matches declare the user as winner. The game will end after 10 attempts.*/

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   srand(time(NULL)); //a random number generator 
   int number= (rand() % 500) +1; //this will generate a number between 0-500
   int guess=0, n=1;
   printf("Enter a guess from 0-500:\n");
   do
   {
       if(number!=guess)
       {
       printf("\t\tAttempt-%d: ",n);
       scanf("\t\t%d",&guess);
       
       if(guess==number)
       {
           printf("\t\tWinner! :D\n");
           break;
       }
       
       
       else if((guess<number) && n!=10)
       printf("\t\tGuess higjher!\n");
       
       else if((guess>number) && n!=10)
       printf("\t\tGuess lower!\n");
       printf("\n");
       n++;
       }
   } while(n<=10); //this loop will continue maximum 10 times
   
   if (n==11)
   {
       printf("\t\tThe number was %d\n\t\tYou lose :(",number);
   }
   
    return 0;
}
