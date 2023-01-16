RESOURCES_LIBRARY()


INCLUDE(resources.inc)

IF(JDK_VERSION == "16")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK16_DARWIN} FOR DARWIN
        ${JDK16_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK16_LINUX} FOR LINUX
        ${JDK16_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK16)
    ENDIF()
ELSEIF(JDK_VERSION == "15")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK15_DARWIN} FOR DARWIN
        ${JDK15_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK15_LINUX} FOR LINUX
        ${JDK15_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK15)
    ENDIF()
ELSEIF(JDK_VERSION == "14")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK14_DARWIN} FOR DARWIN
        ${JDK14_LINUX} FOR LINUX
        ${JDK14_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK14)
    ENDIF()
ELSEIF(JDK_VERSION == "13")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK13_DARWIN} FOR DARWIN
        ${JDK13_LINUX} FOR LINUX
        ${JDK13_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK13)
    ENDIF()
ELSEIF(JDK_VERSION == "12")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK12_DARWIN} FOR DARWIN
        ${JDK12_LINUX} FOR LINUX
        ${JDK12_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK12)
    ENDIF()
ELSEIF(JDK_VERSION == "11")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK11_DARWIN} FOR DARWIN
        ${JDK11_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK11_LINUX} FOR LINUX
        ${JDK11_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK11)
    ENDIF()
ELSEIF(JDK_VERSION == "10")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK10_DARWIN} FOR DARWIN
        ${JDK10_LINUX} FOR LINUX
        ${JDK10_WINDOWS} FOR WIN32
    )
ELSEIF(JDK_VERSION == "8")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK_DEFAULT
        ${JDK8_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK8_DARWIN} FOR DARWIN
        ${JDK8_LINUX} FOR LINUX
        ${JDK8_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK8)
    ENDIF()
ELSE()
    MESSAGE(FATAL_ERROR Unsupported JDK version)
ENDIF()

DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK16
    ${JDK16_DARWIN} FOR DARWIN
    ${JDK16_DARWIN_ARM64} FOR DARWIN-ARM64
    ${JDK16_LINUX} FOR LINUX
    ${JDK16_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK15
    ${JDK15_DARWIN} FOR DARWIN
    ${JDK15_DARWIN_ARM64} FOR DARWIN-ARM64
    ${JDK15_LINUX} FOR LINUX
    ${JDK15_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK14
    ${JDK14_DARWIN} FOR DARWIN
    ${JDK14_LINUX} FOR LINUX
    ${JDK14_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK13
    ${JDK13_DARWIN} FOR DARWIN
    ${JDK13_LINUX} FOR LINUX
    ${JDK13_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK12
    ${JDK12_DARWIN} FOR DARWIN
    ${JDK12_LINUX} FOR LINUX
    ${JDK12_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK11
    ${JDK11_DARWIN} FOR DARWIN
    ${JDK11_DARWIN_ARM64} FOR DARWIN-ARM64
    ${JDK11_LINUX} FOR LINUX
    ${JDK11_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK10
    ${JDK10_DARWIN} FOR DARWIN
    ${JDK10_LINUX} FOR LINUX
    ${JDK10_WINDOWS} FOR WIN32
)
DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
    JDK8
    ${JDK8_DARWIN_ARM64} FOR DARWIN-ARM64
    ${JDK8_DARWIN} FOR DARWIN
    ${JDK8_LINUX} FOR LINUX
    ${JDK8_WINDOWS} FOR WIN32
)

IF(OS_DARWIN AND ARCH_ARM64)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK16 ${JDK16_DARWIN_ARM64})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK15 ${JDK15_DARWIN_ARM64})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK11 ${JDK11_DARWIN_ARM64})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK8 ${JDK8_DARWIN_ARM64})
ELSEIF(OS_DARWIN)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK16 ${JDK16_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK15 ${JDK15_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK14 ${JDK14_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK13 ${JDK13_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK12 ${JDK12_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK11 ${JDK11_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK10 ${JDK10_DARWIN})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK8 ${JDK8_DARWIN})
ELSEIF(OS_LINUX)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK16 ${JDK16_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK15 ${JDK15_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK14 ${JDK14_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK13 ${JDK13_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK12 ${JDK12_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK11 ${JDK11_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK10 ${JDK10_LINUX})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK8 ${JDK8_LINUX})
ELSEIF(OS_WINDOWS)
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK16 ${JDK16_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK15 ${JDK15_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK14 ${JDK14_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK13 ${JDK13_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK12 ${JDK12_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK11 ${JDK11_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK10 ${JDK10_WINDOWS})
    DECLARE_EXTERNAL_RESOURCE(WITH_JDK8 ${JDK8_WINDOWS})
ENDIF()

IF(USE_SYSTEM_JDK)
    MESSAGE(WARNING System JDK $USE_SYSTEM_JDK will be used)
ELSEIF(JDK_VERSION == "16")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK16_DARWIN} FOR DARWIN
        ${JDK16_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK16_LINUX} FOR LINUX
        ${JDK16_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK16)
    ENDIF()

    IF(OS_DARWIN AND ARCH_ARM64)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK16_DARWIN_ARM64})
    ELSEIF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK16_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK16_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK16_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "15")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK15_DARWIN} FOR DARWIN
        ${JDK15_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK15_LINUX} FOR LINUX
        ${JDK15_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK15)
    ENDIF()

    IF(OS_DARWIN AND ARCH_ARM64)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK15_DARWIN_ARM64})
    ELSEIF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK15_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK15_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK15_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "14")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK14_DARWIN} FOR DARWIN
        ${JDK14_LINUX} FOR LINUX
        ${JDK14_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK14)
    ENDIF()

    IF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK14_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK14_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK14_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "13")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK13_DARWIN} FOR DARWIN
        ${JDK13_LINUX} FOR LINUX
        ${JDK13_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK13)
    ENDIF()
    IF(SANITIZER_TYPE == "address")
        IF(HOST_OS_LINUX)
            DECLARE_EXTERNAL_RESOURCE(JDK_FOR_TESTS ${JDK13_LINUX_ASAN})
        ELSE()
            MESSAGE(FATAL_ERROR Unsupported platform for JDK13 with asan)
        ENDIF()
    ENDIF()

    IF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK13_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK13_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK13_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "12")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK12_DARWIN} FOR DARWIN
        ${JDK12_LINUX} FOR LINUX
        ${JDK12_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK12)
    ENDIF()

    IF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK12_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK12_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK12_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "11")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK11_DARWIN} FOR DARWIN
        ${JDK11_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK11_LINUX} FOR LINUX
        ${JDK11_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK11)
    ENDIF()
    IF(SANITIZER_TYPE == "address")
        IF(HOST_OS_LINUX)
            DECLARE_EXTERNAL_RESOURCE(JDK_FOR_TESTS ${JDK11_LINUX_ASAN})
        ELSE()
            MESSAGE(FATAL_ERROR Unsupported platform for JDK11 with asan)
        ENDIF()
    ENDIF()

    IF(OS_DARWIN AND ARCH_ARM64)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK11_DARWIN_ARM64})
    ELSEIF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK11_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK11_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK11_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "10")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK10_DARWIN} FOR DARWIN
        ${JDK10_LINUX} FOR LINUX
        ${JDK10_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK10)
    ENDIF()

    IF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK10_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK10_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK10_WINDOWS})
    ENDIF()
ELSEIF(JDK_VERSION == "8")
    DECLARE_EXTERNAL_HOST_RESOURCES_BUNDLE(
        JDK
        ${JDK8_DARWIN_ARM64} FOR DARWIN-ARM64
        ${JDK8_DARWIN} FOR DARWIN
        ${JDK8_LINUX} FOR LINUX
        ${JDK8_WINDOWS} FOR WIN32
    )
    IF(NOT HOST_OS_LINUX AND NOT HOST_OS_WINDOWS AND NOT HOST_OS_DARWIN)
        MESSAGE(FATAL_ERROR Unsupported platform for JDK8)
    ENDIF()

    IF(OS_DARWIN AND ARCH_ARM64)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK8_DARWIN_ARM64})
    ELSEIF(OS_DARWIN)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK8_DARWIN})
    ELSEIF(OS_LINUX)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK8_LINUX})
    ELSEIF(OS_WINDOWS)
        DECLARE_EXTERNAL_RESOURCE(WITH_JDK ${JDK8_WINDOWS})
    ENDIF()
ELSE()
    MESSAGE(FATAL_ERROR Unsupported JDK version)
ENDIF()

END()
