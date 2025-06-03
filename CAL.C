#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

void welcomeScreen() {
    settextstyle(3, 0, 4);
    outtextxy(150, 100, "Simple Calculator");
    sound(1000);
    delay(300);
    nosound();
    delay(500);
    outtextxy(150, 160, "With Graphics & Sound");
    sound(1200);
    delay(300);
    nosound();
    delay(800);
    cleardevice();
}

void displayMenu() {
    settextstyle(3, 0, 2);
    outtextxy(100, 50, "Choose Operation:");
    outtextxy(100, 100, "1. Addition");
    outtextxy(100, 130, "2. Subtraction");
    outtextxy(100, 160, "3. Multiplication");
    outtextxy(100, 190, "4. Division");
    outtextxy(100, 220, "5. Exit");
}

void getNumbers(float *a, float *b) {
    char str[50];
    cleardevice();

    settextstyle(2, 0, 5);
    outtextxy(100, 100, "Enter first number: ");
    scanf("%f", a);
    sprintf(str, "First number = %.2f", *a);
    outtextxy(100, 140, str);
    sound(800); delay(150); nosound();

    outtextxy(100, 180, "Enter second number: ");
    scanf("%f", b);
    sprintf(str, "Second number = %.2f", *b);
    outtextxy(100, 220, str);
    sound(1000); delay(150); nosound();
}

void performOperation(int choice) {
    float a, b, result;
    char resStr[100];
    getNumbers(&a, &b);
    cleardevice();

    switch(choice) {
        case 1:
            result = a + b;
            sprintf(resStr, "Addition: %.2f + %.2f = %.2f", a, b, result);
            break;
        case 2:
            result = a - b;
            sprintf(resStr, "Subtraction: %.2f - %.2f = %.2f", a, b, result);
            break;
        case 3:
            result = a * b;
            sprintf(resStr, "Multiplication: %.2f * %.2f = %.2f", a, b, result);
            break;
        case 4:
            if (b != 0)
                result = a / b;
            else {
                outtextxy(100, 200, "Error: Division by zero!");
                sound(300); delay(500); nosound();
                return;
            }
            sprintf(resStr, "Division: %.2f / %.2f = %.2f", a, b, result);
            break;
        default:
            return;
    }

    settextstyle(3, 0, 2);
    outtextxy(50, 200, resStr);
    sound(1200); delay(400); nosound();
    delay(1000);
}

int main() {
    int gd = DETECT, gm;
    int choice;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    welcomeScreen();

    do {
        cleardevice();
        displayMenu();
        gotoxy(5, 17);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4)
            performOperation(choice);
    } while (choice != 5);

    closegraph();
    return 0;
}

