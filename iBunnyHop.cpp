/*
Basic BunnyHop Script edited by badiiiro for Counter-Strike 1.6
*/
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

char editedBy[] = "badiiiro";

void setColor(int ForgC);
void outputProgramFeatures();
void iBunnyHop();

void setColor(int ForgC)
{
    WORD wColor;
    //This handle is needed to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    //csbi is used for wAttributes word
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //To mask out all but the background attribute, and to add the color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
	return;
}
void outputProgramFeatures()
{
	// Write text to Readme.txt
	ofstream writeToReadMe;
	writeToReadMe.open ("Readme.txt");
	writeToReadMe << "iBunnyHop v0.1\n\nThis script is undetectable in Valve Anti Cheat system because it doesnt access any memory within the game\nUsage: Press F5 = ON/OFF\nIn game consol: bind \"MWHEELUP\" \"+jump\"\n\nContact badiiiro at:\nFacebook: https://www.facebook.com/badiiiro/\nYoutube: https://www.youtube.com/badiiiro/\nSteam: https://steamcommunity.com/id/badiiiro/\nDiscord Server: https://discord.gg/Pzzsd3J\n\nAll rights reserved (C) badiiiro";
	writeToReadMe.close();
	// Program features
	setColor(12);  
	cout << "================================================================================\n";
	setColor(9);  
	cout << "\t\t\t}--{+} iBunnyHop v0.1 {+}--{ \n\t\t\t}-{*} Coded By " << editedBy << " {*}-{\n\n"; 
	setColor(12);  
	cout << "================================================================================\n";
	setColor(15);  	
	cout << "Usage: Press F5 = ON/OFF\nIn game consol: bind \"MWHEELUP\" \"+jump\"\n\n";
}
void iBunnyHop()
{
	start: 
	CONST int scrolldown = -120;
	CONST int scrollup = 120;
	 while (true){
		if (GetAsyncKeyState(VK_F5)) 
		{
			while (true)
			{				
				Sleep(20); //play around with this for other games, 20 is best for cs 1.6
				mouse_event(MOUSEEVENTF_WHEEL, 0, 0, scrollup, 0); //make sure you have mwheelup binded to +jump in game
				if (GetKeyState(VK_F5))
				{
					goto start;
				}
			}
		}
	}
}
int main(){
	outputProgramFeatures();
	iBunnyHop();
}
