#include <time.h>
#include <stdio.h>
#include "card.h"
#include "../TERMINAL/terminal.h"
#include "../SERVER/server.h"
#include <string.h>
#include "application.h"
ST_cardData_t customer;
ST_terminalData_t terminal1;
ST_accountsDB_t accountsDB[255];
ST_transaction_t transactions;
extern int acindex;
void appStart(void){
    //transactions[0].cardHolderData;
    accountsDB[0].balance=2000.0;accountsDB[0].state=RUNNING;
    strcpy(accountsDB[0].primaryAccountNumber,"8989374615436851");

    accountsDB[1].balance=0.0;accountsDB[1].state=BLOCKED;
    strcpy(accountsDB[1].primaryAccountNumber,"8989374615436852");
    
    accountsDB[2].balance=20000;accountsDB[2].state=RUNNING;
    strcpy(accountsDB[2].primaryAccountNumber,"8989374615436853");
    
    accountsDB[3].balance=10000;accountsDB[3].state=BLOCKED;
    strcpy(accountsDB[3].primaryAccountNumber,"8989374615436854");
    
    accountsDB[4].balance=500;accountsDB[4].state=RUNNING;
    strcpy(accountsDB[4].primaryAccountNumber,"8989374615436855");
    
    accountsDB[5].balance=16000;accountsDB[5].state=RUNNING;
    strcpy(accountsDB[5].primaryAccountNumber,"8989374615436856");
    
    accountsDB[6].balance=4000;accountsDB[6].state=BLOCKED;
    strcpy(accountsDB[6].primaryAccountNumber,"8989374615436857");
    
    while(1){
        getCardHolderName(&customer);
        getCardExpiryDate(&customer);
        getCardPAN(&customer);
        getTransactionDate(&terminal1);
        setMaxAmount(&terminal1, 5000);
        if(isCardExpired(&customer, &terminal1)==EXPIRED_CARD){
            printf("card expired\n");
            break;
        }
        else {
            getTransactionAmount(&terminal1);
        }
        if(isBelowMaxAmount(&terminal1)==EXCEED_MAX_AMOUNT){
            printf("exceed maximum terminal amount\n");
            break;
        }
        
        if(isValidAccount(&customer, &accountsDB)==ACCOUNT_NOT_FOUND){
            printf("FRAUD CARD\n");
            break;
        }else if (isAmountAvailable(&terminal1,&accountsDB[acindex])==LOW_BALANCE){
            printf("low balance\n");
            break;
        }else if(isBlockedAccount(&accountsDB[acindex])==BLOCKED_ACCOUNT){
            printf("blocked account\n");
            break;
        }else {
            printf("current ammount:%f\n",(accountsDB[acindex].balance));
            printf("approved\n");
            
            break;
        }

        
           break;
      }
}
