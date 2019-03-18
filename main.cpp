/*
 Alex Hughes
 CS 110B
 3/14/19
 Professor Dave
 Assignment 7.1

 A program that records high-score data for a fictitious game. The program will ask the user to enter five names,
 and five scores. It will store the data in memory, and print it back out sorted by score. Then rewrite my most recent
 high scores program so that each name/score pair is stored in a struct named highscore.
 */


#include <iostream>
#include <string>
using namespace std;


struct highscore
{

    int score;
    char name[24];
};


void initializeArrays(highscore scores[], int size);
void displayData(highscore scores[], int size);
void sortData(highscore scores[], int size[]);






void initializeArrays(highscore scores[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the name for the score #" << i + 1 << ": ";
        cin >> scores[i].name;

        cout << "Enter the score for the score #" << i + 1 << ": ";
        cin >> scores[i].score;
    }
}







void sortData(highscore scores[], int size)
{
    int i, j;
    highscore minObj, temp;

    for (int i = 0; i < size; i++)
        {
            for (j = i + 1; j < size; j++)
            {
                if(scores[i].score > scores[j].score)
                {
                    temp = scores[i];
                    scores[i]=scores[j];
                    scores[j]= temp;

                }
            }
        }
        }







void displayData(highscore scores[], int size) {
    for (int i = 0; i < size; i++) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    }


}






int main() {
    int *pointer = nullptr;

    pointer = new int;

    cout << "How many scores will you enter?";
    cin >> *pointer;
    const int size = *pointer;

    highscore *obj = new highscore[size];

    initializeArrays(obj, size);

    displayData(obj, size);

    sortData(obj, size);
}