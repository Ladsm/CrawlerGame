cmake_minimum_required(VERSION 3.10)
project(CrawlerGame VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_definitions(-DUNICODE -D_UNICODE)
set(PROJECT_SOURCES
  src/ActionMenu.cpp
  src/ActionMenu.h
  src/CrawlerPlayer.cpp
  src/CrawlerPlayer.h
  src/Entity.cpp
  src/Entity.h
  src/GameExterns.cpp
  src/GameExterns.h
  src/Inventory.h
  src/Item.cpp
  src/Item.h
  src/LDGWLogo.h
  src/Main.cpp
  src/MainMenu.cpp
  src/MainMenu.h
  src/MenuExterns.cpp
  src/MenuExterns.h
  src/MenuGame.cpp
  src/MenuGame.h
)
if(WIN32)
    list(APPEND PROJECT_SOURCES "src/resource.h")
    list(APPEND PROJECT_SOURCES "src/resource1")
    list(APPEND PROJECT_SOURCES "src/CrawlerGame.rc")
endif()
add_executable(CrawlerGame ${PROJECT_SOURCES})
if(NOT WIN32)
    target_link_libraries(CrawlerGame PRIVATE 
        -Wl,-Bstatic,--whole-archive -lpthread -Wl,-Bdynamic,--no-whole-archive
    )
else()
    target_link_libraries(CrawlerGame PRIVATE 
        winmm
        User32.lib
        Gdi32.lib
        Shell32.lib
        Advapi32.lib
    )
endif()
target_include_directories(CrawlerGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
