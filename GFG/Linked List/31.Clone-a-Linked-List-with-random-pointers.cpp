// Clone a Linked List with random pointers

#include <bits/stdc++.h>

Node *cloneLL(Node *head){
	// Write your code here
	Node* temp = head;
	while(temp) {
		Node* newNode = new Node(temp->data);
		newNode->next = temp->next;
		temp->next = newNode;
		temp = temp->next->next;
	}

	temp = head;
	while(temp) {
		if(temp->random) {
			temp->next->random = temp->random->next;
		}
		temp = temp->next->next;
	}

	Node* dummy = new Node(-1);
	Node* ans = dummy;
	temp = head;
	while(temp) {
		ans->next = temp->next;
		ans = ans->next;
		temp->next = temp->next->next;
		temp = temp->next;
	}

	return dummy->next;
}
// T : O(N)
// S : O(1Extra)



#include <bits/stdc++.h>

Node *cloneLL(Node *head){
	// Write your code here
	unordered_map<Node*,Node*> mp;
	Node* temp = head;
	while(temp) {
		mp[temp] = new Node(temp->data);
		temp = temp->next;
	}

	temp = head;
	while(temp) {
		Node* node = mp[temp];
		node->next = temp->next!=NULL ? mp[temp->next] : NULL;
		node->random = temp->random!=NULL ? mp[temp->random] : NULL;
		temp = temp->next;
	}

	return mp[head];
}
// T : O(N)
// S : O(N)


/*

	Time complexity: O(n)
	Space complexity: O(n)

	Where n is the number of nodes in the list

 */

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

#include <unordered_map>

Node *cloneLLHelper(Node *head, unordered_map<Node *, Node *> &visited)
{
	// Base Condition.
	if (head == NULL)
	{
		return NULL;
	}

	// If we have already processed the current node, simply return the cloned version of it.
	if (visited.find(head) != visited.end())
	{
		return visited[head];
	}

	// Create copy of the current node.
	Node *node = new Node(head->data);

	//  Store this value in the map. This is needed since there might be
	//  loops during traversal due to randomness of random pointers and this would
	//  help us avoid them. 
	visited[head] = node;

	//  Recursively copy the remaining linked list starting once from the next
	//  pointer and then from the random pointer.
	//  Thus we have two independent recursive calls.
	//  Finally we update the next and random pointers for the new node created.
	node->next = cloneLLHelper(head->next, visited);
	node->random = cloneLLHelper(head->random, visited);

	return node;
}

Node *cloneLL(Node *head)
{

	// Map which holds old nodes as keys and new nodes as its values.
	unordered_map<Node *, Node *> visited;

	return cloneLLHelper(head,visited);
}
