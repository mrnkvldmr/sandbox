#include <ctime>
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void print_greating() {
    cout << "Welcome to the Guessing Number game!"
         << endl
         << endl;;
}

void print_offer_input() {
    cout << "Type a number: ";
}

int random_number() {
    time_t t;
    srand((unsigned)time(&t));
    return rand() % 100 + 1;
}

bool maybe_continue() {
    cout << "Do you want to continue? (y/n) ";
    char answer;
    cin >> answer;
    return answer == 'y';
}

bool process_guess(int rand_num, int guess) {
    if (rand_num == guess) {
        cout << "You win!" << endl;
        return true;
    }

    if (rand_num < guess)
        cout << "Guess is smaller" << endl << endl;
    else
        cout << "Guess is bigger" << endl << endl;

    return false;
}

int main() {
    do {
        print_greating();

        int rand_num = random_number();

        while (true) {
            print_offer_input();
            int guess;
            cin >> guess;
            if (process_guess(rand_num, guess))
                break;
        }

    } while (maybe_continue());

    return 0;
}
