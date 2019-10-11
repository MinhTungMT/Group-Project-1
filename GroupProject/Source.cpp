#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


void object1(string str)
{
	cout << setprecision(3);
	string teamname = str;
	cout << endl;
	cout << "TEAM: " << teamname << endl;
	str = str + ".txt";   //str = red1 + .txt = red1.txt
	ifstream groupname;
	groupname.open(str);
	string name, team;
	int s1, s2;
	float time;
	float sum1 = 0;
	float sum2 = 0;
	float sum3 = 0;
	for (int i = 1; i <= 3; i++)
	{
		groupname >> name >> s1 >> s2 >> time >> team;
		cout << left << setw(5) << name << right << setw(3) << s1 << setw(3) << s2 << setw(5) << time << " " << team << endl;
		sum1 = sum1 + s1;
		sum2 = sum2 + s2;
		sum3 = sum3 + time;
	}
	cout << left << setw(5) << "AVG" << right << setw(3) << sum1/3 << setw(3) << sum2/3 << setw(5) << sum3/3 << endl;
}


double score(int s1, int s2, double time)
{
	cout << setprecision(3);
	double s = (s1 + s2) - (1 * ((time * 60) / 5));
	return s;
}

void object4(string str)  //paramenter str is team name
{
	int s1, s2;
	float time;
	string name, name2, name3, team;
	
	ifstream file, file2;
	string strbackup = str;
	str = str + "1"+".txt";
	file.open(str);
	file >> name >> s1 >> s2 >> time >> team;
	double score1 = score(s1, s2, time);

	file >> name2 >> s1 >> s2 >> time >> team;
	double score2 = score(s1, s2, time);

	file >> name3 >> s1 >> s2 >> time >> team;
	double score3 = score(s1, s2, time);
	
	if (score1 > score2 && score1 > score3)
	{
		cout << name << " " << score1;
	}
	else if (score2 > score3 && score2 > score1)
	{
		cout << name2 << " " << score2;
	}
	else if (score3 > score1 && score3 > score2)
	{
		cout << name3 << " " << score3;
	}

	cout << "                      ";

	str = strbackup + "2" + ".txt";
	file2.open(str);
	file2 >> name >> s1 >> s2 >> time >> team;
	score1 = score(s1, s2, time);

	file2 >> name2 >> s1 >> s2 >> time >> team;
	score2 = score(s1, s2, time);

	file2 >> name3 >> s1 >> s2 >> time >> team;
	score3 = score(s1, s2, time);

	if (score1 > score2 && score1 > score3)
	{
		cout << name << " " << score1;
	}
	else if (score2 > score3 && score2 > score1)
	{
		cout << name2 << " " << score2;
	}
	else if (score3 > score1 && score3 > score2)
	{
		cout << name3 << " " << score3;
	}
	cout << endl;
}

void teamdividing(string str)
{
	str = str + ".txt";
	ifstream file;
	ofstream blue, yellow, red;

	file.open(str);
	blue.open("blue1.txt");
	red.open("red1.txt");
	yellow.open("yellow1.txt");

	string s, name, team;
	int s1, s2;
	float time;
	file >> s >> s;
	for (int i = 1; i <= 9; i++)
	{
		file >> name >> s1 >> s2 >> time >> team;
		if (team == "Red")
		{
			red << name << " " << s1 << " " << s2 << " " << time << " " << team << " " << endl;
		}
		else if (team == "Yellow")
		{
			yellow << name << " " << s1 << " " << s2 << " " << time << " " << team << " " << endl;
		}
		else if (team == "Blue")
		{
			blue << name << " " << s1 << " " << s2 << " " << time << " " << team << " " << endl;
		}
	}
} 

void teamdividing2(string str)
{
	str = str + ".txt";
	ifstream file;
	ofstream blue, yellow, red;

	file.open(str);
	blue.open("blue2.txt");
	red.open("red2.txt");
	yellow.open("yellow2.txt");

	string s, name, team;
	int s1, s2;
	float time;
	file >> s >> s;
	for (int i = 1; i <= 9; i++)
	{
		file >> name >> s1 >> s2 >> time >> team;
		if (team == "Red")
		{
			red << name << " " << s1 << " " << s2 << " " << time << " " << team << " " << endl;
		}
		else if (team == "Yellow")
		{
			yellow << name << " " << s1 << " " << s2 << " " << time << " " << team << " " << endl;
		}
		else if (team == "Blue")
		{
			blue << name << " " << s1 << " " << s2 << " " << time << " " << team << " " << endl;
		}
	}
}

int main()
{

	string filename;
	cout << "pls enter the file name for scenario 1: " << endl;
	cin >> filename;
	teamdividing(filename);
	cout << "pls enter the file name for scenario 2: " << endl;
	cin >> filename;
	teamdividing2(filename);

	int choice = 1;
	for (choice = 1; choice;)
	{
		cout << endl;
		cout << "=======================================" << endl;
		cout << " what you want to do? " << endl;
		cout << "1. Teaminfo" << endl;
		cout << "2. Individual Performance Summery" << endl;
		cout << "3. Output Speed Result" << endl;
		cout << "4. Most Valuable Officer" << endl;
		cout << "5. Overall Summery" << endl;
		cout << "enter 0 to end the program." << endl;
		cout << "=======================================" << endl;
		cin >> choice;
		string teamname;
		switch (choice)
		{
		case 1:
			cout << endl;
			cout << "which scenario you want to see:" << endl;
			cin >> choice;
			if (choice == 1)
			{
				object1("red1");
				object1("blue1");
				object1("yellow1");
			}
			else if (choice == 2)
			{
				object1("red2");
				object1("blue2");
				object1("yellow2");
			}
			break;
		case 2:
			cout << "not yet" << endl;
			break;
		case 3:
			cout << "not yet" << endl;
			break;
		case 4:
			cout << endl;
			object4("red");
			cout << endl;
			object4("yellow");
			cout << endl;
			object4("blue");
			break;
		case 5:
			cout << "not yet" << endl;
			break;
		}
	}

}