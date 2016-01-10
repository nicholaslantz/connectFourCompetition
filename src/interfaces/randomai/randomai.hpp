/* randomai.hpp
 *
 * Author: Nicholas Lantz
 * Date: <2016-01-10>
 */

#pragma once
#include <cstdlib>
#include "../../engine/interface.hpp"

class RandomAI : public Interface {
public:
    using Interface::Interface;
    virtual void TakeTurn();
private:

protected:
};
