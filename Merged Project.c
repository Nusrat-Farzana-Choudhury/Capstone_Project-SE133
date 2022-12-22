/*--------Project: Lost Kitchen-----------
    (An online homemade food delivery system)

  ---Submitted by---
  Nusrat Farzana Choudhury (221-35-990) 
                &
  Mashruba Sultana Zerin (221-35-885)
  
  Section: B
  Batch : 37
  ---------------------------------------*/
  
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
#include <string.h>
#include <stdlib.h>

int choice, order_id, order=0;
int code=0;
float discount=0,sum2=0;
int count_log=0;
char username[100],address[100], contact[20];

int home_page();
int back_exit();
void takepassword();
int order_now();
int hot_deals();
int login();
int authentication_page();
int Bill_show();


int home_page()
{
	system ("cls");
	system("color B0");
	printf("\n\n\t\t\t\t\t\t\t\t\t\tWelcome to\n");
	printf("\t\t\t\t\t\t\t\t\t\t----------LOST KITCHEN-------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t-Where every flavor tells a story\n\n\n");

	printf("1. About us\n");
	printf("2. User guides\n");
	printf("3. Register/Log in\n");
	printf("4. Order now!\n");
	printf("5. Hot deals!!!\n");
	printf("6. FAQs\n");
	printf("7. Review\n");
	printf("8. Exit\n");

	printf("\n\nEnter your choice: ");
	scanf("%d",&choice);

}
int back_exit()
{
	int opt_1;
	printf("\n\nPress 1 to back to homepage or 0 to exit: ");
	scanf("%d",&opt_1);
	if (opt_1==1)
	{
		system("cls");
		home_page(); //recalling home_page (code-page00) func
	}
	else{
		choice=0;
	}

}

struct login
{
	char fname [100];
	char lname[100];
	char username[100];
	char studentmail[100];
	char phonenumber[20];
	char studentid[10];
	char password[20];

};
void takepassword(char pwd[20])
{
	int i;
	char ch;
	while(1)
	{
		ch = getch();
		if(ch == ENTER || ch == TAB)
		{
			pwd[i] = '\0';
			break;
		}
		else if(ch == BCKSPC)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}
registration ()
{
	system ("cls");
	char password2[30];
	FILE*log;
	log=fopen("login.txt","w");
	struct login l;
	printf("\n\nEnter your first name\t: ");
	scanf("%s",l.fname);
	printf("Enter your last name\t: ");
	scanf("%s",l.lname);
	printf("Enter username\t\t: ");
	scanf("%s",l.username);
	printf("Enter DIU student mail\t: ");
	scanf("%s",l.studentmail);
	printf("Enter your phone number\t: ");
	scanf("%s",l.phonenumber);
	printf("Enter student ID\t: ");
	scanf("%s",l.studentid);
	printf("Enter password\t\t: ");
	takepassword(l.password);
	printf("\nConfirm your password\t: ");
	takepassword(password2);
	if(!strcmp(l.password,password2))
	{

		fwrite(&l,sizeof (l),1,log);
		fclose(log);
		printf("\n\nUser resgistration successful, Your username is %s\n",l.username);
	}
	else
	{
		printf("\n\nPassword do not match.\n");
		Beep(750,300);
		printf("\nPlease complete the process carefully.\nPress any key to continue...");
		getch();
		registration();
	}


}
int login()
{
	system ("cls");
	system("color 0B");
	printf("\n\n");
	char password [100];
	FILE*log;
	struct login l;
	log=fopen("login.txt","r");
	printf("Username\t: ");
	scanf("%s",&username);
	printf("Password\t: ");
	takepassword(password);
	
	while (fread (&l, sizeof (l),1,log))
	{
		if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
		{
			printf("\nYou've logged in successfully!!!");
			count_log=1; //verify if order now can be applicable
			strcpy(username,l.username);
		}
		else
		{
			printf("\nInvalid username or password.");
			Beep(750,300);
			printf("\nPlease complete the process carefully!...\nPress any key to continue...");
			getch();
		}
	}
	fclose(log);
	
	if(count_log==1)
	{
		printf("\n\nDo you want to order now?");
		printf("\nPress  1 for yes\nOr, any key to return to authentication page: ");
		int opt5;
		scanf("%d",&opt5);
		if((opt5==1)&&(code!=0))
		{
			system("cls");
			order_now();
			return 0;
		}
		else if((opt5==1)&&(code==0))
		{
			printf("\nPlease check your offer first!\nRedirecting you to offer page 'Hot Deals'...\nPress any key to continue...");
			getch();
			system("cls");
			hot_deals();
			printf("\nRedirecting you to 'Order Now'...\nPress any key to continue... ");
			getch();
			system("cls");
			order_now();
		}
	}
}

int authentication_page() //int authentication_page(){ }
{
	system ("cls");
	system("color 0B");
	int opt3, opt3_1;;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Authentication system---------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-We value your privacy!\n\n\n");
	printf("1.Sign up\n");
	printf("2.Log in\n");
	printf("3.Back\n");
	printf("4.Exit\n");
	printf("\nChoose your operation: ");
	scanf("%d",&opt3);
	if(opt3==1)
	{
		system ("cls");
		printf("\n\n");
		registration();
		printf("\n\nPress 1 to log in now\nor, 2 to back to authentication page\nor, 3 to back to homepage\nor, 0 to exit: ");
		scanf("%d",&opt3_1);
		if(opt3_1==1)
		{
			system("cls");
			login();

		}

		else if(opt3_1==2)
		{
			system("cls");
			authentication_page();
		}

		else if(opt3_1==3)
		{
			system("cls");
			home_page();
		}

		else {
			choice=8;
		}
			
	}
	else if(opt3==2)
	{
		system ("cls");
		login();
		
		if (order==1){
			choice=0;
			return 0;
		}
	}

	else if(opt3==3)
	{
		home_page();
	}
	else if (opt3==4)
	{
		printf("Enter any key to exit...");
		getch();
		choice=0;
	}
}

int Bill_show(int arID[],int arqty[],int counter)
{
	system ("cls");
	system("color C0");
	
	int i,n;
	float sum=0;
	int costs[30]= {10,10,10,10,15,30,10,15,10,15,20,40,65,55,90,20,40,40,15,10,10,10,10,30,30,30,10,25,25,15};
	char items[30][16]= {"Rooti","Paratha","Daal","Sobji","Omlette","Khichuri","Cha","Coffee","Singara","Samusa","Rice","Chicken (Half)","Chicken (Full)","Beef (Half)","Beef (Full)","Egg Curry","Fish Curry","Fish Fry","Mixed Sobji","Aloo Vorta","Mach Vorta","Shutki Vorta","Daal","Kheer","Roshmalai","Doi","Rosogolla","Coca-cola","Mirinda","Mineral Water"};
	
	printf("\n\n\t\t\t\t\t\t\t\t\t\t----------LOST KITCHEN-------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t-Where every flavor tells a story\n\n\n");
	printf("\n\nHere's your bill:\n\n\n\t\tItem(s)\t\t     Quantity\t\t    Cost\n\n\n\n");
    for(i=0; i<counter; i++)
	{
		printf("\t%2d. %-16s ________\t%-5d piece(s) ____ %7d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
		sum=sum+(costs[arID[i]-1]*arqty[i]);
	}

	if(code==501)
	{
		discount=sum*0.05;
		sum2=sum-discount;
	}
	if(code==502)
	{
		discount=sum*0.03;
		sum2=sum-discount;
	}
	if((code==503)&&(sum>=100))
	{
		discount=sum*0.10;
		sum2=sum-discount;
	}
	if((code==504) && (sum>=150))
	{
		discount=50;
		sum2=sum-discount;
	}
	if((code==505)&& (sum>=90))
	{
		discount=30;
		sum2=sum-discount;
	}

 
    order_id=(rand())%100+1000;
	/*An unique Order ID should be generated under time.h function*/

	printf("\n\n\n\n\t\t\t\t\tSub-total\t= %.2f",sum);
	printf("\n\t\t\t\t\tDiscount\t= -%.2f",discount);
	printf("\n\t\t\t\t\tTotal\t\t= %.2f\n\n\n\n\n",sum2);



	printf("---------------Billing info (in Ashuliya)-----------------\n");
	printf("\n\nOder ID\t\t\t: LK-%d",order_id);

	printf("\nName\t\t\t: %s\nAddress\t\t\t: %s\nPhone\t\t\t: %s",username,address,contact);
	printf("\nPayment method\t\t: COD\n\n");

	printf("Thanks for your order. Soon you'll get a call from our representative.\nYour food will be delivered in 20-30 minutes after confirmation.\n\n\n\n");

}


int order_now()
{
	system ("cls");
	system("color B0");
	int arID[30],decision,arqty[10],Bill[10],counter=0;

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Order Now!!!---------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-Fresh flavour at the best rate!\n\n\n");

	if (code==0)
	{
		printf("You haven't checked your offer yet. Redirecting you to 'Hot deals'.\nPress any key to continue...");
		getch();
		system("cls");
		hot_deals();
		getch();
		system("cls");
		order_now();
	}


	printf("\nYour discount code is %d",code);

	if(code==503)
		printf("You have to order at least BDT 100/- to enjoy 10% discount.");
	if(code==504)
		printf("You have to order at least BDT 150/- to enjoy the discount.");
	if(code==505)
		printf("You have to order at least BDT 90/- to enjoy the discount.");


	printf("\t\t\t\tBreakfast\t\t\t\n\t\t(Available from 7 a.m. to 12 p.m)\n");
	printf("\t1. Rooti .......................................10/-\n");
	printf("\t2. Paratha .....................................10/-\n");
	printf("\t3. Daal ........................................10/-\n");
	printf("\t4. Sobji .......................................10/-\n");
	printf("\t5. Omlette .....................................15/-\n");
	printf("\t6. Khichuri.....................................30/-\n");
	printf("\t7. Cha .........................................10/-\n");
	printf("\t8. Coffee ......................................15/-\n");
	printf("\t9. Singara .....................................10/-\n");
	printf("\t10. Samusa .....................................15/-\n");
	printf("\n\n\t\t\t\tLunch & Dinner\t\t\t\n\t\t(Available from 12-4 p.m. & 7-11 p.m.)\n");
	printf("\t11. Rice .......................................20/-\n");
	printf("\t12. Chicken (Half) .............................40/-\n");
	printf("\t13. Chicken (Full) .............................65/-\n");
	printf("\t14. Beef (Half) ................................55/-\n");
	printf("\t15. Beef (Full) ................................90/-\n");
	printf("\t16. Egg curry ..................................20/-\n");
	printf("\t17. Fish curry .................................40/-\n");
	printf("\t18. Fish fry   .................................40/-\n");
	printf("\t19. Mixed sobji ................................15/-\n");
	printf("\t20. Aloo vorta .................................10/-\n");
	printf("\t21. Mach vorta .................................10/-\n");
	printf("\t22. Shutki Vorta ...............................10/-\n");
	printf("\t23. Daal .......................................10/-\n");
	printf("\n\n\t\t\tDesserts & Beverages\t\t\t\n\t\t\t(Always Available)\n");
	printf("\t24. Kheer ......................................30/-\n");
	printf("\t25. Roshmalai ..................................30/-\n");
	printf("\t26. Doi ........................................30/-\n");
	printf("\t27. Rosogollah .................................10/-\n");
	printf("\t28. Coca-Cola ..................................25/-\n");
	printf("\t29. Mirinda   ..................................25/-\n");
	printf("\t30. Mineral Water   ............................15/-\n");
	printf("\n\n\tOrder your dish: (Enter 0 to finish order)\n");
	for(; ; )
	{
		counter++;
		printf("\t Enter Food ID\t\t: ");
		scanf("%d",&arID[counter-1]);

		if(arID[counter-1]==0)
		{
			break;
		}
		else if((arID[counter-1]<0)||(arID[counter-1]>30))
		{
			printf("\t\t Wrong food ID!!!\n");
			counter--;
		}
		else if(!((arID[counter-1]<0)||(arID[counter-1]>30)))
		{
			printf("\t Enter Quantity\t\t: ");
			scanf("%d",&arqty[counter-1]);
		}


	}
	counter--;
	system("cls");
	system("color 9F");
	printf("\nEnter your adddress (In Ashuliya)\t\t: ");
	getchar();
	gets(address);
	printf("Enter your contact no. for confirmation\t\t: ");
	gets(contact);
	printf("\n\nPress any key to continue...");
	getch();

	Bill_show(arID,arqty,counter);
	order=1;
	choice=8;
}


int hot_deals()
{
	system ("cls");
	system("color 5F");
	srand(time(NULL)); //A random number generator
	int num=(rand()%5)+1; //This will generate a number between 1-5

	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Hot Deals!!!---------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-Hurry up! When it's gone, it's gone\n\n\n");
	printf("Dear user, here's the offer for YOU ONLY:\n\n");
	if (num==1)
	{
		code=501;
		printf("Discount code:%d\nCongratulations! You've got 5%% off on your purchase.\n\n",code);
	}
	if(num==2)
	{
		code=502;
		printf("Discount code:%d\nCongratulations! You've got 3%% off on your purchase.\n\n",code);
	}
	if(num==3)
	{
		code=503;
		printf("Discount code:%d\nCongratulations! You've got 10%% discount on purchasing more than 100 BDT.\n\n",code);
	}
	if(num==4)
	{
		code=504;
		printf("Discount code:%d\nCongratulations! You've got BDT 50 off on your purchase.\nYou have to order at least BDT 150/- to enjoy the discount.\n\n",code);

	}
	if(num==5)
	{
		code=505;
		printf("Discount code:%d\nCongratulations! You've got BDT 30 off on your purchase.\nYou have to order at least BDT 90/- to enjoy the discount.\n\n",code);

	}


}

int main()
{

	home_page();
	while((choice<=8)&&(choice!=0))
	{
		switch(choice)
		{
			case 1:
				system("cls");
				system("color 30");
				printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------About Us---------------------\n");
				printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-We are always here to serve you\n\n");
				printf("----------Our story----------\n");
				printf("Our system is specially made for resident students of Daffodil International University who live in Ashuliya.\nIn our university, a large number of students come from far away.They stay in the hall or live on rent nearby.\nMany of them eat at different restaurants daily.\nWhile having food they face some challenges regularly such as consuming unhealthy foods, having a poor diet, safety issues for females, and unreasonable costs.\n\t-These thoughts led us to create a homemade food delivery service named 'LOST KITCHEN'.\n\tIt will bring back the taste, which they used to get from the kitchen of their home right next to their doorsteps within a few clicks.\n\n");
				printf("----------Our Mission----------\n");
				printf("We are committed to providing you with-\n\t~Hygenic food made with care\n\t~Food made with fresh ingredients\n\t~Fast delivery with no delivery cost at all\n\t~Offer packages maintaining proper diet chart by a certified nutritionist\n\n");
				printf("***OUR SERVICES ARE ONLY AVAILABLE IN ASHULIYA & JUST FOR THE STUDENT OF DAFFODIL INTERNATIONAL UNIVERSITY.***\n\n");
				printf("----------Our team----------\n");
				printf("Our team is consisted of a group of courageous people who have made our service successful-\n\n\t||Founder:\n\t\t~Ms. Nusrat Farzana Choudhury\n\t\t Founder, Lost Kitchen\n\t\t~Ms. Mashruba Sultana Zerin\n\t\t Founder, Lost Kitchen\n\n\t||Management Team:\n\t\t~Ms. Dr. Tasnim Zara\n\t\t Nutritionist, Lost Kitchen\n\t\t~Mr. Abin Mahmud Khan\n\t\t Manager, Lost Kitchen\n\t\t~Mr. Jamshed Uddin\n\t\t Supervisor, Lost Kitchen\n\t\t~Ms. Sheuly Khanam\n\t\t Customer support, Lost Kitchen\n\n\t||Delivery service:\n\t\t~SteadFast\n\n");
				printf("----------Contact Us----------\n");
				printf("Address-\n18/A, Prantik Road,\nCharabagh, Ashuliya,\nDhaka.\n\nPhone number-\n\t~ +88 01423272703\n\t~ +02 436183543\n\nE-mail:\nlostkitchensupport@gmail.com\n\n");

				back_exit();
				break;

			case 2:
				system("cls");
				system("color 61");
				printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------User Guides---------------------\n");
				printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-It is simple, quick but significant\n\n\n");
				printf("----------Order procedure----------");
				printf("\n\n* If you are new here, you must create an account by signing up.\nFor sign up go to:\n\thomepage-->choose 3 (Register/Log in)-->choose 1 (Sign up).\n\tThen just give some information to register.\nOr,\n\thomepage-->choose 4 (Order now)--> It'll redirect you to authentication page (as you don’t have any account)\n\t& proceed with giving some  info.");
				printf("\n\n* Congrats! You have your Lost Kitchen account. Now you can log in.\nFor log in go to:\n\thomepage-->choose 3 (Register/Log in)-->choose 2 (Log in)-->give some information to log in.\n\tYou can see an option to order if you wanna order now.\nOr,\n\thomepage-->choose 4 (Order now)-->It'll redirect you to authentication page (as you're not logged in) & proceed with giving info.\n\tYou can place an order now.");
				printf("\n\n*If you are registered and already logged in to your account, you can place your order by inputting the number of items you wanna order & serial number.");
				printf("\n\n*After placing your order you can enter the contact number through which you intend to communicate with the delivery man & desired address (must be within Ashuliya).\nYou can see your order ID, approximate delivery time, billing address & bill as well.");
				printf("\n\n\n----------Offers----------");
				printf("\n\n*If you wanna check recent offers go to Hot deals!\nFor checking offers:\n\thomepage-->choose 5 (Hot deals!!!)");
				printf("\n\n----------Have any query?\?\?----------");
				printf("\n\n*If you have questions about any of our services check out FAQs where Frequently Asked Questions by the users are listed and answered.\nFor checking out  FAQs:\n\thomepage-->choose 6  (FAQs)\n*If you further have any queries welcome to our support team. We’re eagerly waiting for a hello from you!!\nPhone number:\n\t~ +88 01423272703\n\t~ +02 436183543\nE-mail:\n\tlostkitchensupport@gmail.com");
				printf("\n\n\n----------Review----------");
				printf("\n\n*If you have something to say about our service you can directly contact us or review through this system.\nFor review:\n\thomepage-->choose 7  (Review)\n\n");
				back_exit();

				break;

			case 3:
				authentication_page();
				break;

			case 4:
				system ("cls");
				if(count_log==1)
				{
					order_now();
				}

				else
				{
					printf("\nYou need to log in first to place an order.\nRedirecting to authentication page...\nPress any key to continue...");
					getch();
					authentication_page();
				}

				break;



			case 5:
				system("cls");
				system("color 5F");
				if(code==0)
				{
					hot_deals();
				}
				else
				{
					printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Hot Deals!!!---------------------\n");
					printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-Hurry up! When it's gone, it's gone\n\n\n");
					printf("You've already checked your offer!\nYour discount code is: %d",code);
				}
				printf("\n\n");
				back_exit();
				break;

			case 6:
				system("cls");
				system("color E1");

				printf("\n\n\t\t\t\t\t\t\t\t\t\t\t----------FAQs-------------\n");
				printf("\t\t\t\t\t\t\t\t\t\t\t\t--Solutions to make things easier\n\n\n");
				printf("---Where are you situated?---\n\tWe are situated in Ashuliya. You can find more info in 'About Us' page.\n\n");
				printf("---Do you deliver outside Ashuliya?---\n\tNo.\n\n");
				printf("---How much is your delivery charge?---\n\t0 BDT. Yes, you read it right, we deliver free of cost for students of Daffodil International University.\n\n");
				printf("---Why does it always show different offers at the same time for different users?---\n\tIt's somewhat like a lottery! It depends on your luck. But you'll get at least 1 offer for sure.\n\n");
				printf("---Can I make offline purchase directly from your address?---\n\tYes.\n\n");
				printf("---What are your time for offline purchase hours?---\n\tFrom 10 am-7 pm,Saturday to Friday\n\n");
				printf("---Can I get discount on offline purchase?---\n\tNo.\n\n");
				printf("---Why is it only for DIU students?---\n\tActually, we try to provide our best services to our customers, so it initially started in a small group.\n\tStill, as we expand our branches we'll try to provide for all customers in Ashuliya or nearby.\n\n");
				printf("---How to place an order?---\n\tSo easy!!! Just check out 'User Guides'.\n\tIf you need further help, please feel free to contact us.\n\n");
				printf("---What is the approximate delivery time?---\n\t20 minutes.\n\n");
				printf("---I have encountered a bug or the system is not working---\n\tPlease send us an e-mail at lostkitchensupport@gmail.com along with screenshots of the problem with a detailed description.\n\tWe'll fix it for you ASAP.\n\n");
				printf("---My question is not listed here---\n\tIf you cannot find your query, please feel free to contact us:\n\n\tE-mail:\n\tlostkitchensupport@gmail.com\n\n\tPhone number:\n\t~ +88 014232727033\n\t~ +02 436183543\n\n");

				printf("\n\n");
				back_exit();
				break;

			case 7:
				system("cls");
				system("color DF");
				int choice7;
				char review[100];
				printf("\n\n\t\t\t\t\t\t\t\t\t\t--------------------Review--------------------\n");
				printf("\t\t\t\t\t\t\t\t\t\t\t-Reflection enables us to evaluate the experience,\n\t\t\t\t\t\t\t\t\t\t\t\tlearn from mistakes, repeat success\n\n\n");
				printf("Rate your experience with our service:\n\t1. Worst\n\t2. Bad\n\t3. Fair\n\t4. Good\n\t5. Excellent\n\nEnter your choice: ");
				scanf("%d",&choice7);
				choice7=NULL;
				printf("\n\nWanna tell more about your experience?\n\t1. Yes\n\t2. No\n\tEnter your choice: ");
				scanf("%d",&choice7);
				if(choice7==1)
				{
					printf("\nWrite here about your experince:\n");
					getchar();
					gets(review);
				}
				printf("\nGreetings from Lost Kitchen! We've received your feedback about our service.\n\n\n\t\t\t\t\t\t\t\t\t\t-----------(: Thanks for staying with us :)-----------");
				back_exit();
				break;

			case 8:
				printf("\n\nThanks for exploring our service. Hope to see you soon!\nBest wishes from Lost Kitchen team! :)\n\n\n\n");
				choice=0;
				getch();
				break;

		}

	}

}
