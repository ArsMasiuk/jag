#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <QList>
#include <QTimer>

#ifdef USE_SDL

#ifdef Q_OS_WIN32
#include "SDL.h"
#include "SDL_mixer.h"
#else
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#endif

#endif

class GameSound : public QObject
{
    Q_OBJECT

public:
    GameSound();
    ~GameSound();

    enum Sounds {
        sndItemDisappear = 0,
        sndSmallHammer = 1,
        sndUnblock = 2,
        sndHammer = 3,
        sndBigHammer = 4,
        sndBomb = 5,
        sndRow = 6,
        sndRandomKill = 7,
        sndMixer = 8,
        sndTwin = 9,
        sndClock = 10,
        sndBonus = 11,
        sndNewItem = 12,
        sndTarget = 13,
        sndLevelStart = 14,
        sndLevelFail = 15,
        sndLevelWon = 16,
        sndBeep = 17,
        sndBonusGot,
        sndTool
    };

    void playSound(int index, int loops = 1);
    void stopSound(int index);
    void stopAllSounds();
    void setChannelVolume(int val, int ch = -1);
    int soundVolume() const { return channel_vol; }

    void loadMusic(const QString &filename);
    void playMusic();
    void stopMusic();
    void setMusicVolume(int val);
    int musicVolume() const { return music_vol; }

    inline bool isMusicEnabled() const { return musicEnabled; }
    void enableMusic(bool on = true);

private slots:
    void checkPlayMusic();

signals:
    void musicFinished();

private:

#ifdef USE_SDL

    Mix_Chunk* loadSound(const QString &filename);

    QList<Mix_Chunk*> m_sounds;

    Mix_Music *music;

#endif //SDL

    QTimer *myTimer;
    bool musicEnabled, musicPlaying;
    int music_vol, channel_vol;
};

extern GameSound* sndEngine;

#endif // GAMESOUND_H
