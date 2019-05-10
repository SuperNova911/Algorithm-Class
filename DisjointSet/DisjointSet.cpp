#include <iostream>
#include <vector>

using namespace std;

class Element
{
public:
	int value;
	Element* nextElement;
	Element* HeadElement;
};

vector<Element*> ElementList;

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

int main()
{
	int n, m;
	cin >> n >> m;

	int x, y;
	Element elementX, elementY;
	for (int index = 0; index < m; index++)
	{
		cin >> x >> y;

		if (FindSet(x) == NULL)
		{
			MakeSet(x);
		}

		if (FindSet(y) == NULL)
		{
			MakeSet(y);
		}

		Union(x, y);
	}

	int max = 0;
	for (int index = 0; index < ElementList.size(); index++)
	{
		Element* currentElement = ElementList[index];
		int length = GetLength(currentElement);

		if (length > max)
		{
			max = length;
		}
	}

	cout << max << endl;

	return 0;
}