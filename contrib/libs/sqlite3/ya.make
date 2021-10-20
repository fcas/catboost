# Generated by devtools/yamaker.

LIBRARY()

LICENSE(
    Public-Domain
    blessing
)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)



VERSION(3.34.0)

ORIGINAL_SOURCE(https://sqlite.org/2020/sqlite-src-3340000.zip)

ADDINCL(contrib/libs/sqlite3)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

CFLAGS(
    -DBUILD_sqlite
    -DHAVE_USLEEP
    -DSQLITE_ENABLE_COLUMN_METADATA
    -DSQLITE_ENABLE_DBSTAT_VTAB
    -DSQLITE_ENABLE_FTS3
    -DSQLITE_ENABLE_FTS3_PARENTHESIS
    -DSQLITE_ENABLE_FTS3_TOKENIZER
    -DSQLITE_ENABLE_FTS4
    -DSQLITE_ENABLE_FTS5
    -DSQLITE_ENABLE_JSON1
    -DSQLITE_ENABLE_RTREE
    -DSQLITE_ENABLE_STMT_SCANSTATUS
    -DSQLITE_ENABLE_UNLOCK_NOTIFY
    -DSQLITE_ENABLE_UPDATE_DELETE_LIMIT
    -DSQLITE_HAVE_ZLIB=1
    -DSQLITE_MAX_EXPR_DEPTH=10000
    -DSQLITE_MAX_VARIABLE_NUMBER=250000
    -DSQLITE_SECURE_DELETE
    -DSQLITE_SOUNDEX
    -DSQLITE_TEMP_STORE=1
    -DSQLITE_THREADSAFE=1
)

IF (OS_WINDOWS)
    CFLAGS(-DSQLITE_OS_WIN)
ELSE()
    CFLAGS(-DSQLITE_OS_UNIX)
ENDIF()

SRCS(
    sqlite3.c
    test_multiplex.c
)

END()
