# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(5_1_ProBrackets LANGUAGES C)

# Установка стандарта языка C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включение поддиректорий с модулями
add_subdirectory(src/stack)
add_subdirectory(src/hw_5-1_proBrackets)

# Создание исполняемого файла
add_executable(proBrackets src/hw_5-1_proBrackets/hw_5-1_proBracketsMain.c)

# Связывание с библиотеками модулей
target_link_libraries(proBrackets stackLib proBracketsLib)

# Установка путей заголовочных файлов
target_include_directories(proBrackets PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stack
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hw_5-1_proBrackets
)

# Установка флагов компиляции
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
