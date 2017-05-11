// CBSE project beta 1.0
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <ctype.h>
#include <process.h>
#include <conio.h>
#include <stdio.h>

fstream file("HIGHSCORE.DAT", ios::out|ios::in|ios::binary);
void rules();
void highscore();
void welcome();
class player
{char name[15];
	int sc;
	int g;
	public:
	player()
		{sc=0;g=0;}
	void incsc(int n=1)
		{sc=sc+n;}
	void getname()
	{cout<<"\nEnter player name: ";
		gets (name);
	}
	void dispscore()
	{cout<<"\nPlayer Name: "<<name<<endl;
		cout<<"Player Score: "<<sc;cout<<endl;
		cout<<"Number of guesses: "<<g<<endl;
	}
	void addg(int n=1)
		{g+=n;}
};
player p1;
class hangman{
private:
	 char guessword[15];
	 char temp;
	 char inputword[15];
	 char ttt[15];
	 int wrong;
	 int score;
	 int gus;
public:
	 hangman()
	 {wrong=-1;score=0;gus=0;}
	 void blanks();
	 void scored()
	 {cout<<score;}
	 void gusinc()
		{gus++;}
	 int gusret()
		{return(gus);}
	 int winner()
		{if(strcmp(ttt,guessword)==0)
			{cout<<"\nCongratulations!\nYou have won!\n";p1.incsc(8);
			return (0);}
		else
			return(10);
		}
	 void inputw()
	 {cout<<"\nEnter word to be guessed:\n";
		  cin>>guessword;
		  clrscr();
	 }
	 void fillblanks(char gu);

	 int gword(char wrd[])
	 {if(strcmp(wrd, guessword)==0)
	 {cout<<"\nCongratulations!\nYou have won!";
		 p1.incsc(8);
	 return(0);}
	 else
	 {wrong++;
	 cout<<"Incorrect guess!\n"<<endl;
	 fillblanks(' ');
	 gusinc();
	 p1.addg(gus);
	 return(10);}}
};
void hangman::blanks()
{int l;
for(l=0;guessword[l]!='\0';l++)
	{cout<<"__ ";}
	cout<<endl;
}
void hangman::fillblanks(char gu)
{int i,cnt=0;
	if(gu==' ')
		{for (i=0; guessword[i]!='\0'; i++) {
		  if(ttt[i]==guessword[i])
		  {cout<<guessword[i]<<' ';}
		  else
		  {cout<<"__ ";}
	 }}
	else
	 {for (i=0; guessword[i]!='\0'; i++) {
		  if (gu==guessword[i]) {
				ttt[i]=guessword[i];
				cnt++;
				p1.incsc();
		  }
				}

	 if (cnt==0) {cout<<"\n******Character not found******\n";
		  wrong++;
		  gusinc();

	 }
	 if(strcmp(ttt, guessword)==0)
	 {cout<<"You Won!";p1.incsc(8);}
	 for (i=0; guessword[i]!='\0'; i++) {
		  if(ttt[i]==guessword[i])
		  {cout<<guessword[i]<<' ';}
		  else
		  {cout<<"__ ";}
	 }
	 cout<<'\n'; }

}



void main()
{hangman h;
	 int guess=0,i,j=0,k=0,x=100,y=100;x=0;
	 char t,tw[15],used[8],cont[3];
	 welcome();
	 do{
	 do{cout<<"Enter 1 for rules\nEnter 2 for Highscores\nEnter 3 to play: ";
	 cin>>x;
	 if(x==1)
		{rules();}
	 else if(x==2)
		{highscore();}
	 }while(x!=3);
	 p1.getname();
	 h.inputw();
	 h.blanks();
	 while (h.gusret()!=8)
	 {guess=h.gusret();
		cout<<"Guesses left: "<<8-guess<<'\n';
		  cout<<"Enter 1 to input character and 2 to input word: ";
		  cin>>k;
			p1.addg();
		  if(k==1)
		  {cout<<"Enter character to guess: \n";
		  cin>>t;
		  cout<<'\n';
				used[j]=t;
				j++;
				h.fillblanks(t);}
		  else if(k==2)
		  {cout<<"Enter Guess: ";
				cin>>tw;
				y=h.gword(tw);
		  }

			x=h.winner();
			if(x==0)
				{break;}

		  if(y==0)
			{break;}

	 }
	 if(guess>=8)
		{cout<<"Game Over!\nExceeded guess number.";}
	 file.write((char*)&p1,sizeof(p1));
	 p1.dispscore();
	 cout<<"Enter 'Yes' to play again"<<endl;
	 cin>>cont;
	 clrscr();
}while(strcmp(cont,"Yes")==0);
}

void welcome()
{cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

		  cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

		  cout<<"                             WELCOME TO HANGMAN                           \n";

		  cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

		  cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";

}

void rules()
{cout<<"Hello!\nWelcome to Hangman Beta 1.0. The rules of the game are as follows:\n";
	cout<<"A player must enter a word to be guessed and a second player will have to guess the word.\nAll characters must be in lower case and once you have guessed all the characters you must type in the word to win.\n";
	cout<<"For every correct guess you get 1 point and for guessing the correct word you get 8 points.\nYou only have 8 guesses.\n\n";
}

void highscore()
{file.seekg(0);player P;
	while(file.read((char*)&P,sizeof(P)))
		{
			P.dispscore();
			}

}

