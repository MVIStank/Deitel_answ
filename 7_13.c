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
}
void printCards(const int mix[][ARR_SIZE_COLUMN],const char *mast [], const char *card []){
  printf (" \n");
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 )
      printf ("%s of %s \n", card[j], mast[i]);
    }
  }
}
int checkPair(const int mix[][ARR_SIZE_COLUMN], const char * card []){
int mass[12]={0};
int check = 0;
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 )
            mass[j] += 1;    
    }
  }
 for (int i = 0; i < 12; i ++){
  if (mass[i] == 2){
     check = 1;
     return 1;
  }
 }
 if (check ==0)
   return 0;
}
int checkDoublePair(const int mix[][12], const char *card[]){
int mass[12]={0};
int doble = 0;
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
     return 2;
  }
}
  else
  return 0;
  
  }
int checkThreeCards(const int mix [][ARR_SIZE_COLUMN], const char *card[]){
int mass[12]={0};
int count = 0;
int match = 0;
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 ){
            mass[j] += 1;
      }      
    }
  }
  for (int i = 0; i < 12; i ++){
  if (mass[i] == 3){
     match ++;
     return 3;
  }
 }
 if (match == 0)
return 0;
}
int checkFourCards(const int mix [][12], const char *card[]){
int mass[12]={0};
int count = 0;
int match = 0;
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){
      if (mix[i][j] == 1 ){
            mass[j] += 1;
      }      
    }
  }
  for (int i = 0; i < 12; i ++){
  if (mass[i] == 4){
     match ++;
     return 4;
  }
 }
 if (match == 0)
return 0;
}
int checkFlush (const int mix [][ARR_SIZE_COLUMN], const char *card[], const char *masti[]){
int count = 0;
int res = 0;
int match = 0;
  for (int i = 0; i < ARR_SIZE_LINE; i ++){
    for ( int j = 0; j < ARR_SIZE_COLUMN; j ++ ){   
      if (mix[i][j] == 1 )
            match ++;
    }  
      if (match == FLUSH)  {
       res = 1;
       return 5;
      }
    else 
    match = 0;
    }
    if (res == 0)
    return 0;
}
int checkStraight(const int mix [][ARR_SIZE_COLUMN]){
  int count = 0;
  int s = 0;
  int t = 0;
  int light = 0;
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
  return 6;
  }
  else if (light == 0)
   count = 0;
   light = 0;
   }

   if (count != 5)
   return 0;
}
void compare(int arr1 [][ARR_SIZE_COLUMN], int arr2[][ARR_SIZE_COLUMN], const char *card[],const char *masti[]){
int cointPlayerOne = 0;
int cointPlayerTwo = 0;
cointPlayerOne +=checkPair(arr1,card);
cointPlayerTwo +=checkPair(arr2,card);
cointPlayerOne +=checkDoublePair(arr1,card);
cointPlayerTwo +=checkDoublePair(arr2,card);
cointPlayerOne +=checkThreeCards(arr1,card);
cointPlayerTwo +=checkThreeCards(arr2,card);
cointPlayerOne +=checkFourCards(arr1,card);
cointPlayerTwo +=checkFourCards(arr2,card);
cointPlayerOne +=checkFlush(arr1,card,masti);
cointPlayerTwo +=checkFlush(arr2,card,masti);
cointPlayerOne +=checkStraight(arr1);
cointPlayerTwo +=checkStraight(arr2);

printf ("\n");
 if (cointPlayerOne > cointPlayerTwo)
 printf ("Player One is win! \n");
  if (cointPlayerOne < cointPlayerTwo)
 printf ("Player Two is win! \n");
  if (cointPlayerOne == cointPlayerTwo)
 printf ("Player one is equal Player two! \n");
}

int main (int argc, char *argv[])
{  
  srand(time(NULL));
  char *masti [ARR_SIZE_LINE] ={"Worm", "Peaks", "Club", "Booby"};
  char *cards [ARR_SIZE_COLUMN] ={ "two","three", "four","five", "six", "seven", "eight","nine","ten","Valet","Qeen","King","Ace"};
   
   int arrPlayerOne [ARR_SIZE_LINE][ARR_SIZE_COLUMN];
   int arrPlayerTwo [ARR_SIZE_LINE][ARR_SIZE_COLUMN];

    printf (" \n");
    printf ("Pаздаем карты ..: \n");
    printf ("Игрок 1 получает: \n");
    mixCards (arrPlayerOne);
    printCards(arrPlayerOne,masti,cards);
    printf (" \n");
    printf ("Игрок 2 получает: \n");
    mixCards (arrPlayerTwo);
    printCards(arrPlayerTwo,masti,cards);
    compare(arrPlayerOne,arrPlayerTwo,cards,masti);
 }
