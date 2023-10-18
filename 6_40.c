#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define CARD 5
#define FLUSH 5
#define ARR_SIZE_LINE 4
#define ARR_SIZE_COLUMN 13

  void mixCards ( int a[][ARR_SIZE_COLUMN])
  {
    for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
    a[i][j] = 0;
    }
  } 

  printf ("Начинаем миксовать .. \n");
  srand(time(NULL));
  int count = 0;
  while ( count != CARD)
  {
    int masti = rand() % 4;
    int cards = rand() % 13;
    if (a [masti][cards] != 1)
      {
       a [masti][cards] = 1;
        count ++;
      }
  }
  printf ("готово. \n");
}
void printCards(const int mix[][ARR_SIZE_COLUMN],const char *mast [], const char *card []){
  printf ("Ваши карты: \n");
  printf (" \n");
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 )
      printf ("%s of %s \n", card[j], mast[i]);
    }
  }
}
void checkPair(const int mix[][ARR_SIZE_COLUMN], const char * card []){
int mass[12]={0};
int check = 0;
 printf ("Определяем есть ли пара ..\n");
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 )
            mass[j] += 1;    
    }
  }
 for (int i = 0; i < 12; i ++){
  if (mass[i] == 2){
     printf("Yes, Pair of %s \n", card[i]);
     check = 1;
     break;
  }
 }
 if (check ==0)
     printf("No \n");
}
void checkDoublePair(const int mix[][12], const char *card[]){
int mass[12]={0};
int doble = 0;
 printf ("Определяем есть ли две пары ..\n");
   for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 ){
            mass[j] += 1;
      }      
    }
  }
  
 for (int i = 0; i < 12; i ++){
  if (mass[i] == 2)
     doble ++;
 }

if (doble == 2){
  for (int i = 0; i < 12; i ++){
  if (mass[i] == 2)
     printf("Yes, Pair of %s \n", card[i]); 
  }
}
  else
  printf ("No \n");
  
  }
void checkThreeCards(const int mix [][ARR_SIZE_COLUMN], const char *card[]){
int mass[12]={0};
int count = 0;
int match = 0;
 printf ("Определяем есть ли тройка ..\n");
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 ){
            mass[j] += 1;
      }      
    }
  }
  for (int i = 0; i < 12; i ++){
  if (mass[i] == 3){
     printf("Yes, Three of a kind is %s \n", card[i]);
     match ++;
  }
 }
 if (match == 0)
 printf ("No \n");
}
void checkFourCards(const int mix [][12], const char *card[]){
int mass[12]={0};
int count = 0;
int match = 0;
 printf ("Определяем есть ли каре ..\n");
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 ){
            mass[j] += 1;
      }      
    }
  }
  for (int i = 0; i < 12; i ++){
  if (mass[i] == 4){
     printf("Yes, Four of a kind is %s \n", card[i]);
     match ++;
  }
 }
 if (match == 0)
 printf ("No \n");
}
void checkFlush (const int mix [][ARR_SIZE_COLUMN], const char *card[], const char *masti[]){
int count = 0;
int res = 0;
int match = 0;
 printf ("Определяем есть ли флэш ..\n");
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){   
      if (mix[i][j] == 1 )
            match ++;
    }  
      if (match == FLUSH)  {
       printf ("Yes, It's Flush of %s \n", masti[i]);    
       res = 1;
      }
    else 
    match = 0;
    }
    if (res == 0)
    printf ("No \n");
}
void checkStraight(const int mix [][ARR_SIZE_COLUMN]){
  int count = 0;
   int s = 0;
    int t = 0;
    int light = 0;
    printf ("Определяем есть ли стрит ..\n");
   for (; s < 12; s++){
   for (; t < 4; t++){
    if (mix[t][s] == 1 )
    {
      count ++;
      light ++;
      break;
    }
   }
   t = 0;
  if (count == 5){
  printf ("It's Straight! \n");
  break;
  }
  else if (light == 0)
   count = 0;
   light = 0;
   }

   if (count != 5)
   printf ("No  \n");
}

int main (int argc, char *argv[])
{  

  char *masti [ARR_SIZE_LINE] ={"Worm", "Peaks", "Club", "Booby"};
  char *cards [ARR_SIZE_COLUMN] ={ "two","three", "four","five", "six", "seven", "eight","nine","ten","Valet","Qeen","King","Ace"};
   
   int mix [4][ARR_SIZE_COLUMN];
   int menu = 0;
  while (menu != 9){
    printf (" \n");
    printf ("Выбирите пункт меню: \n");
    printf (" 1. Миксуем карты \n");
    printf (" 2. Показать карты \n");
    printf (" 3. Определить пару \n");
    printf (" 4. Определить две пары\n");
    printf (" 5. Определяем три пары \n");
    printf (" 6. Определить Каре \n");
    printf (" 7. Определить Флэш \n");
    printf (" 8. Определить Стрит \n");
    printf (" 9. Выход \n");
    scanf ("%d" , &menu);
   switch (menu)
    {
    case 1:
      mixCards(mix);
      break;
    case 2:
      printCards(mix, masti, cards);
      break;
    case 3:
      checkPair(mix,cards);
      break;
    case 4:
      checkDoublePair(mix,cards);
      break;
    case 5:
      checkThreeCards(mix,cards);
      break;
    case 6:
      checkFourCards(mix,cards);
      break;
    case 7:
      checkFlush(mix,cards,masti);
      break;
    case 8:
      checkStraight(mix);
      break;
    case 9:
      menu = 9;
      break;
    default:
    printf ("Нет такого пункта меню..\n");
    }
  }
 }
