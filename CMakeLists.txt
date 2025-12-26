# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Общее название проекта
project(Homework_5 LANGUAGES C)

# Установка стандарта языка C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Включение общей библиотеки stack
add_subdirectory(src/stack)

# =========== ПРОЕКТ 1: Проверка скобок ==========
# Включение модуля для проекта скобок
add_subdirectory(src/hw_5-1_proBrackets)

# Создание исполняемого файла для проверки скобок
add_executable(hw_5_1_proBrackets
    src/hw_5-1_proBrackets/hw_5-1_proBracketsMain.c
)

# Связывание с библиотеками
target_link_libraries(hw_5_1_proBrackets
    PRIVATE
    stackLib
    hw_5_1_proBracketsLib
)

# Установка путей заголовочных файлов для proBrackets
target_include_directories(hw_5_1_proBrackets
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stack
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hw_5-1_proBrackets
)

# ========== ПРОЕКТ 2: Сортировочная станция ==========
# Включение модуля для сортировочной станции
add_subdirectory(src/hw_5-2_sortStation)

# Создание исполняемого файла для сортировочной станции
add_executable(hw_5_2_sortStation
    src/hw_5-2_sortStation/hw_5-2_sortStationMain.c
)

# Связывание с библиотеками
target_link_libraries(hw_5_2_sortStation
    PRIVATE
    stackLib
    hw_5_2_sortStationLib
)

# Установка путей заголовочных файлов для sortingStation
target_include_directories(hw_5_2_sortStation
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stack
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hw_5-2_sortStation
)

# ======== Цель для сборки всех проектов ============
add_custom_target(all_projects
    DEPENDS
    hw_5_1_proBrackets
    hw_5_2_sortStation
)
