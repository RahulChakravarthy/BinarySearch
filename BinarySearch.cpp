#include <iostream>
#include <cstdlib>

using namespace std;
//Playing around with Binary Search Algorithms
//Update Fix bugs with infinite recursion; something wrong with Query Method

//Encapuslate into a class for further organization
class SearchAlg {

	private:
	int size; //size of list
	int* SearchList; //List itself
	int NumberOfInterest; //Number that you want to query the List
	int LowIndex; //Low index
	int HighIndex; //High index
	int Midpoint; //Midpoint of array
	int randomRange;
	bool Section;

	void CalculateMidPoint(); //Resets the midpoint recursivly

	public:
	//Constructors and Destructors
	SearchAlg(int size, int randomRange);
	~SearchAlg();
	//Public methods
	void GenerateRandomList();
	void printList();
	void Delete();
	void SortList();
	int Query();
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SearchAlg::SearchAlg(int size, int randomRange){
	(*this).SearchList = new int;
	(*this).size = size;
	(*this).LowIndex = 0;
	(*this).HighIndex = size;
	(*this).Midpoint = (HighIndex - LowIndex)/2;
	(*this).randomRange = randomRange;
	(*this).Section = false; //False means search lower end of list, true means search higher end of list
}
SearchAlg::~SearchAlg(){}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void SearchAlg::SortList(){
	//Sort using simple bubble sort to sort the newly made list
	for (int i = 0; i < (*this).size - 1; i++){
		for (int q = 0; q < (*this).size; q++){
			if ((*this).SearchList[q + 1] < (*this).SearchList[q]){
				int temp = (*this).SearchList[q+1];
				(*this).SearchList[q+1] = (*this).SearchList[q];
				(*this).SearchList[q] = temp;
			}
		}
	}
}

void SearchAlg::GenerateRandomList(){
	//Randomize a value q between 0 and size that will be the number of interest in the binary search
	int q = rand() % (*this).size;
	for (int i = 0; i < (*this).size; i++){
		(*this).SearchList[i] = rand() % (*this).randomRange + 1; //Generates a random number between 1 - 100 for each element in SearchList of the preset size

		if (i == q){
			//Set the number of interest
			(*this).NumberOfInterest = (*this).SearchList[i];
		}
	}

	//Sort List as soon as it is done begin generated
	(*this).SortList();
}

void SearchAlg::printList(){
//Prints every element in the SearchList
	for (int i = 0; i < (*this).size; i++){
		cout << (*this).SearchList[i] << "   ";
	}
}
void SearchAlg::CalculateMidPoint(){
	if ((*this).Section){
		(*this).LowIndex = (*this).Midpoint; //This means the number of interest is in the higher half of the tree
		(*this).Midpoint = ((*this).HighIndex - (*this).LowIndex)/2;
	}
	else {
		(*this).HighIndex = (*this).Midpoint; //This means number of interest is in the lower half of the tree
		(*this).Midpoint = ((*this).HighIndex - (*this).LowIndex)/2;
	}
}


int SearchAlg::Query(){
//Implementation of Binary search to find number of interest
	//If the number of interest is the same as the middle of the sorted list then return the index midpoint
	cout << "TEST" << endl;
	if ((*this).SearchList[(*this).Midpoint] == (*this).NumberOfInterest){
		return (*this).Midpoint;
	}
	//If the number of interest is higher than the midpoint set the low to equal midpoint and recalculate midpoint
	else if ((*this).NumberOfInterest > (*this).SearchList[(*this).Midpoint]){
		(*this).Section = true;
		(*this).CalculateMidPoint();
		return (*this).Query();
	}
	//If the number of interest is lower than the midpoint then set the high to be the midpoint and recalculate the midpoint 
	else {
		(*this).Section = false;
		(*this).CalculateMidPoint();
		 return (*this).Query();
	}
}

void SearchAlg::Delete(){
	//Frees Allocated memory for the Search List
	delete (*this).SearchList;
}

int main(){

	SearchAlg BinaryList(30, 99);

	BinaryList.GenerateRandomList();
	BinaryList.printList();

	cout << "The randomized Number of interest in the randomly generated List is located at index value: " << BinaryList.Query() << endl;
	//BinaryList.Delete();
	
	return 0;
}