#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
int count_log;
struct login {
    char fname [100];
    char lname[100];
    char username[100];
    char studentmail[100];
    char phonenumber[20];
    char studentid[10];
    char password[20];

};
void takepassword(char pwd[20]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}
registration ()
{
	char password2[30];
    FILE*log;
    log=fopen("login.txt","w");
    struct login l;
    printf("Enter your first name\t: ");
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
	if(!strcmp(l.password,password2)){
				
				fwrite(&l,sizeof (l),1,log);
                fclose(log);
                printf("\n\nUser resgistration successful, Your username is %s\n",l.username);
			}
			else{
				printf("\n\nPassword do not matched.\n");
				Beep(750,300);
				printf("\nPlease complete the process carefully.");
				printf("\n\n");
				registration();
			}
	
    
}
int login()
{
    char username[100], password [100];
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
            printf("\nYou're logged in successfully!!!");
            count_log=1; //verify if order now can be applicable
            /*printf("\n\nDo you want to order now?");
             printf("\nPress 1 for yes:");
             scanf("%d",&opt5);
             if((opt5==1)&&(501<=code<=504)){
             //order_now();
             }
             if((opt5==1)&&(!(501<=code<=504)){
             //hot_deals();
               order_now();
               
             }*/
        }
        else{
        	printf("\nInvalid username or password.");
		}
    }
    fclose(log);
}
int main() //int authentication_page(){ }
{
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
        if(opt3_1==1){
    	system("cls");
    	login();
    	
	}
    
    /*else if(opt3_1==2)
    authentication_page();
    else if(opt3_1==3)
    home_page();*/
    else if(opt3_1==0)
    return 0;
    }
    else if(opt3==2)
    {
        system ("cls");
        login();
        /*printf("Press 1 to back to authentication page\nor, 0 to exit);
        int opt3_2;
		scanf("%d,&opt3_2);
		if(opt3_2==0)
		authentication_page();
		else if(opt3_2==0)
		return 0;
		*/
    }
    /*else if(opt3==3){
    	home_page();
	}*/
	else if (opt3==4){
		return 0;
	}
}
