// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

/*hp1, üapöhp2ö % Äcountöiöma1,
    öhp2ö % Älawöhp3öö / önextöstepö % Ädacöiöml1ö % Älawö7ö % Ädacöiömb1ö %
        Ärandomöö % Äscrö9sö % Äsirö9sö % Äxctöhr1ö % Äaddöiömx1ö %
        Ädacöiömx1ö % Äswapö % Äaddöiömy1ö % Ädacöiömy1ö % Ärandomö % Äscrö9sö %
        Äsirö9sö % Äxctöhr2ö % Ädacöiömdyö % Ädioöiömdxö % Äsetupö.hpt,
    3ö % Älacöranö % Ädacöiömth
*/
#pragma once
#include <string>

namespace star_map {
    enum class System {
        Sol,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
        BetaHydri,
        EpsilonEridani
    };
}

namespace heaven {
    class Vessel {
        public:
            Vessel(std::string n, int x);
            Vessel(std::string n, int x, star_map::System s);
            Vessel replicate(std::string str);
            void make_buster();
            bool shoot_buster();
            std::string name;
            int generation;
            star_map::System current_system;
            int busters;
    };
    std::string get_older_bob(Vessel v1, Vessel v2);
    bool in_the_same_system(Vessel v1, Vessel v2);  
}