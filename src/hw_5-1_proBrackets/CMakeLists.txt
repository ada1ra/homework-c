# Создание статической библиотеки для модуля сортировочной станции
add_library(proBracketsLib STATIC hw_5-1_proBrackets.c)

# Установка путей для включения заголовочных файлов
target_include_directories(proBracketsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Указание зависимости от библиотеки стека
target_link_libraries(proBracketsLib PRIVATE stackLib)
