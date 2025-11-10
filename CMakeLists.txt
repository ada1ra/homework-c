# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(5_1_SortingStation LANGUAGES C)

# Установка стандарта языка C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включение поддиректорий с модулями
add_subdirectory(src/stack)
add_subdirectory(src/hw_5-2_sortStation)

# Создание исполняемого файла
add_executable(sortingStation src/hw_5-2_sortStation/hw_5-2_sortStationMain.c)

# Связывание с библиотеками модулей
target_link_libraries(sortingStation stackLib sortStationLib)

# Установка путей заголовочных файлов
target_include_directories(sortingStation PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stack
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hw_5-2_sortStation
)

# Установка флагов компиляции
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
