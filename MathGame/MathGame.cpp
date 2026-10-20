#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

struct stGameResults {
    int HowManyQustions = 0;
    enQuestionsLevel Level;
    enOperationType Operation;
    int Number1 = 0;
    int number2 = 0;
};


int ReadPositiveNumber() {
    int number;

    do {
        cout << "How many Questions do you want to answer ? ";
        cin >> number;
    } while (number <= 0 || number > 100);
    return number;
}

enQuestionsLevel QuestionsLevel() {
    short Choise;

    do {

        cout << "Enter Questions Level : [1] : Easy, [2] : Med, [3] : Hard, [4] Mix ? ";
        cin >> Choise;

    } while (Choise < 1 || Choise > 4);


    return enQuestionsLevel(Choise);
}






enOperationType OperationType() {
    int choise;

    do {
        cout << "Enter Operations Type : [1] : Add, [2] : Sub, [3] : Mul, [4] Div , [5] Mix ? ";
        cin >> choise;

    } while (choise < 1 || choise > 5);

    return enOperationType(choise);
}


//select number
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

int SelectNumberForLevel(enQuestionsLevel Level) {
    switch (Level) {
    case enQuestionsLevel::EasyLevel:
        return RandomNumber(1, 10);
    case enQuestionsLevel::MedLevel:
        return RandomNumber(10, 50);
    case enQuestionsLevel::HardLevel:
        return RandomNumber(10, 100);
    case enQuestionsLevel::Mix:
        return RandomNumber(1, 100);
    }
    return RandomNumber(1, 100);
}

//calclute 
int AddNumber(int number1, int number2) {
    return number1 + number2;
}
int SubNumber(int number1, int number2) {
    return number1 - number2;
}
int MulNumber(int number1, int number2) {
    return number1 * number2;
}
float DivNumber(int number1, int number2) {
    return (number2 != 0) ? ((float)number1 / number2) : 0;
}

float CalculateNumber(enOperationType OperationType, int number1, int number2) {
    switch (OperationType) {
    case enOperationType::Add:
        return AddNumber(number1, number2);
    case enOperationType::Sub:
        return  SubNumber(number1, number2);
    case enOperationType::Mult:
        return MulNumber(number1, number2);
    case enOperationType::Div:
        return DivNumber(number1, number2);

    }
    return 0;

}





//print operatios
string Operation(enOperationType Type) {

    switch (Type) {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "*";
    case enOperationType::Div:
        return "/";
    case enOperationType::MixOp:
        return "mix";
    }
    return "Unknown";
}

//print level
string Level(enQuestionsLevel Level) {

    switch (Level) {
    case enQuestionsLevel::EasyLevel:
        return "EasyLevel";
    case enQuestionsLevel::MedLevel:
        return "MedLevel";
    case enQuestionsLevel::HardLevel:
        return "HardLevel";
    case enQuestionsLevel::Mix:
        return "Mix";
    }
    return "Unknown";
}

//print quize
void PrintQuize(int number1, int number2, enOperationType Type) {
    cout << number1 << endl;
    cout << number2 << " " << Operation(Type) << endl;
    cout << "-------------" << endl;
}




void FillOfQustaion(int numberofqustions, enQuestionsLevel QuestionsLevel, enOperationType OperationType, int NumberOfRihthAnswer, int NumberOfWrongAnswer) {
    cout << endl;
    if (NumberOfRihthAnswer > NumberOfWrongAnswer)cout << "Final Result Is Pass"; else cout << "Final Result Is Fail";
    cout << "\n-------------------------------" << endl;
    cout << "number of qustions : " << numberofqustions << endl;
    cout << "QuestionsLevel  : " << Level(QuestionsLevel) << endl;
    cout << "Operation Type : " << Operation(OperationType) << endl;
    cout << "NumberOfRihthAnswer : " << NumberOfRihthAnswer << endl;
    cout << "NumberOfWrongAnswer : " << NumberOfWrongAnswer << endl;

    cout << "-------------------------------";
}

//mix operation 
enOperationType GetRandomOperation() {
    return enOperationType(RandomNumber(1, 4));
}
//mix level 
enQuestionsLevel GetRandomLevel() {
    return enQuestionsLevel(RandomNumber(1, 3));
}



void PlayGame() {
    stGameResults st;

    int CorcctAnswer = 0, WoringAnswer = 0;

    st.HowManyQustions = ReadPositiveNumber();
    st.Level = QuestionsLevel();
    st.Operation = OperationType();


    enOperationType CurrentOperation = st.Operation;
    enQuestionsLevel CurrentLevel = st.Level;


    for (int i = 1; i <= st.HowManyQustions;i++) {
        if (st.Operation == enOperationType(5)) {
            CurrentOperation = GetRandomOperation();
        }
        if (st.Level == enQuestionsLevel(4)) {
            CurrentLevel = GetRandomLevel();
        }


        float Answer = 0;
        cout << "\n\nquestion [" << i << "/" << st.HowManyQustions << "]" << endl;

        st.Number1 = SelectNumberForLevel(CurrentLevel);
        st.number2 = SelectNumberForLevel(CurrentLevel);
        cout << endl;
        PrintQuize(st.Number1, st.number2, CurrentOperation);
        cin >> Answer;

        float value = CalculateNumber(CurrentOperation, st.Number1, st.number2);

        if (Answer == value) {
            cout << "\nCorcct Answer : " << value;
            system("color 0A");
            CorcctAnswer++;
        }
        else {
            cout << "\nWoring Answer : " << value;
            system("color 0C");
            WoringAnswer++;
        }

    }
    FillOfQustaion(st.HowManyQustions, st.Level, st.Operation, CorcctAnswer, WoringAnswer);
}

void ResetScreen() {
    system("cls");
    system("color 0F");

}


void StartGame() {
    char PlayAgine = 'Y';

    do {
        PlayGame();
        cout << "Do you want to play again? Y/N  ";
        cin >> PlayAgine;
        ResetScreen();

    } while (PlayAgine == 'y' || PlayAgine == 'Y');
}



int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}


