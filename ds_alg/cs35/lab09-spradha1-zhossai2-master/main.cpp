/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/
#include <iostream>
#include <string>
#include "adts/graph.h"
#include "adjacencyListUndirectedGraph.h"
#include "graphAlgorithms.h"
using namespace std;

// function prototypes
void printMenu();
void printError();
void fillGraph(Graph<string, string, float> *swatMap);
void reachability(Graph<string, string, float> *swatMap);
void shortestDistance(Graph<string, string, float> *swatMap);
void allDistances(Graph<string, string, float> *swatMap);
int main()
{
  // TO DO: implement the main program here
  string choice;
  Graph<string, string, float> *swatMap = new AdjacencyListUndirectedGraph<string, string, float>();
  fillGraph(swatMap);
  printMenu();
  cin >> choice;
  while (choice != "0")
  {
    while (choice != "1" && choice != "2" && choice != "3")
    {
      cout << "\nYou entered '" << choice << "' but the only options are: 1, 2, 3, or 0" << endl;
      cout << "Please enter one of the valid operation number" << endl;
      cout << "1. Reachability from one building to another" << endl;
      cout << "2. Shortest length path from one building to another" << endl;
      cout << "3. Distances from one building to all others" << endl;
      std::cout << "0. Quit" << endl;
      cin >> choice;
    }
    cout << "Choice: " << choice << endl;
    if (choice == "1")
    {
      reachability(swatMap);
    }
    if (choice == "2")
    {
      shortestDistance(swatMap);
    }
    if (choice == "3")
    {
      allDistances(swatMap);
    }

    if (choice == "0")
    {
      break;
    }

    printMenu();
    cin >> choice;
  }
  std::cout << "Goodbye!";
  delete swatMap;
  return 0;
}

void printMenu()
{
  std::cout << "\nLet's explore Swarthmore's north campus" << endl;
  std::cout << "1. Reachability from one building to another" << endl;
  std::cout << "2. Shortest length path from one building to another" << endl;
  std::cout << "3. Distances from one building to all others" << endl;
  std::cout << "0. Quit" << endl;
}

void fillGraph(Graph<string, string, float> *swatMap)
{
  vector<string> names = {"Sci", "Sing", "Mar", "Ber", "Kohl", "Trot", "LPAC", "Par"};

  for (string name : names)
  {
    swatMap->insertVertex(name);
  }

  swatMap->insertEdge("Sci", "Mar", " ", 6);
  swatMap->insertEdge("Sci", "Sing", " ", 3);
  swatMap->insertEdge("Sci", "Ber", " ", 4);

  swatMap->insertEdge("Sing", "Trot", " ", 5);
  swatMap->insertEdge("Sing", "Ber", " ", 2);

  swatMap->insertEdge("Mar", "LPAC", " ", 3);

  swatMap->insertEdge("Kohl", "Trot", " ", 3);

  swatMap->insertEdge("Kohl", "Par", " ", 4);
  swatMap->insertEdge("Kohl", "Ber", " ", 2);
  swatMap->insertEdge("Kohl", "LPAC", " ", 2);
}

void reachability(Graph<string, string, float> *swatMap)
{
  string src, dest;
  cout << endl
       << "Enter the building to start from:  ";
  cin >> src;
  while (!swatMap->containsVertex(src))
  {
    cout << src << " is not a valid building names" << endl;
    cout << "The building names are: Sci, Sing, Mar, Ber, Kohl, Trot, LPAC, Par" << endl;
    cout << "Enter the building to start from: ";
    cin >> src;
  }
  cout << "Enter the building to reach:  ";
  cin >> dest;
  while (!swatMap->containsVertex(dest))
  {
    cout << dest << " is not a valid building names" << endl;
    cout << "The building names are: Sci, Sing, Mar, Ber, Kohl, Trot, LPAC, Par" << endl;
    cout << "Enter the building to reach: ";
    cin >> dest;
  }
  if (reachableDFS(src, dest, swatMap))
  {
    cout << dest << " is reachable from " << src << endl;
  }
  else
  {
    cout << dest << " is not reachable from " << src << endl;
  }
}

void shortestDistance(Graph<string, string, float> *swatMap)
{
  string src, dest;
  cout << endl
       << "Enter the building to start from: ";
  cin >> src;
  while (!swatMap->containsVertex(src))
  {
    cout << src << " is not a valid building names" << endl;
    cout << "The building names are: Sci, Sing, Mar, Ber, Kohl, Trot, LPAC, Par" << endl;
    cout << "Enter the building to start from: ";
    cin >> src;
  }
  cout << "Enter the building to reach:   ";
  cin >> dest;
  while (!swatMap->containsVertex(dest))
  {
    cout << dest << " is not a valid building names" << endl;
    cout << "The building names are: Sci, Sing, Mar, Ber, Kohl, Trot, LPAC, Par" << endl;
    cout << "Enter the building to reach: ";
    cin >> dest;
  }
  if (!reachableDFS(src, dest, swatMap))
  {
    cout << dest << "\n is not reachable from " << src << endl;
    return;
  }
  vector<string> path = shortestLengthPathBFS(src, dest, swatMap);
  cout << "\nThe shortest length path is ";
  for (auto vertex : path)
  {
    cout << vertex << " ";
  }
  cout << endl;
}

void allDistances(Graph<string, string, float> *swatMap)
{
  string src;
  vector<pair<string, float>> costPairs;
  Dictionary<string, float> *cost;
  cout << endl
       << "Enter the building to start from: ";
  cin >> src;
  while (!swatMap->containsVertex(src))
  {
    cout << src << " is not a valid building names" << endl;
    cout << "The building names are: Sci, Sing, Mar, Ber, Kohl, Trot, LPAC, Par" << endl;
    cout << "Enter the building to start from: ";
    cin >> src;
  }
  cost = singleSourceShortestPath(src, swatMap);
  cout << "Distance from " << src << " to all other buildings" << endl;
  costPairs = cost->getItems();
  for (pair<string, float> c : costPairs)
  {
    cout << c.first << " : " << c.second << endl;
  }
  delete cost;
}
