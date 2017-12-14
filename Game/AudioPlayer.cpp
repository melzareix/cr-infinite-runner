//
// Created by Mohamed El Zarei on 12/9/17.
//
#include "AudioPlayer.h"
AudioPlayer::AudioPlayer() {
  backgroundMusic = AudioManager::file("Content/Sounds/bg_s.mp3");
  backgroundMusic->stop();
}

void AudioPlayer::Play() {
  this->backgroundMusic->play();
}
bool AudioPlayer::isPlaying() {
  return this->backgroundMusic->isPlaying();
}
double AudioPlayer::duration() {
  return this->backgroundMusic->duration();
}
void AudioPlayer::seek() {
  this->backgroundMusic->seek(0);
  this->backgroundMusic->play();
}
double AudioPlayer::remaining() {
  return this->duration() - this->progress();
}
double AudioPlayer::progress() {
  return this->backgroundMusic->progress();
}

void AudioPlayer::playLogMusic() {
  logMusic = AudioManager::file("Content/Sounds/log_vocal_01.mp3");
  logMusic->play();
}

void AudioPlayer::playCollision() {
  hitMusic = AudioManager::file("Content/Sounds/blowdart_hit_01.wav");
  hitMusic->play();
}
void AudioPlayer::playRocketMusic() {
  rocketMusic = AudioManager::file("Content/Sounds/rocket_launch_02v2.wav");
  rocketMusic->play();
}
void AudioPlayer::playGoblinJump() {
  goblinJump = AudioManager::file("Content/Sounds/blowdart_gob_jump_01.wav");
  goblinJump->play();
}
void AudioPlayer::playGoblinWalk() {
  goblinJump = AudioManager::file("Content/Sounds/blowdart_goblin_atk_02.wav");
  goblinJump->play();
}
void AudioPlayer::reloadFile() {
  backgroundMusic = AudioManager::file("Content/Sounds/bg_s.mp3");
}
void AudioPlayer::playBombMusic() {
  bombMusic = AudioManager::file("Content/Sounds/bomb_drop_01.wav");
  bombMusic->play();
}
void AudioPlayer::playSpellMusic(bool rage) {
    if (rage) {
      spellMusic = AudioManager::file("Content/Sounds/rage.wav");
      spellMusic->play();
    } else {
      spellMusic = AudioManager::file("Content/Sounds/heal.wav");
      spellMusic->play();
    }
}
void AudioPlayer::stop() {
  backgroundMusic->stop();
}
