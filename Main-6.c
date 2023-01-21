#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct 
	{
		int hit;
		int armor;
		int experience;
	} enemy;

int RandomInt(int min, int max)
{
	int range = (max - min) + 1;
	int value = rand() % range + min;

	return value;
}

void main()
{
	int numOfEnemies = 0;
	int totalSum = 0;
	srand(time(NULL));
	printf("Enter number of enemies: ");
	scanf("%i", &numOfEnemies);

	enemy* enemyArray;
	enemyArray = (enemy*)calloc(sizeof(enemy), numOfEnemies);

	for (int i = 0; i < numOfEnemies; i++)
	{
		enemyArray[i].hit = RandomInt(50, 100);
		enemyArray[i].armor = RandomInt(12, 22);
		enemyArray[i].experience = (enemyArray[i].hit * enemyArray[i].armor) / 50;
		totalSum += enemyArray[i].experience;
		printf("Created enemy: %i\t Hit Points: %i\t Armor: %i\t Experience Points: %i\n",
			i,
			enemyArray[i].hit,
			enemyArray[i].armor,
			enemyArray[i].experience
			);

	}
	printf("Total XP for this level: %i", totalSum);

	free(enemyArray);
}