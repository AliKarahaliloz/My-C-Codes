#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node{
    
    int data;
    struct Node* next;
    
};

struct Student{
    
    int number;
    int age;
    char name[50];
    struct Student* next;
};

//first student node for student information system
struct Student* head = NULL;


//func do that add new nodes, if its even end of the list or its odd beginning of the list
void insertNode(struct Node **head, int value) {
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node)); //first node
    newNode->data=value;
    newNode->next=NULL;
    
    if(*head==NULL){
        *head=newNode; //first node should be head
    }
    //if its odd
    else if(newNode->data %2 != 0){
        struct Node *current=newNode;
        current->data=value;
        current->next=*head;
        *head=current;
    }
    //if its even
    else{
       struct Node *current=*head;
       while(current->next!=NULL){
           current=current->next;
       }
       current->next=newNode;
        
    }
    
}

//func that adds new nodes to linked list
void insertNodeSort100(struct Node** head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //first node
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL || value <= (*head)->data){
        newNode->next=*head;
        *head=newNode;
    }
    else{
        struct Node* current=*head;
        while(current->next != NULL && current->next->data < value){
            current = current->next;    
        }
        newNode->next=current->next;
        current->next=newNode;
    }
}


void evenOdd(){
    int value;
    struct Node *head=NULL;
    printf("Enter data to add to list(for exit, type -1): \n");
    
    while(1){
        scanf("%d",&value);
        if (value==-1){
            break;
        }
        //we should call the func
        insertNode(&head,value);
    }
    
    struct Node *current=head;
    
    printf("List start with: ");
    
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("End of the list.\n");
    
}

void sort100(){
    
    struct Node* head = NULL;
    int nums[100];
    int i;
    //creating random numbers
    srand(time(NULL));
    for (i = 0; i < 100; i++){
        nums[i]=rand()%500; //creating random numbers between 0-499
        insertNodeSort100(&head,nums[i]);
    }
    
    //print the list
    printf("Random Numbers Sorted:\n");
    while (head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("End of the list.\n");
}

//add student
void addStudent(){
    
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student)); //first node
    if (newNode == NULL) {
        printf("Out of memory.\n");
        return;
    }
    
    //get inputs
    printf("Enter student name(It's important if it's uppercase or lowercase.): ");
    scanf("%s", newNode->name);
    printf("Enter student age: ");
    scanf("%d", &newNode->age);
    printf("Enter student number: ");
    scanf("%d", &newNode->number);
    
    newNode->next = head;
    head = newNode;

    printf("Student added.\n");
}


//search student
void searchStudent(char nameSearch[50]){
    struct Student* current = head;
    int counter=1;
    
    while(current!=NULL){
        if(strcmp(current->name, nameSearch)==0){ //if it finds same name
            printf("%d: %s %d %d\n", counter, current->name, current->age, current->number);
            counter++; //continue to search if there is another student with same name
        }
        current=current->next;
    }
    
    if (counter==1){
        printf("Student not found.");
    }
}

//delete student
void deleteStudent(char nameDelete[50]){
    
    struct Student* current = head;
    struct Student* previous = NULL;
    
    
    while (current != NULL){
        if (strcmp(current->name, nameDelete) == 0){
            
            if (previous == NULL){
                head=current->next;
            } 
            
            else {
                previous->next = current->next;
            }
            free(current);
            printf("%s has been deleted.\n", nameDelete);
            return;
        }
        previous = current;
        current = current->next;
    }
    
    
}


//print student who has longest name
void longestName(){
    
    struct Student* current = head;
    char longestName[50] = "";
    
    while (current != NULL) {
    if (strlen(current->name) > strlen(longestName)) {//compare the lenghts
        strcpy(longestName, current->name);
    }
        current = current->next;//move to the next node
    }
    
    printf("The longest name on the list: %s\n", longestName);
    printf("Lenght: %ld\n", strlen(longestName));    
}


//student information system menu
void studentInfoSystem(){
    
    int choice;
    char nameSearch[50];
    char nameDelete[50];
    
    while (1) {
        printf("Choose one to work: \n1:Add student.\n2:Search student.\n3:Delete student.\n4:Student with longest name.\n5:Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            
            case 1:
                addStudent();    
                break;
            case 2:
                printf("Enter student name to search(It's important if it's uppercase or lowercase.): ");
                scanf("%s", nameSearch);
                searchStudent(nameSearch);
                break;
            case 3:
                printf("Enter student name to delete(It's important if it's uppercase or lowercase.): ");
                scanf("%s", nameDelete);
                deleteStudent(nameDelete);
                break;
            case 4:
                longestName();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.");
            
            
            
            
            
        }
    
    
    
    
    
    }
}






int main(){
    
    int start;
    printf("Choose one to work: \n1:Add numbers to head or end of the list whether nums are odd or even.\n2:Create 100 random numbers and sort them.\n3:Student information system.\n");
    scanf("%d",&start);
    switch(start){
        case 1:
            evenOdd();
            break;
        case 2:
            sort100();
            break;
        case 3:
            studentInfoSystem();
            break;
        default:
            printf("Invalid Choice.");
    return 0;
    }
    
    
    return 0;
}