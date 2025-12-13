# Создание статической библиотеки для модуля стека
add_library(stackLib STATIC stack.c)

# Установка путей для включения заголовочных файлов
target_include_directories(stackLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
