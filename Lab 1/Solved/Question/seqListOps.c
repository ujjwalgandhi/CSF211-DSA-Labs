/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; 
 int size;

 printf("\nEnter the Number of Jobs: ");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
	if (!sl) createlist();

	sl.size++;
	int count = 0;
	while (st[count].next != -1){
		if (compare(j, st[count].ele) == LESSER){
			Location temp = st[count-1] || null;
			if (temp){
				Location new = {j, count}
				temp.next = count-1;
			}
			Location new = {j, 1};

		}
		count++;
	}
	return(sl);
 }
  
void insertelements (JobList list , int size, SeqList s[3])
{

// Implement this function
	for (int i=0; i<3; i++)
		s[i] = createlist();


}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
	int count = 0
	for (int i=2; i>=0; i--){
		for(int j = 0; j < sizeof(s[i]/sizeof(s[i][0])); j++){
			ele[count++] = s[i][j];
		}
	}
}

void printSeqList(SeqList sl)
{

// Implement this function
	int i=0;
	while (st[i].next != -1){
		printJob(st[i].ele);
		i++;
	}
}

void printJobList(JobList list, int size)
{

// Implement this function
	for (int i=0; i<size; i++)
		printJob(list[i]);
}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
