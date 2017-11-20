/*This is a program that implements 
merge sort using array*/


#include<iostream>
#include<functional>

//all the funtion declarations are done here

static void display(int* array, int size);

std::tuple<int*, int> newArray();

int* enterDataToArray(int* array, int size);

static int selection();

void displayText(char* string);	

int* mergeSort(int* array, int size);

int* merge(int* array1, int* array2, int size1, int size2);

void main()	//the main funtion
{
	int size;		//stores the size of the array
	int select;			//the selection variable 
	int* array = nullptr;		//the main array 
	bool exit = false;

	while (!exit)
	{
		select = selection();

		switch (select)
		{
		case 1:
		{
			std::tuple<int*, int> sources = newArray();		//tuple is used to receve the data from the funtion
			array = std::get<0>(sources);		//extraction of the data from the tuple 
			size = std::get<1>(sources);
			display(array, size);

			break;
		}
		case 2:
		{

			array = mergeSort(array, size);

			display(array, size);

			break;
		}
		case 3:
			exit = true;
			break;
		default:
			break;
		}
	}
}

int* mergeSort(int* array, int size)		//devides the array into two and gets the sorted arrays and then merges them and returns the an array
{
	int size1 = (int)size / 2;
	int size2 = size - size1;
	int* array1 = new int[size1];		//these are the sub arrays that the main array is split into
	int* array2 = new int[size2];
	
	array1 = array;
	array2 = &array[size1];

	std::cout << "array1 : ";
	display(array1, size1);
	std::cout << "array2 : ";
	display(array2, size2);

	if (size1 != 1)
	{
		array1 = mergeSort(array1, size1);
	}
	if (size2 != 1)
	{
		array2 = mergeSort(array2, size2);
	}
	array = merge(array1, array2, size1, size2);
	
	return(array);
}

int* merge(int* array1, int* array2, int size1, int size2)	//		merges two arrays allong with the sorting 
{
	int beg1 = 0;
	int beg2 = 0;
	int size = size1 + size2;
	int cur = 0;	
	int* array = new int[size];
	memset(array, 0, size);

	while (true)
	{
		if (array1[beg1] > array2[beg2] && beg2 < size2)
		{
			array[cur] = array2[beg2];
			beg2++;
		}
		else if(array1[beg1] <= array2[beg2] && beg1 < size1)
		{
			array[cur] = array1[beg1];
			beg1++;
		}
		else if (beg2 == size2)
		{
			while (true)
			{
				array[cur] = array1[beg1];
				beg1++;
				cur++;
				if (beg1 == size1)
					return(array);
			}
		}
		else
		{
			while (true)
			{
				array[cur] = array2[beg2];
				beg2++;
				cur++;
				if (beg2 == size2)
					return(array);
			}
		}
		cur++;
		if (cur == size)
		{
			break;
		}
	}
	return(array);

}
static void display(int* array, int size) //displays the array
{
	if (array)		//if array is not a nullptr
	{
		int i = 0;
		std::cout << "[";
		for (; i < size; i++)
		{
			std::cout << array[i] << " ";
		}
		std::cout << "]";
		std::cout << std::endl;
	}
}

std::tuple<int*, int> newArray()		//creates an array and returns the array and its size 
{
	int size;

	std::cout << "Enter the size of the array:";
	std::cin >> size;

	int* array = new int[size];
	memset(array, 0, size);

	array = enterDataToArray(array, size);

	return std::make_pair(array, size);
}

int* enterDataToArray(int* array, int size)		//allows the user to input the values to the array
{
	std::cout << "Enter the array:";
	for (int i = 0; i < size; i++)
	{
		std::cin >> array[i];
	}
	return(array);
}

static int selection()		//does the selection
{
	int select;

	displayText("Enter your choice");
	displayText("New Array -----> 1");
	displayText("Sort Array ----> 2");
	displayText("Exit ----------> 3");

	std::cin >> select;

	return (select);
}

void displayText(char* string)	//displaying the text 
{
	std::cout << string << std::endl;
}