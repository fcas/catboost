# Generated by devtools/yamaker from nixpkgs 32f7980afb5e33f1e078a51e715b9f102f396a69.

LIBRARY()



VERSION(2.4.1)

ORIGINAL_SOURCE(https://github.com/libexpat/libexpat/releases/download/R_2_4_1/expat-2.4.1.tar.xz)

LICENSE(
    CC0-1.0
    JSON
    MIT
)

LICENSE_TEXTS(.yandex_meta/licenses.list.txt)

ADDINCL(
    contrib/libs/expat
    contrib/libs/expat/lib
)

NO_COMPILER_WARNINGS()

NO_RUNTIME()

IF (OS_WINDOWS)
    CFLAGS(GLOBAL -DXML_STATIC)
ELSE()
    CFLAGS(-DHAVE_EXPAT_CONFIG_H)
ENDIF()

SRCS(
    lib/xmlparse.c
    lib/xmlrole.c
    lib/xmltok.c
)

END()
