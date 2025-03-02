#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <sstream>

using namespace std;

std::vector<std::string> hero = {
    "Brave knight",
    "Cunning thief",
    "Wise wizard",
    "Fearless pirate",
    "Bold explorer",
    "Mighty warrior",
    "Clever detective",
    "Skilled archer",
    "Daring adventurer",
    "Mysterious magician"
};

std::vector<std::string> place = {
    "in a distant kingdom",
    "in an abandoned factory",
    "in a dense forest",
    "in the vastness of space",
    "at the foot of a mountain",
    "in an ancient castle",
    "on a mysterious island",
    "in a haunted mansion",
    "in a hidden valley",
    "on a remote planet"
};

std::vector<std::string> event = {
    "defeated a dragon",
    "discovered a treasure",
    "won a battle",
    "threw a grand ball",
    "uncovered an ancient secret",
    "rescued a princess",
    "stopped an evil sorcerer",
    "found a lost civilization",
    "saved a village",
    "destroyed a curse"
};

std::vector<std::string> detail = {
    "with a magical sword.",
    "on a flying carpet.",
    "to the sound of enchanting music.",
    "with incredible strength.",
    "in the company of a mystical creature.",
    "under the moonlit sky.",
    "with a trusted companion.",
    "while wearing a cloak of invisibility.",
    "guided by an ancient map.",
    "with the power of a magic crystal."
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random(0, 9);

    cout << "Press any key or Q for quit: " << endl;
    string input;
    while (getline(cin, input) && input != "Q") {

        int id[4] = {
            random(gen),
            random(gen),
            random(gen),
            random(gen),
        };

        cout << "History number: " << id[0] << id[1] << id[2] << id[3] << endl;
        string story = hero[id[0]] + " " + place[id[1]] + " " + event[id[2]] + " " + detail[id[3]];
        cout << story << endl;

        input.clear();
        cout << "Press any key or Q for quit: " << endl;
        getline(cin, input);
    }

    cout << "Good Bye";
}