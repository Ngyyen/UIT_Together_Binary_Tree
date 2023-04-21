#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Node {
public:
	Node() = default;
	Node(int x) {
		data = x;
	}
	int data = 0;
	Node* left = NULL;
	Node* right = NULL;
};

using Tree = Node*;

void init(Tree&);
int is_empty(Tree&);
Node* get_node(int data);
int insert_node(Tree&, int data);
int Nhap(Tree&, string file_name);
void Xuat(const Tree&, ostream&);
int dem_node(const Tree&);

int main() {
	Tree t;
	for (int i = 1; i <= 13; ++i) {
		string file_name = "intdata";
		if (i < 10) {
			file_name += "0";
		}
		string num_file = to_string(i);
		string file_in = file_name + num_file + ".inp";
		string file_out = file_name + num_file + ".out";
		ofstream fo(file_out);
		if (Nhap(t, file_in) == 1) {
			fo << "So luong node: " << dem_node(t) << endl;
			Xuat(t, fo);
		}
	}
	return 0;
}

void init(Tree& t) {
	t = NULL;
}
int is_empty(Tree& t) {
	if (t == NULL)
		return 1;
	return 0;
}
Node* get_node(int data) {
	Node* p = new Node(data);
	return p;
}
int insert_node(Tree& t, int data) {
	if (t != NULL) {
		int rvalue = rand();
		if (rvalue % 2 == 0) {
			return insert_node(t->right, data);
		}
		return insert_node(t->left, data);
	}
	t = get_node(data);
	if (t == NULL)
		return -1;
	return 1;
}
int Nhap(Tree& t, string file_name) {
	ifstream fi(file_name);
	if (fi.fail() == true)
		return -1;
	int n, x;
	fi >> n;
	init(t);
	for (int i = 0; i < n; ++i) {
		fi >> x;
		insert_node(t, x);
	}
	return 1;
}
void Xuat(const Tree& t, ostream& os) {
	if (t == NULL) {
		return;
	}
	Xuat(t->left, os);
	os <<setw(5)<< t->data;
	Xuat(t->right, os);
}
int dem_node(const Tree& t) {
	if (t == NULL) {
		return 0;
	}
	int a = dem_node(t->left);
	int b = dem_node(t->right);
	return a + b + 1;
}
