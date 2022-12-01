#include "terminal.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

//*******get transaction date******
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
lable:
    printf("please enter transaction date: ");
    scanf("%s",termData->transactionDate);
    
    if(strlen(termData->transactionDate)>5||strlen(termData->transactionDate)<5||strlen(termData->transactionDate)=='NULL'||termData->transactionDate[0]>'1'){
        printf("Wrong Date\n");
        goto lable;
        return WRONG_DATE;
    }
    else{      

        return TERMINAL_OK;}
}

//*****is card expired*****
EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData){
    
        if(cardData->cardExpirationDate[3] > termData->transactionDate[3]||(cardData->cardExpirationDate[3] >= termData->transactionDate[3]&&cardData->cardExpirationDate[4] > termData->transactionDate[4])){
            //printf("terminal ok\n");

            return TERMINAL_OK;
            
        }else if ((cardData->cardExpirationDate[4] < termData->transactionDate[4]&&cardData->cardExpirationDate[3] == termData->transactionDate[3])){
            
            return EXPIRED_CARD;
        }
        else if(cardData->cardExpirationDate[0] > termData->transactionDate[0]||(cardData->cardExpirationDate[0] >= termData->transactionDate[0]&&cardData->cardExpirationDate[1] > termData->transactionDate[1])){
            printf("terminal ok\n");

            return TERMINAL_OK;
    
        }
        else {printf("card expired\n");
            return EXPIRED_CARD;}
        
}

//*******get transaction amount*******
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
label:
    printf("please enter transaction amount: ");
    scanf("%f",&termData->transAmount);
    if(termData->transAmount <=0){
        termData->transAmount=0;
        printf("invalid amount\n");
        goto label;
        return INVALID_AMOUNT;
    }else{
        printf("terminal ok\n");
        return TERMINAL_OK;}
}

//******** set max amount ********
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount){
    if(maxAmount<=0){
        printf("invalid max amount\n");
        return INVALID_MAX_AMOUNT;
    }else{
        termData->maxTransAmount=maxAmount;
        //printf("terminal ok\n");

        return TERMINAL_OK;
    }
}

//******** is below max amount ********
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    
        if(termData->maxTransAmount < termData->transAmount){
            
            return EXCEED_MAX_AMOUNT;
        }else {        
           // printf("terminal ok\n");

            return TERMINAL_OK;}
}

//******** is valid card pan ********

