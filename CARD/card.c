#include "card.h"
#include <stdio.h>
#include <string.h>


EN_cardError_t getCardHolderName(ST_cardData_t*cardData){
    
    printf("please enter card name: ");
   scanf("%[^\n]s",cardData->cardHolderName);
    
    if(strlen(cardData->cardHolderName)>24||strlen(cardData->cardHolderName)<20||(cardData->cardHolderName)==NULL){
        printf("wrong name\n");
        return WRONG_NAME;
    }
    else {
        printf("card ok\n");
        return CARD_OK;
    }
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
label:
    printf("please enter card expiry date: ");
    scanf("%s",cardData->cardExpirationDate);
    if(strlen(cardData->cardExpirationDate)>5||strlen(cardData->cardExpirationDate)<5||(cardData->cardExpirationDate)==NULL||cardData->cardExpirationDate[0]>'1'){
        printf("wrong expiry date\n");
        goto label;
        return WRONG_EXP_DATE;
    }
    else {
        printf("card ok\n");
        return CARD_OK;
    }
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
label:
    printf("please enter pan number: ");
    scanf("%s",cardData->primaryAccountNumber);
    if(strlen(cardData->primaryAccountNumber)>19||strlen(cardData->primaryAccountNumber)<16||(cardData->primaryAccountNumber)==NULL){
        printf("wrong pan number\n");
        goto label;
        return WRONG_PAN;
    }
    else {
        printf("card ok\n");
        return CARD_OK;
    }
}


