#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

struct User
{
    char name[30];
    int pin;
    int balance;
};

void playBeep()
{
    sound(1000);
    delay(100);
    nosound();
}

void showTitle()
{
    cleardevice();
    settextstyle(3, 0, 4);
    outtextxy(130, 50, "GRAPHICAL ATM SYSTEM");
    line(120, 90, 520, 90);
}

void createUser()
{
    FILE *fp = fopen("user.dat", "wb");
    struct User u;

    cleardevice();
    showTitle();
    settextstyle(2, 0, 5);
    outtextxy(100, 150, "Enter your name: ");
    gotoxy(35, 12);
    scanf("%s", u.name);
    outtextxy(100, 180, "Create 4-digit PIN: ");
    gotoxy(35, 13);
    scanf("%d", &u.pin);
    u.balance = 1000;

    fwrite(&u, sizeof(u), 1, fp);
    fclose(fp);

    outtextxy(100, 220, "Account created successfully!");
    playBeep();
    delay(1000);
}
int loginUser(struct User *u)
{
    FILE *fp = fopen("user.dat", "rb");
    int inputPin;
    if (fp == NULL)
    return 0;
    cleardevice();
    showTitle();
    settextstyle(2, 0, 5);
    outtextxy(100, 150, "Enter your 4-digit PIN: ");
    gotoxy(35, 12);
    scanf("%d", &inputPin);

    fread(u, sizeof(struct User), 1, fp);
    fclose(fp);

    if (inputPin == u->pin)
    {
	playBeep();
	return 1;
    }

    outtextxy(100, 190, "Incorrect PIN.");
    delay(1000);
    return 0;
}

void saveUser(struct User u)
{
    FILE *fp = fopen("user.dat", "wb");
    fwrite(&u, sizeof(u), 1, fp);
    fclose(fp);
}

void atmMenu(struct User *u)
{
    int choice, amount;
    char buffer[100];

    while (1)
    {
	cleardevice();
	showTitle();
	settextstyle(2, 0, 5);
	outtextxy(100, 120, "1. Check Balance");
	outtextxy(100, 150, "2. Deposit");
	outtextxy(100, 180, "3. Withdraw");
	outtextxy(100, 210, "4. Exit");
	outtextxy(100, 250, "Enter your choice: ");
	gotoxy(35, 18);
	scanf("%d", &choice);

	switch (choice)
	{
	    case 1:
		cleardevice();
		showTitle();
		sprintf(buffer, "Hello %s, Your Balance is: Rs. %d", u->name, u->balance);
		outtextxy(100, 150, buffer);
		playBeep();
		getch();
		break;
	    case 2:
		cleardevice();
		showTitle();
		outtextxy(100, 150, "Enter deposit amount: ");
		gotoxy(35, 12);
		scanf("%d", &amount);
		u->balance += amount;
		saveUser(*u);
		outtextxy(100, 190, "Deposited successfully.");
		playBeep();
		getch();
		break;
	    case 3:
		cleardevice();
		showTitle();
		outtextxy(100, 150, "Enter withdrawal amount: ");
		gotoxy(35, 12);
		scanf("%d", &amount);
		if (amount <= u->balance) {
		    u->balance -= amount;
		    saveUser(*u);
		    outtextxy(100, 190, "Please collect your cash.");
		    playBeep();
		} else {
		    outtextxy(100, 190, "Insufficient balance.");
		    sound(200);
		    delay(300);
		    nosound();
		}
		getch();
		break;
	    case 4:
		cleardevice();
		outtextxy(100, 150, "Thank you for using the ATM!");
		playBeep();
		delay(1000);
		return;
	    default:
		outtextxy(100, 250, "Invalid choice.");
		getch();
	}
    }
}

void main() {
    int gd = DETECT, gm;


    struct User currentUser;

    int choice;
     initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    while (1) {
	cleardevice();
	showTitle();
	settextstyle(2, 0, 5);
	outtextxy(100, 150, "1. Create Account");
	outtextxy(100, 180, "2. Login to ATM");
	outtextxy(100, 210, "3. Exit");
	outtextxy(100, 250, "Enter your choice: ");
	gotoxy(35, 18);
	scanf("%d", &choice);

	if (choice == 1) {
	    createUser();
	} else if (choice == 2) {
	    if (loginUser(&currentUser)) {
		atmMenu(&currentUser);
	    }
	} else if (choice == 3) {
	    closegraph();
	    exit(0);
	} else {
	    outtextxy(100, 270, "Invalid Option. Try again.");
	    getch();
	}
    }
}
