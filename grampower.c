#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int parseForHello(char);
int next_state(int , char , int , char *);

int main(){
	char* string="gffthghelloopopk";  //initial hard coding input
	int i=0;
	while(1){
		char c=string[i];
		int helloFound= parseForHello(c);

		if(helloFound){
			printf("\nFound\n");
			break;
		}

		i++;
	}
		return 0;
}


int parseForHello(char c)
{
/*
Function to return 1/0 for presence of 'hello' in string
*/
    char string[]="hello";
    int success_state= strlen(string);
    static int state=0;
    char *ptr=&string[0];
    state=next_state(state, c, success_state, ptr);
    if(state==success_state)
    {
        state=0;
        return 1;
    }
    else
        return 0;
}

int next_state(int state, char c, int success_state, char *ptr)
/*
Function to return next state of FSM based on current state and input
*/
{
    int i;
    for(i=0; i<success_state; i++)
    {
        if(state==i)
        {
            if(*(ptr+i)==c)
            {
                state++;
                break;
            }
            else if(c==*ptr)
            {
                state=0;
                i=-1;
                continue;

            }
            else break;
        }

        else continue;

    }
    return (state);
}



