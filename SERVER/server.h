
#ifndef server
#define server
#include "../CARD/card.h"
#include "../TERMINAL/terminal.h"

typedef enum en_transStat_t
{
     APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}en_transStat_t;

typedef struct ST_transaction_t
{
     ST_cardData_t cardHolderData;// ha5od el prim. no a3ml check eno mwgod
     ST_terminalData_t terminalData;// ha5od elflos an2sha mn el acc
     en_transStat_t transState;
     int transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
     SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t ;

typedef enum EN_accountState_t
{
     RUNNING,
     BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
     float balance;
     EN_accountState_t state;
     char primaryAccountNumber[20];
}ST_accountsDB_t;


EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountRefrence);
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountRefrence);
en_transStat_t recieveTransactionData(ST_transaction_t *transData);
EN_serverError_t saveTransaction(ST_transaction_t *transData);
void listSavedTransactions(void);

#endif
