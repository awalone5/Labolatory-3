#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
void firstTask(int array[], int length);
void secondTask(vector<vector<double>>& A, vector<double> b);
void thirdTask(string text);
void gaussianMethod(vector<vector<double>>& A, vector<double>& b);
void printMatrix(const vector<vector<double>>& matrix);
bool isHasLatinLetter(string& w);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int array[] = { 0, 33, -23, -10, 32, 1, 1, 9, -10 };
	
	int length = sizeof(array) / sizeof(array[0]);
	
	firstTask(array, length);
	
	//------------------------------------------------------
	vector<vector<double>> Matrix = { {1, 2, 3},
									  {4, 5, 6},
									  {7, 8, 9} };

	vector<double> b = {10, 20, 30};
	secondTask(Matrix, b);
	//------------------------------------------------------
	cout << "--------------------------------------------------" << endl;
	cout << "Tird task: " << endl << endl;
	cout << "Enter words for task three:" << endl;


	string str;
	getline(cin, str);
	thirdTask(str);
	
}

void firstTask(int array[], int length)
{
	cout << "First task:" << endl << endl;
	int max = INT32_MIN;

	for (int i = 0; i < length; i++)
	{
		int a = array[i];

		if (a < 0)
		{
			a = a * (-1);
		}

		if (a > max)
		{
			max = a;
		}
	}

	cout << "The maximum element of the array modulo: " << max << endl;

	int firstPositive = -1;
	int secondPositive = -1;

	for (int i = 0; i < length; i++)
	{
		if (array[i] > 0)
		{
			firstPositive = i;
			break;
		}
	}

	for (int i = firstPositive + 1; i < length; i++)
	{
		if (array[i] > 0)
		{
			secondPositive = i;
			break;
		}
	}

	int sum = 0;

	if (firstPositive != -1 && secondPositive != -1) {
		for (int i = firstPositive + 1; i < secondPositive; i++) {
			sum = sum + array[i];
		}
		cout << "Sum of elements between first and second positive element: " << sum << endl;
	}
	else {
		cout << "No positive elemets in array" << endl;
	}

	sort(array, array + length, [](int a, int b) {
		return !(a == 0 || a == 1) && (b == 0 || b == 1);
	});

	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
}

void secondTask(vector<vector<double>>& Matrix, vector<double> b) {
	cout << "--------------------------------------------------" << endl;
	cout << "Second task: " << endl << endl;

	gaussianMethod(Matrix, b);
	double threshold = 5.0;
	int count = 0;
	int n = Matrix.size();

	for (int i = 0; i < n; i++)
	{
		double sum = 0;

		for (int j = 0; j < n; j++)
		{
			sum = sum + Matrix[i][j];
		}

		double average = sum / n;
		if (average < threshold)
		{
			count++;
		}
	}
	printMatrix(Matrix);

	cout << "Count of rows with average less than " << threshold << ": " << count << endl;
}

void thirdTask(string text) {
	 
	string textt = text + "  ";
	vector<char> arr(textt.begin(), textt.end());
	int length = arr.size();
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == ' ' || arr[i] == '\0')
		{
			if (arr[i-1] == 'à' || arr[i-1] == 'å' || arr[i-1] == 'ó' || arr[i-1] == 'º' || arr[i-1] == '³' || arr[i-1] == '¿' ||
				arr[i-1] == 'è' || arr[i-1] == 'î' || arr[i-1] == 'ª' || arr[i-1] == 'þ' || arr[i-1] == 'ÿ' || arr[i-1] == 'ß')
			{																										

				count++;

			}
		}
	}
	cout <<"Count of words wich ends with loud letter: " << count << endl << endl;

	string input(arr.begin(), arr.end());
	vector<string> words;
	string word;

	for (char c : input) {
		if (c != ' ') {
			word = word + c;
		}
		else {
			words.push_back(word);
			word.clear();
		}
	}

	words.push_back(word);

	
	for (string& w : words) {
		if (w.length() < 5 && !isHasLatinLetter(w)) {
		
			cout << w << " ";
			
		}
	}
	cout << endl;
}

bool isHasLatinLetter(string& w) {
	for (char c : w)
	{
		if (isalpha(static_cast<unsigned char>(c))) {
			return true;
		}
		else {
			return false;
		}
	}
}

void gaussianMethod(vector<vector<double>>& Matrix, vector<double>& b) {
	int n = Matrix.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{

			double ratio = Matrix[j][i] / Matrix[i][i];

			for (int k = i; k < n; k++)
			{

				Matrix[j][k] = Matrix[j][k] - ratio * Matrix[i][k];

			}
			b[j] -= ratio * b[i];
		}
	}
}

void printMatrix(const vector<vector<double>>& Matrix) {
	int rows = Matrix.size();
	int colons = Matrix[0].size();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colons; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}