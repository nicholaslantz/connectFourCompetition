

#pragma once
#include "../engine/interface.hpp"

class UserInterface : public Interface {
public:
    using Interface::Interface;
    virtual void TakeTurn();

private:
    void printHelp();

protected:
};
