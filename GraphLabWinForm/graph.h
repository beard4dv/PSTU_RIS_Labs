#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>

using namespace std;

const int maxSize = 8;

class Graph
{
private:
	vector<int> vertList;
	int adjMatrix[maxSize][maxSize];
public:
	Graph();
	~Graph();
	bool IsEmpty();
	bool IsFull();
	void Print(System::Windows::Forms::RichTextBox^ box);
	int GetVertPos(const int& vertex);
	void insertVertex(const int& vertex, System::Windows::Forms::RichTextBox^ box);
	void removeVertex(const int& vertex, System::Windows::Forms::RichTextBox^ box);
	void insertEdge(const int& vertex1, const int& vertex2, int weight, System::Windows::Forms::RichTextBox^ box);
	void removeEdge(const int& vertex1, const int& vertex2, System::Windows::Forms::RichTextBox^ box);
	void DFS(const int& startVertex, System::Windows::Forms::RichTextBox^ box);
	void BFS(const int& startVertex, System::Windows::Forms::RichTextBox^ box);
	void Dijkstra(const int& startVertex, System::Windows::Forms::RichTextBox^ box);
	void DrawGraph(sf::RenderWindow& window);
};
