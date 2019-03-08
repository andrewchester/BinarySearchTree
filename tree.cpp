#include <iostream>
#include <cmath>
#include "tree.h"
//---- Non member function ---- 

int get_spaces(int depth, int max_depth){
	depth = max_depth - depth;
	if (depth == 1)
		return 1;
	return pow(2, depth);
}

//-----------------------------
Tree::Tree(){
	size = 0;
	root = 0;
}
int Tree::get_depth(Node* root, int depth){
	depth++;
	if(root->left == 0 && root->right == 0)
		return depth;
	int max_depth = depth;
	if(root->left != 0){
		int next_depth = get_depth(root->left, depth);
		if (next_depth > max_depth)
			max_depth = next_depth;
	}
	if(root->right != 0){
		int next_depth = get_depth(root->right, depth);
		if(next_depth > max_depth)
			max_depth = next_depth;
	}
	return max_depth;
}
void Tree::print_helper(Node* root, int current_depth, int target_depth, int inbetween_tabs){
	if(current_depth > target_depth) //If we're too deep into the tree, return
		return;
	if(current_depth == target_depth){ //If this is the right depth, then print out the data of the node
		std::cout << root->data;
		for (int i = 0; i < inbetween_tabs; i++)
			std::cout << ' ';
		return;
	}
	if(current_depth < target_depth){ //If we need to go deeper
		if(root->left != 0) //Make sure left exists
			print_helper(root->left, current_depth + 1, target_depth, inbetween_tabs); //Go down the left side
		if(root->right != 0) //Make sure right exists
			print_helper(root->right, current_depth + 1, target_depth, inbetween_tabs); //Go down the right side
	}
}

void Tree::print(bool tree_output){
	int total_depth = get_depth(root, 1) - 1;
	if(tree_output){
		int print_depth = 1; //The current depth of the heap we're printing
		int width = 1;
		int tabs_before, inbetween_tabs, distance_from_bottom;
		while(print_depth <= total_depth){ 
			distance_from_bottom = total_depth - print_depth;
			tabs_before = distance_from_bottom;
			inbetween_tabs = pow(2, distance_from_bottom + 1);
			for(int i = 0; i < tabs_before; i++)
				std::cout << " ";
			print_helper(root, 1, print_depth, inbetween_tabs); //Prints out all nodes in the heap at the right depth
			std::cout << std::endl; 
			/*
			if(print_depth != total_depth){ //If we're not at the bottom of the list print out the right number of '/\'
				for(int i = 0; i < width; i++){
					for (int x = 0; x < num_spaces; x++)
						std::cout << " ";
					std::cout << "/\\ ";
				}
				std::cout << std::endl;
			}
			*/
			width *= 2;
			print_depth++; //Increase the print depth
		}
	}else{
		for(int i = 1; i <= total_depth; i++) //Loop through the layers and output it all in one go
			print_helper(root, 1, i, 0);
		std::cout << std::endl;
	}
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