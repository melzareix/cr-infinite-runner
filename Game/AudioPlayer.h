//
// Created by Mohamed El Zarei on 12/9/17.
//

#ifndef GFX_PROJECT_AUDIOPLAYER_H
#define GFX_PROJECT_AUDIOPLAYER_H
#include "../Engine/Audio/AudioManager.h"

struct AudioPlayer {
 private:
  AudioManager *backgroundMusic;
  AudioManager *logMusic;
  AudioManager *goblinJump;
  AudioManager *hitMusic;
  AudioManager *rocketMusic;
  AudioManager *bombMusic;
  AudioManager *spellMusic;
 public:
  AudioPlayer();
  bool isPlaying();
  void seek();
  void stop();
  double duration();
  double progress();
  double remaining();
  void Play();
  void reloadFile();
  void playLogMusic();
  void playCollision();
  void playGoblinJump();
  void playGoblinWalk();
  void playRocketMusic();
  void playBombMusic();
  void playSpellMusic(bool);
};
#endif //GFX_PROJECT_AUDIOPLAYER_H
