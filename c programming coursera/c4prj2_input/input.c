/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "input.h"
#include "future.h"
#include "deck.h"
#include "cards.h"

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t *ans=malloc(sizeof(*ans));
  assert(ans!=NULL);
  ans->cards=NULL;
  ans->n_cards=0;
  size_t i=0;
  while(str[i]!='\0'){
    if(str[i]=='?' && isdigit(str[i+1])){
      char *number=malloc(2*sizeof(*number));
      assert(number!=NULL);
      size_t j=0;
      number[j++]=str[i+1];
      number[j]='\0';
      if(isdigit(str[i+2])){
	number=realloc(number,3*sizeof(*number));
	assert(number!=NULL);
	number[j++]=str[i+2];
	number[j]='\0';
	i++;
      }
      add_future_card(fc,atoi(number),add_empty_card(ans));
      free(number);
    }
    else if((isdigit(str[i]) || str[i]=='A' || str[i]=='K' || str[i]=='Q' || str[i]=='J') && (str[i+1]=='s' || str[i+1]=='h' || str[i+1]=='d' || str[i+1]=='c')){
      add_card_to(ans,card_from_letters(str[i],str[i+1]));
    }
    else{
      fprintf(stderr,"Error: Invalid input file format, line %s",str);
      card_from_letters(0,0);
    }
    i++;
    while(isspace(str[i+1]) && str[i+1]!='\0'){
      i++;
    }
    /*else if(str[i+1]=='\0'){
      break;
    }
    else{
      fprintf(stderr,"Error: Invalid input file format, line '%s'\n",str);
      card_from_letters(0,0);
      }
    i++;
  }
  return ans;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  deck_t **ans=NULL;
  n_hands=0;

  char *line=NULL;
  size_t sz=0;
  while(getline(&line,&sz,f)>=0){
    char *p=strchr(line,'\n');
    if(p!=NULL){
      *p='\0';
    }
    else{
      fprintf(stderr,"Error: Invalid line '%s' in input file!\n",line);
      assert(p!=NULL);
    }
    ans=realloc(ans,((*n_hands)+1)*sizeof(*ans));
    assert(ans!=NULL);
    (*n_hands)++;
    ans[(*n_hands)-1]=hand_from_string(line,fc);
    if(ans[(*n_hands)-1]->n_cards<5){
      fprintf(stderr,"Error: Invalid number of cards in input file\n");
      assert(ans[(*n_hands)-1]->n_cards>=5);
    }
    free(line);
    sz=0;
  }
  free(line);

  return ans;
}
*/
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"
deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t* deck=malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards=0;
  for(int i=0;i<strlen(str);i++){
    if((str[i] == '\n')||(str[i] == ' '))continue;
    else{
      if(str[i] == '?'){
	i++;
	char num[strlen(str)];
	int n=0;
	while(!((str[i] == '\n')||(str[i] == ' '))) {
	  num[n]=str[i];
	  i++;n++;}
	num[n]='\0';
	add_future_card(fc,atoi(num),add_empty_card(deck)) ;

      }
      else{
	card_t x = card_from_letters(str[i],str[i+1]);
	add_card_to(deck,x);
	i++;}
    }
  }
  if (deck->n_cards < 5 ){
    return NULL;
    fprintf(stderr,"asas");}
  return deck;
}
deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  deck_t **arr=NULL;
  size_t n_hand=0;
  char *line=NULL;
  size_t sz=0;
  while(getline(&line,&sz,f)>=0){
    arr=realloc(arr,(n_hand+1)*sizeof(*arr));
    deck_t*deck=hand_from_string(line,fc);
    if (deck == NULL)continue;
    arr[n_hand]=deck;
    n_hand ++;
  }
  free(line);
  *n_hands=n_hand;
  return arr;
}
