#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int number, guess, nguess=0;
	srand(time(0));
	number = rand()%100 + 1;    // generates a random number between 1 to 100.
	do
	{
		printf("Guess the number between 1 to 100: ");
		scanf("%d", &guess);
		if(number>guess)
		{
			printf("Higher number please!\n");
		}
		else if(number<guess)
		{
			printf("Lower number please!\n");
		}
		else
		{
			printf("\nYou took %d attempts to find the number.\n",nguess);
		}
		nguess++;
	}while(number!=guess);
	return 0;
}
