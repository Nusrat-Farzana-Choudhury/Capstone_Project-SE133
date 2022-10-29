/*ID: 221-35-990
Nusrat Farzana Choudhury*/
/*Problem-2: Take user input for adding two distances in inch-feet system*/

#include <stdio.h>

struct Distance {
   int feet;
   float inch;
} d1, d2, result;

int main() {
   // taking first distance input
   printf("Enter 1st distance:\n");
   printf("-------------------\n");
   printf("\tEnter feet: ");
   scanf("%d", &d1.feet);
   printf("\tEnter inch: ");
   scanf("%f", &d1.inch);
 
   // taking second distance input
   printf("\nEnter 2nd distance:\n");
   printf("---------------------\n");
   printf("\tEnter feet: ");
   scanf("%d", &d2.feet);
   printf("\tEnter inch: ");
   scanf("%f", &d2.inch);
   
   // adding distances
   result.feet = d1.feet + d2.feet;
   result.inch = d1.inch + d2.inch;

   // converting inches to feet if greater than 12
   while (result.inch >= 12.0) 
   {
      result.inch = result.inch - 12.0;
      result.feet++; //as 12 inches=1 feet, so feet incremented by 1
   }
   printf("\nSum of distances = %d\'-%.1f\"", result.feet, result.inch);
   return 0;
}
