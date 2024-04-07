
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Person {
public:
	
	Person(const string& name) {
		this->name = name;

	}
	Person() { name = ""; age = 0; }
	Person(const string& name,int age)
	{
		this->name = name; 
		this->age = age;
	}
	bool operator > (Person& p)
	{
		if (name.compare(p.getName()) > 0)
			return true;
		return false;
	}
	bool operator < (Person& p)
	{
		if (name.compare(p.getName()) < 0)
			return true;
		return false;
	}

	bool operator == (const Person& p)
	{
		if (!name.compare(p.name) && age == p.age)
			return true;
		return false;
	}
	Person& operator = (Person& p)
	{
		name = p.name;
		age = p.age;
		return *this;
	}
	string& getName()  { return name; }
	string getName() const { return name; }

private:
	string name;
	int age;
};

ostream& operator<<(ostream& out, const Person& p) {
	cout << p.getName();
	return out;
}


class Group {
public:
	Group(const Group& g) {
		members = new Person[g.cap];
		cap = g.cap;
		size = 0;
		for (int i = 0; i < g.size; i++)
				this->add(g.members[i]);
	}
	Group(int max_lenght)  {
		this->cap = max_lenght;
		this->members = new Person[max_lenght];
		this->size = 0;
	}
	void operator=(const Group& g) {
		members = new Person[10];
		cap = g.cap;
		size = 0;
		for (int i = 0; i < g.size; i++)
			this->add(g.members[i]);
	}
	void add(Person p) {
		if (this->size == this->cap) {
			return;
		}
		this->members[size] = p;
		this->size++;
	}
	void deletePerson(string name) {
		int i;
		for (i = 0; i < size; i++) {
			if(members[i].getName() == name)
				break;
			
		}
		for (int index = i; index < size - 1; index++) {
			members[index] = members[index + 1];
		}
		size--;
	}

	int getSize(){	return size;}
	int getCap() { return cap; }
	Person* getMembers(){ return members; }
	Group operator+(Group& g)
	{
		Group output(cap + g.getCap());
		for (int i = 0; i < cap; i++)
			output.add(members[i]);
		for (int i = 0; i < g.getCap(); i++)
			output.add(g.getMembers()[i]);
		return output;
	}
	Group& operator += (Group& g)
	{
		for (int i = 0; i < g.getCap(); i++)
			this->add(g.getMembers()[i]);
		return *this;
	}
	~Group() {
		delete[] members;
	}

private:
	int size;
	int cap;
	Person* members;

};
ostream& operator<<(ostream& out, Group& g)
{
	for (int i = 0; i < g.getSize(); i++)
	{
		cout << g.getMembers()[i].getName() << "\t";
	}
	return out;
}




bool isGroupFull(Group g) {
	return (g.getSize() == g.getCap());
}
   
int main()
{
	
	Person p1("somename");
	Person p2("somename2");
	cout << p1<<p2;
	
	Group g1(5);
	g1.add({ "erfan",20 });
	g1.add({ "saba",20 });
	g1.add({ "mahrokh",20 });
	g1.add({ "yasin",21 });
	cout<<isGroupFull(g1)<<endl;
	

	Group g2(g1);
	Group g3(10);
	g2.deletePerson("erfan");
	cout << g1<<endl;//should cout every Person in it with a \t as the separator
	cout << g2 << endl;
	
	
	g3 = g1;
	cout << g3;
	g3 =  g2 + g3;//adds members of g2 and g3 to each other
	g3 += g3 += g3 += g3;
	
	Person Persons[10];
	Person erfan("erfan",20);
	Persons[0]=erfan;
	for(int i=1;i<10;i++){
		Persons[i].getName()=to_string(rand()%100);
	}
	sort(Persons,Persons+10);//what operator should be overloaded for sort? :) 

	for(int i=0;i<10;i++){
		cout<<Persons[i].getName()<<' ';
	}
	if(find(Persons, Persons + 10, erfan) != Persons + 10)
	cout<<*find(Persons,Persons+10,erfan);
}

