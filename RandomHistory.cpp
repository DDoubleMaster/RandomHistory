#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <fstream>

using namespace std;

struct HistoryID
{
private:
#pragma region Text
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
#pragma endregion

    int ids[4];

public:
    string text = "";
    string id = "";

    HistoryID() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> random(0, 9);

        for (int i = 0; i < 4; i++) {
            int num = random(gen);
            ids[i] = num;
            id += to_string(ids[i]);
        }
        text = hero[ids[0]] + " " + place[ids[1]] + " " + event[ids[2]] + " " + detail[ids[3]];
    }
};

int main() {
	// If folder is have not created, create it, else do nothing
	system("mkdir stories");

    cout << "Press any key or Q for quit: " << endl;
    string input;
    while (getline(cin, input) && input != "Q") {
        HistoryID history;

        cout << "History number: " << history.id << endl;
        cout << history.text << endl;

		cout << "Save to file? (Y/[N]): ";
		string save; getline(cin, save);
        if (save == "Y") {
            string fileName = "./stories/story_" + history.id + ".txt";
            string filePath;
            ofstream outfile(fileName);

            outfile << history.text << std::endl;
            outfile.close();
        }

        input.clear();
        cout << "Press any key or Q for quit: " << endl;
        getline(cin, input);
    }

    cout << "Good Bye";
}