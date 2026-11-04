#include "power_of_troy.h"
#include <memory>
#include <string>
#include <utility>

namespace troy {

    void give_new_artifact(human& h, std::string artifact_name) {
        artifact new_artifact{{artifact_name}};
        h.possession = std::make_unique<artifact>(new_artifact);
    }

    void exchange_artifacts(std::unique_ptr<artifact>& h1, std::unique_ptr<artifact>& h2) {
        std::swap(h1,h2);
    }

    void manifest_power(human& h, std::string s) {
        power new_power{{s}};
        h.own_power = std::make_shared<power>(new_power);
    }

    void use_power(human& h1, human& h2) {
        h2.influenced_by = h1.own_power;
    }

    int power_intensity(human& h) {
        if (h.own_power == nullptr) {
            return 0;
        }
        return static_cast<int>(h.own_power.use_count());   
    }
}  // namespace troy
