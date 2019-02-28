#include <iostream>
#include "tree.h"

Tree::Tree(){
	size = 0;
	root = 0;
}

void Tree::insert(int data){
	if(root == 0){
		root = new Node();
		root->left = 0;
		root->right = 0;
		root->parent = 0;
		root->data = data;
		size++;
		std::cout << "Inserted " << data << std::endl;
		return;
	}

	Node* current = root;
	while(true){
		if(data <= current->data){
			if(current->left){
				current = current->left;
				continue;
			}
			Node* new_node = new Node();
			new_node->data = data;
			new_node->left = 0;
			new_node->right = 0;
			new_node->parent = current;
			current->left = new_node;
			size++;
			std::cout << "Inserted " << data << " to the left of " << current->data << std::endl;
			return;
		}else if(data > current->data){
			if(current->right){
				current = current->right;
				continue;
			}
			Node* new_node = new Node();
			new_node->data = data;
			new_node->left = 0;
			new_node->right = 0;
			new_node->parent = current;
			current->right = new_node;
			size++;
			std::cout << "Inserted " << data << " to the right of " << current->data << std::endl;
			return;
		}
	}
}