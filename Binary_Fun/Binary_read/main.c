#include <stdio.h>

typedef struct{
    int identifier;
    char name[30];
    char occupation[30];
    int salary;
}PEOPLE;


int main() {
    FILE *ftxt, *fbin;

    ftxt = fopen("File_View.txt", "w");
    if(ftxt == NULL){
        perror("Can't create text file");
        return -1;
    } printf("\nSucces! Text file created");

    fbin = fopen("binary", "rb");
    if(fbin == NULL){
        perror("Failed to import binary file");
        return -1;
    }printf("\nSucces! Binary file opened");

    PEOPLE variable;

    fprintf(ftxt, "\nIdentifier Name %10s Occupation Salary", " ");
    fread(&variable, sizeof(PEOPLE), 1, fbin);

    while(!feof(fbin)){
        fprintf(ftxt, "\n%d %15s %3s %3d", variable.identifier, variable.name, variable.occupation, variable.salary);
        fread(&variable, sizeof(PEOPLE), 1, fbin);
    }
    printf("\n\nCheck text file to see your data! Have a nice day");
    fclose(ftxt);
    fclose(fbin);
    return 0;
}