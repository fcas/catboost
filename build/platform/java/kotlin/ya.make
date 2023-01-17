# how to build: https://a.yandex-team.ru/arc/trunk/arcadia/devtools/kotlin_compiler_uberjar
RESOURCES_LIBRARY()

IF(USE_SYSTEM_KOTLIN_COMPILER)
    MESSAGE(WARNING System kotlin $USE_SYSTEM_KOTLIN_COMPILER will be used)
ELSEIF(KOTLIN_VERSION == "1.3.72")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:1463870128)
ELSEIF(KOTLIN_VERSION == "1.4.0")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:1708283452)
ELSEIF(KOTLIN_VERSION == "1.4.10")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:1730522145)
ELSEIF(KOTLIN_VERSION == "1.4.20")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:1869719387)
ELSEIF(KOTLIN_VERSION == "1.4.30")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:1974389794)
ELSEIF(KOTLIN_VERSION == "1.5.10")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:2183338194)
ELSEIF(KOTLIN_VERSION == "1.5.20")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:2257446523)
ELSEIF(KOTLIN_VERSION == "1.5.21")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:2285312314)
ELSEIF(KOTLIN_VERSION == "1.5.30")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:2382793744)
ELSEIF(KOTLIN_VERSION == "1.5.31")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:2444978303)
ELSEIF(KOTLIN_VERSION == "1.6.10")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:2754878302)
ELSEIF(KOTLIN_VERSION == "1.6.21")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:3280745476)
ELSEIF(KOTLIN_VERSION == "1.7.10")
    DECLARE_EXTERNAL_RESOURCE(KOTLIN_COMPILER sbr:3302905950)
ELSE()
    MESSAGE(FATAL_ERROR Unexpected KOTLIN_VERSION ${KOTLIN_VERSION})
ENDIF()
END()
