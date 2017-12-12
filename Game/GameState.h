//
// Created by Mohamed El Zarei on 12/11/17.
//

#ifndef GFX_PROJECT_GAMESTATE_H
#define GFX_PROJECT_GAMESTATE_H
struct GameState {
  int currentScence = 0; // 0 -> 2 Values
  long score = 0;
  int lives = 3;
  int mult = 1;
  bool didFinishLoading = false;
  bool gameEnded = false;
  bool rageShown = false;
  bool startShowingSpells = false;
  GameState();
  void CheckGameState();
};
#endif //GFX_PROJECT_GAMESTATE_H
