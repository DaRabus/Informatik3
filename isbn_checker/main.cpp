#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

using namespace std;
//9780306406157

char askforISBN(char abfrage[]) { //Function for requesting ISBN from User
    printf ("Please enter your ISBN-13: ");
    cin.getline(abfrage, 20); //Scanf alternative

    return *abfrage;
}

char filterstring(char tobefiltered[20]){
    char filtered[13];
    int stringcounter = 0;
    for(int i = 0; tobefiltered[i] != '\0'; ++i) //Sorting the string for the numbers
    {
        if (tobefiltered[i] >= '0' && tobefiltered[i]<='9')
        {
            filtered[stringcounter++] = tobefiltered[i];
        }
    }
    filtered[stringcounter] = '\0'; //Restrict the array to the 12 digits
    return *filtered;
}

int main()
{

    char Input_ISBN[20];
    int Int_ISBN[12];
    float divider = 10;
    int checksumfinal = 0;


    askforISBN(Input_ISBN);
    filterstring(Input_ISBN);

    for (int i=0; i<=11; i++){ //Change the array to an int array
            Int_ISBN[i] = Input_ISBN[i] - '0'; }

    printf("Your ISBN without the checksum is:"); //Printout the ISBN for check
    for (int i=0; i < 12; i++) {
            printf("%d", Int_ISBN[i]);
        }
    printf("\n");

    /* Multiply by 1 for calculating the checksum*/
    for (int i=0; i<=11; i=i+2){
        checksumfinal = checksumfinal + Int_ISBN[i];
    }

    /* Multiply by 3 */
    for (int i=1; i<=12; i=i+2){
        checksumfinal = checksumfinal + ((Int_ISBN[i])*3);
    }

    printf("Your checksum for the last number is: %d \n" , checksumfinal);

    float missdigit = (float)checksumfinal / divider; //get digit down to float

   float numberleft = ceil(missdigit)*divider - checksumfinal; //Calculate the checksum

    printf("Your 13th Number should be %2.f" ,numberleft); //Printout checksum
}
