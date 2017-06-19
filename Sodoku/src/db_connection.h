#ifndef _DB_CONNECTION_
#define _DB_CONNECTION_

#define DB_FILE "sodoku_gruppe_a.db"

int query(const char *sql_stmt, sqlite3_stmt *stmt);
int exec(const char *sql_stmt);

#endif