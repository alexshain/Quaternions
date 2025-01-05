enable_testing()

# Укажите путь к файлу FindCUnit.cmake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/tests")

# Найти библиотеку CUnit
find_package(CUnit REQUIRED)

# Укажите директорию с заголовочными файлами
include_directories(${CUnit_INCLUDE_DIRS})

# Создаем исполнимый файл с тестами
add_executable(test_quaternion_operations test_quaternion_operations.cpp)

# Линковка с библиотеками
target_link_libraries(test_quaternion_operations
    quaternion_operations
    ${CUnit_LIBRARIES}
)

# Добавляем тесты в CTest
add_test(NAME QuaternionOperationsTest COMMAND test_quaternion_operations)
