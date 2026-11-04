#include "speedywagon.h"


namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* ptr) {
    if(ptr == nullptr) {
        return false;
    }
    return true;
}

pillar_men_sensor sensor_array[3] = {{0}, {101}, {22}};

int activity_counter(pillar_men_sensor* sensor_array, int x) {
    int result{0};
    for (int i{0}; i < x; i++) {
        result += (sensor_array + i)->activity;
    }
    return result;
}

bool alarm_control(pillar_men_sensor* pms) {
    if (pms == nullptr) {
        return false;
    } else if (pms->activity > 0) {
        return true;
    }
    return false;
}

bool uv_alarm(pillar_men_sensor* pms) {
    if(!connection_check(pms)) {
        return false;
    }
    int uvh{uv_light_heuristic(&pms->data)};
    if (uvh > pms->activity) {
        return true;
    }
    return false;
}


// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
