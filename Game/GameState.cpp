//
// Created by Mohamed El Zarei on 12/11/17.
//

#include "GameState.h"
void GameState::CheckGameState() {
    if (lives <= 0) { // gameLost
      gameEnded = true;
    }
}
GameState::GameState() {
  currentScence = 0;
  score = 0;
  lives = 3;
  mult = 1;
  didFinishLoading = false;
  gameEnded = false;
  rageShown = false;
  startShowingSpells = false;
}
