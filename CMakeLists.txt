cmake_minimum_required(VERSION 3.28)
project(OKWXTrain)

set(CMAKE_CXX_STANDARD 23)

set(wxWidgets_CONFIG_EXECUTABLE /usr/local/bin/wx-config)
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(OKWXTrain main.cpp
        src/UIPanels/LeftUPB/HexagonalGrid.cpp
        src/UIPanels/LeftUPB/StationMapPanel.cpp
        src/UIPanels/LeftUPB/TrainBoardPanel.cpp
        src/UIPanels/LeftUPB/UserPrimaryBook.cpp
        src/UIPanels/MainPanels/BottomPanel.cpp
        src/UIPanels/MainPanels/LeftPanel.cpp
        src/UIPanels/MainPanels/MainScreen.cpp
        src/UIPanels/MainPanels/RightPanel.cpp
        src/UIPanels/MainPanels/TopPanel.cpp
        src/UIPanels/RightISB/BoardDataPanel.cpp
        src/UIPanels/RightISB/ConstructListPanel.cpp
        src/UIPanels/RightISB/InfoSecondBook.cpp
        src/UITools/UIControllers/ConstructListSelector.cpp
        src/UITools/UIControllers/HexGridManager.cpp
        src/UITools/UIControllers/SwitchboardOperator.cpp
        src/UITools/UIControllers/TopPanelSelector.cpp
        src/Actors/TrainStation.cpp
        src/Actors/Train.cpp
        src/Actors/TrainLine.cpp
        src/CustomEvent.cpp
        src/UIPanels/Dialogs/CreationDialog.cpp
)



target_include_directories(OKWXTrain
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(OKWXTrain ${wxWidgets_LIBRARIES})