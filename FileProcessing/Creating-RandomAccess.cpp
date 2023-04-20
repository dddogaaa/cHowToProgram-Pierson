// Fig. 11.10: fig11_10.c (Creating a random-access file sequentially)

#include <stdio.h>

struct clientData {
    unsigned int acctNum;
    char lastName[15];
    char firstName[10];
    double balance;
};

typedef struct clientData Client; //Additionally

int main(void)
{
    FILE *cfPtr;

    cfPtr = fopen("accounts.dat","wb");

    if(cfPtr == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        Client blankClient = {0,"","",0.0}; //whose do not use additional line, alway use struct clientData instead Client.
        
        for(unsigned int i = 0; i<=100; i++)
        {
            fwrite(&blankClient,sizeof(Client),1,cfPtr);
        }
        fclose(cfPtr);
    }
    return 0;
}