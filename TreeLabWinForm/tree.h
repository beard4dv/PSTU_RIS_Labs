#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

class Tree
{
private:
	double data;
	Tree* left;
	Tree* right;
	Tree* parent;
public:
	Tree(double);
	~Tree();
	void insertNode(double);
	void deleteTree() { delete this; }
	void printTree(int, System::Windows::Forms::RichTextBox^ box);
	Tree* findElement(double);
	Tree* findMax();
	Tree* findMin();
	Tree* next();
	Tree* prev();
	void deleteNode(double, System::Windows::Forms::RichTextBox^ box);
	void preOrder(Tree*, System::Windows::Forms::RichTextBox^ box);
	void inOrder(Tree*, System::Windows::Forms::RichTextBox^ box);
	void postOrder(Tree*, System::Windows::Forms::RichTextBox^ box);
	void addLeftTree(Tree* tree) { left = tree; }
	void addRightTree(Tree* tree) { right = tree; }
	void inOrderVector(Tree* node, System::Windows::Forms::RichTextBox^ box, vector<double>&);
	Tree* buildBalancedTree(const std::vector<double>& elems, int start, int end);
	Tree* balancedTree(System::Windows::Forms::RichTextBox^ box);
	int getHeight();
	int getPos(int index, int width, int curLevel, int maxLevel);
	Tree* copyTree();
	Tree* replaceNULLforEmpty();
	int getLevel(Tree* node);
	void insertLeft(double dt);
	void insertRight(double dt);
	Tree* getLeft() { return left; }
	Tree* getRight() { return right; }
	Tree* replace_help(Tree* node, int h);
	int getAmountOfNodes();
	void printVTree(int, System::Windows::Forms::RichTextBox^ box);
	void drawTree(sf::RenderWindow& window, Tree* node, float x, float y, float offsetX, float levelHeight = 100);
	Tree* getParent() { return parent; }
};