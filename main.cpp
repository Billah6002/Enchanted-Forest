#include <bits/stdc++.h>
using namespace std;

struct StoryNode {
    string outcome;
    string op1 = "";
    string op2 = "";

    struct StoryNode * ch1 = NULL;
    struct StoryNode *ch2 = NULL;
} *startNode;

StoryNode * setStory(string a, string b, string c){
    struct StoryNode *currentNode = (StoryNode*)malloc(sizeof(StoryNode));
    string x(a);
    currentNode->op1 = x;
    string y(b);
    currentNode->op2 = y;
    string z(c);
    currentNode->outcome = z;
    return currentNode;
}



void creatStory(){
   startNode = setStory("1. Enter the Enchanted Forest.", "2. Turn back and leave the forest behind.", 
   "You find yourself at the edge of the Enchanted Forest. What will you do?");


   StoryNode *ForestEnter = setStory("1. Follow the path to the left, where a faint melody can be heard.", 
   "2. Take the path to the right, where a dim, mysterious light glows.",
   "You entered the Enchanted Forest");


   StoryNode *leftPath = setStory(" ", " ", "You join the fairy's dance.");
   StoryNode *rightPath = setStory(" ", " ", "You ask for a boon.");

   StoryNode *cp = startNode;
   startNode->ch1 = ForestEnter;
   cp = startNode->ch1;
   cp->ch1 = leftPath;
   cp->ch2 = rightPath;
   
}

void playStory(){
    StoryNode *temp = startNode;
    while(temp != NULL){
        int chose;
        system("clear");
        cout << "\n";
        cout << temp->outcome << "\n";
        if(temp->op1 != " ")
            cout << temp->op1 << "\n";
        if(temp->op2 != " ")
            cout << temp->op2 << "\n";

        if(temp->op1 == " " or temp->op2 == " "){
            temp = NULL;
            continue;
        }
        cin >> chose;
        if(chose==1){
            temp = temp->ch1;
        }
        else if(chose == 2){
            temp = temp->ch2;
        }
    }
}



int main() {
    creatStory();
    playStory();

    return 0;
}
