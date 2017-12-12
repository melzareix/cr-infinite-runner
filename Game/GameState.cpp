//
// Created by Mohamed El Zarei on 12/11/17.
//

#include "GameState.h"
GameState::GameState() {}
void GameState::CheckGameState() {
    if (lives <= 0) { // gameLost
      gameEnded = true;
    }
}
