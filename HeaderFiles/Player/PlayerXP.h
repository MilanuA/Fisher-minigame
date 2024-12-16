
#ifndef PLAYERXP_H
#define PLAYERXP_H

class PlayerXP {

    int currentXP;
    int level;

public:
    PlayerXP() : currentXP(0), level(1) {}

    bool AddXP(int amount);

    void LevelUp();

    int GetCurrentXP() const { return currentXP; }

    int GetLevel() const { return level; }
};

#endif //PLAYERXP_H
