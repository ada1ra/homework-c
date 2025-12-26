cmake_minimum_required(VERSION 3.10)
project(MultiProject)

# переменная для управления подпроектами
set(SUBPROJECTS src/hw_12-1_binary)

# Добавляем все подпроекты
foreach(subproject ${SUBPROJECTS})
    add_subdirectory(${subproject})
endforeach()

# Опционально: создаем цель для сборки всех проектов
add_custom_target(all_projects DEPENDS ${SUBPROJECTS})
