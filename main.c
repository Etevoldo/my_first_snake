#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "engine.h"

int main(void){
    char key;
    printf("Snake game\n");
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
    printf("\033[H\033[J");
    return 0;
}