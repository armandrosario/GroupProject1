using namespace std;
#include <iostream>;
#include <fstream>;

int gradebook[10][5];
//////////
void readGrades(string fileName, int numExams, int numStudents);
void getWeights(double(&weights)[5], int numExams);void getAvgsOfExams(double (&examAvgs)[5], int numOfExams, int numOfStudents);void getAvgsOfStudents(double (&studentAvgs)[10], double weights[], int numOfExams, int numOfStudents);void writeFinalGrades(double examAvgs[], double studentGrades[],int numOfExams, int numOfStudents);//////////
void main()
{
	double weights[] = { 0,0,0,0,0 };
	double examAvgs[] = { 0,0,0,0,0 };
	double studentAvgs[] = { 0,0,0,0,0,0,0,0,0,0};
	readGrades("grades.txt", 5, 10);
	getWeights(weights, 5);
	cout << examAvgs[0]<< endl;
	getAvgsOfExams(examAvgs, 5, 10);
	cout << examAvgs[0] << endl;
	
	getAvgsOfStudents(studentAvgs, weights, 5, 10);
	writeFinalGrades(examAvgs, studentAvgs, 5, 10);
	system("pause");

}
//////////
void readGrades(string fileName, int numExams, int numStudents)
{

	ifstream file;
	file.open(fileName);
	if (file.fail())
	{
		cout << "Error with file" << endl;
		exit(1);
	}
	else
	{
		while (!file.eof()) 
		{
			for (int r = 0; r < numStudents; r++)
			{
				for (int c = 0; c < numExams; c++)
				{
					file >> gradebook[r][c];
				}
			}
		}
	}
	file.close();
}

void getWeights(double(&weights)[5], int numExams)
{
	int length = numExams;
	weights[numExams];
	cout << "Please enter " << length << " weights in decimal form." <<endl;
	for (int i = 0; i < numExams; i++)
	{
		cin >> weights[i];
	}
}

void getAvgsOfExams(double (&examAvgs)[5], int numOfExams, int numOfStudents)
{

	for (int c = 0; c < numOfExams; c++)
	{
		for (int r = 0; r < numOfStudents; r++)
		{
			examAvgs[c] += (gradebook[r][c]/numOfStudents);
		}
	}
}

void getAvgsOfStudents(double(&studentAvgs)[10], double weights[], int numOfExams, int numOfStudents)
{
	
	for (int r = 0; r < numOfStudents; r++)
	{
		for (int c = 0; c < numOfExams; c++)
		{
			studentAvgs[r] += (gradebook[r][c] * weights[c]);
		}
	}
	
}

void writeFinalGrades(double examAvgs[], double studentGrades[], int numOfExams, int numOfStudents)
{
	ofstream outFile;
	outFile.open("finalgrades.txt");
	for (int r = 0; r < numOfStudents; r++)
	{
		for (int c = 0; c < numOfExams; c++)
		{
			outFile << gradebook[r][c]<< " ";
		}
		outFile << studentGrades[r]<<endl;
	}

	for (int i = 0; i < numOfExams; i++)
	{
		outFile << examAvgs[i] << " ";
	}
	outFile.close();
}


