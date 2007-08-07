#include "state.ih"

void State::allStates()
{
    if (!Msg::display())
        return;

    msg() << info;

    msg() << "Grammar States: " << info;

    if (s_insert == &State::insertExt)
        msg() << 
    "\n"
    "For each state information like the following is shown for its items:\n"
    "   0: [P1 1] S -> C  . C   { <EOF> }  0, (1 2 ) 0\n"
    "which should be read as follows:\n"
    "   0:          The item's index\n"
    "   [P1 1]:     The rule (production) number and current dot-position\n"
    "   S -> C . C: The item (lhs -> Recognized-symbols . "
                                                  "symbols-to-recognize)\n"
    "   { <EOF> }   The item's lookahead (LA) set\n"
    "   0,          The next state's LA set is not enlarged (1: "
                                                        "it is enlarged)\n"
    "   (1 2)       Item indices of items whose LA sets depend on this item\n"
    "   0           The next-element (shown below the items) describing the\n"
    "               action associated with this item (-1 for reducible "
                                                            "items)\n"
    "\n"
    "The Next tables show entries like:\n"
    "   0: On C to state 5 with (0 )\n"
    "meaning:\n"
    "   0:               The Next table's index\n"
    "   On C to state 5: When C was recognized, continue at state 5\n"
    "   with (0 )        The item(s) whose dot is shifted at the next state\n"
    "Also, reduction item(s) may be listed\n" << info;

    msg() << info;

    copy(s_state.begin(), s_state.end(), 
                ostream_iterator<State const *>(msgstream(), "\n"));

    msgstream() << info;
}
