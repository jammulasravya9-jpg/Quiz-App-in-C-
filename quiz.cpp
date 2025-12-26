#include <iostream>
using namespace std;

class Question {
    string question;
    string opt1, opt2, opt3, opt4;
    int correctAnswer;

public:
    Question() {}

    Question(string q, string o1, string o2, string o3, string o4, int ans) {
        question = q;
        opt1 = o1;
        opt2 = o2;
        opt3 = o3;
        opt4 = o4;
        correctAnswer = ans;
    }

    void display() {
        cout << "\n" << question << endl;
        cout << "1) " << opt1 << endl;
        cout << "2) " << opt2 << endl;
        cout << "3) " << opt3 << endl;
        cout << "4) " << opt4 << endl;
    }

    bool checkAnswer(int userAnswer) {
        return userAnswer == correctAnswer;
    }
};

class Quiz {
    Question questions[5];
    int totalQuestions;
    int score;

public:
    Quiz() {
        totalQuestions = 5;
        score = 0;

        questions[0] = Question("Who invented C++?", "Dennis Ritchie", "Bjarne Stroustrup", "James Gosling", "Guido Van Rossum", 2);
        questions[1] = Question("Which OOPS concept hides data?", "Inheritance", "Encapsulation", "Polymorphism", "Abstraction", 2);
        questions[2] = Question("Which keyword creates object?", "class", "object", "new", "create", 3);
        questions[3] = Question("C++ is extension of?", "C", "Java", "Python", "C#", 1);
        questions[4] = Question("Which is not OOPS concept?", "Abstraction", "Inheritance", "Compilation", "Polymorphism", 3);
    }

    void startQuiz() {
        int answer;

        for(int i = 0; i < totalQuestions; i++) {
            questions[i].display();
            cout << "Enter your answer (1-4): ";
            cin >> answer;

            if(questions[i].checkAnswer(answer)) {
                cout << "Correct!\n";
                score++;
            } else {
                cout << "Wrong!\n";
            }
        }

        cout << "\n========== RESULT ==========\n";
        cout << "Score: " << score << " / " << totalQuestions << endl;
        cout << "============================\n";
    }
};

int main() {
    Quiz q;
    q.startQuiz();
    return 0;
}
