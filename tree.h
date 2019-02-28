class Tree {
	private:
		struct Node{
			Node* parent;
			Node* left;
			Node* right;
			int data;
		};
		int size;
		Node* root;
		void sort(Node*);
	public: 
		Tree();

		void insert(int);
		Node* search(int);
		void remove(int);
		void print();
};