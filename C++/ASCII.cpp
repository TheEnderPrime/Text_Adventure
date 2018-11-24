#include <iostream>
#include <string>
#include <time.h>

#include "Player.h"
#include "ASCII.h"

using namespace std;

//INITIAL START UP FUNCTIONS
ASCII::ASCII ()
{

}

void ASCII::Welcome ()
{
    cout << "                     _                                \n";
    cout << "                   (` '.                              \n";
    cout << "        _.--.     /   a '-.                           \n";
    cout << "        '->  \\ __/     __.'   ______ ______  _____   \n";
    cout << "         <_   |.'  /`-._)`-   | ___ \\| ___ \\|  __ \\  \n";
    cout << "           >--'    \\          | |_/ /| |_/ /| |  \\/  \n";
    cout << "        .--;'       |--.      |    / |  __/ | | __   \n";
    cout << "  ,-    _\\.'        |   \\_    | |\\ \\ | |    | |_\\ \\  \n";
    cout << " //    /-'    \\    / `\\__/    \\_| \\_|\\_|     \\____/  \n";
    cout << "| |  .'       /_._ |                                  \n";
    cout <<"\\  '-'  _/  --.  \\ ' -.                             \n";
    cout <<"'.___.-' \\____/jgs\\___/                             \n\n";

    cout <<"WELCOME TO MY RPG\n\n";
}

void ASCII::pageBreak(void)
{
    cout <<"                                                           \n";
    cout <<"               ,                                           \n";
    cout <<"              (@|                                          \n";
    cout <<" ,,           ,)|_____________________________________     \n";
    cout <<"//\\\\8@8@8@8@8@8 / _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ \\ \n";
    cout <<"\\\\//8@8@8@8@8@8 \\_____________________________________/ \n";
    cout <<" ``           `)|                                          \n";
    cout <<" jgs          (@|                                          \n";
    cout <<"              `                                            \n";
    cout <<"                                                           \n";

}

void ASCII::Victory(void)
{
    cout <<"\n";
    cout <<" _   _  _____  _____  _____  _____ ______ __   __\n";
    cout <<"| | | ||_   _|/  __ \\|_   _||  _  || ___ \\\\ \\ / /\n";
    cout <<"| | | |  | |  | /  \\/  | |  | | | || |_/ / \\ V / \n";
    cout <<"| | | |  | |  | |      | |  | | | ||    /   \\ /  \n";
    cout <<"\\ \\_/ / _| |_ | \\__/\\  | |  \\ \\_/ /| |\\ \\   | |  \n";
    cout <<" \\___/  \\___/  \\____/  \\_/   \\___/ \\_| \\_|  \\_/  \n";
    cout <<"\n";
}

void ASCII::Defeat(void)
{
    cout <<"\n";
    cout <<"______ ___________ _____  ___ _____ \n";
    cout <<"|  _  \\  ___|  ___|  ___|/ _ \\_   _|\n";
    cout <<"| | | | |__ | |_  | |__ / /_\\ \\| |  \n";
    cout <<"| | | |  __||  _| |  __||  _  || |  \n";
    cout <<"| |/ /| |___| |   | |___| | | || |  \n";
    cout <<"|___/ \\____/\\_|   \\____/\\_| |_/\\_/  \n";
    cout <<"\n";
}

void ASCII::Egg1(void)
{
    cout <<"           .-\"-.    \n";
    cout <<"         .'     '.  \n";
    cout <<"        /         \\ \n";
    cout <<"       :           ;\n";
    cout <<"       |           |\n";
    cout <<"       :           :\n";
    cout <<"        \\         / \n";
    cout <<"         `.     .'  \n";
    cout <<"     jgs   `~~~`    \n";
}

void ASCII::Egg2(void)
{
    cout <<"           .-\"-.    \n";
    cout <<"         .'     '.  \n";
    cout <<"        /         \\ \n";
    cout <<"       :           ;\n";
    cout <<"       |           |\n";
    cout <<"       :      'Y   :\n";
    cout <<"        \\       \\ / \n";
    cout <<"         `.     .'  \n";
    cout <<"     jgs   `~~~`    \n";
}

void ASCII::Egg3(void)
{
    cout <<"           .-\"-.    \n";
    cout <<"         .'     '.   \n";
    cout <<"        /         \\ \n";
    cout <<"       :        \\/ ; \n";
    cout <<"       |    __  /  | \n";
    cout <<"       :      'Y   : \n";
    cout <<"        \\       \\ / \n";
    cout <<"         `.     .'   \n";
    cout <<"     jgs   `~~~`     \n";
}

void ASCII::Egg4(void)
{
    cout <<"           .-\"-.    \n";
    cout <<"         .'     '.   \n";
    cout <<"        /    _\\_  \\ \n";
    cout <<"       :        \\/ ; \n";
    cout <<"       |   \\__  /  | \n";
    cout <<"       :   /  'Y   : \n";
    cout <<"        \\       \\ / \n";
    cout <<"         `.     .'   \n";
    cout <<"     jgs   `~~~`     \n";
}

void ASCII::Egg5(void)
{
    cout <<"           .-\"-.    \n";
    cout <<"         .'  \\/ '.   \n";
    cout <<"        /\\/  _\\_  \\ \n";
    cout <<"       : _\\     \\/ ; \n";
    cout <<"       |   \\__  /  | \n";
    cout <<"       :  _/  `Y-- : \n";
    cout <<"        \\ /  .--\\ / \n";
    cout <<"         `. /   .'   \n";
    cout <<"     jgs   `~~~`     \n";
}

void ASCII::Egg6(void)
{
    cout <<"           .-\\\"-.         \n";
    cout <<"         .' `\\/_'.         \n";
    cout <<"        /\\/ \\_\\_  \\     \n";
    cout <<"       : _\\ /   \\//       \n";
    cout <<"       |/  \\__/ / \\       \n";
    cout <<"       : \\_/  `Y--':       \n";
    cout <<"        \\ / \\.--\\ /      \n";
    cout <<"         `. /   .'  /\\     \n";
    cout <<"     jgs   `~~~` .-.`\"     \n";
    cout <<"                 `'`        \n";
}
void ASCII::Egg7(void)
{
    cout <<"           .-\"-.         \n";
    cout <<"         .' `\\/_'.         \n";
    cout <<"        /\\/{\\_\\/\\/\\     \n";
    cout <<"        `\\ | \" | /\\       \n";
    cout <<"       //:\\(o o)//\\\\       \n";
    cout <<"       |/  \\_^/\\_/\\|       \n";
    cout <<"       : \\_/  `Y--':      \n";
    cout <<"   /^|  \\ / \\.--\\ /    |\\     \n";
    cout <<"   `\" .-.`. /   .'  /\\ `~     \n";
    cout <<"     jgs`  `~~~` .-.`\"        \n";
    cout <<"                 `'`        \n";
}

void ASCII::Egg8(void)
{
    cout <<"      _(,  {\\V/}  ,)_         \n";
    cout <<"        /\\ |\" | /\\         \n";
    cout <<"       //\\\\(o o)//\\\\ \\/\\-'^^\\/\\/     \n";
    cout <<"       ||::/ ^ \\::||  '.     .'       \n";
    cout <<"       : \\_/\\_/`Y-':    '-.-'       \n";
    cout <<"   /^|  \\ / \\.--\\ /    |\\       \n";
    cout <<"   `\" .-.`. /   .'  /\\ `~      \n";
    cout <<"     jgs`  `~~~` .-.`\"     \n";
    cout <<"         /'.     `'`     \n";
    cout <<"         ``        \n";
}

void ASCII::Egg9(void)
{
    cout <<"      _(,  {\\V/}  ,)_         \n";
    cout <<"        /\\ |\" | /\\         \n";
    cout <<"       //\\\\(o o)//\\\\ \\/\\-'^^\\/\\/     \n";
    cout <<"       ||::/ ^ \\::||  '.     .'    \n";
    cout <<"       : \\_/\\_/`Y-':    '-.-'     \n";
    cout <<" /^|\\ /|'  \" \"/  '|-\\ /|\\          \n";
    cout <<" `\" .`.     )I(    .'/\\ `~          \n";
    cout <<"   jgs``~  \"\"`\"\"  `-.`\"             \n";
    cout <<"       /'.          `'`             \n";
    cout <<"       ``                           \n";
}

void ASCII::Egg10(void)
{
    cout <<"      _(,  {\\V/}  ,)_    \n";
    cout <<"        /\\ | \" | /\\      \n";
    cout <<"       //\\\\(o o)//\\\\     \n";
    cout <<"       ||::/ ^ \\::||     \n";
    cout <<"       |||((   ))|||     \n";
    cout <<"       |'  \\\" \"/  '|     \n";
    cout <<"            )I(          \n";
    cout <<"   jgs     \"\"`\"\"         \n";
}

void ASCII::DragonHatch()
{
    int i;
    Egg1();
    for(i=0;i<200000000;i++);
    Egg2();
    for(i=0;i<200000000;i++);
    Egg3();
    for(i=0;i<200000000;i++);
    Egg4();
    for(i=0;i<200000000;i++);
    Egg5();
    for(i=0;i<200000000;i++);
    Egg6();
    for(i=0;i<200000000;i++);
    Egg7();
    for(i=0;i<200000000;i++);
    Egg8();
    for(i=0;i<200000000;i++);
    Egg9();
    for(i=0;i<200000000;i++);
    Egg10();
}

/*eventualy quest will return a int for which quest is choosen
You could use the pointer int requirement here later*/

void ASCII::getQuest(void)
{
    cout <<"\nBrave Adventurer! Welcome to our most humble town!";
    cout <<"\nMy name is Isaac Alexi Carroll! I am the mayor of this here town.";
    cout <<"\nCreatures of all manner have taken camp on the outskirts.";
    cout <<"\nA Terrible Dragon has recently arrived and has become their leader\n";
    cout <<"\nKill The Monsters! Kill The Dragon!\n";
    cout <<"I think if you were to kill 5 Monsters, the Dragon would be so enraged that he will fight you himself!\n";
    cout <<"Folks are terrified to leave their homes, much less fight of monsters.\n";
    cout <<"Please Help Us!";
}

/*Pretty Picture
    cout <<"   ,   A           {}     \n");
    cout <<"  / \\, | ,        .--.    \n");
    cout <<" |    =|= >      /.--.\\   \n");
    cout <<"  \\ /` | `       |====|   \n");
    cout <<"   `   |         |`::`|   \n");
    cout <<"       |     .-;`\\..../`;_.-^-._     \n");
    cout <<"      /\\\\/  /  |...::..|`   :   `|   \n");
    cout <<"      |:'\\ |   /'''::''|   .:.   |   \n");
    cout <<"       \\ /\\;-,/\\   ::  |..:::::..|   \n");
    cout <<"       |\\ <` >  >._::_.| ':::::' |   \n");
    cout <<"       | `\"\"`  /   ^^  |   ':'   |   \n");
    cout <<"       |       |       \\    :    /   \n");
    cout <<"       |       |        \\   :   /    \n");
    cout <<"       |       |___/\\___|`-.:.-`     \n");
    cout <<"       |        \\_ || _/             \n");
    cout <<"       |        <_ >< _>             \n");
    cout <<"       |        |  ||  |             \n");
    cout <<"       |        |  ||  |             \n");
    cout <<"       |       _\\.:||:./_            \n");
    cout <<"       | jgs  /____/\\____\\           \n");
    cout <<"                                     \n");
*/
