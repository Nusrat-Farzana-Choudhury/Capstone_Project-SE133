#include<stdio.h>
int main(){
	int choice7;
	char review[100];
	printf("\t\t\t\t\t\t\t\t\t\t--------------------Review--------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t-Reflection enables us to evaluate the experience,\n\t\t\t\t\t\t\t\t\t\t\t\tlearn from mistakes, repeat success\n\n\n");
	printf("Rate your experience with our service:\n\t1. Worst\n\t2. Bad\n\t3. Fair\n\t4. Good\n\t5. Excellent\n\nEnter your choice: ");
	scanf("%d",&choice7);
	choice7=NULL;
	printf("\n\nWanna tell more about your experience?\n\t1. Yes\n\t2. No\n\tEnter your choice: ");
	scanf("%d",&choice7);
	if(choice7==1){
		printf("\nWrite here about your experince:\n");
		getchar();
		gets(review);
	}
	printf("\nGreetings from Lost Kitchen! We've received your feedback about our service.\n\n\n\t\t\t\t\t\t\t\t\t\t-----------(: Thanks for staying with us :)-----------");
	return 0;
}
