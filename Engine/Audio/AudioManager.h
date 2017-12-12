#ifndef GFX_AUDIOPLAYER_H
#define GFX_AUDIOPLAYER_H

class AudioManager {
 public:
  static AudioManager *file(const char *fn);
  virtual ~AudioManager() = default;
  virtual bool isPlaying() const = 0;
  virtual double duration() const = 0;
  virtual double progress() const = 0;
  virtual void play() = 0;
  virtual void seek(double t) = 0;
};

#endif
