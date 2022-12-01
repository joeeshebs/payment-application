#include "server.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//en_transStat_t recieveTransactionData(ST_transaction_t *transData){
//
//}
int acindex;
extern ST_accountsDB_t accountsDB[255];
//******** is valid account ********
EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence){
    int x=1;
    for(int i=0;i<256;i++){
        if(!strcmp(cardData->primaryAccountNumber,accountRefrence[i].primaryAccountNumber) ){
           // printf("found\n");
            x=0;
            acindex=i;
            return SERVER_OK;
        }
    }
    if(x) {
        //printf(" not found\n");
        return ACCOUNT_NOT_FOUND;
    }else return SERVER_OK;
    
    
}
//******** revieve transaction data********
en_transStat_t recieveTransactionData(ST_transaction_t *transData){
    if(isValidAccount(&transData->cardHolderData,&accountsDB)==ACCOUNT_NOT_FOUND){
        transData->transState=FRAUD_CARD;
        printf("fraud card");
        return FRAUD_CARD;
    }else if(isAmountAvailable(&transData->terminalData,&accountsDB[acindex])==LOW_BALANCE){
        transData->transState=DECLINED_INSUFFECIENT_FUND;
        printf("declined insuffecient fund");
        return DECLINED_INSUFFECIENT_FUND;
    }else if(isBlockedAccount(&accountsDB[acindex])==BLOCKED_ACCOUNT){
        transData->transState=DECLINED_STOLEN_CARD;
        printf("Declined stolen card");
        return DECLINED_STOLEN_CARD;
    }else{accountsDB[acindex].balance=accountsDB[acindex].balance - transData->terminalData.transAmount;
        
        printf("approved");
        return APPROVED;}


}

//******** is blocked account ********
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence){
    if(accountRefrence->state==RUNNING){
        //printf("running");
        return SERVER_OK;
    }else{//printf("blocked");
        return BLOCKED_ACCOUNT;}}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence){
    if(termData->transAmount<=accountRefrence->balance){
        accountRefrence->balance=accountRefrence->balance-termData->transAmount;
        return SERVER_OK ;
    }else{//printf("low balance");
        return LOW_BALANCE;}
}
    
  
//EN_serverError_t saveTransaction(ST_transaction_t *transData){
//    
//}
