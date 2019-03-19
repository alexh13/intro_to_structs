/*
 Alex Hughes
 CS 110B
 3/14/19
 Professor Dave
 Assignment 7.1

 A program that records high-score data for a fictitious game. The program will ask the user to enter five names,
 and five scores. It will store the data in memory, and print it back out sorted by score. Then rewrite my most recent
 high scores program so that each name/score pair is stored in a struct named highscore. The program asks the user to
 enter the amount of scores, then asks for the name and the score of each player in the original amount entered. Once
 that data is collected the program executes and returns the list of scores from highest to lowest.
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
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(scores[i].score < scores[j].score)
            {
                highscore temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}







void displayData(highscore scores[], int size) {
    cout << "Top Scores:" << endl;
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

    sortData(obj, size);

    displayData(obj, size);
}






/* Output:
How many scores will you enter?4
Enter the name for the score #1: Alex
Enter the score for the score #1: 13
Enter the name for the score #2: Sasha
Enter the score for the score #2: 15
Enter the name for the score #3: Max
Enter the score for the score #3: 19
Enter the name for the score #4: Morgan
Enter the score for the score #4: 8
Top Scores:
Max: 19
Sasha: 15
Alex: 13
Morgan: 8
*/