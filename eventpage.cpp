#include<iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
   cout << "\t\tEVENT PAGE\n\t\t----------\n\n";
   	string output, temp, title, input, date, time,posth;
   	int ch;
   	int tempi;
   	cout << "\n\n\nENTER TITLE :";
   	getline(cin,title);
   	bool l_c=true;
   	bool content_enter=false;
   	
   	/*
   	time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	char time_string[100];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	date = strftime(date_string, 50, "%B %d, %Y", curr_tm);
	time = strftime(time_string, 50, "%T", curr_tm);
	*/
	
	date="";
	time="";
   	
   	
   	while(l_c)
   	{
   	
   		cout << "\n\n\t\tChoose Content :\n\t";
   		cout << "1. Text\n\t";
   		cout << "2. Images \n\t";
   		cout << "3. Documents/File \n\t";
   		cout << "4. Link\n\t";
   		cout << "5. Video \n\t";
   		cout << "6. Audio \n\t";
   		cout << "0. Done\n\n\n\tEnter your Choice : " ;
   		cin >> ch;
   		
   		switch(ch)
   		{
   			
   			case 0:
   				l_c=false;
   				break;
   				
   			case 1:
	   			input="";
   				cout<< "\n\n\nEnter Text : \n[ Enter 0 on a newline to stop ]\n\n";
   				while (getline(cin, temp))
				{
					if (temp == "0")
						break;

					input += temp + "\n";
				}
				cout << "\n\n";
				output += "<div class=\"textpost\">\n\n" + input + "\n\n</div>\n";
 				cout << output << endl;
 				content_enter=true;
 				break;
 				
 			case 2:
 				input="";
 				cout<< "\n\n\nInserting Image\n[ file must be located in folder resources/images/ ]\n\nEnter Image file name : ";
 				cin >> input;
 				output += "<img src=\"resources/images/"+input+"\">\n";
 				cout << output << endl;
 				content_enter=true;
 				break;
 			case 3:
 				input="";
 				cout<< "\n\n\nInserting Document/File\n[ file must be located in folder resources/documents/ ]\n\nEnter file name : ";
 				cin >> input;
 				output += "<a href=\"resources/documents/"+input+"\">\n";
 				cout << output << endl;
 				content_enter=true;
 				break;
 			case 4:
 				input="";
 				cout<< "\n\n\nInserting Link\n\nEnter URL : ";
 				cin >> input;
 				output += "<a href=\""+input+"\">\n";
 				cout << output << endl;
 				content_enter=true;
 				break;
 			case 5:
 				input="";
 				temp="";
 				cout<< "\n\n\nInserting Video\n[ file must be located in folder resources/videos/ ]\n\nEnter file name : ";
 				cin >> input;
 				
 				for( int i = 0; input[i] != '.'; tempi=i++);
 				
 				for( int i = tempi + 2; input[i] != '\0'; temp+=input[i++]);
 					
 				output += "<video src=\"resources/videos/"+input+"\" type=\"video/"+temp+"\">\n";
 				cout << output << endl;
 				content_enter=true;
 				break;
 			case 6:
 				input="";
 				cout<< "\n\n\nInserting Audio\n[ file must be located in folder resources/audios/ ]\n\nEnter file name : ";
 				cin >> input;
 				
 				for( int i = 0; input[i] != '.'; tempi=i++);
 				
 				for( int i = tempi + 2; input[i] != '\0'; temp+=input[i++]);
 					
 				output += "<video src=\"resources/audios/"+input+"\" type=\"audio/"+temp+"\">\n";
 				cout << output << endl;
 				content_enter=true;
 				break;	
 			
 				
 			
 				
 			default :
 				cout << "\ninvalid choice.";
   		}
   			   	
   	}
 	
	if(content_enter)
	{ 
		posth="<article class=\"post\">\n \
    <h2 class=\"title\"> " + title + " </h2>\n \
\n \
  <p class=\"datetime\">\n \
    <span class=\"date\">" + date + "</span>\n \
    <span class=\"time\">" + time + "</span>\n \
  </p>\n \
  <div class=\"content\">\n \
    <p>\n \
      " + output + "\n \
    </p>\n \
  </div>\n \
</article>\n\n";	
		
		
		
		ifstream inFile;
		inFile.open("index.html");
			if (!inFile) {
				cerr << "Unable to open file datafile.txt";
				exit(1);   // call system to stop
			}
		
		string sum;
		char x;
		while (inFile.get(x)) {
		  sum = sum + x;
			}
	
		inFile.close();
		
		int i,j;
		i=0;
		j=0;
		
		string str=sum;
		
		for( i=0; !(str[i] == ']' && str[i-1] == 'c' && str[i-2] == '['); i++);
		
		string head, tail;
		
		for( j=0; j <= i ; j++)
		{
			head += str[j];
		}
		
		head = head + "-->";
		
		cout << "HEAD = \n" << head << endl;
		
		for( j=i+1; str[j] != '\0' ; j++)
		{
			tail += str[j];
		}
		
		tail = "<!--  " + tail;	
		
		cout << "TAIL = \n" << tail << endl;
		
		string finalt = head + posth + tail;
		
		ofstream myfile;
		myfile.open ("index.html");
		myfile << finalt;
		myfile.close();
	}
	else{
	cout << "No Content Entered";
	}
   	return 0;
   	
}
