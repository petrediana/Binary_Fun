#include <stdio.h>

typedef struct{
    int identifier;
    char name[30];
    char occupation[30];
    int salary;
}PEOPLE;

int main() {
    FILE *fbin;

    fbin = fopen("binary", "wb");
    if(fbin == NULL){
        perror("Can't create binary file");
        return -1;
    }
    printf("Succes, binary file created!\n");
    fseek(fbin, 0, 0);

    PEOPLE variable;
    char y_n, stop;
    stop = 0;

    printf("Identifier: ");
    scanf("%d", &variable.identifier);
   // fprintf(ftxt, "%d", variable.identifier);

    while(stop != 1){
        fflush(stdin);
        printf("Name: ");
        gets(variable.name);
        //fprintf(ftxt, "%s", variable.name);

        fflush(stdin);
        printf("Occupation: ");
        gets(variable.occupation);
        //fprintf(ftxt, "%s", variable.occupation);

        fflush(stdin);
        printf("Salary(euro): ");
        scanf("%d", &variable.salary);
        //fprintf(ftxt, "%d", variable.salary);
        fflush(stdin);

        fwrite(&variable, sizeof(PEOPLE), 1, fbin);


        printf("\nAdd a new person? (y/n): ");
        scanf("%c", &y_n);

        if(y_n == 'n') {
            stop = 1;
            printf("File is done!");
        }
        else{
            printf("\nIdentifier: ");
            scanf("%d", &variable.identifier);
           //fprintf(ftxt, "%d", variable.identifier);
        }
    }

    printf(" Binary file contains: %ld elements", ftell(fbin)/sizeof(PEOPLE));
    fclose(fbin);
    return 0;
}