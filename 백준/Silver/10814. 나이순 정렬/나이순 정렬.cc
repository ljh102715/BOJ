#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct person{
	int age;
	string name;
};
bool compare(const person& a, const person& b){
	if(a.age != b.age){return a.age < b.age;}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int num;
	cin >> num;
	person people[100001];
	
	for(int i = 0; i< num; i++){
		cin >> people[i].age >> people[i].name;
	}

	stable_sort(people, people + num, compare);

	for (int i = 0; i < num; i++)
        cout << people[i].age << " " << people[i].name << "\n";

	return 0;
}