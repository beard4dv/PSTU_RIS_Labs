#include "graph.h"
using namespace System::Windows::Forms;

Graph::Graph()
{
	for (int i = 0; i < maxSize; ++i) {
		for (int j = 0; j < maxSize; ++j) {
			this->adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph()
{

}

bool Graph::IsEmpty()
{
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}

bool Graph::IsFull()
{
	return (vertList.size() == maxSize);
}
//
void Graph::Print(RichTextBox^ box)
{
	if (IsEmpty()) {
		box->AppendText("Граф пуст\n");
		return;
	}
	box->AppendText("\t");
	for (int i = 0; i < vertList.size(); i++)
		box->AppendText("|" + vertList[i].ToString() + "|\t");
	box->AppendText("\n\n");
	for (int i = 0; i < vertList.size(); i++) {
		box->AppendText("|" + vertList[i].ToString() + "|\t");
		for (int j = 0; j < vertList.size(); j++)
			box->AppendText(adjMatrix[i][j].ToString() + "\t");
		box->AppendText("\n\n");
	}
}

int Graph::GetVertPos(const int& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i) {
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

void Graph::insertVertex(const int& vertex, RichTextBox^ box)
{
	if (!this->IsFull()) {
		this->vertList.push_back(vertex);
	}
	else {
		box->AppendText("Граф уже заполнен. Невозможно добавить новую вершину\n");
		return;
	}
}

void Graph::removeVertex(const int& vertex, RichTextBox^ box)
{
	int pos = GetVertPos(vertex);
	if (pos == -1) {
		box->AppendText("Вершина " + vertex + " не найдена\n");
		return;
	}
	vertList.erase(vertList.begin() + pos);
	for (int i = pos; i < vertList.size(); ++i) {
		for (int j = 0; j < maxSize; ++j) {
			adjMatrix[i][j] = adjMatrix[i + 1][j];
		}
	}
	for (int i = 0; i < vertList.size(); ++i) {
		for (int j = pos; j < vertList.size(); ++j) {
			adjMatrix[i][j] = adjMatrix[i][j + 1];
		}
	}
	for (int i = 0; i < maxSize; ++i) {
		adjMatrix[vertList.size()][i] = 0;
		adjMatrix[i][vertList.size()] = 0;
	}

	box->AppendText("Вершина " + vertex + " удалена\n");
}

void Graph::insertEdge(const int& vertex1, const int& vertex2, int weight, RichTextBox^ box)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0)
		{
			box->AppendText("Ребро между этими вершинами уже существует\n");
			return;
		}
		else {
			this->adjMatrix[vertPos1][vertPos2] =
				weight;
		}
	}
	else {
		box->AppendText("Обеих вершин (или одной из них) нет в графе\n");
		return;
	}
}

void Graph::removeEdge(const int& vertex1, const int& vertex2, RichTextBox^ box)
{
	int pos1 = GetVertPos(vertex1);
	int pos2 = GetVertPos(vertex2);
	if (pos1 == -1 || pos2 == -1) {
		box->AppendText("Одна или обе вершины не найдены\n");
		return;
	}
	if (adjMatrix[pos1][pos2] == 0) {
		box->AppendText("Ребро между вершинами " + vertex1 + " и " + vertex2 + " не существует\n");
		return;
	}
	adjMatrix[pos1][pos2] = 0;
	box->AppendText("Ребро между вершинами " + vertex1 + " и " + vertex2 + " удалено\n");
}

void DFS_Visit(int vertexPos, vector<bool>& visited, const vector<int>& vertList, int adjMatrix[maxSize][maxSize], RichTextBox^ box)
{
	visited[vertexPos] = true;
	box->AppendText("Вершина " + vertList[vertexPos] + " посещена\n");
	for (int i = 0; i < vertList.size(); ++i) {
		if (adjMatrix[vertexPos][i] != 0 && !visited[i]) {
			DFS_Visit(i, visited, vertList, adjMatrix, box);
		}
	}
}

void Graph::DFS(const int& startVertex, RichTextBox^ box)
{
	int startPos = GetVertPos(startVertex);
	if (startPos == -1) {
		box->AppendText("Начальная вершина не найдена в графе\n");
		return;
	}
	vector<bool> visited(vertList.size(), false);
	box->AppendText("Обход в глубину начиная с вершины " + startVertex + "\n");
	DFS_Visit(startPos, visited, vertList, adjMatrix, box);
	cout << endl;
}

void Graph::BFS(const int& startVertex, RichTextBox^ box)
{
	int startPos = GetVertPos(startVertex);
	if (startPos == -1) {
		box->AppendText("Начальная вершина не найдена в графе\n");
		return;
	}
	vector<bool> visited(vertList.size(), false);
	queue<int> q;
	visited[startPos] = true;
	q.push(startPos);
	box->AppendText("Обход в ширину начиная с вершины " + startVertex + "\n");
	while (!q.empty()) {
		int currPos = q.front();
		q.pop();
		box->AppendText("Вершина " + vertList[currPos] + " посещена\n");
		for (int i = 0; i < vertList.size(); ++i) {
			if (adjMatrix[currPos][i] != 0 && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	};
}

void Graph::Dijkstra(const int& startVertex, RichTextBox^ box)
{
	int n = vertList.size();
	int startPos = GetVertPos(startVertex);
	if (startPos == -1) {
		box->AppendText("Начальная вершина не найдена в графе\n");
		return;
	}
	const int INF = 1000000;
	vector<int> dist(n, INF);
	vector<bool> visited(n, false);
	dist[startPos] = 0;
	for (int count = 0; count < n - 1; ++count)
	{
		int minDist = INF;
		int u = -1;
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && dist[i] <= minDist)
			{
				minDist = dist[i];
				u = i;
			}
		}
		if (u == -1) break;
		visited[u] = true;
		for (int v = 0; v < n; ++v) {
			if (!visited[v] && adjMatrix[u][v] != 0 && dist[u] + adjMatrix[u][v] < dist[v])
			{
				dist[v] = dist[u] + adjMatrix[u][v];
			}
		}
	}
	box->AppendText("Кратчайшие расстояния от вершины " + startVertex + ":\n");
	for (int i = 0; i < n; ++i)
	{
		if (i != startVertex - 1)
		{
			box->AppendText("До вершины " + vertList[i] + ": ");
			if (dist[i] == INF)
				box->AppendText("(отсутствует)\n");
			else
				box->AppendText(dist[i] + "\n");
		}
	}
}

void drawArrowhead(sf::RenderWindow& window, sf::Vector2f from, sf::Vector2f to, float arrowSize = 10.f, float offset = 20.f)
{
	const float PI = 3.14159265f;

	sf::Vector2f direction = to - from;
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (length == 0) return;

	direction /= length;

	sf::Vector2f newTo = to - direction * offset;

	float angle = std::atan2(direction.y, direction.x);
	float arrowAngle = 25 * PI / 180;

	sf::Vector2f arrowPoint1 = newTo - arrowSize * sf::Vector2f(std::cos(angle - arrowAngle), std::sin(angle - arrowAngle));
	sf::Vector2f arrowPoint2 = newTo - arrowSize * sf::Vector2f(std::cos(angle + arrowAngle), std::sin(angle + arrowAngle));

	sf::Vertex arrowHead[] =
	{
		sf::Vertex(newTo, sf::Color::Black),
		sf::Vertex(arrowPoint1, sf::Color::Black),
		sf::Vertex(newTo, sf::Color::Black),
		sf::Vertex(arrowPoint2, sf::Color::Black),
	};
	window.draw(arrowHead, 4, sf::Lines);
}

void drawEdgeWithWeight(sf::RenderWindow& window, sf::Vector2f from, sf::Vector2f to, int weight, float arrowSize = 10.f, float offset = 20.f, float textShift = 10.f)
{
	sf::Vector2f midPoint = (from + to) / 2.f;

	sf::Vector2f dir = to - from;
	float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	sf::Vector2f unitDir = dir / len;
	sf::Vector2f lineStart = from + unitDir * offset;
	sf::Vector2f lineEnd = to - unitDir * offset;

	sf::Vertex line[] =
	{
		sf::Vertex(lineStart, sf::Color::Black),
		sf::Vertex(lineEnd, sf::Color::Black)
	};
	window.draw(line, 2, sf::Lines);

	drawArrowhead(window, from, to, arrowSize, offset);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Ошибка загрузки шрифта!" << std::endl;
	}

	sf::Text weightText;
	weightText.setFont(font);
	weightText.setString(std::to_string(weight));
	weightText.setCharacterSize(15); 
	weightText.setFillColor(sf::Color::Black);

	sf::Vector2f textPosition = from + unitDir * textShift;

	weightText.setPosition(textPosition.x - weightText.getLocalBounds().width / 2, textPosition.y - weightText.getLocalBounds().height / 2);

	window.draw(weightText);
}

void Graph::DrawGraph(sf::RenderWindow& window)
{
	const float radius = 20.0f;
	const float centerX = 400.0f, centerY = 300.0f;
	const float angleStep = 360.0f / vertList.size();
	vector<sf::Vector2f> positions;

	for (size_t i = 0; i < vertList.size(); ++i)
	{
		float angle = angleStep * i * 3.14159f / 180.0f;
		float x = centerX + 200 * cos(angle);
		float y = centerY + 200 * sin(angle);
		positions.push_back(sf::Vector2f(x, y));

		sf::CircleShape circle(radius);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(sf::Color::Black);
		circle.setPosition(x - radius, y - radius);
		window.draw(circle);

		sf::Font font;
		if (!font.loadFromFile("arial.ttf")) continue;
		sf::Text text;
		text.setFont(font);
		text.setString(to_string(vertList[i]));
		text.setCharacterSize(16);
		text.setFillColor(sf::Color::Black);
		text.setPosition(x - 8, y - 10);
		window.draw(text);
	}

	float vertexRadius = 20.f;

	for (size_t i = 0; i < vertList.size(); ++i)
	{
		for (size_t j = 0; j < vertList.size(); ++j)
		{
			if (adjMatrix[i][j] != 0)
			{
				sf::Vector2f from = positions[i];
				sf::Vector2f to = positions[j];

				sf::Vector2f dir = to - from;
				float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
				sf::Vector2f unitDir = dir / len;
				sf::Vector2f lineStart = from + unitDir * vertexRadius;
				sf::Vector2f lineEnd = to - unitDir * vertexRadius;

				sf::Vertex line[] =
				{
					sf::Vertex(lineStart, sf::Color::Black),
					sf::Vertex(lineEnd, sf::Color::Black)
				};
				window.draw(line, 2, sf::Lines);

				drawEdgeWithWeight(window, from, to, adjMatrix[i][j], 10.f, vertexRadius, 80.f);
			}
		}
	}
}