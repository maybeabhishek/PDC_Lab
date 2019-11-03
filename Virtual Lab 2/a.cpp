   #include<iostream>
   #include <mpi.h>


   struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* Returns true if linked lists a and b 
are identical, otherwise false */
bool areIdentical(struct Node *a, 
				struct Node *b) 
{ 
	while (a != NULL && b != NULL) 
	{ 

		if (a->data != b->data) 
			return false; 

		/* If we reach here, then a and b are 
		not NULL and their data is same, so 
		move to next nodes in both lists */
		a = a->next; 
		b = b->next; 
	} 

	// If linked lists are identical, then 
	// 'a' and 'b' must be NULL at this point. 
	return (a == NULL && b == NULL); 
} 

/* UTILITY FUNCTIONS TO TEST fun1() and fun2() */
/* Given a reference (pointer to pointer) to the 
head of a list and an int, push a new node on the 
front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
		(struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

void printList(struct Node* a){
    cout<<endl;
    while(a!=NULL){
        cout<<a->data<<" ";
        a=a->next;
    }
    cout<<endl;
}


   int main(int argc, char **argv) 
   { 
     MPI_Comm   myComm;      /* intra-communicator of local sub-group */ 
     MPI_Comm   myFirstComm; /* inter-communicators */ 
     MPI_Comm   mySecondComm; 
     MPI_Status status; 
     int membershipKey; 
     int rank; 
 
     MPI_Init(&argc, &argv); 
     MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
 
     /* User code must generate membershipKey in the range [0, 1, 2] */ 
     membershipKey = rank % 3; 
 
     /* Build intra-communicator for local sub-group */ 
     MPI_Comm_split(MPI_COMM_WORLD, membershipKey, rank, &myComm); 
 
     /* Build inter-communicators.  Tags are hard-coded. */ 
     if (membershipKey == 0) 
     {             /* Group 0 communicates with groups 1 and 2. */ 
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 1, 
                            1, &myFirstComm); 
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 2, 
                            2, &mySecondComm); 
     } 
     else if (membershipKey == 1) 
     {         /* Group 1 communicates with groups 0 and 2. */ 
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 0, 
                            1, &myFirstComm); 
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 2, 
                            12, &mySecondComm); 
     } 
     else if (membershipKey == 2) 
     {        /* Group 2 communicates with groups 0 and 1. */ 
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 0, 
                            2, &myFirstComm); 
       MPI_Intercomm_create( myComm, 0, MPI_COMM_WORLD, 1, 
                            12, &mySecondComm); 
     } 
 
     struct Node *a = NULL; 
	struct Node *b = NULL; 
	push(&a, 1); 
	push(&a, 2); 
	push(&a, 3); 
	push(&b, 1); 
	push(&b, 2); 
	push(&b, 3); 

	cout<<"First List";
    printList(a);
    cout<<"Second List List";
    printList(b);
    if(areIdentical(a, b)) 
		cout << "\n\nIdentical\n"; 
	else
		cout << "Not identical";  
     /* Then free communicators before terminating... */ 
     MPI_Comm_free(&myFirstComm); 
     MPI_Comm_free(&mySecondComm); 
     MPI_Comm_free(&myComm); 
     MPI_Finalize(); 
   } 