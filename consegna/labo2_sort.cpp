#include "labo2_sort.h"


void scambia(vector<int>& v, int i, int j)
{ 
  int tmp = v[j];
  v[j] = v[i];
  v[i] = tmp;
}


/**************************************************************************************
                SELECTION SORT
***************************************************************************************/
void selectionSort(vector<int>& v)
{
   int current_min_index;
   unsigned int size = v.size();
   for (unsigned int i=0; i<size; ++i)
   { 
     current_min_index = i;
     for (unsigned int j=i+1;j<size; ++j)
        if (v[current_min_index] > v[j])
            current_min_index = j;
     scambia(v, i, current_min_index);
   }
}



/**************************************************************************************
                INSERTION SORT
***************************************************************************************/
void insertionSort(vector<int>& v)
{
   int current, prev;
   unsigned int size = v.size();
   for (unsigned int i=1; i<size; ++i)
   { current=i; 
     prev=i-1;
     while(prev>=0 && v[current]<v[prev])
        {
         scambia(v, current, prev);
         --current;
         --prev;
        }
   }
}


/**************************************************************************************
                BUBBLESORT
***************************************************************************************/
void bubbleSort(vector<int>& v)
{
   unsigned int size = v.size();
   bool scambiati;
   for (unsigned int i=1; i<size; ++i)
      {
      scambiati = false;
      for (unsigned int j=0; j<size-i; ++j)
          if(v[j]>v[j+1])
            { 
              scambia(v, j, j+1);
              scambiati = true;
            }
      if (!scambiati) return;
      }
}



/**************************************************************************************
                   MERGESORT
***************************************************************************************/
void fondi(vector<int>& v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
   vector<int> vsinistra, vdestra;

   for (unsigned int i=inizio; i<=centro; ++i)
      vsinistra.push_back(v[i]);

   for (unsigned int i=centro+1; i<=fine; ++i)
      vdestra.push_back(v[i]);

   unsigned int indicesinistra = 0;
   unsigned int maxsin = vsinistra.size();
   unsigned int indicedestra = 0;
   unsigned int maxdes = vdestra.size();
   
   for (unsigned int i=inizio; i<=fine; ++i)
   {
      if (indicesinistra < maxsin && indicedestra < maxdes)
         {
         if (vsinistra[indicesinistra]<vdestra[indicedestra])
            {
             v[i] = vsinistra[indicesinistra];
             indicesinistra++; continue;
             }
         else
            { 
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
            }
         } 
      
      if (indicesinistra == maxsin && indicedestra < maxdes)
         { 
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
         }

       if (indicedestra == maxdes && indicesinistra < maxsin)
         { 
            v[i] = vsinistra[indicesinistra];
            indicesinistra++; continue;
         }         
   } 
}

void ms(vector<int>& v, unsigned int inizio, unsigned int fine)
{
    if (inizio < fine)
      {
          unsigned int centro = (inizio+fine)/2;
          ms(v, inizio, centro);
          ms(v, centro+1, fine);
          fondi(v, inizio, centro, fine);
      }
}


void mergeSort(vector<int>& v)
{
   if (v.size() != 0)
      ms(v, 0, v.size()-1);
}


/**************************************************************************************
                QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/




int partitionAux (vector<int>& v, int start, int end)
{
    int pivotIndex = start;
    int i = start+1;
    for (int j=start+1; j<=end; ++j)
        {
        if (v[j] < v[start]) 
        {
            scambia(v, i, j);
            ++i;
        }
        }
    scambia(v, start, i-1);
    return i-1;
    
}

void quickSortAux (vector<int>&v, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partitionAux (v, start, end);
        quickSortAux(v, start, pivotIndex-1);
        quickSortAux(v, pivotIndex+1, end); 
    }
}
void quickSortTrivial(vector<int>& v)
{
   /* Implementare quickSort banale con partizione in place */
   quickSortAux(v, 0, v.size()-1);
  
}




/**************************************************************************************
                QUICKSORT RANDOMIZZATO
***************************************************************************************/


int partitionAuxRand (vector<int>& v, int start, int end)
{
    int pivotIndex = start+rand()%(end-start+1); //range tra 0 e (end-start+1)?
    scambia(v, pivotIndex, start);
    int i = start+1;
    for (int j=start+1; j<=end; ++j)
        {
        if (v[j] < v[start]) 
        {
            scambia(v, i, j);
            ++i;
        }
        }
    scambia(v, start, i-1);
    return i-1;
    
}

void quickSortAuxRand (vector<int>&v, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partitionAuxRand (v, start, end);
        quickSortAuxRand(v, start, pivotIndex-1);
        quickSortAuxRand(v, pivotIndex+1, end); 
    }
}


void quickSortRandom(vector<int>& v)
{
   srand(777777);
   /* Implementare quickSort banale con partizione in place */
   quickSortAuxRand(v, 0, v.size()-1);
  
}

