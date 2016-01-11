# connectFourCompetition
A competition between me and luckcow to see who can program the better
Connect Four AI.

The base gameplay system is complete.

# TODO
    * Modify the program so that the user interface is more friendly and looks
      better.
    * Add a main menu and a way to run the program from the commandline.
        - The program needs to be told what interfaces to use and how many
          rounds to play for that runtime.
        - The program should output the results of the games to stdout (cout).
    * There should be a way to reset the game so that it isn't necessary to
      delete the ConnectFour or GameManager object and remake it to reset it.
    * Make the interfaces "safe" in the respect that an interface can't call
      TakeTurn() to the ConnectFour class multiple times on its turn.
