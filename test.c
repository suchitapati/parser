#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "test.h"
#include "main.h"

#define BUF_SIZE 100

void generateRandomString(char *, int, int);
char *randomStringAtEnd(char *);
char *randomStringAtStart(char *);
void test_1(char*);
void test_2(char*);
void test_3(char*);
void test_4(char*);

void generateRandomString(char *buffer, int startIndex, int lastIndex)
{
	srand(time(NULL));
	int i=lastIndex;
	while(i >= startIndex) {
		int randNum = random() % 52;
		char c=' ';

		if(randNum > 26) {
			c='A' + randNum - 26;	/* generate characters 'A' to 'Z' */
		}else {
			c='a' + randNum; /* generate lowercase characters */
		}

		buffer[i] =c;
		i--;
	}

}

char *randomStringAtEnd(char *token) {
	static char buffer[BUF_SIZE];
	strcpy(buffer, token);
	generateRandomString(buffer, strlen(token), BUF_SIZE - 1);
	buffer[BUF_SIZE-1]='\0';
	return buffer;
}

char *randomStringAtStart(char *token) {
	static char buffer[BUF_SIZE];
	strcpy(buffer,token);
	generateRandomString(buffer, 0, BUF_SIZE-strlen(token) - 1);
	strcpy(buffer + BUF_SIZE -strlen(token) - 1, token);
	buffer[BUF_SIZE-1]='\0';
	return buffer;
}


void test_4(char *string)
{
	char test[BUF_SIZE];
	int i;
	strcpy(test,"ertyuiokjhgfdtyujnbvgfdwertyui");
	int hellofound;
	for(i=0;i<strlen(test);i++)
	{
		hellofound=parseForHello(test[i]);
		if(hellofound)
		{
			printf("\nTestCase4 failed\n");
			break;
		}
	}
	if(i==strlen(test)&&(hellofound==0))
		printf("\nNot Found\nTestCase4 passed\n");



}




void test_3(char *string)
{
	char test[BUF_SIZE];
	int i;
	strcpy(test,"hhehelhellhellohhehelhellhello");
	int hellofound;
	for(i=0;i<strlen(test);i++)
	{
		hellofound=parseForHello(test[i]);
		if(hellofound)
		{
			printf("\nFound\n");
			break;
		}
	}
	if((i==14)&& hellofound)
		printf("\nTestCase3 passed\n");
	else
		printf("\nTestCase3 failed\n");


}


void test_2(char *string)
{
	char test[BUF_SIZE];
	int i;
	strcpy(test,randomStringAtStart(string));
	int hellofound;
	for(i=0;i<BUF_SIZE;i++)
	{
		hellofound=parseForHello(test[i]);
		if(hellofound)
		{
			printf("\nFound");
			break;
		}
	}
	if((i==strlen(test)-1) && hellofound)
		printf("\nTestCase2 passed\n");
	else
		printf("\nTestCase2 failed\n");


}


void test_1(char *string)
{
	char test[BUF_SIZE];
	int i;
	strcpy(test,randomStringAtEnd(string));
	int hellofound;
	for(i=0;i<BUF_SIZE;i++)
	{
		hellofound=parseForHello(test[i]);
		if(hellofound)
		{
			printf("\nFound\n");
			break;
		}
	}
	if(i==4)
		printf("\nTestCase1 passed\n");
	else
		printf("\nTestCase1 failed\n");


}


void testDriver() {
char string[]="hello";
test_1(string);
test_2(string);
test_3(string);
test_4(string);
}



