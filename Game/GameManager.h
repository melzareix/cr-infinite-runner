//
// Created by Mohamed El Zarei on 12/9/17.
//

#ifndef GFX_PROJECT_GAMEMANAGER_H
#define GFX_PROJECT_GAMEMANAGER_H
#include "AudioPlayer.h"

struct GameManager {
 private:
 public:
  AudioPlayer *backgroundAudioPlayer;
  GameManager();
  void PlayBackgroundMusic();
  void PlayLogMusic();
  void PlayRocketMusic();
  void PlayBombMusic();
  void PlayCollision();
  void PlayGoblinJump();
  void PlayGoblinWalk();
  void PlaySpellMusic(bool);
};
#endif //GFX_PROJECT_GAMEMANAGER_H
