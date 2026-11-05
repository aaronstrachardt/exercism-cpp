#include "grade_school.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>

namespace grade_school {

// TODO: add your solution here
    void school::add(const std::string& name, int grade) {

        for (const auto& entry : roster_) {

            auto found = std::find(roster_.at(entry.first).begin(), roster_.at(entry.first).end(), name);
            if (found != roster_.at(entry.first).end()) {
                return;
            }
        }
        
        roster_[grade].push_back(name);
        std::sort(roster_.at(grade).begin(), roster_.at(grade).end());
    }

    std::map<int, std::vector<std::string>> school::roster() const {
        return roster_;
    }

    std::vector<std::string> school::grade(int grade) const {
        auto it = roster_.find(grade);
        if (it != roster_.end()) {
            return roster_.at(grade);
        }
        return {};
    }

}  // namespace grade_school
