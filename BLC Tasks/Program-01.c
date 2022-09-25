/*ID: 221-35-990
Section: B
Nusrat Farzana Choudhury*/

/*Write a C program to find the eligibility of getting scholarship for a professional course based on the following criteria:
Marks in Maths >=65
Marks in Phy >=55
Marks in Chem>=50
Total in all three subject >=190
or
Total in Math and Physics >=140*/

#include<stdio.h>
int main()
{
int math,phy,chem,total, math_phy;

printf("Enter marks in Maths: ");
scanf("%d",&math);
printf("Enter marks in Physics: ");
scanf("%d",&phy);
printf("Enter marks in Chemistry: ");
scanf("%d",&chem);
printf("\n");

total=math+phy+chem;
math_phy=math+phy;

  if((math>=65)&&(phy>=55)&&(chem>=50)&&(total>=190))
  {
	printf("ELIGIBLE for scholarship.");
  }
  else if(math_phy>=140)
  {
	printf("ELIGIBLE for scholarship.");
  }
  else
  {
	printf("NOT ELIGIBLE for scholarship.");
  }

return 0;
}

