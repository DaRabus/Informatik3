/* Lösung.cpp

Autor: Rabus Dominik
Version: 0.1
Date: 24.09.2019
Changes:
Excercise 1 Chiffre
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string>
#include <limits>

using namespace std;

int userchoice = 0;
char output[100];

void caesar_chiffre_encrypt(char *input, int shift){
    if (userchoice == 1){
        for (int i=0; i<100; i++){
            if(input[i]>='a' && input[i]<='z') {
                int tempAsciiCode = input[i];

                // in case we would count over z, we start by a again.
                output[i] = ((tempAsciiCode + shift - 97) % 26) + 97;
            } else if(input[i]>=' ') {
                        output[i] = input[i];
                    }
 }

    }
    }



void askforinput() { //Function for requesting input from User
    char user_input[100];
    int shift;
    cout << "Please enter your text to decrypt/encrypt:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(user_input , 100);

    printf ("Please enter your shift from 1-99: ");
    cin >> shift;
    caesar_chiffre_encrypt(user_input, shift);
}



int main()
{

    printf("Excuse me Sir, may you choose your option: \n");
    cout << endl;
        cout << "- Caesar Ciffre Tool -  v1.0" << endl << endl;
        cout << "Menueauswahl:" << endl;
        cout << "Encrypt/Decrypt Message   [1]" << endl;
        cout << "Exit              [3]" << endl << endl;
        cout << "Please choose wisly: ";
        cin  >> userchoice;

        do{
        switch(userchoice)
        {
          case 1:
            askforinput();
         cout << "Your encrypted Message is: " << endl << output << endl;
        output == NULL;
        cout << "Encrypt/Decrypt Message   [1]" << endl;
        cout << "Exit              [3]" << endl << endl;
        cin  >> userchoice;
                  break;
        }
        }while(userchoice != 3);
printf("Goodbye \n");
return 0;





}
