#include <iostream>
using namespace std;
const int PERSONS = 2;
#define print cout<<"This edge is not present in the graph!"<<endl 
//zad1
struct Vector
{
	int x;
	int y;
	int z;
};
Vector CreateVector(int x, int y, int z)
{
	Vector p = { x,y,z };
	return p;
}
Vector CreateVector()
{
	int x = 0, y = 0, z = 0;
	cin >> x >> y >> z;
	Vector p = { x,y,z };
	return p;
}
Vector SborVectors(Vector p1, Vector p2)
{
	Vector p3;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;
	p3.z = p1.z + p2.z;
	return p3;
}
void PrintVector(Vector p1)
{
	cout << endl << "x: " << p1.x << endl;
	cout << "y: " << p1.y << endl;
	cout << "z: " << p1.z << endl;
}
void LZVectors(Vector v1, Vector v2)
{

}
//zad2

enum Education
{
	BACALAVAR = 1,
	MASTER,
	DOCTOR
};
struct Person
{
	Education stepen;
	int number;
	int count_of_students;
};
int Power(int number, int k)
{
	int n = number;
	for (int i = 1; i < k; i++)
	{
		number *= n;
	}
	return number;
}
Person CreatePerson(Education stepen, int number, int count_of_students)
{
	int min_number = Power(10, 4);
	int max_number = Power(10, 5) - 1;
	if (number< min_number || number>max_number)
	{
		cout << "Invalid count of students!!!";

	}
	else
	{
		Person p = { stepen ,number ,count_of_students };
		return p;
	}

}
void PrintPerson(Person p)
{
	cout << "Person's information:" << endl << endl;
	cout << "Editonal degree: ";
	switch (p.stepen)
	{
	case 1:
	{
		cout << "Bacalavar";
		break;
	}
	case 2:
	{
		cout << "Master";
		break;
	}
	case 3:
	{
		cout << "Doctor";
		break;
	}
	}
	cout << endl << "Number: " << p.number << endl;
	cout << "Broken students: " << p.count_of_students << endl;
}
//zad 3
struct University
{
	Person* arr;
	double averige_cout_of_students;

};
University CreateUniversity(Person* arr)
{
	double avg = 0; int sum = 0;
	for (int i = 0; i < PERSONS; i++)
	{
		sum += arr[i].count_of_students;
	}
	avg = sum / PERSONS;
	University u = { arr,avg };
	return u;
}
int Bonus(University u, int broken_students)
{
	int br = 0;
	for (int i = 0; i < PERSONS; i++)
	{
		if (u.arr[i].count_of_students > broken_students)
		{
			br++;
		}
	}
	return br;
}
void BubbleSort(Person* arr)
{
	for (int i = 0; i < PERSONS - 1; i++)
	{
		for (int j = 0; j < PERSONS - i - 1; j++)
		{
			if (arr[j].count_of_students > arr[j + 1].count_of_students)
			{
				Person swap = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = swap;
			}
		}
	}

}
//zad 4
struct Vrux
{
	string name;

};
struct Rebro
{
	Vrux v1;
	Vrux v2;

};
struct Graf
{
	int vrux_count;
	int rebro_count;
	Rebro* arr = new Rebro[rebro_count];

};
bool CheckThisVrux(Vrux* vrux, Vrux v1,int size)
{
	bool check = true;
	for (int i = 0; i < size; i++)
	{
		if (vrux[i].name == v1.name)
		{
			check = false;
			break;
		}
	}
	return check;
}
int FindCountOfVruxs(int size,Rebro* arr)
{
	Vrux* vrux = new Vrux[size * 2];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (CheckThisVrux(vrux, arr[i].v1, index))
		{
			vrux[index] = arr[i].v1;
			index++;
		}
		if (CheckThisVrux(vrux, arr[i].v2, index))
		{
			vrux[index] = arr[i].v2;
			index++;
		}

	}
	return index;
}
int FindCountOfVruxsPlusTwo(int size, Rebro* arr, Vrux v1, Vrux v2)
{
	Rebro* rebra = new Rebro[size + 1];
	for (int i = 0; i < size; i++)
	{
		rebra[i] = arr[i];
	}
	Rebro r1 = { v1,v2 };
	rebra[size] = r1;
	int result = FindCountOfVruxs(size + 1, rebra);
	return result;
}
Graf CreateGraf(int m, Rebro* arr)
{
	
	Graf g1 = { FindCountOfVruxs(m,arr),m,arr };
	return g1;
}
Graf AddRebroInGraff(Graf g1,Vrux v1,Vrux v2)
{
	
	Rebro* arr = new Rebro[g1.rebro_count+1];
	for (int i = 0; i < g1.rebro_count; i++)
	{
		arr[i] = g1.arr[i];
	}
	Rebro r1 = {v1,v2};
	arr[g1.rebro_count] = r1;
	Graf g2 = { FindCountOfVruxsPlusTwo(g1.vrux_count,g1.arr,v1,v2),g1.rebro_count + 1,arr };
	return g2;
}
Graf CreateGrafWithoutParametars()
{
	int m = 0;
	cin >> m;
	Rebro* arr = new Rebro[m];
	for (int i = 0; i < m; i++)
	{
		string name1;
		string name2;
		cin>> name1;
		cin >> name2;
		Vrux v1 = { name1 };
		Vrux v2 = { name2 };
		Rebro r1 = { v1,v2 };
		arr[i] = r1;

	}
	delete[] arr;
	return CreateGraf(m, arr);
}

int StepenGraf(Graf g1,Vrux v1)
{
	Vrux* vrux = new Vrux[g1.rebro_count * 2];
	Rebro* rebra = new Rebro[g1.rebro_count];
	int index = 0;
	int br = 0;
	bool check = true;
	for (int i = 0; i < g1.rebro_count; i++)
	{
		if (v1.name == g1.arr[i].v1.name || v1.name == g1.arr[i].v2.name)
		{
			for (int j = 0; j < index; j++)
			{
				if (rebra[j].v1.name == g1.arr[i].v1.name && rebra[j].v2.name == g1.arr[i].v2.name)
				{
					check = false;
				}
				if (rebra[j].v2.name == g1.arr[i].v1.name && rebra[j].v1.name == g1.arr[i].v2.name)
				{
					check = false;
				}
			}
			if (check)
			{
				rebra[index] = g1.arr[i];
				index++;
				check = true;
				br++;
			}
			
			
		}
		

	}
	delete[] vrux;
	delete[] rebra;
	return br;
}
bool PulenGraf(Graf g1)
{
	Vrux* vrux = new Vrux[g1.rebro_count * 2];
	int index = 0;
	bool check = true;
	for (int i = 0; i < g1.rebro_count; i++)
	{
		if (CheckThisVrux(vrux, g1.arr[i].v1, index))
		{
			vrux[index] = g1.arr[i].v1;
			index++;
		}
		if (CheckThisVrux(vrux, g1.arr[i].v2, index))
		{
			vrux[index] = g1.arr[i].v2;
			index++;
		}

	}
	for (int i = 0; i < index; i++)
	{
		if (StepenGraf(g1, vrux[i]) != index - 1)
		{
			check = false;
		}
	}
	return check;
}
Graf RemoveGraf(Graf &g1,Rebro r)
{
	Rebro* rebra = new Rebro[g1.rebro_count];
	int index = 0;
	bool check = false;
	for (int i = 0; i < g1.rebro_count; i++)
	{
		if (g1.arr[i].v1.name == r.v1.name && g1.arr[i].v2.name == r.v2.name)
		{
			check = true;
		}
		else
		{
			rebra[index] = g1.arr[i];
			index++;
		}
	}
	if (check)
	{
		Graf g2 = { FindCountOfVruxs(index,rebra),index,rebra};
	}
	else
	{
		print;
	}
}
void PrintGraf(Graf g1)
{
	cout << g1.rebro_count << " " << g1.vrux_count;
	cout << endl;
	for (int i = 0; i < g1.rebro_count; i++)
	{
		cout << g1.arr[i].v1.name << " " << g1.arr[i].v2.name << endl;
	}
	Vrux v1 = { "zzzz" };
	cout << StepenGraf(g1, v1);
}
int main()
{
	Graf g1 =CreateGrafWithoutParametars();
	PrintGraf(g1);
	Person arr[] = { CreatePerson(BACALAVAR, 10001, 32324),CreatePerson(DOCTOR, 10002, 37324) };
	return 0;
}