# Создание статической библиотеки для модуля сортировочной станции
add_library(sortStationLib STATIC hw_5-2_sortStation.c)

# Установка путей для включения заголовочных файлов
target_include_directories(sortStationLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Указание зависимости от библиотеки стека
target_link_libraries(sortStationLib PRIVATE stackLib)
