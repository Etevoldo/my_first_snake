#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "engine.h"

int main(void){
    char key;
    clrscr();
    printf("Snake game\n");
    do {
        printf("Choose an option:\nS: Start game\nQ: Quit\n");
        key = getch();
        key = toupper(key);
        switch (key){
            case 'S':
                start();
                break;
            default:
                break;
        }
        clrscr();
    }while(key != 'Q');
    clrscr();
    return 0;
}