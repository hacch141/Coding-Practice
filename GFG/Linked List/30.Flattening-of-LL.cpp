// Flattening of LL

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

#include <bits/stdc++.h>

Node* merge(Node* a, Node* b) {
	if(!a) return b;
	if(!b) return a;

	Node* ans = new Node(-1);
	Node* res = ans;
  
	while(a && b) {
		if(a->data <= b->data) {
			res->child = a;
			res = res->child;
			res->next = NULL;
			a = a->child;
		}
		else {
			res->child = b;
			res = res->child;
			res->next = NULL;
			b = b->child;
		}
	}
	
	if(a) {
		a->next = NULL;
		res->child = a;
	}

	if(b) {
		b->next = NULL;
		res->child = b;
	}

	return ans->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head || !head->next) return head;

	head->next = flattenLinkedList(head->next);
	head = merge(head,head->next);
	return head;
}
// T : O(n*n*k)
// S : O(n*k)




/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

#include <bits/stdc++.h>

static bool compare(Node* n1, Node* n2) {
	return n1->data > n2->data;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	priority_queue<Node*, vector<Node*>, decltype(&compare)> pq(compare);

	while(head) {
		pq.push(head);
		head = head->next;
	}

	Node* newHead = new Node(-1);
	Node* temp = newHead;

	while(!pq.empty()) {
		Node* curr = pq.top();
		pq.pop();
		temp->child = curr;
		temp = curr;
		temp->next = NULL;
		if(curr->child) pq.push(curr->child);
	}

	return newHead->child;
}
// T : O(log(n) * (n*k))
// S : O(n)

// ============================================================================

// make NodeValue pair class

/*
	Time Complexity: O(log(n) * (n*k))
	Space complexity: O(n)

	Where 'n' denotes the size of the linked list and 'k' is the average number of child nodes for each of the n nodes.
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */


#include <queue>
using namespace std;

class NodevaluePair {

public:
    int value;
    Node *node;

    NodevaluePair(Node *node, int value) {
        this->node = node;
        this->value = value;
    }

    // To compare values pointed by Node
    bool operator < (const NodevaluePair &other) const {
        return value > other.value;
    }
};


Node *flattenLinkedList(Node *head) {
    Node *pointer = head;
    Node *result = NULL;
   
    // Heap to store all the node value pair.
    priority_queue<NodevaluePair> pq;

    // Push the head nodes.
    while (pointer) {
        pq.push(NodevaluePair(pointer, pointer->data));
        pointer = pointer->next;
    }

    // Add child nodes while popping out the minimum.
    while (!pq.empty()) {
        Node *temp = pq.top().node;
        pq.pop();
    
        // If the child of temp is not null add it to the heap.
        if (temp->child) {
            pq.push(NodevaluePair(temp->child, temp->child->data));
        }

        if (!result) {
            result = temp;
            pointer = temp;
            pointer->next = nullptr;
        } else {
            pointer->child = temp;
            pointer = temp;
            pointer->next = nullptr;
        }
    }
    
    return result;
}
