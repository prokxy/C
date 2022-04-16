#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    // declaration
    // player
    char yesno;
    int healthPlayer = 100;
    int healthPlayerMax = 200;
    int damagePlayer = 2;
    int defensePlayer = 0;
    int scorePlayer = 0;

    // Enemy defense
    int defenseEnemy;
    int minDefenseEnemy = 0;
    int maxDefenseEnemy = 2;
    // Enemy damage
    int damageEnemy;
    int minDamageEnemy = 1;
    int maxDamageEnemy = 3;
    // Enemy health
    int healthEnemy;
    int minHealthEnemy = 5;
    int maxHealthEnemy = 15;

    int difficultyScaling;

    char enemyNames[10][25] = {
        "Wild Boar",
        "Rat",
        "Massive Turtle",
        "Turek the Deathbringer",
        "Hypnotic Frog"};

    // Items
    int item;
    int itemValue;

    ///////////
    // START //
    ///////////
    printf("Start game?(y/n) ");
    scanf(" %c", &yesno);

    if (yesno == 'y')
    {
        while (healthPlayer > 0)
        {

            printf("Player stats: HP:%d DMG:%d DEF:%d\n", healthPlayer, damagePlayer, defensePlayer);
            {
                // Random enemy names and stats
                printf("\n%s has appeared\n", enemyNames + rand() % 4 + 0);
                healthEnemy = rand() % maxHealthEnemy + minHealthEnemy;
                damageEnemy = rand() % maxDamageEnemy + minDamageEnemy;
                defenseEnemy = rand() % maxDefenseEnemy + minDefenseEnemy;
                printf("Enemy stats: HP:%d DMG:%d DEF:%d\n", healthEnemy, damageEnemy, defenseEnemy);
            }

            // Fight
            printf("Fight?(y/n) ");
            scanf(" %c", &yesno);
            if (yesno == 'y')
            {
                while (healthEnemy > 0 && healthPlayer > 0)
                {
                    healthEnemy = healthEnemy - (damagePlayer - defenseEnemy);
                    healthPlayer = healthPlayer - (damageEnemy - defensePlayer);

                    printf("Player stats: HP:%d DMG:%d DEF:%d\n", healthPlayer, damagePlayer, defensePlayer);
                    printf("Enemy stats: HP:%d DMG:%d DEF:%d\n", healthEnemy, damageEnemy, defenseEnemy);
                }
                // Conclusion
                if (healthPlayer > minHealthEnemy)
                {
                    printf("\nYou beat the enemy\n");
                    
                    // Random Loot
                    item = rand() % 2 + 0;
                    if (item == 0)
                    {
                        itemValue = rand() % 10 + 3;
                        printf("You found a new weapon DMG:%d\n", itemValue);
                        printf("Equip?(y/n) ");
                        scanf(" %c", &yesno);
                        if (yesno == 'y')
                        {
                            damagePlayer = itemValue;
                            printf("Player stats: HP:%d DMG:%d DEF:%d\n", healthPlayer, damagePlayer, defensePlayer);
                        }
                    }
                    else if (item == 1)
                    {
                        itemValue = rand() % 25 + 15;
                        printf("You found a Potion HP:%d\n", itemValue);
                        printf("Use it?(y/n) ");
                        scanf(" %c", &yesno);
                        if (yesno == 'y')
                        {
                            healthPlayer += itemValue;
                            printf("Player stats: HP:%d DMG:%d DEF:%d\n", healthPlayer, damagePlayer, defensePlayer);
                        }
                    }
                    else
                    {
                        itemValue = rand() % 4 + 1;
                        printf("You found New Armor DEF:%d\n", itemValue);
                        printf("Equip?(y/n) ");
                        scanf(" %c", &yesno);
                        if (yesno == 'y')
                        {
                            defensePlayer = itemValue;
                            printf("Player stats: HP:%d DMG:%d DEF:%d\n", healthPlayer, damagePlayer, defensePlayer);
                        }
                    }
                }
                else
                {
                    printf("\nYou lost\n");
                    printf("Play again?(y/n) ");
                    scanf(" %c", &yesno);
                    if (yesno == 'y')
                    {
                        main();
                    }
                    else
                    {
                        exit(0);
                    }
                }
            }
            printf("Continue Journey?(y/n) ");
            scanf(" %c", &yesno);
            printf("\n");
            if (yesno == 'n')
            {
                exit(0);
            }
        }
    }
}
