// LinkedListBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <crtdbg.h>
//#include <stdlib.h>
struct Node
{
	int data;
	Node* next;
};
Node* start;
void addNewNodeToStartOfList(int data);
void printList();
void addNewNodeToEndOfList(int data);
void deleteNodeFromStartList();
void deleteNodeFromEndList();
void deleteNodeFromEndListWithTemp();
void addNewNodeAfterSpecificElementInList(int nodeDataToFind, int newNodedata);
void addNewNodeBeforeSpecificElementInList(int nodeDataToFind, int newNodedata);
void deleteSpecificNodeFromList(int nodeDataToFind);
void deleteAfterSpecificNodeFromList(int nodeDataToFind);
void deleteBeforeSpecificNodeFromList(int nodeDataToFind);
struct Node* reverseList(struct Node* start);

int main()
{
	/*printf("Add node in front of head note:\n");
	addNewNodeToStartOfList(1);*/
	/*addNewNodeToStartOfList(2);
	addNewNodeToStartOfList(3);
	addNewNodeToStartOfList(4); 
	printList();*/
	printf("Add node at the end of list:\n");
	addNewNodeToEndOfList(1);
	addNewNodeToEndOfList(2);
	addNewNodeToEndOfList(3);
	/*addNewNodeToEndOfList(4);
	addNewNodeToEndOfList(5);*/	
	printList();
	//deleteNodeFromStartList();
	//printList();
	//deleteNodeFromEndList();
	/*deleteNodeFromEndListWithTemp();
	printList();*/
	/*addNewNodeAfterSpecificElementInList(2, 55);
	printList();*/
	/*addNewNodeBeforeSpecificElementInList(1, 55);
	printList();*/
	/*printList();
	deleteSpecificNodeFromList(1);*/
	/*deleteAfterSpecificNodeFromList(2);
	printList();*/
	/*deleteBeforeSpecificNodeFromList(1);
	printList();*/
	/*reverseList();*/
	start=reverseList(start);
	printList();
}

void addNewNodeToStartOfList(int data)
{
	if (start == NULL) {
		start = (Node*)malloc(sizeof(Node));
		start->data = data;
		start->next = NULL;
		printf("Head Node added  successfully!\n");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = start;
	printf("Node added in front of head successfully!\n");
	start = newNode;
}
void printList() {
	Node* current = start;
	printf("<-Start->\n");
	bool found = false;
	while (current != NULL) {
		printf("Current Next Data: %d,Current Next Address %p\n", current->data, current->next);
		current = current->next;
	}
	printf("<- End ->\n");
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	if (_CrtDumpMemoryLeaks()) {
		printf("You have some memory leaks\n");
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);  //check if memory leak
	
}

void addNewNodeToEndOfList(int data) {
	if (start == NULL) {
		start = (Node*)malloc(sizeof(Node));
		start->data = data;
		start->next = NULL;
		printf("Head Node added successfully!\n");
		return;
	}
	Node* tempNode = start;
	while (tempNode->next != NULL) {
		tempNode = tempNode->next;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	tempNode->next = newNode;
	printf("Node added to the end of list successfully!\n");
}

void deleteNodeFromStartList() {
	if (start == NULL) {
		printf("No node can be deleted from the start of list!\n");
		return;
	}
	Node* tempNode = start;
	start = start->next;
	free(tempNode);
	printf("Node deleted in front of head successfully!\n");
}

void deleteNodeFromEndList() {
	if (start == NULL) {
		printf("No node can be deleted from the end of list!\n");
		return;
	}
	if (start->next == NULL) {
		free(start);
		start = NULL;
		printf("Linked list is now empty!");
		return;
	}
	Node* current = start;
	while (current->next->next != NULL) {
		printf("current data : %d\n", current->data);
		current = current->next;
	}
	current->next = NULL;
	free(current->next);	
	printf("Node deleted from the end of list successfully!\n");
}

void deleteNodeFromEndListWithTemp() {
	if (start == NULL) {
		printf("No node can be deleted from the end of list!\n");
		return;
	}
	if (start->next == NULL) {
		free(start);
		start = NULL;
		printf("Linked list is now empty!");
		return;
	}
	Node* current = start;
	Node* temp = NULL;
	while (current->next != NULL) {
		printf("current data : %d\n", current->data);
		temp = current;
		current = current->next;
	}
	temp->next = NULL;
	free(current);
	printf("Node deleted from the end of list successfully!\n");
}


void addNewNodeAfterSpecificElementInList(int nodeDataToFind, int newNodedata) {
	if (start == NULL) {
		printf("Nothing in the linked list!\n");
		return;
	}
	Node* current = start;
	bool found = false;
	while (current != NULL) {
		if (current->data == nodeDataToFind) {
			found = true;
			printf("The specific element is found! The data is %d\n", current->data);
			break;
		}
		else {
			current = current->next;
		}
	}
	if (found == true) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = newNodedata;
		if (current->next != NULL) {
			newNode->next = current->next;
		}
		else {
			newNode->next = NULL;
		}
		current->next = newNode;
		printf("Node added after Node %d successfully!\n", nodeDataToFind);
	}
	else {
		printf("The specific element is not found! New node can not add\n");
	}
}

void addNewNodeBeforeSpecificElementInList(int nodeDataToFind, int newNodedata) {
	if (start == NULL) {
		printf("Nothing in the linked list!\n");
		return;
	}
	if (start->data == nodeDataToFind) {
		printf("The specific element is found at head! The data is %d\n", start->data);
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = newNodedata;
		newNode->next = start;
		start = newNode;
		printf("Node added before head node %d successfully!\n", nodeDataToFind);
		return;
	}
	Node* current = start;
	Node* preCurrent = NULL;
	bool found = false;
	while (current != NULL) {
		if (current->data == nodeDataToFind) {
			found = true;
			printf("The specific element is found! The data is %d\n", current->data);
			break;
		}
		else {
			preCurrent = current;
			current = current->next;
		}
	}
	if (found == true) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = newNodedata;
		newNode->next = current;
		preCurrent->next = newNode;
		printf("Node added before Node %d list successfully!\n", nodeDataToFind);
	}
	else {
		printf("The specific element is not found! New node can not add\n");
	}
}


void deleteSpecificNodeFromList(int nodeDataToFind) {
	if (start == NULL) {
		printf("No node can be deleted from the list!\n");
		return;
	}
	if (start->data == nodeDataToFind) {
		Node* current = start;
		start = start->next;
		free(current);
		printf("The specific Node %d is found and deleted from the list successfully!\n", nodeDataToFind);
		return;
	}

	Node* current = start;
	Node* preCurrent = NULL;
	bool found = false;
	while (current != NULL) {
		if (current->data == nodeDataToFind) {
			found = true;
			printf("The specific element is found! The data is %d\n", current->data);
			break;
		}
		else {
			preCurrent = current;
			if (current->next != NULL) {
				current = current->next;
			}
			else {
				printf("The specific element node %d is not found! Node can not delete!\n", nodeDataToFind);
				return;
			}
		}
	}
	if (found == true) {
		preCurrent->next = current->next;
		free(current);
		printf("The specific Node %d is found and deleted from the list successfully!\n", nodeDataToFind);
		return;
	}
}

void deleteAfterSpecificNodeFromList(int nodeDataToFind)
{
	if (start == NULL) {
		printf("Nothing in the linked list!\n");
		return;
	}
	Node* current = start;
	Node* afterCurrent = NULL;
	bool found = false;
	while (current != NULL) {
		if (current->data == nodeDataToFind) {
			found = true;
			if (current->next == NULL) {
				printf("The specific element is found at the end! The data is %d. Nothing to delete!\n", current->data);
				return;
			}
			else {
				afterCurrent = current->next;
				printf("The specific element is found! The data is %d\n", current->data);
				printf("The node after the specific element is found! The data is %d\n", afterCurrent->data);
				break;
			}
		}
		else {
			if (current->next != NULL) {
				current = current->next;
			}
			else {
				printf("The specific element node %d is not found! Node can not delete!\n", nodeDataToFind);
				return;
			}
		}
	}
	if (found = true) {
		if (current->next->next != NULL) {
			current->next = current->next->next;
		}
		else {
			current->next = NULL;
		}
		free(afterCurrent);
		printf("The node after the specific element is found! The data is %d. It is deleted successfully!\n", afterCurrent->data);
	}
}

void deleteBeforeSpecificNodeFromList(int nodeDataToFind)
{
	if (start == NULL) {
		printf("No node can be deleted from the list!\n");
		return;
	}
	if (start->data == nodeDataToFind) {
		printf("The specific Node %d is found at the start and nothing can be deleted!\n", nodeDataToFind);
		return;
	}
	if (start->next->data == nodeDataToFind) {
		Node* preCurrent = start;
		start = start->next;
		printf("The node before the specific element is found! The data is %d. \n", preCurrent->data);
		free(preCurrent);
		printf("The node before the specific element is found! The data is %d. It is deleted successfully!\n", preCurrent->data);
		return;
	}

	Node* prePreCurrent = start;
	Node* preCurrent = prePreCurrent->next;
	Node* current = preCurrent->next;
	bool found = false;
	while (current->next != NULL) {
		if (current->data == nodeDataToFind) {
			found = true;
			printf("The specific element is found! The data is %d\n", current->data);
			break;
		}
		else {
			prePreCurrent = preCurrent;
			preCurrent = current;
			current = current->next;
		}
		if (!found) {
			printf("The specific element node %d is not found! Node can not delete!\n", nodeDataToFind);
			return;
		}
	}
	if (found = true) {
		printf("The node before the specific element is found! The data is %d. \n", preCurrent->data);
		free(preCurrent);
		prePreCurrent->next = current;
		printf("The node before the specific element is found! The data is %d. It is deleted successfully!\n", preCurrent->data);
	}
}

struct Node* reverseList(struct Node* start) {
	if (start == NULL) {
		printf("List is empty,nothing to reverse!\n");
		return start;
	}
	
	struct Node* preNode = NULL;
	struct Node* current = start;
	struct Node* temp = NULL;

	while (current!= NULL) {
		temp = current->next;  // Store the next node
		current->next = preNode;  // Reverse the link
		preNode = current;  // Move prev and curr one step forward
		current = temp;
	}
	return preNode;  // Return the new start pointer
}

void LinkedListComponentsBrokenDown() {
	//Node start;
	Node* start = (Node*)malloc(sizeof(Node));
	Node* node2 = (Node*)malloc(sizeof(Node));
	Node* node3 = (Node*)malloc(sizeof(Node));
	Node* node4 = (Node*)malloc(sizeof(Node));
	//start.data = 1;
	start->data = 1;
	//start.next = node2;
	start->next = node2;
	node2->data = 2;
	node2->next = node3;
	node3->data = 3;
	node3->next = node4;
	node4->data = 4;
	node4->next = NULL;
	//printf("Start Data: %d,Start Address %p, Start Next Address %p\n", start.data, &start, start.next);
	printf("Start Data: %d,Start Address %p, Start Next Address %p\n", start->data, &start, start->next);
	printf("Node2 Data: %d,Node2 Address %p, Node2 Next Address %p\n", node2->data, node2, node2->next);
	printf("Node3 Data: %d,Node3 Address %p, Node3 Next Address %p\n", node3->data, node3, node3->next);
	//printf("Start Next Data: %d,Start Next Address %p, Start Next Next Address %p\n", start.next->data, start.next, start.next->next);
	printf("Start Next Data: %d,Start Next Address %p, Start Next Next Address %p\n", start->next->data, start->next, start->next->next);
	//-----add into function--------------------
	Node* current = start;
	bool found = false;
	while (current != NULL) {
		printf("Current Next Data: %d,Current Next Address %p\n", current->data, current->next);
		current = current->next;
	}
	//  ----add to function 
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
