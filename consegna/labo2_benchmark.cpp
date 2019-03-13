// compilare con il comando seguente:
// g++ -Wall -std=c++11 labo2_main.cpp labo2_aux.cpp labo2_sort.cpp -o labo2

#include <stdexcept>
#include <vector>
#include <iostream>
#include "labo2_aux.h"   // funzioni ausiliarie per lettura/scrittura su file
#include "labo2_sort.h"  // vari algoritmi di ordinamento
#include <string>

using namespace std;


#include <chrono>        // Namespace e funzioni per misurare il tempo, utili per la valutazione delle prestazioni dei programmi e inclusi nello standard C++ dal 2011 in avanti.  Per usarli con il compilatore g++ e' necessario inserire l'opzione di compilazione -std=c++11.  Altri compilatori potrebbero richiedere opzioni diverse da questa.

using namespace std::chrono;


int main()
{
try {

    
    string output_csv = "insertionSort1, insertionSort2, insertionSort3, media1, selectionSort1, selectionSort2, selectionSort3, media2, Bubblesort1, Bubblesort2, Bubblesort3, media3, Mergesort1, Mergesort2, Mergesort3, media4, Quicksortbanale1, Quicksortbanale2, Quicksortbanale3, media5, Quicksortrandom1, Quicksortrandom2, Quicksortrandom3 \n";
    vector<int> v1;
    
    string files[] = {"in-10.txt","in-10-ordinati.txt", "in-100.txt","in-100-ordinati.txt", "in-1000.txt",  "in-1000-ordinati.txt", "in-10000.txt","in-10000-ordinati.txt", "in-40000.txt", "in-40000-ordinati.txt"};
    int files_size = 10;
    string file_name;
    high_resolution_clock::time_point t1, t2;
    int duration;
    
    for (int i = 0; i < files_size; i++) {
        file_name = files[i];
	cout << "doing " << file_name << endl;    

	
	string line = "";
	

	
	// selectionSort 1
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        insertionSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 2
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        insertionSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 3
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        insertionSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	
	line.append(",");
	
	// selectionSort 1
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        selectionSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 2
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        selectionSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 3
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        selectionSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	
	line.append(",");
	
	// selectionSort 1
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        bubbleSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 2
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        bubbleSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 3
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        bubbleSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	
	line.append(",");
	
	// selectionSort 1
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        mergeSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 2
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        mergeSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 3
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        mergeSort(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	
	line.append(",");
	
	// selectionSort 1
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        quickSortTrivial(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 2
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        quickSortTrivial(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 3
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        quickSortTrivial(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	
	line.append(",");
	
	// selectionSort 1
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        quickSortRandom(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 2
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        quickSortRandom(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	// selectionSort 3
	v1 = leggiVettoreDaFile(file_name);
        t1 = high_resolution_clock::now();
        quickSortRandom(v1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>( t2 - t1 ).count();
	line.append(to_string(duration));
	line.append(", ");
	
	line.append(",");
	

	
	
	line.append("\n");
	output_csv.append(line);
    }


cout << output_csv;
	
	
	

return 0;
     } 
catch (runtime_error &msg) 
   {cerr << "Errore a runtime: " << msg.what() << endl;} 
catch (...) 
   {cerr << "Eccezione non riconosciuta\n";}
}
