 //Includes
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Defines
#define DRIVE      0
#define TURN_LEFT  1
#define TURN_RIGHT 2
#define REVERSE    3
#define MAX_POINTS 6

//Defined Structures
typedef struct WAYPOINT_TAG
{
  int waypointNumber;
  int direction;
  int amount;
  struct WAYPOINT_TAG *next;
  
} WAYPOINT;  

//Prototypes of the functions you need to implement
 WAYPOINT* InsertOneWaypoint(WAYPOINT* head, WAYPOINT wPoint);
 WAYPOINT* DeleteAllWaypoints(WAYPOINT* head);

//Prototypes of sample functions provided to you
 WAYPOINT* AddFirstWaypoint(WAYPOINT* head, WAYPOINT wPoint);
 void FollowWaypoints(WAYPOINT* head);

//Waypoints you need to insert in your linked list
WAYPOINT waypointsDisarray[MAX_POINTS] = {
                            {3,REVERSE,150,NULL},
                            {0,DRIVE,55,NULL},
                            {4,DRIVE,100,NULL},
                            {1,TURN_RIGHT,45,NULL},
                            {2,DRIVE,80,NULL},
                            {5,TURN_LEFT,10,NULL}
                       };

///////////////////////////////////////////////////////////////////////////////
//
// Function: Main
//
// Description: You have to call the functions to implement the requirements of
//              the exam here.
//
// Parameters: none
//
// Returns: int - 0 for normal exit of the program
//
///////////////////////////////////////////////////////////////////////////////
int main(void)
{
    WAYPOINT* head=NULL; //make head of type WAYPOINT structure pointer. set it to point to NULL
   // WAYPOINT* new_node=NULL; //make new_node to use of type WAYPOINT structure pointer. set it to point to NULL
   // WAYPOINT* cursor=NULL;
    
    //1. Here you need to call the function to insert each waypoint that is
    //   in the array into a your link list.
    //starting from the head there you keep adding
for(int i = 0; i < MAX_POINTS; i++) {
    //make sure save to head, so it catches the return
    head = InsertOneWaypoint( head, waypointsDisarray[i]); //call the function to insert. head is passed at the start and on the current index the node from array. but then head gets returned from the function so get one before being new head
    //FollowWaypoints(head);
    //printf("1 head: %d \n", head);
}

    //2. Then you need to follow the waypoints by calling the appropriate function
    FollowWaypoints(head);
    
    //3. Finally you need to delete all the waypoints in the list.
    head = DeleteAllWaypoints(head);
    
    //4. Now call the function to follow the waypoints again, if you see garbage fix the problem
    FollowWaypoints(head);

    system("PAUSE");    
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function: DeleteAllWaypoints
//
// Description: You are required to implement this function. 
//
// Parameters:
//
// Returns:
//
///////////////////////////////////////////////////////////////////////////////
WAYPOINT* DeleteAllWaypoints(WAYPOINT* head) {

     if (head == NULL)
         return NULL;
     WAYPOINT* cursor = head;
     WAYPOINT* back = NULL;
     while (head != NULL) {
         cursor = head;
         back = NULL;
         while (cursor->next != NULL) {
             back = cursor;
             cursor = cursor->next;
         }
         if (back != NULL) {
             back->next = NULL;
            // printf("1 cursor->waypointNumber: %d \n", cursor->waypointNumber);
         }
         /* if this is the last node in the list*/
         if (cursor == head) {
             head = NULL;
             // free(head);
            // printf("2 cursor->waypointNumber: %d \n", cursor->waypointNumber);

         }
         free(cursor);
         // FollowWaypoints(head);
     }
     return head;
 }

    //5.	The function must delete all the waypoints in the list, freeing the
  //    memory of each node that is deleted.



  //6.	The function must return the head


///////////////////////////////////////////////////////////////////////////////
//
// Function: InsertOneWaypoint
//
// Description: You are required to complete this function to insert a waypoint
//              based on its number in the correct order 0,1,2....
//
// Parameters: pointer to a WAYPOINT; the head of the list
//
// Returns: the head of the list in case it changes
//
///////////////////////////////////////////////////////////////////////////////

WAYPOINT* InsertOneWaypoint(WAYPOINT* head, WAYPOINT wPoint) {

    //
    // WAYPOINT* cursor = head; //cursor becomes a copy of the head. it is like a pointer now that can move around the array

     //first part is the same as AddFirstWaypoint
     //7.	The function must first check if the list is empty.
     //    If it is empty call the AddFirstWaypoint function that has been provided.

    if (head == NULL) { //if head still not pointing to anything. means wasn't created any yet, so need to call AddFirstWaypoint function to add the first one
        // printf("head: %d", head);
        head = AddFirstWaypoint(head, wPoint); //make sure save to head, so it catches the return
        // printf("head: %d", head);
         return head;
     }
     //8.	If the list is not empty, the function must ask for memory. And fill the
     //    information from the wPoint into the linked list.
    // WAYPOINT* cursor=NULL;
    //WAYPOINT* cursor = head; //cursor becomes a copy of the head. it is like a pointer now that can move around the array
    WAYPOINT* new_node=(WAYPOINT*) malloc(sizeof(WAYPOINT));

     new_node->waypointNumber = wPoint.waypointNumber;
     new_node->direction = wPoint.direction;
     new_node->amount = wPoint.amount;
     new_node->next = NULL;
    //printf("new_node: %d \n", new_node);

     //9.	The function must then check if the node's waypointNumber is smaller than the
     //    current head. It is the node is inserted at the head.

     //head is just a pointer always pointing to the start of linked list (it doesn't point to the start one, it will get lost)
     //so when inserting before the node that is the head: need make the head point to the new_node. while new_node points to the node that head was pointing to before
     if (new_node->waypointNumber <
         head->waypointNumber) { //if number waypointNumber at new_node is less than the value that head is pointing to (so accessing its value)
         //printf(" 1 new_node: %d head: %d \n", new_node, head);
         new_node->next = head; //new_node location that points to next is set to the same location as what *head pointer pointing to (the current head)
         head = new_node;

         //printf(" 2 new_node->next: %d head: %d \n", new_node->next, head);
     } else {
         // WAYPOINT* cursor =(WAYPOINT*) malloc(sizeof(WAYPOINT)); && cursor->next != NULL, cursor = cursor->next;
         //printf(" 3 new_node: %d head: %d \n", new_node, head);
         WAYPOINT* cursor = head; //cursor becomes a copy of the head. it is like a pointer now that can move around the array
         // cursor->waypointNumber = head->waypointNumber;//pointer of type WAYPOINT called cursor created. location that it is to point becomes the head. so it now points to the head
         //printf(" 31 new_node->waypointNumber %d cursor %d \n", new_node->waypointNumber, cursor);
         while (cursor->waypointNumber < new_node->waypointNumber ) {
             //printf(" 311 cursor->waypointNumber: %d new_node->waypointNumber %d cursor->next %d \n", cursor->waypointNumber, new_node->waypointNumber, cursor->next);
             if (cursor->next == NULL) {
                 // new_node->next = cursor->next;
                 cursor->next = new_node;
                 //printf(" 41 new_node->next: %d head->next: %d \n", new_node->next, cursor->next);
             }
             if (cursor->next->waypointNumber > new_node->waypointNumber) {
                 new_node->next = cursor->next;
                 cursor->next = new_node;
                 //printf(" 42 new_node->next: %d cursor->next: %d \n", new_node->next, cursor->next);
                 // printf(" 3111 cursor: %d cursor->waypointNumber %d cursor->next->waypointNumber %d \n", cursor, cursor->next->waypointNumber,
             }
             cursor = cursor->next; //cursor moves over to next address

         }

         //printf(" 4 new_node->next: %d head->next: %d \n", new_node->next, head->next);
     }

     //10.	If the waypoint has to be inserted after the head, the function must traverse
     //    the list until either it finds the insertion point or the end of the list is reached.


     //11.	The function must then insert the node at that location.

     //12.	The function must return the head for all the conditions mentioned above.
     return head;
 }
///////////////////////////////////////////////////////////////////////////////
//
// Function: AddFirstWaypoint
//
// Description: This function is provided to you as a starter. You may use it as
//              part of your solution or just as a sample.
//
// Parameters: head of the list pointer to WAYPOINT, node to insert of type WAYPOINT
//
// Returns: the head of the list
//
///////////////////////////////////////////////////////////////////////////////
WAYPOINT* AddFirstWaypoint(WAYPOINT* head, WAYPOINT wPoint)
{
   // printf(" addfirst = %d \n", wPoint );
  if(head==NULL)
  {
    head=(WAYPOINT*)malloc(sizeof(WAYPOINT));
    if(head == NULL)
    {
      printf("Error no dynamic memory available");
      system("PAUSE");    
      exit(0);
    }
    head->waypointNumber=wPoint.waypointNumber;
    head->direction=wPoint.direction;
    head->amount=wPoint.amount;
    head->next=NULL;
  }
  else
  {
    printf("Error List not empty");
  }
 // printf("waypointNumber: %d, direction: %d. amount: %d, head next: %d, head: %d", head->waypointNumber, head->direction, head->amount, head->next, head);

  return head;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function: FollowWaypoints
//
// Description: This function is provided to you.  Assuming you
//              created all the waypoints in the linked list correctly, all
//              that is required is to follow them!
//
// Parameters: head of the list a pointer to WAYPOINT
//
// Returns: nada
//          zip
//
///////////////////////////////////////////////////////////////////////////////
void FollowWaypoints(WAYPOINT* head)
{
  WAYPOINT* traverse = head;
  char message[50];
  if (head == NULL)
    printf("Cannot Follow Empty List\n");
  else 
    printf("Following List\n");
  while (traverse != NULL)
  {

        switch (traverse->direction)
        {
               case DRIVE:
                    sprintf(message,"Waypoint %d, DRIVE, \t%d\n",traverse->waypointNumber,traverse->amount);
                    break;
               case TURN_RIGHT:
                    sprintf(message,"Waypoint %d, TURN_RIGHT, %d\n",traverse->waypointNumber,traverse->amount);
                    break;
               case TURN_LEFT:
                    sprintf(message,"Waypoint %d, TURN_LEFT, \t%d\n",traverse->waypointNumber,traverse->amount);
                    break;
               default://reverse
                    sprintf(message,"Waypoint %d, REVERSE, \t%d\n",traverse->waypointNumber,traverse->amount);
                    break;                    
        }                    
        traverse=traverse->next; 
        printf(message);                                                           
  }     
  return;
}
