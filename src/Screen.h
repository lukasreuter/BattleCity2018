#pragma once

#include "Messages.h"
#include "Singleton.h"


class Screen
{
public:
    Screen() = default;
    virtual ~Screen() = default;

    virtual void Enter() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    virtual void Leave() = 0;
    virtual void Update(float dt) = 0;

    virtual void keyPressed(const KeyPressedEvent& evt) = 0;
    virtual void keyReleased(const KeyReleasedEvent& evt) = 0;
    virtual void mouseMoved(const MouseMovedEvent& evt);
    virtual void mousePressed(const MousePressedEvent& evt);
    virtual void mouseReleased(const MouseReleasedEvent& evt);


     /*
    entityx::ptr<entityx::EntityManager> getEntities() { return mEntities; }
    OgreBites::SdkTrayManager *getTrayMgr() { return mTrayMgr; }


protected:
    entityx::ptr<entityx::EntityManager> mEntities;
    OgreBites::SdkTrayManager *mTrayMgr;
*/
};



class MenuScreen : public Screen
{
public:
    MenuScreen() = default;

    void Enter() final;
    void Pause() final;
    void Resume() final;
    void Leave() final;
    void Update(float dt) final;
    //void buttonHit(OgreBites::Button *button);
    //void yesNoDialogClosed(const Ogre::DisplayString &question, bool yesHit);
    void keyPressed(const KeyPressedEvent& evt) final;
    void keyReleased(const KeyReleasedEvent& evt) final;

private:
    bool change = false;
};

class PlayScreen : public Screen
{
public:
    PlayScreen() = default;

    void Enter() final;
    void Pause() final;
    void Resume() final;
    void Leave() final;
    void Update(float dt) final;
    void keyPressed(const KeyPressedEvent& evt) final;
    void keyReleased(const KeyReleasedEvent& evt) final;
    void mouseMoved(const MouseMovedEvent& evt) final;
    void mousePressed(const MousePressedEvent& evt) final;
    void mouseReleased(const MouseReleasedEvent& evt) final;

private:
    //OgreBites::ParamsPanel *mInfoPanel;
    //OgreBites::ProgressBar *mHealthBar;
    //OgreBites::ProgressBar *mHeatBar;
};

class PauseScreen : public Screen
{
public:
    PauseScreen() = default;

    void Enter() final;
    void Pause() final;
    void Resume() final;
    void Leave() final;
    void Update(float dt) final;
    
    void keyPressed(const KeyPressedEvent& evt) final;
    void keyReleased(const KeyReleasedEvent& evt) final;
    
    //void buttonHit(OgreBites::Button *button);
    void YesNoDialogClosed(const std::string& question, bool yesHit);
};

class GameOverScreen : public Screen
{
public:
    GameOverScreen() = default;

    void Enter() final;
    void Pause() final;
    void Resume() final;
    void Leave() final;
    void Update(float dt) final;

    void keyReleased(const KeyReleasedEvent& evt) final;
    void keyPressed(const KeyPressedEvent& evt) final;

private:
    static constexpr double screenDuration = 5;
    double mTime = 0;
};
