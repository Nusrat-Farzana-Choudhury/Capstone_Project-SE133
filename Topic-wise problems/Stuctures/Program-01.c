/*ID: 221-35-990
Nusrat Farzana Choudhury*/
/*Problem-1: Store SGPA of 5 students in a structure & show the output*/

#include <stdio.h>
struct result {
    char name[30];
    float SGPA;
};

int main()
{
    struct result student1={"Tiyasha", 3.88};
    struct result student2={"Asha", 3.81};
    struct result student3={"Maria", 3.98};
    struct result student4={"Tania", 3.77};
    struct result student5={"Rafa", 3.65};
    
    printf("The reult of 5 students are as below:\n");
    printf("%s \t %.2f \n", student1.name, student1.SGPA);
    printf("%s \t\t %.2f \n", student2.name, student2.SGPA);
    printf("%s \t\t %.2f \n", student3.name, student3.SGPA);
    printf("%s \t\t %.2f \n", student4.name, student4.SGPA);
    printf("%s \t\t %.2f \n", student5.name, student5.SGPA);
    
    return 0;
}
