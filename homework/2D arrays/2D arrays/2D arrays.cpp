#include <iostream>
#include<vector> 

void InitMatrix(std::vector<std::vector<int>>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			v[i][j] = rand() % 25 - 10;
		}
	}
}
void printMatrix(const std::vector<std::vector<int>>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
		{
			std::cout << v[i][j] << " ";
		}
		std::cout << "\n";
	}
}
void insertColumn(std::vector<std::vector<int>>& v, const std::vector<int>& new_column, int pos) {
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i].push_back(0);
		for (int j = v[i].size() - 1; j >= pos; j--)
		{
			v[i][j] = v[i][j - 1];
		}
		v[i][pos] = new_column[i];
	}
}
void deleteColumn (std::vector<std::vector<int>>& v, int pos){
	for (size_t i = 0; i < v.size(); i++)
	{
		auto iter = v[i].cbegin();
		v[i].erase(iter + pos);
	}
}
void deleteLine(std::vector<std::vector<int>>& v, int pos) {
	for (int i = pos; i < v.size()-1; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			v[i][j] = v[i+1][j];
		}
	}
		v.pop_back();

}

std::vector<std::vector<int>> multiply_matrixes(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
	std::vector <std::vector <int> > C(A.size(), std::vector <int>(B[0].size()));
	for (int row = 0; row < C.size(); row++) {
		for (int col = 0; col < C[row].size(); col++) {
			for (int inner = 0; inner < B.size(); inner++) {
				C[row][col] += A[row][inner] * B[inner][col];
			}
		}
	}
	return C;
}
void insertLine(std::vector<std::vector<int>>& v, const std::vector<int>& line, int pos) {

	auto iter = v.cbegin();
	v.insert(iter + pos, line);
}
int main()
{
	
	int size_linesA;
	std::cout << "Input number of lines ";
	std::cin >> size_linesA;
	int size_columnsA;
	std::cout << "Input number of columns ";
	std::cin >> size_columnsA;
	std::vector <std:: vector <int> > A(size_linesA, std::vector <int>(size_columnsA));
	InitMatrix(A);
	printMatrix(A);
	
	int size_linesB;
	std::cout << "Input number of lines ";
	std::cin >> size_linesB;
	int size_columnsB;
	std::cout << "Input number of columns ";
	std::cin >> size_columnsB;
	std::vector <std::vector <int> > B(size_linesB, std::vector <int>(size_columnsB));
	InitMatrix(B);
	printMatrix(B);

	if (size_columnsA != size_linesB) { 
		std::cout<<"Can't multiply matrixes";
	}
	else {
		std::cout << "Matrixes multiplication \n";
		std::vector<std::vector<int>> C=multiply_matrixes(A, B);
		printMatrix(C);
	}
	std::vector <int> N{1, 2, 3};

	insertLine(A,N, 1);
	std::cout << "\n New matrix \n";
	printMatrix(A);
}

