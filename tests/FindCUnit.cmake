# Поиск заголовочных файлов CUnit
find_path(CUNIT_INCLUDE_DIR CUnit/CUnit.h PATHS /opt/homebrew/include)

# Поиск библиотеки CUnit
find_library(CUNIT_LIBRARY cunit PATHS /opt/homebrew/lib)

# Проверка наличия заголовков и библиотеки
if (CUNIT_INCLUDE_DIR AND CUNIT_LIBRARY)
    set(CUnit_FOUND TRUE)
else()
    set(CUnit_FOUND FALSE)
endif()

# Установка переменных для использования в проекте
if (CUnit_FOUND)
    set(CUnit_INCLUDE_DIRS ${CUNIT_INCLUDE_DIR})
    set(CUnit_LIBRARIES ${CUNIT_LIBRARY})
    message(STATUS "CUnit found: ${CUNIT_INCLUDE_DIR}, ${CUNIT_LIBRARY}")
else()
    message(FATAL_ERROR "CUnit not found. Please install CUnit.")
endif()
