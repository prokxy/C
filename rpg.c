#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
//declaration
  //player
  char yesno;
  int healthPlayer = 100;
  int healthPlayerMax = 100;
  int damagePlayer = 2;
  int defensePlayer = 0;
  int scorePlayer = 0;
  
  //Enemy defense
  int defenseEnemy;
  int minDefenseEnemy = 0;
  int maxDefenseEnemy = 2;
  //Enemy damage
  int damageEnemy;
  int minDamageEnemy = 1;
  int maxDamageEnemy = 3;
  //Enemy health
  int healthEnemy;
  int minHealthEnemy = 5;
  int maxHealthEnemy = 15;
  
  int difficultyScaling;
  
  char enemyNames[10][25] = {
                              "Wild Boar",
                              "Rat",
                              "Massive Turtle",
                              "Turek the Deathbringer",
                              "Hypnotic Frog"
                            };
  
  //Items
  char item[1][20];
  int itemValue;
  char items[3][20] = {
                              "Health Potion HP:",
                              "Weapon DMG:",
                              "Armor DEF:"
                          };
  int damageWeapon = 5;
  
  srand(time(0));
  
//start
  printf("Start game?(y/n) ");
  scanf(" %c", &yesno);

  if(yesno == 'y') {
      printf("Player stats: HP:%d DMG:%d DEF:%d\n",
	      healthPlayer, damagePlayer, defensePlayer);
      
      printf("\nDivoka stonozka se objevila\n");
      printf("Enemy stats: HP:%d DMG:%d DEF:%d\n",
	      minHealthEnemy, minDamageEnemy, minDefenseEnemy);
      
//Fight
      printf("Fight?(y/n) ");            
      scanf(" %c", &yesno);
      if(yesno == 'y') {     
          while (minHealthEnemy > 0 && healthPlayer > 0){
	      minHealthEnemy = minHealthEnemy - (damagePlayer - minDefenseEnemy);
	      healthPlayer = healthPlayer - (minDamageEnemy - defensePlayer);
	      
	      printf("Player stats: HP:%d DMG:%d DEF:%d\n",healthPlayer, damagePlayer, defensePlayer);
	      printf("Enemy stats: HP:%d DMG:%d DEF:%d\n",minHealthEnemy, minDamageEnemy, minDefenseEnemy);
          }
//Conclusion
          if( healthPlayer > minHealthEnemy){
              printf("\nYou beat the enemy\n");
          } else {
              printf("\nYou lost\n");
              printf("Play again?(y/n) ");
              scanf(" %c", &yesno);
              if(yesno == 'y'){
                  main();
              }
          }
      }
//Finding a weapon
      printf("\nYou found a weapon DMG:%d\n", damageWeapon);
      printf("Equip?(y/n) ");
      scanf(" %c", &yesno);
      if(yesno == 'y') {
          damagePlayer = damageWeapon;
          printf("Player stats: HP:%d DMG:%d DEF:%d\n",
	      healthPlayer, damagePlayer, defensePlayer);
      }
///////////////
// REAL GAME // 
///////////////
     printf("Continue journey?(y/n)");
     scanf(" %c", &yesno);
     if(yesno == 'y'){
     //Random enemy names and stats
        printf("\n%s has appeared\n", enemyNames + rand()%4 + 0);
        healthEnemy = rand()%maxHealthEnemy + minHealthEnemy;
        damageEnemy = rand()%maxDamageEnemy + minDamageEnemy;
        defenseEnemy = rand()%maxDefenseEnemy + minDefenseEnemy;
        printf("Enemy stats: HP:%d DMG:%d DEF:%d\n",healthEnemy, damageEnemy, defenseEnemy);
     
     } else {
        printf("\nThanks for playing the game!\n");
        printf("Player stats: HP:%d DMG:%d DEF:%d\n",
	      healthPlayer, damagePlayer, defensePlayer);
     }
     
//Fight
     printf("Fight?(y/n) ");            
     scanf(" %c", &yesno);
     if(yesno == 'y') {     
          while (healthEnemy > 0 && healthPlayer > 0){
	      healthEnemy = healthEnemy - (damagePlayer - defenseEnemy);
	      healthPlayer = healthPlayer - (damageEnemy - defensePlayer);
	      
	      printf("Player stats: HP:%d DMG:%d DEF:%d\n",healthPlayer, damagePlayer, defensePlayer);
	      printf("Enemy stats: HP:%d DMG:%d DEF:%d\n",healthEnemy, damageEnemy, defenseEnemy);
          }
     }
//Conclusion
      if( healthPlayer > minHealthEnemy){
          printf("\nYou beat the enemy\n");
      } else {
          printf("\nYou lost\n");
          printf("Play again?(y/n) ");
          scanf(" %c", &yesno);
          if(yesno == 'y'){
              main();
          }
      }
//Finding an item //TODO
/*
      item = items[rand()% 3 + 0];
      
      if(item == item[){
          itemValue = rand()%25 + 15;
      } else if(item == "Weapon DMG:") {
          itemValue = rand()%10 + 4;          
      } else {
          itemValue = rand()%3 + 1;
      }
      printf("\nYou found a %s %d\n", items + rand()%2 + 0, itemValue);
      printf("Equip?(y/n) ");
      scanf(" %c", &yesno);
      if(yesno == 'y') {
          if(item == "Health Potion HP:"){
              itemValue = rand()%25 + 15;//TODO
          } else if(item == "Weapon DMG:") {
              damagePlayer = itemValue;         
          } else {
              defensePlayer = itemValue;
          }
      }
  }
}
