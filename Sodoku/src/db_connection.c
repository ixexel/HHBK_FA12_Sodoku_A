#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sqlite3.h"
#include "db_connection.h"

int main(){
  
  sqlite3_stmt *stmt = 0;

  exec("insert into games values ('1', '1', '1', '1', '1')");
  /*query("select id from games;", stmt);

  while(SQLITE_DONE != sqlite3_step(stmt)){
    printf("%i", (int *)sqlite3_column_int(stmt, 1));
  }*/
  system("pause");

  return 1;
}

/**
**/
int query(const char *sql_stmt, sqlite3_stmt *stmt){
  sqlite3 *db_handle;
  int rc;

  rc = sqlite3_prepare_v2(db_handle,  sql_stmt, strlen(sql_stmt), &stmt, NULL);

  if(rc != SQLITE_OK){
    printf("Failed executing query: %s", sql_stmt);
  }

  return rc;
}

/******************************************************************************
Function: exec
Date: 19/06/2017
Description: Executes the given sql statement and returns 1 on success.
             If the function fails, the error message is logged and the
             application is closed.
******************************************************************************/
int exec(const char *sql_stmt){
  sqlite3 *db_handle;
  char *errMsg;
  int rc;

  rc = sqlite3_open(DB_FILE, &db_handle);

  if(rc != SQLITE_OK){
    sqlite3_close(db_handle);
  }

  rc = sqlite3_exec(db_handle, sql_stmt, NULL, NULL, &errMsg);

  if(rc != SQLITE_OK){
    printf("Error executing the sql statement: %s \n %s", sql_stmt, errMsg);
    // TODO: Log the error message and exit the application
  }

  return rc;
}