#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Element
{
public:
	int value;
	Element* nextElement;
	Element* HeadElement;
};

class Edge
{
public:
	int weight;
	int vertexA;
	int vertexB;

	Edge(int vertexA, int vertexB, int weight)
	{
		this->vertexA = vertexA;
		this->vertexB = vertexB;
		this->weight = weight;
	}
};

vector<Element*> ElementList;
vector<Edge> EdgeList;

int GetLength(Element* element)
{
	int length = 0;
	while (element != NULL)
	{
		length++;
		element = element->nextElement;
	}

	return length;
}

void MakeSet(int x)
{
	Element* newElement = new Element;
	newElement->value = x;
	newElement->nextElement = NULL;
	newElement->HeadElement = newElement;

	ElementList.push_back(newElement);
}

Element* FindSet(int x)
{
	Element targetElement;
	targetElement.value = -1;

	for (int index = 0; index < ElementList.size(); index++)
	{
		Element* currentElement = ElementList[index];

		while (currentElement != NULL)
		{
			if (currentElement->value == x)
			{
				return currentElement->HeadElement;
			}

			currentElement = currentElement->nextElement;
		}
	}

	return NULL;
}

void Union(int x, int y)
{
	Element* elementX = FindSet(x);
	Element* elementY = FindSet(y);

	if (elementX == elementY)
	{
		return;
	}

	Element* baseElement;
	Element* targetElement;

	if (GetLength(elementX) > GetLength(elementY))
	{
		baseElement = elementX;
		targetElement = elementY;
	}
	else
	{
		baseElement = elementY;
		targetElement = elementX;
	}

	Element* baseTail = baseElement;
	while (baseTail->nextElement != NULL)
	{
		baseTail = baseTail->nextElement;
	}
	baseTail->nextElement = targetElement;

	Element* currentElement = targetElement;
	while (currentElement != NULL)
	{
		currentElement->HeadElement = baseElement;
		currentElement = currentElement->nextElement;
	}

	for (int index = 0; index < ElementList.size(); index++)
	{
		if (ElementList[index]->value == targetElement->value)
		{
			ElementList.erase(ElementList.begin() + index);
			break;
		}
	}
}

bool EdgeCompare(const Edge& a, const Edge& b)
{
	return a.weight < b.weight;
}

int main()
{
	int n, m;
	int x, y, w;

	cin >> n >> m;

	int** graph;

	graph = new int* [n];
	for (int index = 0; index < n; index++)
	{
		graph[index] = new int[n];
		memset(graph[index], 0, sizeof(int) * n);
	}

	for (int index = 0; index < m; index++)
	{
		cin >> x >> y >> w;
		graph[x - 1][y - 1] = w;
		graph[y - 1][x - 1] = w;
	
		MakeSet(index + 1);
		EdgeList.push_back(Edge(x, y, w));
	}

	sort(EdgeList.begin(), EdgeList.end(), EdgeCompare);

	Edge *targetEdge;

	int unionedEdge = 0;
	int total = 0;

	while (unionedEdge < n - 1)
	{
		targetEdge = &EdgeList[0];

		if (FindSet(targetEdge->vertexA) != FindSet(targetEdge->vertexB))
		{
			cout << targetEdge->weight << " ";
			total += targetEdge->weight;

			Union(targetEdge->vertexA, targetEdge->vertexB);
			unionedEdge++;
		}

		EdgeList.erase(EdgeList.begin());
	}

	cout << total << endl;

	return 0;
}