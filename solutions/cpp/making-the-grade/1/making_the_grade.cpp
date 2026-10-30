#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> rounded_down{};
    for (int i{0}; i < static_cast<int>(student_scores.size()); i++) {
        rounded_down.emplace_back(student_scores.at(i));
    }
    return rounded_down;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int failed_students{0};
    for (int i{0}; i < static_cast<int>(student_scores.size()); i++) {
        if (student_scores.at(i) <= 40) {
            failed_students++;
        } else {
            continue;
        }
    }
    return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int interval = (highest_score - 40) / 4;
    std::array<int, 4> letter_grades{41, 41 + interval, 41 + interval * 2, 41 + interval * 3};
    return letter_grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> ranking{};
    for (int i{}; i < static_cast<int>(student_scores.size()); i++) {
        int rank{i+1};
        std::string ranking_string{std::to_string(rank) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i))};
        ranking.emplace_back(ranking_string);
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (int i{}; i < static_cast<int>(student_scores.size()); i++) {
        if (student_scores.at(i) == 100) {
            return student_names.at(i);
        }
        else {
            continue;
        }
    }
    return "";
}
