#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


int Bill_show(int arID[],int arqty[],int counter)
{

    int n;
    int i,sum=0;
    int costs[30]= {10,10,10,10,15,30,10,15,10,15,20,40,65,55,90,20,40,40,15,10,10,10,10,30,30,30,10,25,25,15};
    char items[30][16]= {"Rooti","Paratha","Daal","Sobji","Omlette","Khichuri","Cha","Coffee","Singara","Samusa","Rice","Chicken (Half)","Chicken (Full)","Beef (Half)","Beef (Full)","Egg Curry","Fish Curry","Fish Fry","Mixed Sobji","Aloo Vorta","Mach Vorta","Shutki Vorta","Daal","Kheer","Roshmalai","Doi","Rosogolla","Coca-cola","Mirinda","Mineral Water"};
    printf("\n\nHere's your bill:\n\n\n\t\tItem(s)\t\t     Quantity\t\t    Cost\n\n\n\n");

    for(i=0; i<counter; i++)
    {
        printf("\t%2d. %-16s ________\t%-5d piece(s) ____ %7d\n",i+1,items[arID[i]-1],arqty[i],arqty[i]*costs[arID[i]-1]);
        sum=sum+(costs[arID[i]-1]*arqty[i]);
    }
    
    /*if(code==501){
        discount=sum*0.05;
    	sum2=sum-discount;
	}
    if(code==502){
        discount=sum*0.03;
    	sum2=sum-discount;
	}
	if(code==503){
	    discount=sum*0.01;
    	sum2=sum-discount;
	}
	if((code==504) && (sum>=150)){
	    discount=50;
    	sum2=sum-discount;
	}
	if((code==505)&& (sum>=90)){
	    discount=30;
    	sum2=sum-discount;
	}*/
    printf("\n\n\n\n\t\t\t\t\t\t\t  Total = %d\n\n\n\n",sum);
    
    printf("Billing address (in Ashuliya)\t:\n");
    //printf("Name\t:%s\nAddress\t:%s\nPhone\t:%s",name,address,contact);
    printf("Payment method\t\t\t: COD\n\n");
    
    printf("Thanks for your order. Soon you'll get a call from our representative.\nYour food will be delivered in 20-30 minutes after confirmation.\n\n");


}
/*void order_now{

}*/
int main()
{
	int arID[30],decision,arqty[10],Bill[10],counter=0;
	char address[100], contact[20];
	
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Order Now!!!---------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-Fresh flavour at the best rate!\n\n\n");
    
    /*if (!((code>500)&& (code<506))){
    printf("You haven't checked your offer yet. Redirecting you to 'Hot deals'.");
    hot_deals(code);
	}
	/else{
	printf("Your discount code is %d",code);
    }
	if(code==504)
	printf("You have to order at least BDT 150/- to enjoy the discount.");
	if(code==505)
	printf("You have to order at least BDT 90/- to enjoy the discount.");
	*/
	
	system("cls");
	system("color B0");
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t---------------------Order Now!!!---------------------\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t-Fresh flavour at the best rate!\n\n\n");
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
        
        if(arID[counter-1]==0){
            break;
        }
        else if((arID[counter-1]<0)||(arID[counter-1]>30)){
            printf("\t\t Wrong food ID!!!\n");
            counter--;
        }
        else if(!((arID[counter-1]<0)||(arID[counter-1]>30))){
        	printf("\t Enter Quantity\t\t: ");
            scanf("%d",&arqty[counter-1]);
		}
        

    }
    counter--;
    system("cls");
    system("color 90");
    printf("\nEnter your adddress\t\t\t\t: ");
    gets(address); //Error: gets() not working here
    printf("\nEnter your contact no. for confirmation\t\t: ");
    gets(contact);
    
    system("cls");
    system("color B0");
    Bill_show(arID,arqty,counter);
    

}
