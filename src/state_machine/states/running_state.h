#pragma once

#include "state_machine/abstract_state.h"

class RunningState : public AbstractState
{
public:
    explicit RunningState(IStateActions& stateActions) : AbstractState("RunningState", GameStateType::Running, stateActions)
    {}

    void entered() override
    {
        stateActions_.enablePiecesAnimation();
    }

    void exited() override
    {
        stateActions_.disablePiecesAnimation();
    }

    void transitionTo(AbstractState* newState) override
    {
        switch (newState->type())
        {
            case GameStateType::EscapeMenu:
            case GameStateType::EndedVictoryNorthPlayer:
            case GameStateType::EndedVictorySouthPlayer:
                break;

            default:
                handleIllegalTransition(newState);
        }

        printTransition(newState);
    }

    void onKeyPress(const int key) override
    {
        switch (key)
        {
            case Qt::Key_Escape:
                stateActions_.setGameState(GameStateType::EscapeMenu);
                break;

            default:
                break;
        }
    }
};
