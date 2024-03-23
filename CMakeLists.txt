cmake_minimum_required(VERSION 3.5) # Минимальная версия CMake
project(test) # Имя проекта
find_package(OpenCV REQUIRED) # Поиск пакета OpenCV
add_executable(test main.cpp) # Создание исполняемого файла
target_link_libraries(test ${OpenCV_LIBS}) # Линковка с библиотеками OpenCV