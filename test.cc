#include<iostream>
#include<string>
using namespace std;

int main() {

	string B = ".DAT output";
	string C = ".txt";

	//Cantidad de ficheros M.DAT
	int n = 100;

	for(int i = 0; i < n; ++i) {

		string number = to_string(i);

		if(i < 10) {
			string A = "./exLU M0" + number + B + "0" + number + C;
			
			cout << endl <<"-------------------------" << endl;
			cout << A << endl;
			cout << "-------------------------" << endl;

			const char *command1 = A.c_str();
			system(command1);
		}

		else {
			string A = "./exLU M" + number + B + number + C;

			cout << endl <<"-------------------------" << endl;
			cout << A << endl;
			cout << "-------------------------" << endl;

			const char *command2 = A.c_str();
			system(command2);
		}
	}

	//Cantidad de ficheros MSINGULAR.DAT
	int m = 4;

	for(int i = 0; i < m; ++i) {

		string number = to_string(i);

		string A = "./exLU MSINGULAR0" + number + B + "SING0" + number + C;
			
			cout << endl <<"-------------------------" << endl;
			cout << A << endl;
			cout << "-------------------------" << endl;

			const char *command1 = A.c_str();
			system(command1);		

	}
}