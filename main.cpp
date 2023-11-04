#include <bits/stdc++.h>
using namespace std;

struct StoryNode {
    string outcome;
    string op1 = "";
    string op2 = "";

    struct StoryNode *ch1 = NULL;
    struct StoryNode *ch2 = NULL;
} *startNode;

struct StoryNode * setStory(string a, string b, string c){
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
    //level-0
   startNode = setStory("1. Enter the Enchanted Forest.", "2. Turn back and leave the forest behind.", 
   "You find yourself at the edge of the Enchanted Forest. What will you do?");

    //level-1
   StoryNode *ForestEnter = setStory("1. Follow the path to the left, where a faint melody can be heard.", 
   "2. Take the path to the right, where a dim, mysterious light glows.",
   "You entered the Enchanted Forest");

    StoryNode *ForestVoice = setStory(" ", 
   " ",
   "As you turn back, you hear a whispering breeze that seems to say, \"The forest will remember you.\"");

    //level-2
   StoryNode *dimLight = setStory("1. Push through the thicket.", 
   "2. Turn back.",
   "You find yourself in a dense thicket, the air growing colder.");

   
   StoryNode *melody = setStory("1. Investigate the ancient stones.", 
   "2. Leave the grove.",
   "You find yourself in a moonlit grove, where ancient \nstones form a circle. Whispers fill the air.");

    //level-3
   StoryNode *figure = setStory("1. Speak to the figure.", 
   "2. Retreat cautiously.",
   "As you approach the stones, a spectral figure \nmaterializes, its eyes filled with longing.");

    StoryNode *cave = setStory("1. Follow a faint, ghostly light.", 
   "2. Explore an ominous-looking cave.",
   "You continue deeper into the forest, the melody fading into the distance.");

    StoryNode *mansion = setStory("1. Enter the mansion.", 
   "2. Continue along the path.",
   "As you forge ahead, you come across an eerie, dilapidated mansion covered in ivy.");
    

    StoryNode *yourReturn = setStory(" ", 
   " ",
   "You rush out of the mansion, heart pounding.");


   //level-4
   StoryNode *loveStory = setStory(" ", 
   " ",
   "The figure shares a tale of lost love and a secret buried within the forest.");

    StoryNode *RunAway = setStory(" ", 
   " ",
   "You back away slowly, leaving the grove.");


   StoryNode *shrine = setStory(" ", 
   " ",
   "The light leads you to a forgotten shrine, where whispers echo through the silence.");


   StoryNode *dance = setStory("1. Join the spectral dance.", 
   "2. Flee the mansion.",
   "Inside, you encounter ghostly apparitions that seem \ntrapped in a never-ending ballroom waltz.");

   StoryNode *treasure = setStory(" ", 
   " ",
   "Inside the cave, you uncover ancient markings that hint at a hidden treasure.");

    StoryNode *calmClearing = setStory(" ", 
   " ",
   "You press on, the thicket eventually giving way to an eerily calm clearing.\nIn the center of the clearing stands a weathered statue, its features worn by time.");


    //level-5
    StoryNode *despair = setStory(" ", 
   " ",
   "You become part of the haunting dance, your senses overwhelmed by the music and despair.");

   StoryNode *heart = setStory(" ", 
   " ",
   "You rush out of the mansion, heart pounding.");

    //connection
   
   startNode->ch1 = ForestEnter;
   startNode->ch2 = ForestVoice;

   startNode->ch1->ch1 = melody;
   startNode->ch1->ch2 = dimLight;

   startNode->ch1->ch1->ch1 = figure;
   startNode->ch1->ch1->ch2 = cave;
   startNode->ch1->ch2->ch1 = mansion;
   startNode->ch1->ch2->ch2 = yourReturn;

   startNode->ch1->ch1->ch1->ch1 = loveStory;
   startNode->ch1->ch1->ch1->ch2 = RunAway;
   startNode->ch1->ch1->ch2->ch1 = shrine;
   startNode->ch1->ch1->ch2->ch2 = treasure;
   startNode->ch1->ch2->ch1->ch1 = dance;
   startNode->ch1->ch2->ch1->ch2 = calmClearing;

   startNode->ch1->ch2->ch1->ch1->ch1 = despair;
   startNode->ch1->ch2->ch1->ch1->ch2 = heart;
   
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
    system("clear");
    cout << "WELCOME TO ENCHANTED FOREST\n";
    system("sleep 2s");
    creatStory();
    
    int chose = -1;
    while(chose){
        system("sleep 2s");
        system("clear");
        cout << "\n\n1. Play\n";
        cout << "2. Quit\n";
        cin >> chose;
        if(chose==1){
            playStory();
        }
        else if(chose==2) chose = 0;
    }

    return 0;
}