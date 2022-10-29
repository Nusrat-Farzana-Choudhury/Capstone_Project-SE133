/*ID: 221-35-990
Nusrat Farzana Choudhury*/
/*Problem-2: Take user input for storing Name, SGPA of students in a structure & show the output.*/

#include <stdio.h>
struct result {
    char name[30];
    double SGPA;
};

int main()

{
    int i, n;
    
    //taking user input for no. of nodes to be stored
    printf("How many students' data do you wanna insert?\n");
    scanf("%d",&n);
    printf("\n");
    struct result student[n];
    
    //taking user input for each node
    for(i=0;i<n;i++)
    { 
        printf("Insert the data for Student-%d:\n",i+1);
        printf("\tName: ");
        scanf("%s", &student[i].name);
        printf("\tSGPA: ");
        scanf("%lf",&student[i].SGPA);
        
    }
    printf("\nThe reult of %d students are as below:\n",n);
    //printing the output
    for(i=0; i<n; i++)
    {
    printf("%s \t %.2lf \n", student[i].name, student[i].SGPA);
    }
    return 0;
}
