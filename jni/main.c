/* tbox database connection test
 *
 * Builds on Android with ndk-build and on the Linux host (tests/host) with
 * the same sources.  It opens a SQLite database through the tbox database
 * API, creates a table, inserts rows and reads them back.
 *
 * Usage: test [database-url]
 *   Android default: /data/local/tmp/tbox_test.db
 *   Host default:    current directory / tbox_test.db
 */

#include "tbox/tbox.h"

#include <stdio.h>

#if defined(__ANDROID__)
#   define TBOX_DEFAULT_DB_URL "/data/local/tmp/tbox_test.db"
#else
#   define TBOX_DEFAULT_DB_URL "tbox_test.db"
#endif

static int tbox_db_exec(tb_database_sql_ref_t database, tb_char_t const* sql)
{
    if (!tb_database_sql_done(database, sql))
    {
        printf("  [FAIL] sql: %s (state: %s)\n", sql, tb_state_cstr(tb_database_sql_state(database)));
        return 0;
    }

    printf("  [ OK ] sql: %s\n", sql);
    return 1;
}

int main(int argc, char** argv)
{
    tb_char_t const* url = (argc > 1)? argv[1] : TBOX_DEFAULT_DB_URL;
    int              ok  = 0;

    printf("=== tbox database connection test ===\n");
    printf("database url: %s\n", url);

    if (!tb_init(tb_null, tb_null))
    {
        printf("DB CONNECTION TEST: FAIL (tb_init)\n");
        return 1;
    }

    tb_database_sql_ref_t database = tb_null;
    do
    {
        /* open the database connection */
        database = tb_database_sql_init(url);
        if (!database)
        {
            printf("  [FAIL] tb_database_sql_init\n");
            break;
        }
        printf("  [ OK ] tb_database_sql_init\n");

        if (!tb_database_sql_open(database))
        {
            printf("  [FAIL] tb_database_sql_open (state: %s)\n",
                   tb_state_cstr(tb_database_sql_state(database)));
            break;
        }
        printf("  [ OK ] tb_database_sql_open (connected)\n");

        /* exercise the connection with simple SQL */
        if (!tbox_db_exec(database, "drop table if exists tbox_test")) break;
        if (!tbox_db_exec(database, "create table tbox_test(id integer, name text)")) break;
        if (!tbox_db_exec(database, "insert into tbox_test values(1, 'tbox')")) break;
        if (!tbox_db_exec(database, "insert into tbox_test values(2, 'sqlite')")) break;

        /* run a query and walk the tbox result set */
        if (!tbox_db_exec(database, "select id, name from tbox_test order by id")) break;

        tb_iterator_ref_t result = tb_database_sql_result_load(database, tb_true);
        if (!result)
        {
            printf("  [FAIL] tb_database_sql_result_load\n");
            break;
        }

        tb_size_t rows = 0;
        tb_for_all_if (tb_iterator_ref_t, row, result, row)
        {
            tb_size_t cols = tb_iterator_size(row);
            tb_size_t col;

            printf("  row[%lu]:", (unsigned long)rows);
            for (col = 0; col < cols; col++)
            {
                tb_database_sql_value_t const* value =
                    (tb_database_sql_value_t const*)tb_iterator_item(row, col);
                if (value)
                {
                    tb_char_t const* text = tb_database_sql_value_text(value);
                    printf(" %s=%s", tb_database_sql_value_name(value), text? text : "(null)");
                }
            }
            printf("\n");

            rows++;
        }

        tb_database_sql_result_exit(database, result);

        if (rows == 2)
            ok = 1;
        else
            printf("  [FAIL] expected 2 rows, got %lu\n", (unsigned long)rows);

    } while (0);

    if (database)
    {
        tb_database_sql_close(database);
        tb_database_sql_exit(database);
    }

    tb_exit();

    printf("DB CONNECTION TEST: %s\n", ok? "PASS" : "FAIL");
    return ok? 0 : 1;
}
