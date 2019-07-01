#include "sorting.h"
#include "quickSorting.cpp"
#include "insertionSort.cpp"
#include "hybrid.cpp"

int main(int argc, char* argv[]){
	if(argc < 3){
		std::cout<< "Missing arguments! Usage: ./sorting sampleFileName.txt saida.txt" <<std::endl;
		return 1;
	}
	std::ifstream infile(argv[1]);
	if(!infile.is_open()){
		std::cout<< "Invalid file name. File missing or cannot be open!" <<std::endl;
		return 2;
	}
	std::cout << "Starting..." << std::endl;
	//std::string outname("result");
	std::ifstream output(argv[2]);
	std::string line;
	std::vector<int> numbersQ;
	std::vector<int> numbersI;
	int *numbersarrQ;
	int *numbersarrI;
	int numberarrSizeQ;
	int numberarrSizeI;
	while(infile >> line){
		numbersQ.push_back(std::stoi(line));
	}
	//Arrays preparation
	numbersarrQ = new int[numbersQ.size()];
	numbersarrI = new int[numbersQ.size()];
	numberarrSizeQ = numbersQ.size();
	numberarrSizeI = numberarrSizeQ;
	std::copy(numbersQ.begin(), numbersQ.end(), numbersarrQ);
	std::copy(numbersQ.begin(), numbersQ.end(), numbersarrI);
	numbersI = numbersQ;
	std::cout << "Data structures ready!" << std::endl;
	
	//-----Time measurements---------
	//Quicksort using vector
	clock_t begin = clock();
	Quicksort(&numbersQ, 0, numbersQ.size()-1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	//QuickSorting using simple array
	begin = clock();
	QuicksortArray(numbersarrQ, 0, numberarrSizeQ-1);
	end = clock();
	double elapsed_secs2 = double(end - begin) / CLOCKS_PER_SEC;
	
	//Insertion Sorting using vector
	begin = clock();
	InsertionSortVector(&numbersI, numbersI.size());
	end = clock();
	double elapsed_secs3 = double(end - begin) / CLOCKS_PER_SEC;
	
	//Insertion sorting using simple array
	begin = clock();
	InsertionSort(numbersarrI, numberarrSizeI);
	end = clock();
	double elapsed_secs4 = double(end - begin) / CLOCKS_PER_SEC;
	
	//for(int i=0; i<numberarrSizeI; i++) std::cout << numbersQ.at(i) << " | ";
	//std::cout << std::endl;
	//for(int i=0; i<numberarrSizeI; i++) std::cout << numbersI.at(i) << " | ";
	//std::cout << std::endl;
	//for(int i=0; i<numberarrSizeI; i++) std::cout << numbersarrQ[i] << " | ";
	std::cout << std::endl;
	//for(int i=0; i<numberarrSizeI; i++) std::cout << numbersarrI[i] << " | ";
	std::cout << std::endl;
	
	std::cout << "Quick sorting: Vector = " << elapsed_secs << " | Native array = " << elapsed_secs2 << std::endl;
	std::cout << "Insertion sorting: Vector = " << elapsed_secs3 << " | Native array = " << elapsed_secs4 << std::endl;
	
	return 0;
}
