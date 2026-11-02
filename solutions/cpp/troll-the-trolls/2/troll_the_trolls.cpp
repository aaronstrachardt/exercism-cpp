namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
    read,
    write,
    remove
};

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll && viewer != AccountStatus::troll){
        return false;
    }
    return true;
}
// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action a, AccountStatus user) {
    if (user == AccountStatus::mod) {
        return true;
    }

    switch (a) {
        case Action::read:
            return true;
        
        case Action::remove:
            return false;

        case Action::write:
            if (user == AccountStatus::user || user == AccountStatus::troll) {
                return true;
            }
            return false;
        default:
            return false;
    
    }
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus user1, AccountStatus user2) {

    if (user1 == AccountStatus::guest || user2 == AccountStatus::guest) {
        return false;
    }
    
    switch (user1) {
        case AccountStatus::guest:
            return false;
        case AccountStatus::troll:
            if (user1 == user2) {
                return true;
            }
            return false;
        case AccountStatus::user:
        case AccountStatus::mod:
            if (user2 != AccountStatus::troll) {
                return true;
            }
            return false;
        default:
            return false;
    }
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
// mod -> user -> guest -> troll
bool has_priority(AccountStatus user1, AccountStatus user2) {
    if (user1 == user2) {
        return false;
    }
    
    if (user1 == AccountStatus::mod) {
        return true;
    }

    switch (user2) {
        case AccountStatus::mod:
            return false;
        case AccountStatus::user:
            return false;
        case AccountStatus::guest:
         if (user1 != AccountStatus::user) {
            return false;
         }
         return true;
        case AccountStatus::troll:
            return true;
        default:
            return false;
    }
}

}  // namespace hellmath
