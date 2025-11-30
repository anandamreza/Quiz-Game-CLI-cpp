#include<iostream>
#include<vector>
#include<string>

class Questions
{
    public:
        std::string question;
        std::string options[4];
        int correctAnswer;

        Questions
        (
            std::string q, 
            std::string opt1, 
            std::string opt2, 
            std::string opt3, 
            std::string opt4, 
            int answer
        )
            : question(q), correctAnswer(answer)
        {
            options[0] = opt1;
            options[1] = opt2;
            options[2] = opt3;
            options[3] = opt4;
        }

        bool checkAnswer(int choice)
        {
            return choice == correctAnswer; //kalo jawaban sama = true, 
                                            //kalo jawaban beda = false.
        }
};

class GameManager
{
    public:
        std::vector<Questions> questionlist;
        int score=0;

        void play()
        {
            for(int i = 0; i < questionlist.size(); i++)
            {
                auto& q = questionlist[i];
                std::cout << q.question << '\n';

                for(int j = 0; j < 4; j++)
                {
                    std::cout << j+1 << ". " << q.options[j] << '\n';
                }
            
                int takeAnswer;
                std::cout << "Your answer (1-4): ";
                std::cin >> takeAnswer;

                if(takeAnswer - 1 == q.correctAnswer)
                {
                    std::cout << "Correct!\n\n";
                    score++;
                }
                else
                {
                    std::cout << "Incorrect! The correct answer was: " 
                    << q.options[q.correctAnswer] << "\n\n";
                }
            }
            std::cout << "Score: " << score << '/' << questionlist.size() << '\n';
        }
};

int main()
{
    GameManager game;

    std::cout << "WELCOME TO THE QUIZ SHOW!\n"; 
    
    game.questionlist.push_back
    (
        Questions
        (
            "What is the capital of Indonesia?",
            "Jakarta",
            "Bandung",
            "Surabaya",
            "Medan",
            0 
        )
    );

    game.questionlist.push_back
    (
        Questions
        (
            "What is the first president of Indonesia?",
            "Bennito Mussolini",
            "Mohammed Hijab",
            "Ir. Soekarno",
            "Dr. Strange",
            2
        )
    );

    game.questionlist.push_back
    (
        Questions
        (
            "What is the largest continent in the world?",
            "Asia",
            "Africa",
            "Europe",
            "America",
            0
        )
    );

    game.questionlist.push_back
    (
        Questions
        (
            "What is the first element on the periodic table?",
            "Vibranium",
            "Argon",
            "Hydrogen",
            "Oxygen",
            2
        )
    );

    game.play();

    std::cout << "Thank you for playing the quiz!\n";

    return 0;
}