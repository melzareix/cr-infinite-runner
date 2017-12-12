//
// Created by Mohamed El Zarei on 12/9/17.
//
#include <iostream>
#include "GameManager.h"
using namespace std;
void GameManager::PlayBackgroundMusic() {
  if (!backgroundAudioPlayer->isPlaying()) {
    backgroundAudioPlayer->reloadFile();
    backgroundAudioPlayer->Play();
  }
}

GameManager::GameManager() {
  backgroundAudioPlayer = new AudioPlayer();
}

void GameManager::PlayLogMusic() {
  backgroundAudioPlayer->playLogMusic();
}
void GameManager::PlayCollision() {
  backgroundAudioPlayer->playCollision();
}
void GameManager::PlayGoblinJump() {
  backgroundAudioPlayer->playGoblinJump();
}
void GameManager::PlayGoblinWalk() {
  backgroundAudioPlayer->playGoblinWalk();
}
void GameManager::PlayRocketMusic() {
  backgroundAudioPlayer->playRocketMusic();
}
void GameManager::PlayBombMusic() {
  backgroundAudioPlayer->playBombMusic();
}
void GameManager::PlaySpellMusic(bool rage) {
  backgroundAudioPlayer->playSpellMusic(rage);
}
