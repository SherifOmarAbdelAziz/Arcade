

add_library(
    App SHARED
    App/App.h
    App/App.cpp
)

add_library(
    Games SHARED
    Games/Game.h
    Games/GameScene.h
    Games/GameScene.cpp
)

add_library(
    BreakOut SHARED
    Games/BreakOut/Ball.cpp
    Games/BreakOut/Ball.h
    Games/BreakOut/BoundaryEdge.h
    Games/BreakOut/BreakOut.h
    Games/BreakOut/BreakOut.cpp
    Games/BreakOut/Excluder.h
    Games/BreakOut/Excluder.cpp
    Games/BreakOut/Paddle.h
    Games/BreakOut/Paddle.cpp
    Games/BreakOut/LevelBoundary.h
    Games/BreakOut/LevelBoundary.cpp
)

add_library(
    Graphics SHARED
    Graphics/Color.h
    Graphics/Color.cpp
    Graphics/Screen.h
    Graphics/Screen.cpp
    Graphics/ScreenBuffer.h
    Graphics/ScreenBuffer.cpp
)

add_library(
    input SHARED
    input/GameController.h
    input/GameController.cpp
    input/inputAction.h
    input/InputController.h
    input/InputController.cpp
)


add_library(
    Scenes SHARED
    Scenes/ArcadeScene.h
    Scenes/ArcadeScene.cpp
    Scenes/Scene.h
)

add_library(
    Shapes SHARED
    Shapes/AARectangle.cpp  
    Shapes/Circle.cpp  
    Shapes/Line.cpp  
    Shapes/Shape.cpp  
    Shapes/Triangle.cpp
    Shapes/AARectangle.h    
    Shapes/Circle.h    
    Shapes/Line.h    
    Shapes/Shape.h    
    Shapes/Triangle.h    
)

add_library(
    Utils SHARED
    Utils/FileCommandLoader.cpp  
    Utils/Utils.cpp  
    Utils/Vec2D.cpp
    Utils/FileCommandLoader.h    
    Utils/Utils.h    
    Utils/Vec2D.h
)

add_library(
    Arcade
    ArcadeApp.cpp
)

target_include_directories(
    App 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    Games 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    BreakOut 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    Graphics 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    input 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    Scenes 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    Shapes 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(
    Utils 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games/BreakOut"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(Graphics PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(Utils PUBLIC ${SDL2_INCLUDE_DIRS})

target_link_libraries(App PRIVATE Games BreakOut Graphics input Scenes Shapes Utils)
target_link_libraries(Games PRIVATE Graphics input Scenes Shapes Utils)
target_link_libraries(BreakOut PRIVATE Games Graphics input Scenes Shapes Utils)
target_link_libraries(Graphics PRIVATE Shapes Utils)
target_link_libraries(Scenes PRIVATE input Shapes)
target_link_libraries(Shapes PRIVATE Utils)





find_package(SDL2 REQUIRED)

target_include_directories(
    Arcade 
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/App"
    "${CMAKE_CURRENT_SOURCE_DIR}/Games"
    "${CMAKE_CURRENT_SOURCE_DIR}/Graphics"
    "${CMAKE_CURRENT_SOURCE_DIR}/input"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scenes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Shapes"
    "${CMAKE_CURRENT_SOURCE_DIR}/Utils"
)

target_include_directories(Arcade PUBLIC ${SDL2_INCLUDE_DIRS})

target_link_libraries(Arcade
    App Games Graphics BreakOut input Scenes Shapes Utils ${SDL2_LIBRARIES}
)

add_executable(ArcadeAppExe ArcadeApp.cpp)

target_link_libraries(ArcadeAppExe PRIVATE Arcade)