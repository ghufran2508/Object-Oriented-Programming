#pragma once
class Set
{
private:
	int size;
	int* arr;
	int noOfElements;
	void reduce_size(); // Reduce allocated memory by half
	void increase_size(); // Increase allocated memory by twice
	bool isEmpty(); // return true if the set is empty, else return false
	bool isFull(); // return true if the set is full. Else return false.
public:
	Set(); //default constructor
	Set(int size); // allocates the memory on heap and check if the size is invalid
				//then set null
	Set(const Set& ref); // Copy constructor
	bool insertElement(int value); // This function should insert value at the most recent
									//position.Add necessary checksand increase memory if
								//required.Returns true if the value is inserted else returnsfalse.
	bool removeElement(int value); // find the given value and remove the value from set. Decease
									//the set size(if required).Return true if the value is
									//removed else return false the value is not present in set.
	int searchElementPosition(int value); // if the element is present then return the index of
										//that element else return -1
	bool searchElement(int value); // return true if the value is present in the set else
									//returns false.
	void displaySet(); // display the contents of set. (in curly brakets and coma separated)
	Set intersection(Set a); // return the intersection of the sets.
	 /*
	Example 1:
	Arr = {1,2,3}
	a = {1,3}
	resultSet = {1,3}
	return resultSet
	Example 2:
	Arr = {1,2,3}
	a = {4,5}
	resultSet will be empty
	 */
	Set Union(Set a); // return the union of the sets.
	 /*
	Example 1:
	Arr = {1,2,3}
	a = {1,3}
	resultSet = {1,2,3}
	return resultSet
	Example 2:
	Arr = {1,2,3}
	a = {4,5}
	resultSet = {1,2,3,4,5}
	 */
	Set operator+ (Set& first); // You may call union function in this function.
	Set difference(Set a); // return the difference of the sets.
	 /*
	Example:
	Arr = {1,2,3,4}
	a = {2,3,5}
	resultSet = {1,4}
	return resultSet
	 */
	Set operator-(Set& first); // You may call difference(Set a) function in this function.
	int isSubSet(Set a); // return 1 for proper subset, return 2 for improper subset
						//return 0 if not a subset.
		~Set(); //destructor
	int& operator[](int); // Directly access element in the set. If element does not exist,
						//return -1.
};
