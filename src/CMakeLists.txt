set(SOURCE_FILES
        game.cpp game.h
        controller.cpp controller.h
        log_manager.cpp log_manager.h

        model/model.cpp model/model.h
        model/pieces_model.cpp model/pieces_model.h

        piece.h piece.cpp
        multi_capture_manager.h
        coordinates.h coordinates.cpp
        player_manager.h

        piece_managers/piece_movement_manager.h piece_managers/piece_movement_manager.cpp
        piece_managers/piece_capture_manager.h piece_managers/piece_capture_manager.cpp
        piece_managers/piece_promotion_manager.h piece_managers/piece_promotion_manager.cpp
        piece_managers/piece_state_manager.h piece_managers/piece_state_manager.cpp
        piece_managers/piece_movement_animation_manager.h

        coordinates_database.h coordinates_database.cpp
        game_config.h

        pieces_manager.cpp pieces_manager.h

        qml_helper.h
        overlay_manager.h overlay_manager.cpp

        state_machine/abstract_state.h
        state_machine/game_state_manager.h
        state_machine/game_state_type.h
        state_machine/i_state_actions.h
        state_machine/states/ended_victory_north_player.h
        state_machine/states/ended_victory_south_player.h
        state_machine/states/escape_menu_state.h
        state_machine/states/initialization_state.h
        state_machine/states/ready_to_start_state.h
        state_machine/states/running_state.h

        game_coordinator.cpp game_coordinator.h

        input_handler.cpp input_handler.h
        window_manager.cpp window_manager.h

        game_result_info.h
        player.h)

add_library(${PROJECT_NAME}Backend ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME}Backend PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME}Backend PUBLIC Qt6::Core Qt6::Quick)

target_compile_definitions(${PROJECT_NAME}Backend PRIVATE
        APP_VERSION="${PROJECT_VERSION}"
        BUILD_TYPE="$<CONFIG>"
)

qt_add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Backend CheckersQmlLibplugin)

if (WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE $<CONFIG:Release>) # this avoids opening console window on Windows in Release mode
endif ()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) # Set the output directory for the executable
