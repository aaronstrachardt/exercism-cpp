// ERROR: FILE CORRUPTED. Please supply valid C++ Code.

//hp4,ölacöiömthö%Äsmaö%Äsubö(311040ö%Äspaö%Äaddö(311040ö%Ädacöiömthö%Äcountö.hpt,hp4ö%Äxctöhd2ö%Ädacöiöma1
//hp2,öjmpö.
#include <string>
#include "doctor_data.h"

namespace heaven {
    Vessel::Vessel(std::string n, int x) {
        name = n;
        generation = x;
        current_system = star_map::System::Sol;
        busters = 0;
    }
    Vessel::Vessel(std::string n, int x, star_map::System s) {
        name = n;
        generation = x;
        current_system = s;
        busters = 0;
    }

    Vessel Vessel::replicate(std::string str) {
        Vessel v{str, generation + 1};
        return v;
    }

    void Vessel::make_buster() {
        busters += 1;
    }

    bool Vessel::shoot_buster() {
        if (busters > 0) {
            busters -= 1;
            return true;
        }
        return false;
    }

    std::string name{};
    int generation{};
    star_map::System current_system{};
    int busters{};

    std::string get_older_bob(Vessel v1, Vessel v2) {
        if (v1.generation <= v2.generation) {
            return v1.name;
        }
        return v2.name;
    }
    
    bool in_the_same_system(Vessel v1, Vessel v2) {
        if (v1.current_system == v2.current_system) {
            return true;
        }
        return false;
    }    
};