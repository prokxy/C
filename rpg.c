#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void printPlayerStats(int healthPlayer, int damagePlayer, int defensePlayer);
void printEnemyStats(int healthEnemy, int damageEnemy, int defenseEnemy);
void fightEnemy(int *healthPlayer, int damagePlayer, int defensePlayer, int *healthEnemy, int damageEnemy, int defenseEnemy);
void handleLoot(int *healthPlayer, int *damagePlayer, int *defensePlayer);

int main()
{
    srand(time(0));

    // Player stats
    int healthPlayer = 100;
    int damagePlayer = 2;
    int defensePlayer = 0;

    // Enemy stats
    int healthEnemy;
    int damageEnemy;
    int defenseEnemy;

    char enemyNames[5][25] = {
        "Wild Boar",
        "Rat",
        "Massive Turtle",
        "Turek the Deathbringer",
        "Hypnotic Frog"};

    char yesno;

    // Start game
    printf("Start game? (y/n) ");
    scanf(" %c", &yesno);

    if (yesno == 'y')
    {
        while (healthPlayer > 0)
        {
            // Print player stats
            printPlayerStats(healthPlayer, damagePlayer, defensePlayer);

            // Generate random enemy stats
            int enemyIndex = rand() % 5;
            printf("\n%s has appeared\n", enemyNames[enemyIndex]);
            healthEnemy = rand() % 11 + 5;
            damageEnemy = rand() % 3 + 1;
            defenseEnemy = rand() % 3;
            printEnemyStats(healthEnemy, damageEnemy, defenseEnemy);

            // Fight
            printf("Fight? (y/n) ");
            scanf(" %c", &yesno);
            if (yesno == 'y')
            {
                fightEnemy(&healthPlayer, damagePlayer, defensePlayer, &healthEnemy, damageEnemy, defenseEnemy);

                // Check if player won
                if (healthPlayer > 0)
                {
                    printf("\nYou beat the enemy\n");
                    handleLoot(&healthPlayer, &damagePlayer, &defensePlayer);
                }
                else
                {
                    printf("\nYou lost\n");
                    printf("Play again? (y/n) ");
                    scanf(" %c", &yesno);
                    if (yesno == 'y')
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            printf("Continue Journey? (y/n) ");
            scanf(" %c", &yesno);
            printf("\n");
            if (yesno == 'n')
            {
                break;
            }
        }
    }

    return 0;
}

void printPlayerStats(int healthPlayer, int damagePlayer, int defensePlayer)
{
    printf("Player stats: HP:%d DMG:%d DEF:%d\n", healthPlayer, damagePlayer, defensePlayer);
}

void printEnemyStats(int healthEnemy, int damageEnemy, int defenseEnemy)
{
    printf("Enemy stats: HP:%d DMG:%d DEF:%d\n", healthEnemy, damageEnemy, defenseEnemy);
}

void fightEnemy(int *healthPlayer, int damagePlayer, int defensePlayer, int *healthEnemy, int damageEnemy, int defenseEnemy)
{
    while (*healthEnemy > 0 && *healthPlayer > 0)
    {
        *healthEnemy -= damagePlayer - defenseEnemy;
        *healthPlayer -= damageEnemy - defensePlayer;

        printPlayerStats(*healthPlayer, damagePlayer, defensePlayer);
        printEnemyStats(*healthEnemy, damageEnemy, defenseEnemy);
    }
}

void handleLoot(int *healthPlayer, int *damagePlayer, int *defensePlayer)
{
    int item = rand() % 3;

    if (item == 0)
    {
        int itemValue = rand() % 10 + 3;
        printf("You found a new weapon DMG:%d\n", itemValue);
        printf("Equip? (y/n) ");
        char yesno;
        scanf(" %c", &yesno);
        if (yesno == 'y')
        {
            *damagePlayer = itemValue;
            printPlayerStats(*healthPlayer, *damagePlayer, *defensePlayer);
        }
    }
    else if (item == 1)
    {
        int itemValue = rand() % 25 + 15;
        printf("You found a Potion HP:%d\n", itemValue);
        printf("Use it? (y/n) ");
        char yesno;
        scanf(" %c", &yesno);
        if (yesno == 'y')
        {
            *healthPlayer += itemValue;
            printPlayerStats(*healthPlayer, *damagePlayer, *defensePlayer);
        }
    }
    else
    {
        int itemValue = rand() % 4 + 1;
        printf("You found New Armor DEF:%d\n", itemValue);
        printf("Equip? (y/n) ");
        char yesno;
        scanf(" %c", &yesno);
        if (yesno == 'y')
        {
            *defensePlayer = itemValue;
            printPlayerStats(*healthPlayer, *damagePlayer, *defensePlayer);
        }
    }
}

