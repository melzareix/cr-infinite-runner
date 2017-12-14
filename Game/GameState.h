//
// Created by Mohamed El Zarei on 12/11/17.
//

#ifndef GFX_PROJECT_GAMESTATE_H
#define GFX_PROJECT_GAMESTATE_H
struct GameState {
  int currentScence; // 0 -> 2 Values
  long score;
  int lives;
  int mult;
  bool didFinishLoading;
  bool gameEnded;
  bool rageShown;
  bool startShowingSpells;
  GameState();
  void CheckGameState();
};
#endif //GFX_PROJECT_GAMESTATE_H
